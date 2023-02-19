mandlebrotObject: Mandlebrot/Mandlebrot.c
	gcc -Wall -Wextra -Wpedantic -c Mandlebrot/Mandlebrot.c -o Mandlebrot/target/Mandlebrot.o

mandlebrot: mandlebrotObject
	gcc Mandlebrot/target/Mandlebrot.o -o Mandlebrot/target/Mandlebrot.exe
	Mandlebrot/target/Mandlebrot.exe


minigrepObject: Minigrep/Minigrep.c Minigrep/ExpandableBitVec.c
	gcc -Wall -Wextra -Wpedantic -c Minigrep/Minigrep.c -o Minigrep/target/Minigrep.o
	gcc -Wall -Wextra -Wpedantic -c Minigrep/ExpandableBitVec.c -o Minigrep/target/ExpandableBitVec.o

minigrep: minigrepObject
	gcc Minigrep/target/Minigrep.o Minigrep/target/ExpandableBitVec.o -o Minigrep/target/Minigrep.exe
	Minigrep/target/Minigrep.exe