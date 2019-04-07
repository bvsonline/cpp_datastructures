//
//  doublelinkedlist.cpp
//  cpp_datastructures
//
//  Created by venkata bethamcharla on 3/30/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

// Base structure for Double Linked List


struct DLLDescriptor {
    
    int length = 0;
    struct DLLNode *dllHead;
};

struct DLLNode
{
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
};


void DoubleLinkedListImplementation();
void printdll(struct DLLDescriptor *dll);
struct DLLDescriptor * CreateDLL(struct DLLDescriptor *dll, int data);
struct DLLDescriptor * addNewNodetoDLL(struct DLLDescriptor *dll, int data);
struct DLLDescriptor * addNewNodetoDLLatPos(struct DLLDescriptor *dll, int data, int pos);
struct DLLDescriptor * DeleteFirstNode(struct DLLDescriptor * dll);
struct DLLDescriptor * DeleteLastNode(struct DLLDescriptor * dll);
struct DLLDescriptor * DeleteNodeByKey(struct DLLDescriptor * dll, int data);
struct DLLDescriptor * DeleteNodeByPos(struct DLLDescriptor * dll, int pos);


FILE *f_dll;

void DoubleLinkedListImplementation()
{
    //  Create Head node for DLL
    
    struct DLLDescriptor *dll = (struct DLLDescriptor *)malloc(sizeof(struct DLLDescriptor));
    dll->length = 0;
    dll->dllHead = NULL;
    
    f_dll = fopen("DLL_list.txt", "a");
    
    // Create DLL with base element
    fprintf(f_dll, "add new Node at -1 \n");
    addNewNodetoDLLatPos(dll, 20, -1);
    printdll(dll);
    
    fprintf(f_dll, "add new Node at -1 \n");
    addNewNodetoDLLatPos(dll, 40, -1);
    printdll(dll);
    
    fprintf(f_dll, "add new Node at 1 \n");
    addNewNodetoDLLatPos(dll, 60, 1);
    printdll(dll);
    
    fprintf(f_dll, "add new Node at 0 \n");
    addNewNodetoDLLatPos(dll, 80, 0);
    printdll(dll);
    
    fprintf(f_dll, "add new Node at 0 \n");
    addNewNodetoDLLatPos(dll, 100, 0);
    printdll(dll);
    
    //dll = CreateDLL(dll, 1);
    fprintf(f_dll, "add new Node  \n");
    dll = addNewNodetoDLL(dll, 120);
    printdll(dll);
    
    fprintf(f_dll, "add new Node  \n");
    dll = addNewNodetoDLL(dll, 140);
    printdll(dll);
    
    fprintf(f_dll, "add new Node  \n");
    dll = addNewNodetoDLL(dll, 160);
    printdll(dll);
    
    fprintf(f_dll, "add new Node  \n");
    dll = addNewNodetoDLL(dll, 180);
    printdll(dll);
    
    fprintf(f_dll, "add new Node  \n");
    dll = addNewNodetoDLL(dll, 200);
    printdll(dll);
    
    fprintf(f_dll, "add new Node at 0 \n");
    addNewNodetoDLLatPos(dll, 220, 0);
    printdll(dll);
    
    fprintf(f_dll, "Delete First Node \n");
    DeleteFirstNode(dll);
    printdll(dll);
    
    fprintf(f_dll, "Delete Last Node \n");
    DeleteLastNode(dll);
    printdll(dll);
    
    fprintf(f_dll, "Delete key 120 \n");
    DeleteNodeByKey(dll, 120);
    printdll(dll);
    
    fprintf(f_dll, "Delete pos 1 \n");
    DeleteNodeByPos(dll, 1);
    printdll(dll);
    
    fclose(f_dll);
    return;
}

struct DLLDescriptor * CreateDLL(struct DLLDescriptor *dll, int data)
{
    if (dll->dllHead == NULL)
    {
        struct DLLNode * dllHead = (struct DLLNode *) malloc (sizeof(struct DLLNode));
        dllHead->prev = NULL;
        dllHead->next = NULL;
        dllHead->data = data;
        dll->dllHead = dllHead;
        dll->length = 1;
    }
    
    return dll;
}

struct DLLDescriptor * addNewNodetoDLL(struct DLLDescriptor *dll, int data)
{
    if (dll->dllHead == NULL)
    {
        struct DLLNode* dllHead = (struct DLLNode *) malloc (sizeof(struct DLLNode));
        dllHead->prev = NULL;
        dllHead->next = NULL;
        dllHead->data = data;
        dll->dllHead = dllHead;
        dll->length = 1;
    }
    else
    {
        struct DLLNode * NewNode = (struct DLLNode *) malloc (sizeof(struct DLLNode));
        struct DLLNode * auxillaryNextNode = dll->dllHead, *auxillaryPrevNode;
        while (auxillaryNextNode->next != NULL)
        {
            auxillaryPrevNode = auxillaryNextNode->prev;
            auxillaryNextNode = auxillaryNextNode->next;
        }
        
        auxillaryNextNode->next = NewNode;
        NewNode->prev = auxillaryNextNode;
        NewNode->next = NULL;
        NewNode->data = data;
        dll->length++;

    }
    
    return dll;
}

void printdll(struct DLLDescriptor *dll)
{
    struct DLLNode * Temp = dll->dllHead;
    int length = dll->length;
    
    fprintf(f_dll, "*****************\n");
    fprintf(f_dll, "printing DLL length: %d \n", length);
    while(length)
    {
        fprintf(f_dll, "|||%p|||%p:%d|||%p|||--->",Temp->prev,Temp,Temp->data,Temp->next);
        Temp = Temp->next;
        length--;
    }
    fprintf(f_dll, "\n*****************\n");
    fprintf(f_dll, "\n");
    
    
    return;
}

struct DLLDescriptor * addNewNodetoDLLatPos(struct DLLDescriptor *dll, int data, int pos)
{
    //  pos = 0 update dllHead
    //  pos = -1 add dll at the end
    //  pos =
    
    struct DLLNode * headNode = dll->dllHead;
    struct DLLNode * iterator = dll->dllHead;
    struct DLLNode * auxilary = dll->dllHead;
    struct DLLNode * newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    
    if (pos == 0)
    {
        newNode->data = data;
        newNode->prev = NULL;
        if (headNode == NULL)
        {
            newNode->next = NULL;
        }
        else
        {
            newNode->next = headNode;
            headNode->prev = newNode;
        }
        dll->dllHead = newNode;
        dll->length++;
        
        return dll;
    }
    
    if (pos == -1)
    {
        if (headNode != NULL)
        {
            while (iterator->next != NULL)
            {
                auxilary = iterator;
                iterator = iterator->next;
            }
            auxilary->next = newNode;
        }
        else
            dll->dllHead = newNode;
        
        newNode->prev = auxilary;
        newNode->data = data;
        newNode->next = NULL;
        
        dll->length++;
        
        return dll;
    }
    int k = 0;
    while ((iterator->next != NULL) && (k < pos))
    {
        k++;
        auxilary = iterator;
        iterator = iterator->next;
    }
    auxilary->next = newNode;
    newNode->prev = auxilary;
    newNode->next = iterator;
    iterator->prev = newNode;
    newNode->data = data;
    dll->length++;
    
    return dll;
}

struct DLLDescriptor * DeleteFirstNode(struct DLLDescriptor * dll)
{
    struct DLLNode * dllHead = dll->dllHead;
    if (dllHead == NULL)
    {
        printf("NO DLL \n");
    }
    else
    {
        dll->dllHead = dllHead->next;
        dll->dllHead->prev = NULL;
        free(dllHead);
        dllHead = NULL;
        dll->length--;
    }
    return dll;
}

struct DLLDescriptor * DeleteLastNode(struct DLLDescriptor * dll)
{
    struct DLLNode * dllHead = dll->dllHead;
    
    while(dllHead->next != NULL)
    {
        dllHead = dllHead->next;
    }
    dllHead->prev->next = NULL;
    free(dllHead);
    dllHead = NULL;
    dll->length--;
    
    return dll;
}

struct DLLDescriptor * DeleteNodeByKey(struct DLLDescriptor * dll, int data)
{
    struct DLLNode * dllHead = dll->dllHead;
    while(dllHead->next != NULL)
    {
        dllHead = dllHead->next;
        if (dllHead->data == data)
            break;
    }
    
    dllHead->prev->next = dllHead->next;
    dllHead->next->prev = dllHead->prev;
    free(dllHead);
    dllHead = NULL;
    dll->length--;
    
    return dll;
}

struct DLLDescriptor * DeleteNodeByPos(struct DLLDescriptor * dll, int pos)
{
    
    struct DLLNode * dllHead = dll->dllHead;
    int k = 0;
    while ((dllHead->next != NULL))
    {
        dllHead = dllHead->next;
        if (k == pos)
            break;
        k++;
    }
    
    dllHead->prev->next = dllHead->next;
    dllHead->next->prev = dllHead->prev;
    free(dllHead);
    dllHead = NULL;
    dll->length--;
    
    return dll;
}

