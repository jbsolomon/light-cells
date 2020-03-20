# Light Cells

Light Cells are helpers for working with Light.  Light maintains as few
internal dependencies as possible, so most people will want to use it
through this collection.

A Cell is a small bundle of related functionality.  For example,
[`cell_sdl`](cell_sdl.h) contains SDL2 helpers for Light.

So far, all Cells are ANSI C89 compatible.  In the future, some Cells
might offer support for libraries which require C99.  All Cells will
always work with Windows (MSVC), so no unsupported C standard will ever
be required.  Cells which require C99 will clearly say so.

## Using Light Cells in your project

Like Light, Cells can be used in your project by direct inclusion, as a
CMake submodule, by dropping in the header and shared library file(s),
or as an installed system dependency.

## List of Cells

- [cells.h](cells.h): Cells core types and helpers (always include)
- [cell_sdl.h](cell_sdl.h): SDL-related functionality

## Dependencies

Light Cells depends on a few libraries, mostly since it offers
Light-friendly convenience wrappers for them.

[//]: # (Include mention of "phx cell".)

If you are working in a non-CMake build, such as a system install, you
may install the dependencies yourself.  Otherwise, all Phoenix libraries
have support for use as CMake subtrees / use as Git submodules.

Dependencies:
- [Light](https://github.com/phoenix-engine/light): A light graphics toolkit
- [SDL2](https://github.com/phoenix-engine/SDL): Native UI and graphics
