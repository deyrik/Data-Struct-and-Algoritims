compilador = gcc
caminho = Data\ Structs


caminhoList = $(caminho)/List
caminhoLinkedList = $(caminho)/Linked\ List


list: 
	$(compilador) $(caminhoList)/list.c -o list.o

linkedList: 
	$(compilador) $(caminhoLinkedList)/linkedList.c -o linkedList.o

clear:
	rm -rf *.o