# TicTacToe
IA to play Tic Tac Toe

run:

```
cc *.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 && ./a.out
```

```
emcc -o index.html *.c -Os -Wall ./../../../raylib/src/libraylib.a -I. -I../../../raylib/src/ -L. -L../../../raylib/src/ -s USE_GLFW=3 -s ASYNCIFY --shell-file ../../../raylib/src/minshell.html -DPLATFORM_WEB -s TOTAL_MEMORY=60MB   --preload-file assets   --preload-file sounds  
```