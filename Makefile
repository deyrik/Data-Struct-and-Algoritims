compilador = gcc
caminho1 = Data\ Structs
caminho2 = Ordenation


caminhoList = $(caminho1)/List
caminhoLinkedList = $(caminho1)/Linked\ List
caminhoStack = $(caminho1)/Simple\ Stack
caminhoLinkedStack = $(caminho1)/Stack\ with\ Linked
caminhoQueue = $(caminho1)/Queue\ with\ Array


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

ordenation:
	$(compilador) $(caminho2)/main.c $(caminho2)/ordenation.c -o ordenation.o

clear:
	rm -rf *.o