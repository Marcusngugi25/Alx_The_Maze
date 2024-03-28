# The Maze

The Maze is a 3D Maze game that uses ray casting to render a 2D map into a 3D navigable world!

The Maze was written in C using SDL2 library. Development was performed using Ubuntu 24.04 - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0

### About SDL2

Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and popular games including Valve's award winning catalog and many Humble Bundle games.

The goal of this project is to create a game in 3D using raycasting !

## Keyboard Keys for Players

- `Arrow Keys` -- Player Directions
- `R` -- Refresh
- `M` -- Map
- `C` -- Zoom Player view
- `[` -- Zoom Out in Game
- `]` -- Zoom In in Game
- `F` -- Change Views (Normal view to Panoramic view and vice versa)
- `T` -- Change Texture of walls and square columns

### <u>Tools and Languages Used...</u>

- C language
- SDL2 (Simple DirectMedia Layer)
- Ray-Casting
- Bash

## Compiling

Using a Windows Operating system, Navigate to the `src` folder and Compile with
`gcc -std=c17 *.c -I{Path to SDL2\include} -L{Path to SDL2\lib} -Wall -lmingw32 -lSDL2main -lSDL2 -o raycaster`
Check out [this link](https://www.matsson.com/prog/sdl2-mingw-w64-tutorial.php#:~:text=the%20gcc%20command.-,Step%202%3A%20Installing%20SDL2,library%20for%20Windows%20using%20MinGW.&text=After%20extracting%20the%20contents%20using,bit%20version%20of%20the%20library) for help.

Using Linux, Navigate to the `src` folder and Compile with
`gcc -o raycaster *.c 'sdl2-config --cflags --libs' -lm`

- Remove the line `#define SDL_MAIN_HANDLED` from the source codes in Linux

## Author

- Marcus Ngugi[this link](https://github.com/Marcusngugi25)
