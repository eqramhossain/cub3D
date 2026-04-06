# This project has been created as part of the 42 curriculum by ehossain & roussada

## Description

### What is this project about ? 
cub3D is a 3D game using a first-person perspective — it is mimic the Wolfenstein 3D form the 90s.

The core technology used is called ray-casting. Well what is it?

Ray-casting explained simply: Imagine you're standing in a maze looking forward. Instead of drawing the entire 3D world, we draw invisible lines (rays) from your eyes to the walls. We calculate where each ray hits a wall, how far away that wall is, and then we draw vertical lines on your screen — taller lines for closer walls, shorter lines for distant walls. When you put thousands of these lines side by side, you get the illusion of a complete 3D world! This is how games like Wolfenstein 3D (1992) worked.

### Purpose
The main purpose of this project is to get familiar with games and how 3d things works. Implementin Ray-casting algorithm. 

Some Goals:
- Graphics Programming — learning how 3D rendering actually works
- File Parsing — how to read and interpret configuration files
- Game Loop — Real-time interactive graphics
- Event Handling — Responding to keyboard and mouse input using mlx (X11 window management)
- Proper Memory Management


### Instructions
How to run and create a valid map for cub3D

#### Running the Program:

```
make                   # Compile everything
./cub3D your_map.cub   # Run with your map file
make clean             # Remove object files
make fclean            # Remove everything (objects + executable)
make re                # Rebuild everything
```

>[!note] The program must run with only one argument otherwise return error.

#### Creating Your Map File (.cub)

The .cub file has two main sections: Configuration and Map.

Section 1: Configuration (order doesn't matter)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0
```


Breaking this down:
```
NO = North wall texture file path
SO = South wall texture file path
WE = West wall texture file path
EA = East wall texture file path
F = Floor color in RGB format (Red, Green, Blue) — values 0-255
C = Ceiling color in RGB format
```

Section 2: Map (MUST BE LAST, no reordering!)

The map is a grid made of:

    0 = Empty space (walkable)
    1 = Wall (solid)
    ' ' = Spaces (they are a valid part of the map)
    N = Player starting position, facing North
    S = Player starting position, facing South
    E = Player starting position, facing East
    W = Player starting position, facing West

Example of a valid map:
```
111111
100101
101001
1100N1
111111
```

Critical Rules for Maps:
- MUST be completely surrounded by walls (1's on all edges)
- Exactly ONE player position (N, S, E, or W)
- Spaces ARE part of the map (you must handle them!) 
- Must be the LAST element in your .cub file 
- Can have empty lines before the map (for readability)



#### valgrind cmd
```
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes  ./cub3D maps/good/map.cub

```

### Direction Vector

```
        N (North)
        dir = (0, -1)
           ↑
           |
W ←--------+--------→ E
(-1,0)     |      (1,0)
           |
           ↓
        S (South)
        dir = (0, 1)
```

```
| Letter | Direction         |
| ------ | ----------------- |
| `N`    | Facing up (y-)    |
| `S`    | Facing down (y+)  |
| `E`    | Facing right (x+) |
| `W`    | Facing left (x-)  |
```

```
Direction  |  Movement Type      |  x (horizontal)  |  y (vertical)  |  Vector
-----------|---------------------|------------------|----------------|----------
North (N)  |  UP (smaller Y)     |  0 (no horiz.)   |  -1 (decrease) |  (0, -1)
South (S)  |  DOWN (larger Y)    |  0 (no horiz.)   |  +1 (increase) |  (0, 1)
East (E)   |  RIGHT (larger X)   |  +1 (increase)   |  0 (no vert.)  |  (1, 0)
West (W)   |  LEFT (smaller X)   |  -1 (decrease)   |  0 (no vert.)  |  (-1, 0)
```

### Player data:
```
| Data                 | Purpose                                   |
| -------------------- | ----------------------------------------- |
| `x`, `y`             | Initial coordinates in the map            |
| `dir_x`, `dir_y`     | Where the player is looking               |
| `plane_x`, `plane_y` | Used for FOV in raycasting (camera width) |
```


### Camera plane Vector

The camera plane vector is perpendicular (90° rotated) to your direction vector!

The direction is = where your nose points
The camera plane is = a line across your eyes (left eye to right eye)
The Rotation Math is = (90° rotation):

If direction is (dir_x, dir_y), the perpendicular vector is (-dir_y, dir_x)

The length of the plane vector controls the FOV(field of view)
A value of 0.66 gives roughly a 66° field of view
Larger value = wider FOV (fish-eye effect)
Smaller value = narrower FOV (zoomed in)

```
Direction    dir_x  dir_y  arrow  plane_x   plane_y
─────────────────────────────────────────────────────
North (N)      0     -1     ↑      0.66       0
South (S)      0      1     ↓     -0.66       0
East (E)       1      0     →       0        0.66
West (W)      -1      0     ←       0       -0.66
```

To calculate each ray’s direction:
```
rayDir = direction + cameraPlane * cameraX
```

Where:
```
direction = player direction vector
cameraX = a value from -1 (left edge) to +1 (right edge)
cameraPlane = left/right direction vector (FOV)
```

This means:
```
The leftmost ray = dir - plane
The center ray = dir
The rightmost ray = dir + plane
```

### To-Do
- [ ] Bug 1
    - if there is `NO					textures/north.xpm  .......` like this an invalid read occour
- [ ] Bug 2
    - if there is `\n` inside map area should return error.
- [ ] Bug 3 
    - map4 when `static int	ft_is_num(char *trimmed)` this function fail there are some memory leak.
- [ ] Bug 4 
    - map5 print the error msg of this `static int	ft_is_num(char *trimmed)` function. 
    - check all the return error function and error msg correctly
- [ ] Bug 5
    - if all the texture.xpm files as WALL_SIZE are not same sizes there is an segfault
- [ ] Bug 6 
    - if floor or ceiling color has a `+` or `-` sign it has some memory leak
    - and does not print any error msg
- [ ] Bug 7
    - if floor or ceiling color is memory leak 
    - and also does not print error msg
```
F asd             255,				    199					 ,          155
F                 255,				    199					 ,          155 asd
F                 255,		  asd	    199					 ,          155 
```
- [ ] Bug 8
    - in case of an unknown char is found in map does work but there is an invalid read



### How was AI used in this project



| Ressources for cub3D                                                                                                          |
| ----------------------------------------------------------------------------------------------------------------------------- |
| [subject.pdf](https://github.com/Ebuzzd42/cub3D/blob/main/references/en.subject.pdf)                                          |
| [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/images.html)                                                      |
| [Beginners guide to Desktop window system](https://www.youtube.com/playlist?list=PLTXMX1FE5Hj7JmR73CQDXkNq8OVn9_Z6F)          |
| [Drawing with minilibx](https://www.youtube.com/watch?v=9eAPbNUQD1Y)                                                          |
| [Introduction to minilibx](https://www.youtube.com/watch?v=bYS93r6U0zg)                                                       |
| [Raycasting 1](https://lodev.org/cgtutor/raycasting.html)                                                                     |
| [Raycasting 2](https://lodev.org/cgtutor/raycasting2.html)                                                                    |
| [Raycasting 3](https://lodev.org/cgtutor/raycasting3.html)                                                                    |
| [Raycasting 4](https://lodev.org/cgtutor/raycasting4.html)                                                                    |
| [Make your own Raycaster Part 1](https://www.youtube.com/watch?v=PC1RaETIx3Y&list=PLAaI2BTdQ5UNqKyp-0qwGzsU7U2DmeQmA&index=1) |
| [Make your own Raycaster Part 2](https://www.youtube.com/watch?v=PC1RaETIx3Y&list=PLAaI2BTdQ5UNqKyp-0qwGzsU7U2DmeQmA&index=1) |
