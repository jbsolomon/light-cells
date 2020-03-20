# Light Cells

########################################################################
# CMake policies
########################################################################

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# OLD: project() command manages VERSION variables.
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif(POLICY CMP0048)

# OLD: target_sources() command converts relative paths to absolute.
if(POLICY CMP0076)
  cmake_policy(SET CMP0076 NEW)
endif(POLICY CMP0076)

# OLD: Targets need to be created in the same directory to be used.
if(POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif(POLICY CMP0079)

########################################################################
# CMake Project
########################################################################

project(LightCells
  VERSION 0.0.0.1
  DESCRIPTION "Batteries for Light"
  HOMEPAGE_URL "https://github.com/phoenix-engine/light-cells"
  LANGUAGES C
)

########################################################################
# CMake setup
########################################################################

if(WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif(WIN32)

set(CELLS_DEV
  CACHE
  BOOL
  OFF
  "Enable dev-mode for Cells"
)

set(CELLS_INSTALL_DIR
  CACHE
  PATH
  ${CMAKE_INSTALL_PREFIX}
  "The Cells installation directory"
)

if(CELLS_DEV)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif(CELLS_DEV)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
include(MacroEnsureOutOfSourceBuild)
macro_ensure_out_of_source_build("\
${PROJECT_NAME} requires an out of source build. Please create a \
separate build directory and run \
'cmake /path/to/${PROJECT_NAME} [options]' there."
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${CMAKE_BINARY_DIR}/CellsConfigVersion.cmake"
  VERSION ${CELLS_VERSION}
  COMPATIBILITY AnyNewerVersion
)

set(CELLS_DIR ${CMAKE_CURRENT_LIST_DIR})
set(INCLUDE_INSTALL_DIR include/)
set(LIB_INSTALL_DIR lib/)

configure_package_config_file(
  # The cmake.in file is the template file which will be elaborated.
  CellsConfig.cmake.in

  # The .cmake file is the product of the template elaboration.  It will
  # be consumed by a downstream build which imports this project.
  CellsConfig.cmake

  # INSTALL_DESTINATION is the path where the generated Config.cmake
  # file will be installed.
  INSTALL_DESTINATION ${CMAKE_CURRENT_LIST_DIR}/cmake

  # PATH_VARS specifies the install paths of the products of this Config
  # package.
  # PATH_VARS artifacts/Release
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR

  # [NO_SET_AND_CHECK_MACRO]
  # NO_CHECK_REQUIRED_COMPONENTS_MACRO

  # INSTALL_PREFIX specifies the location the package will be installed.
  # In this case, the package is intended to be used from within the
  # build tree, rather than from a system lib directory.
  #
  # A future binary-only build could set this to a system lib install
  # directory.
  INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}
)

write_basic_package_version_file(
  CellsConfigVersion.cmake
  VERSION 0.0.1
  COMPATIBILITY SameMinorVersion
)

########################################################################
# deps
########################################################################

# Find Light if it's not already a target.
if(NOT(TARGET Light))
  find_package(Light)
  message("Found Light")
endif() # NOT(TARGET Light)

# Find SDL2 if it's not already a target.
if(NOT(TARGET SDL2))
  find_package(SDL2 REQUIRED)
  message("Found SDL2")
endif() # NOT(TARGET SDL2)

########################################################################
# Targets
########################################################################

# cell_sdl.h
add_library(CellSDL SHARED)
target_sources(CellSDL PUBLIC cell_sdl.c)
target_sources(CellSDL PUBLIC cell_sdl.h)
target_include_directories(CellSDL PUBLIC ${CELLS_DIR})

set_property(TARGET CellSDL PROPERTY C_STANDARD 90)
set_property(TARGET CellSDL PROPERTY C_STANDARD_REQUIRED ON)

target_link_libraries(CellSDL Light SDL2)

########################################################################
# Installation
########################################################################

# Export files (shamelessly cribbed from SDL2)
if (WINDOWS)
  set(PKG_PREFIX "cmake")
else ()
  set(PKG_PREFIX "lib/cmake/SDL2")
endif ()

install(
  FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/CellsConfig.cmake
    ${CMAKE_BINARY_DIR}/CellsConfigVersion.cmake
  DESTINATION ${PKG_PREFIX}
)
