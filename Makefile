compilador = gcc
caminho = Data\ Structs


caminhoList = $(caminho)/List
caminhoLinkedList = $(caminho)/Linked\ List
caminhoStack = $(caminho)/Simple\ Stack


list: 
	$(compilador) $(caminhoList)/list.c -o list.o

linkedList: 
	$(compilador) $(caminhoLinkedList)/linkedList.c -o linkedList.o

simpleStack: 
	$(compilador) $(caminhoStack)/simpleStack.c -o simpleStack.o

	
clear:
	rm -rf *.o