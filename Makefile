mandlebrotObject: Mandlebrot/Mandlebrot.c
	gcc -Wall -Wextra -Wpedantic -c Mandlebrot/Mandlebrot.c -o Mandlebrot/target/Mandlebrot.o

mandlebrot: mandlebrotObject
	gcc Mandlebrot/target/Mandlebrot.o -o Mandlebrot/target/Mandlebrot

minigrepObject: Minigrep/Minigrep.c Minigrep/ExpandableBitVec.c Minigrep/Finder.c
	gcc -Wall -Wextra -Wpedantic -c Minigrep/Minigrep.c -o Minigrep/target/Minigrep.o
	gcc -Wall -Wextra -Wpedantic -c Minigrep/ExpandableBitVec.c -o Minigrep/target/ExpandableBitVec.o
	gcc -Wall -Wextra -Wpedantic -c Minigrep/Finder.c -o Minigrep/target/Finder.o


minigrep: minigrepObject
	gcc Minigrep/target/Minigrep.o Minigrep/target/ExpandableBitVec.o Minigrep/target/Finder.o -o Minigrep/target/Minigrep