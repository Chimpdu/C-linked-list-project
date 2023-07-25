project: linked_list.o project.o
	gcc linked_list.o project.o -o project
linked_list.o: linked_list.c
	gcc -c linked_list.c
project.o: project.c
	gcc -c project.c