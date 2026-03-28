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

#### TO DO:

- [ ] Img are not loaded in correctly.

##### Error Case Found:
- [x] when file contains `NO\nfile.xpm` there is a segfault.
    - saying stack overflow

##### File:
- [ ] Except for the map content, each type of element can be separated by one or more empty lines.
    - while "spaces" "tab" "\n" continue until find a flag
    - if a flag is found then while "spaces" "tab" "\n" continue until the path to file is found
    - if path is found extract until the end of line "\n" and return; end
- [ ] Extract every other information about player
    - direction
    - position
    - plane

##### Map:
- [x] Find the map if its the last thing in the map
- [x] Extract the map 
- [x] map can only contains N E S W 0 1 
- [x] tabs are not a valid char in map
    - if found return error
- [x] Spaces are a valid part of the map and are up to you to handle.
    - spaces will be considered as walls "1" in map
- [x] map cannot be separated by newline
    - if a newline is found return error unknown char is found
    - this is handled by default when i split at the beginning of the program.
- [x] map must be closed by walls 
- [ ] map must me valid use a flood fill to check if it is even possible go in all the area
    - have to use a copy of map.
- [ ] When there is a tab `\t` error unknown char found in map.
    - that should not occured cause `\t` is a valid char in map data.

##### Keyboard and mouse:
- [x] left right arrow
- [x] W A S D keys hook
- [x] click on the x of window close the window
- [x] and the esc key
- [x] no segfault or any memorey leak while exiting the program
- [ ] The A and D key are not working properly.

