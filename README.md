#### valgrind cmd
```
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes  ./cub3D maps/good/map.cub

```

#### TO DO:

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
- [ ] 

##### Keyboard and mouse:
- [x] left right arrow
- [x] W A S D keys hook
- [x] click on the x of window close the window
- [x] and the esc key
- [x] no segfault or any memorey leak while exiting the program

