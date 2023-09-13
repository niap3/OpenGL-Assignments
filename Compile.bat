set example="SquareGame.cpp"
::set example="RotatingRect.cpp"
set gcc="C:\MinGW\bin\gcc.exe"

g++ -c -o example.o %example%  
g++ -o example.exe example.o  -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows 
example.exe