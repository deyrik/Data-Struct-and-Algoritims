compilador = gcc
caminho = Data\ Structs


caminhoList = $(caminho)/List
caminhoLinkedList = $(caminho)/Linked\ List
caminhoStack = $(caminho)/Simple\ Stack
caminhoLinkedStack = $(caminho)/Stack\ with\ Linked
caminhoQueue = $(caminho)/Queue\ with\ Array


list: 
	$(compilador) $(caminhoList)/list.c -o list.o

linkedList: 
	$(compilador) $(caminhoLinkedList)/linkedList.c -o linkedList.o

simpleStack: 
	$(compilador) $(caminhoStack)/simpleStack.c -o simpleStack.o

linkedStack: 
	$(compilador) $(caminhoLinkedStack)/linkedStack.c -o linkedStack.o
	
queue:
	$(compilador) $(caminhoQueue)/queue.c -o queue.o


clear:
	rm -rf *.o