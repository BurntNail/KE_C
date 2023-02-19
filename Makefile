mandlebrotObject: Mandlebrot.c
	gcc -Wall -Wextra -Wpedantic -c Mandlebrot.c -o Mandlebrot/Mandlebrot.o

mandlebrot: mandlebrotObject
	gcc Mandlebrot/Mandlebrot.o -o Mandlebrot/Mandlebrot.exe
	Mandlebrot/Mandlebrot.exe