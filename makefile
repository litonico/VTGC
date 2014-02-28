all:

garbagecollector: garbagecollector.h language.h VM.c VM.h
	clang -o garbagecollector garbagecollector.c  

