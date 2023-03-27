CC = g++
INC = -I"E:\Libs\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\include" \
	  -I"E:\Libs\box2d-2.4.1-mingw-64-bit\include" \
	  -I"C:\Program Files\FMOD SoundSystem\FMOD Studio API Windows\api\core\inc"
LIB = -L"E:\Libs\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\lib" \
	  -L"E:\Libs\box2d-2.4.1-mingw-64-bit\lib"
FLAGS = -c -DSFML_STATIC

all: main.o
	$(CC) main.o $(LIB) -static \
	"C:\Program Files\FMOD SoundSystem\FMOD Studio API Windows\api\core\lib\x64\fmod.dll" \
	-lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lfreetype \
	-lopengl32  -lwinmm  -lgdi32 -lbox2d -o app

main.o: main.cpp
	$(CC) $(FLAGS) $(INC) main.cpp
