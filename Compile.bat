set example="spiderWeb.cpp"
::set example="rotatingRect.cpp"
::set example="simple_rect.cpp"
::set example="Moving_Rect.cpp"
set gcc="C:\MinGW\bin\gcc.exe"

g++ -c -o example.o %example%  
g++ -o example.exe example.o  -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows 
example.exe