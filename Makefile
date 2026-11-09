compilador = gcc

caminhoDataStructs = Data\ Structs
caminhoOrdenation  = Ordenation
caminhoTrees       = Trees
caminhoTest        = Test

caminhoList        = $(caminhoDataStructs)/List
caminhoLinkedList  = $(caminhoDataStructs)/Linked\ List
caminhoStack       = $(caminhoDataStructs)/Simple\ Stack
caminhoLinkedStack = $(caminhoDataStructs)/Stack\ with\ Linked
caminhoQueue       = $(caminhoDataStructs)/Queue\ with\ Array

caminhoBST         = $(caminhoTrees)/Binary\ Search\ Tree

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
	$(compilador) $(caminhoTest)/testOrdenation.c $(caminhoOrdenation)/ordenation.c -o ordem.o

dataStructs:
	$(compilador) $(caminhoTest)/testDataStructs.c -o dataStructs.o

BST:
	$(compilador) $(caminhoTest)/testTree.c $(caminhoBST)/BST.c -o BST.o

clear:
	rm -rf *.o
