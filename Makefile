CC=gcc

INCLUDE_PATHS := -ID:\c\SDL\SDL2-2.0.7\x86_64-w64-mingw32\include\SDL2\
-ID:\c\SDL\SDL2_image-2.0.2\x86_64-w64-mingw32\include\SDL2\
-ID:\c\SDL\SDL2_mixer-2.0.2\x86_64-w64-mingw32\include\SDL2

LINK_PATHS := -LD:\c\SDL\SDL2-2.0.7\x86_64-w64-mingw32\lib\
-LD:\c\SDL\SDL2_image-2.0.2\x86_64-w64-mingw32\lib\
-LD:\c\SDL\SDL2_mixer-2.0.2\x86_64-w64-mingw32\lib\

LIBS := -lmingw32 -lSDL2_image -lSDL2_mixer -lSDL2main -lSDL2

OTHER_FLAGS := -Wl,-subsystem,console\
-march=x86-64 -Wall -Wno-unused-function -Werror -g

CFLAGS = $(INCLUDE_PATHS) $(LINK_PATHS) $(LIBS) $(OTHER_FLAGS)

TARGET=bin/main.exe

src = $(wildcard src/*.c)
obj = $(patsubst src/%.c,obj/%.o,$(src))

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) -MP -MMD -MD -MT $@ -MF $(@:.o=.d)
main: $(obj)
	$(CC) -o $(TARGET) $(obj) $(CFLAGS)

.PHONY: clean

clean:
	del /Q obj\*

-include $(obj:.o=.d)