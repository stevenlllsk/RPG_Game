echo @off
setlocal

set APP=runecrawl
set SRC=.\src\
set RES=.\resources\

windres "%RES%resources.rc" "%RES%resources.o"

g++ -std=c++20 -O2 -s "%SRC%main.cpp" "%SRC%enemies.cpp" "%SRC%inventory.cpp" "%SRC%shop.cpp" "%RES%resources.o" -o runecrawl.exe

echo Built "%APP%.exe" successfully.
exit /b 0