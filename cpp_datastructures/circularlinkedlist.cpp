//
//  circularlinkedlist.cpp
//  cpp_datastructures
//
//  Created by venkata bethamcharla on 4/4/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct CLLList {
    
    struct CLLNode *cllHead;
    int length;
};


struct CLLNode {
  
    int data;
    struct CLLNode * next;
    
};

void circularLinkedListImplementation();
struct CLLList * CreateCircularLinkedList(struct CLLList * cllList, int data);
void printCircularLinkedList(struct CLLList * cllList);
struct CLLList * addNewNode2CircularLinkedList(struct CLLList * cllList, int pos, int data);

FILE *f_cll;

void circularLinkedListImplementation()
{
    struct CLLList cllList, *cllListPtr;
    cllList.cllHead = NULL;
    cllList.length = 0;
    cllListPtr = &cllList;
    
    f_cll = fopen("circularLinkedList.txt","a");
    
    //  Create circular linked list
    cllListPtr = CreateCircularLinkedList(cllListPtr, 10);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 20);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 30);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 40);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 50);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 60);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 70);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 80);
    
    //  add a node to circular linked list by position
    //  position = 0 head
    //  position = -1 end of list
    //  position > length of list, Do not add to list
    addNewNode2CircularLinkedList(cllListPtr, 0, 100);
    addNewNode2CircularLinkedList(cllListPtr, -1, 90);
    addNewNode2CircularLinkedList(cllListPtr, 1, 200);
    addNewNode2CircularLinkedList(cllListPtr, 2, 210);
    addNewNode2CircularLinkedList(cllListPtr, 3, 220);
    addNewNode2CircularLinkedList(cllListPtr, 4, 230);
    
    printCircularLinkedList(cllListPtr);
    
    fclose(f_cll);
    
    return;
}

struct CLLList * CreateCircularLinkedList(struct CLLList * cllList, int data)
{
    if(cllList->cllHead == NULL)
    {
        struct CLLNode *cllHead = (struct CLLNode *) malloc(sizeof(struct CLLNode));
        cllHead->data = data;
        cllHead->next = cllHead;
        cllList->cllHead = cllHead;
        cllList->length = 1;
        
        return cllList;
    }
    else
    {
        struct CLLNode * cllNewNode, *cllTempNode, *cllTempNode2;
        
        cllNewNode = (struct CLLNode *) malloc(sizeof(struct CLLNode));
        cllNewNode->data = data;
        cllNewNode->next = cllList->cllHead;
        
        cllTempNode = cllList->cllHead;
        
        do {
            cllTempNode2 = cllTempNode;
            cllTempNode = cllTempNode->next;
        }while (cllTempNode != cllList->cllHead);
        
        cllTempNode2->next = cllNewNode;
        cllList->length++;
        return cllList;
    }
    
}

void printCircularLinkedList(struct CLLList * cllList)
{
    struct CLLNode * TempNode = cllList->cllHead;
    
    for (int count = 0; count < cllList->length; count++)
    {
        fprintf(f_cll, "|||Node:0x%x(data:%d)(next:0x%x)|||===>",TempNode, TempNode->data, TempNode->next);
        TempNode = TempNode->next;
    }
    fprintf(f_cll, "\n\n\n\n");
}

struct CLLList * addNewNode2CircularLinkedList(struct CLLList * cllList, int pos, int data)
{
    struct CLLNode * cllHead = cllList->cllHead, *tempNode;

    struct CLLNode * NewNode = (struct CLLNode *) malloc (sizeof(struct CLLNode));
    NewNode->data = data;
    if (pos == 0)
    {
        if (cllHead == NULL)
        {
            NewNode->next = NewNode;
        }
        else
        {
            tempNode = cllHead;
            NewNode->next = tempNode;
            while (tempNode->next != cllHead)
            {
                tempNode = tempNode->next;
            }
            tempNode->next = NewNode;
        }
        cllList->cllHead = NewNode;
        cllList->length++;
        
        return cllList;
    }
    else if (pos == -1)
    {
        tempNode = cllHead;
        while (tempNode->next != cllHead)
        {
            tempNode = tempNode->next;
        }
        NewNode->next = cllHead;
        tempNode->next = NewNode;
        cllList->length++;
        
        return cllList;
    }
    else
    {
        tempNode = cllHead;
        int k = 0;
        while ((tempNode->next != cllHead) && (k < pos))
        {
            k++;
            tempNode = tempNode->next;
            if (k == pos)
            {
                NewNode->next = tempNode->next;
                tempNode->next = NewNode;
                cllList->length++;
                break;
            }
        }
        
        return cllList;
    }
  
    return cllList;
}
