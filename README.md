# This project has been created as part of the 42 curriculum by ehossain & roussada

## Description

### What is this project about ? 

### Purpose and Goal

### Instructions


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
