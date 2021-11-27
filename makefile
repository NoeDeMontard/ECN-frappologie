# Some variables
x86x64 := x64
FLAGS := -static-libstdc++ -static-libgcc# -Wl,-Bstatic -lpthread#-static
#FLAGS := -static
ifeq ($(OS),Windows_NT)# is Windows_NT on XP, 2000, 7, Vista, 10...
    detected_OS := Windows
else
    detected_OS := $(shell uname)# same as "uname -s"
endif

compilePlatform := $(detected_OS)
targetPlatform := Windows$(x86x64)

ifeq ($(compilePlatform), Linux)
	ifeq ($(targetPlatform), Windowsx64)
		compiler = x86_64-w64-mingw32-g++
		# A 64bit cross compiler to compile 64 windows programs on linux
	else ifeq ($(targetPlatform), Windowsx86)
		compiler = i686-w64-mingw32-g++
		# A 32bit cross compiler to compile 32 windows programs on linux
	endif
#else ifeq ($(compilePlatform), Windows)
#	#TODO : check if the var exist in windows
#	ifeq ($(targetPlatform), Windowsx64)
#		#compiler = 
#	else ifeq ($(targetPlatform), Windowsx86)
#		#compiler = 
#	endif
endif

ifdef DEBUG
$(warning compilePlatform $(compilePlatform))
$(warning targetPlatform $(targetPlatform))
$(warning compiler $(compiler))
endif

app.exe: main.o affichage.o
	$(compiler) main.o affichage.o -o app.exe $(FLAGS)

main.o:  main.cpp constantes.h affichage.h
	$(compiler) -c main.cpp $(FLAGS)

affichage.o: affichage.cpp affichage.h constantes.h
	$(compiler) -c affichage.cpp $(FLAGS)
