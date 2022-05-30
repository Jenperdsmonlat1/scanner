echo "Compiling program";

gcc -Wall scanner.c functions.c -o scanner -lm
./scanner
