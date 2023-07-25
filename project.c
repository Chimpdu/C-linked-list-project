# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "linked_list.h"

int main(void)
{
    char line[20];
    Node* head = NULL;
    printf("Is empty?: %d\n", isEmpty(head));
    FILE * fP = fopen("names.txt","r");
    if(fP == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }
    while (fgets(line, 20, fP))
    {
        strcpy(line, strtok(line,"\n"));
        head = addToEnd(head, line);
    }
    
    fclose(fP);
    printf("Is empty?: %d\n", isEmpty(head));
    print(head);
    printf("Size is: %d\n", size(head));
    Node * nodePtr = tail(head);
    printf("Last name: %s\n", nodePtr -> data);
    nodePtr = get_node(head, 10);
    printf("Name in position %d: %s\n", 10, nodePtr->data);
    nodePtr = get_node(head, 31);
    if (nodePtr == NULL)
    {
        printf("Not found!\n");
    }
    printf("Deleting first...\n");
    head = deleteFirst(head);
    printf("Adding \"Spongebob\" to the beginning...\n");
    head = addToBeginning(head, "Spongebob");
    printf("Deleting last...\n");
    head = deleteLast(head);
    print(head);
     printf("The position of %s is: %d\n", "Teppo", find(head, "Teppo"));
    printf("The position of %s is: %d\n", "Maija", find(head, "Maija"));
    printf("Reversing the list...\n");
    head = reverse(head);
    print(head);
    printf("%s\n", toString(head));
    return 0;
}