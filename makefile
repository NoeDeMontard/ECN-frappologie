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
buildFolder := build

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
$(info compilePlatform $(compilePlatform))
$(info targetPlatform  $(targetPlatform))
$(info compiler        $(compiler))
endif

app.exe: $(buildFolder)/main.o $(buildFolder)/keyWrapper.o $(buildFolder)/password.o $(buildFolder)/lib.o
	$(compiler) $(buildFolder)/main.o $(buildFolder)/keyWrapper.o $(buildFolder)/password.o $(buildFolder)/lib.o -o app.exe $(FLAGS)

$(buildFolder)/main.o:  main.cpp settings.h language.h lib.h
	$(compiler) -c main.cpp $(FLAGS) -o $(buildFolder)/main.o

$(buildFolder)/lib.o:  lib.cpp lib.h settings.h password.h language.h keyWrapper.h
	$(compiler) -c lib.cpp $(FLAGS) -o $(buildFolder)/lib.o

$(buildFolder)/keyWrapper.o: keyWrapper.cpp keyWrapper.h keyConst.h
	$(compiler) -c keyWrapper.cpp $(FLAGS) -o $(buildFolder)/keyWrapper.o

$(buildFolder)/password.o: password.cpp password.h settings.h
	$(compiler) -c password.cpp $(FLAGS) -o $(buildFolder)/password.o

