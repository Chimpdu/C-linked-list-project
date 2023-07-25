# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//forget to deal with empty list
typedef struct node {
    char data[10];
    struct node *pNext;
} Node;

int isEmpty(Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}
Node *addToEnd(Node *head, char str[])
{
    Node *pNew = (Node *) malloc(sizeof(Node));
    if (head != NULL)
    {
        Node *tempo;
        for(Node *i = head; i != NULL; i = i->pNext)
        {
            if (i != NULL)
            {
                tempo = i;
            }
        }
        pNew -> pNext = NULL;
        tempo ->pNext = pNew;
        strcpy(pNew -> data, str); 
    }
    else
    {
        pNew ->pNext = head;
        strcpy(pNew ->data, str);
        head = pNew;
    }
    return head;
}
Node *addToBeginning(Node *head, char str[])
{
    Node *pNew = (Node *) malloc(sizeof(Node));
    pNew -> pNext = head;
    strcpy(pNew -> data, str);
    head = pNew;
    return head;
}
int size(Node *head)
{
    int size = 0;
    for (Node *i = head; i != NULL; i = i-> pNext)
    {
       size ++;
    }
    return size;
}
Node *tail(Node *head)
{
    Node *tail;
    for(Node *i = head; i != NULL; i = i->pNext)
        {
            if (i != NULL)
            {
                tail = i;
            }
        }
    return tail;

}
Node *get_node(Node *head, int pos)
{
    if (pos > size(head))
    {
        return NULL;
    }
    else
    {
        int position = 1;
        for (Node *i = head; i != NULL; i = i-> pNext)
        {
            if (position == pos)
            {
                return i;
            }
            position ++;
        }  
    }
    
    
}
Node *deleteFirst(Node *head)
{
    if(isEmpty(head) == 1)
    {
        return head;
    }
    Node* tempo = head;
    head = head ->pNext;
    free(tempo);
    return head;
}
Node *deleteLast(Node *head)
{
    Node * tempo1;
    Node * tempo2;
    if (size(head)>=2)
    {
        for (Node *i = head; i != NULL; i = i-> pNext)
    {
        if(((i->pNext)->pNext) == NULL)
        {
            tempo1 = i;
            tempo2 = tempo1 -> pNext;
            tempo1 -> pNext = NULL;
            free(tempo2); 
        }
    }
    return head;
    }
    else if (isEmpty(head) == 0)
    {
        tempo2 = head;
        head = NULL;
        free(tempo2);
        return head;
    }
    else 
    {
        return head;
    }

    
}
int find(Node *head, char *str)
{
    int notfound = 1;
    int count = 1;
    for (Node *i = head; i != NULL; i = i-> pNext)
    {
       if (strcmp(str, i -> data) == 0)
       {
            notfound = 0;
            return count;
       }
       count ++;
    }
    if (notfound)
    {
        return 0;
    }
    
}
void print(Node *head)
{
    printf("Printing...\n");
    int position = 1;
    for (Node *i = head; i != NULL; i = i-> pNext)
    {
        printf("Node position %d: %s\n", position, i -> data);
        position ++;
    }
    
}
char *toString(Node *head)
{
    static char str[20] = "";
    strcpy(str, "");
    for (Node*i = head; i != NULL; i = i -> pNext)
    {
        if (i != NULL)
        {
            strcat(str, "(");
            strcat(str, i -> data);
            strcat(str, ") -> ");
        }
        
    }
    strcat(str, "NULL");
    return str;
}
Node *reverse(Node *head) {
    Node *newHead = NULL;
    Node *current = head;
    Node *tempo1 = NULL;
    
    while (current != NULL) {
        tempo1 = current->pNext;
        current->pNext = newHead;
        newHead = current;
        current = tempo1;
    }
    
    
    return newHead;
}

    
