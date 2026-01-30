#### valgrind cmd
```
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes  ./cub3D maps/good/map.cub

```

#### TO DO:

##### Map:
- [ ] Find the map if its the last thing in the map
- [ ] Extract the map 
- [ ] map can only contains N E S W 0 1 
- [ ] map must be closed by walls 
- [ ] Spaces are a valid part of the map and are up to you to handle.
- [ ] map cannot be separated by newline
- [ ]  

##### Keyboard and mouse:
- [x] left right arrow
- [x] W A S D keys hook
- [x] click on the x of window close the window
- [x] and the esc key
- [x] no segfault or any memorey leak while exiting the program

