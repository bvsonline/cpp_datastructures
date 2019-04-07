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

FILE *f_cll;

void circularLinkedListImplementation()
{
    struct CLLList cllList, *cllListPtr;
    cllList.cllHead = NULL;
    cllList.length = 0;
    cllListPtr = &cllList;
    
    f_cll = fopen("circularLinkedList.txt","a");
    
    cllListPtr = CreateCircularLinkedList(cllListPtr, 10);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 20);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 30);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 40);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 50);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 60);
    cllListPtr = CreateCircularLinkedList(cllListPtr, 70);
    
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


