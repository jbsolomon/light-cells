# Light Cells

Light Cells are helpers for working with Light.  Light maintains as few
internal dependencies as possible, so most people will want to use it
through this collection.

A Cell is a small bundle of related functionality.  For example, 
[`cell-sdl`](cell-sdl.h) contains SDL2 helpers for Light.

## Using Light Cells in your project

Like Light, Cells can be used in your project by direct inclusion, as a
CMake submodule, by dropping in the header and shared library file(s),
or as an installed system dependency.

## List of Cells

- [cells.h](cells.h): Cells core types and helpers (always include)
- [cellsdl.h](sellsdl.h): SDL-related functionality

## Dependencies

Cells includes its own dependencies as Git submodules.  After cloning
the repo, you can load them using 
`git submodule update --init --recursive`.

Dependencies:
- [zf_log](https://github.com/phoenix-engine/zf_log): Fast logging
- [SDL2](https://github.com/phoenix-engine/SDL): Native UI and graphics
