@echo off

color a
:menu
echo "Compiling program"
gcc main.c -o scanner.exe -lwsock2
