# Harry potter
Another harry potter clone written in C using SDL2. It lacks a some features compared to [C# version](https://github.com/wingerse/harry-potter-game). Makefile is linux only but you can use WSL and change commands to `bash -c command` to compile on windows.  

## Compile-time dependencies
You need [embed](https://github.com/wingerse/embed) in your `PATH`. This is for embedding the files in res/.  

## Runtime Dependencies  
You need SDL2, SDL2 Image, and SDL2 Mixer in your system.  

## Compiling
Do `make RELEASE=1`. 

## Run
After compiling, run with `bin/release/harry-potter`

![screenshot](https://image.prntscr.com/image/iOpwf9HXSsiQRzF49SK0pQ.png)