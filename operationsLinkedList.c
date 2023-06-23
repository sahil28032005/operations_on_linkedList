#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *nextVal;
};
void traverseList();
struct list *insertAtBeginning();
struct list *insertAtIndex();
void insertAtEnd();
void linerSearch();
void insertAfterReference();
void main()
{

    struct list *head = (struct list *)malloc(sizeof(struct list));
    struct list *nextNode = (struct list *)malloc(sizeof(struct list));
    struct list *lastNode = (struct list *)malloc(sizeof(struct list));

    head->data = 45;
    head->nextVal = nextNode;

    nextNode->data = 18;
    nextNode->nextVal = lastNode;

    lastNode->data = 7;
    lastNode->nextVal = NULL;

    // struct list *ptr = head;

    // printf("%d",head);

    traverseList(head);
    head = insertAtBeginning(head, 57);

    // printf("\n%d",ptr);
    // printing after adding at beginning node in linked list
    traverseList(head);
    head = insertAtIndex(head, 678, 3);
    traverseList(head);
    insertAtEnd(head, 455);
    traverseList(head);
    linerSearch(head, 572);
    insertAfterReference(nextNode, 563, head);
    traverseList(head);
}

void traverseList(struct list *head)
{
    struct list *keyPtr = head;
    while (keyPtr != NULL)
    {
        printf("%d", keyPtr->data);
        keyPtr = keyPtr->nextVal;
    }
    printf("\t");
}

struct list *insertAtBeginning(struct list *head, int data)
{
    struct list *newBeginningNode = (struct list *)malloc(sizeof(struct list));
    newBeginningNode->data = data;
    newBeginningNode->nextVal = head;
    return newBeginningNode;
}

struct list *insertAtIndex(struct list *headptr, int data, int index)
{
    struct list *head = headptr;
    struct list *anotherNode = (struct list *)malloc(sizeof(struct list));
    anotherNode->data = data;
    int i = 0;
    while (i != index - 1)
    {
        head = head->nextVal;
        i++;
    } 
    anotherNode->nextVal = head->nextVal;
    head->nextVal = anotherNode;

    return headptr;
}
void insertAtEnd(struct list *head, int data)
{
    struct list *newNode = (struct list *)malloc(sizeof(struct list *));
    struct list *ptr = head;
    while (ptr->nextVal != NULL)
    {
        ptr = ptr->nextVal;
    }
    newNode->data = data;
    ptr->nextVal = newNode;
    newNode->nextVal = NULL;
}
void linerSearch(struct list *head, int searchElement)
{
    struct list *movingKey = head;
    int flag = 0;
    while (movingKey->nextVal != NULL)
    {
        if (movingKey->data == searchElement)
        {
            flag = 1;
            break;
        }
        else
        {
            movingKey = movingKey->nextVal;
        }
    }
    if (flag)
    {
        printf("\nyour entered element is found....");
    }
    else
    {
        printf("\nSorry! enable to search element..");
    }
}
void insertAfterReference(struct list *prevNode, int data, struct list *head)
{
    struct list *node = (struct list *)malloc(sizeof(struct list));
    struct list *iterator = head;
    node->data = data;
    node->nextVal = prevNode->nextVal;
    prevNode->nextVal = node;
}
