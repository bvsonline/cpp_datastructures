#include <stdio.h>
#include <stdlib.h>
/*

 A linked list is a data structure for storing collection of data.

 Advantages of arrays:
  Simple and fast to use
  Faster access to the elements

 Disadvantages of arrays:
  Preallocates all needed memory upfornt and waste memory space for indices in
  array that are empty.
  Fixed size: The size of array is static.
  One block allocation: To allocate array itself at the beginning, sometimes it
  may not be possible to get the memory for the complete array.

*/

struct Node
{
  int data;
  struct Node* next;
};

void LinkedListImplementation();
void printLinkedlist(struct Node *list);
int Length_of_LinkedList(struct Node *list);
struct Node* create_LinkedList();
struct Node* InsertNodeAtBeginningOfList(struct Node *head, int element);
struct Node* InsertNodeAtPositionInList(struct Node *head, int element, int position);
struct Node* DeleteNodeAtPositionInList(struct Node *head, int position);
struct Node* DeleteLinkedList(struct Node * head);




void LinkedListImplementation()
{

  struct Node* LinkedList;
  LinkedList = create_LinkedList();
  printLinkedlist(LinkedList);
  int length_of_list = Length_of_LinkedList(LinkedList);
  printf ("Length_of_LinkedList : %d \n",length_of_list);

  LinkedList = InsertNodeAtBeginningOfList(LinkedList, 0);
  printLinkedlist(LinkedList);
  length_of_list = Length_of_LinkedList(LinkedList);
  printf ("Length_of_LinkedList : %d \n",length_of_list);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 10, 1);
  printLinkedlist(LinkedList);
  length_of_list = Length_of_LinkedList(LinkedList);
  printf ("Length_of_LinkedList : %d \n",length_of_list);
    
  LinkedList = InsertNodeAtPositionInList(LinkedList, 20, 5);
  printLinkedlist(LinkedList);
  length_of_list = Length_of_LinkedList(LinkedList);
  printf ("Length_of_LinkedList : %d \n",length_of_list);


  LinkedList = InsertNodeAtPositionInList(LinkedList, 20, 2);
    
    printLinkedlist(LinkedList);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 30, 3);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 40, 4);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 50, 5);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 60, 6);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 70, 7);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 80, 8);
    
  printLinkedlist(LinkedList);

  LinkedList = InsertNodeAtPositionInList(LinkedList, 90, -1);
    
  printLinkedlist(LinkedList);
    
  LinkedList = InsertNodeAtPositionInList(LinkedList, 100, 10);
    
  LinkedList = InsertNodeAtPositionInList(LinkedList, 110, 12);
    
  LinkedList = InsertNodeAtPositionInList(LinkedList, 120, 15);
    
  LinkedList = InsertNodeAtPositionInList(LinkedList, 130, 14);
    
  LinkedList = InsertNodeAtPositionInList(LinkedList, 140, 17);

  printLinkedlist(LinkedList);
    
  LinkedList = DeleteNodeAtPositionInList(LinkedList, 0);
    
  printLinkedlist(LinkedList);
    
  LinkedList = DeleteNodeAtPositionInList(LinkedList, -1);
    
  printLinkedlist(LinkedList);

  LinkedList = DeleteNodeAtPositionInList(LinkedList, 4);
    
  printLinkedlist(LinkedList);

    
  LinkedList = DeleteNodeAtPositionInList(LinkedList, 8);
    
  printLinkedlist(LinkedList);
    
  LinkedList = DeleteLinkedList(LinkedList);
    
  printLinkedlist(LinkedList);

  return;
}

struct Node* create_LinkedList()
{

  struct Node *head, *second, *third;

  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  return head;
}

void printLinkedlist(struct Node *list)
{
  printf("List elements ");
  if (list == NULL)
  {
      printf ("List is Empty \n");
  }
  else
  {
      while (list != NULL)
      {
          printf("%d --> ", list->data);
          list = list->next;
      }
      printf("NULL \n");
  }

  return;
}

int Length_of_LinkedList(struct Node *list)
{
  int count = 0;
  while (list != NULL)
  {
    count++;
    list = list->next;
  }

  return count;
}

struct Node* InsertNodeAtBeginningOfList(struct Node *head, int element)
{
    struct Node* NewHead;

    NewHead = (struct Node *)malloc(sizeof(struct Node));
    NewHead->data = element;
    NewHead->next = head;

    return NewHead;
}

struct Node* InsertNodeAtPositionInList(struct Node *head, int element, int position)
{
    //  position = 0    - first/head
    //  position = -1   - last/tail
    //  position =
    
    struct Node* NewNode = (struct Node*) malloc(sizeof(struct Node));
    
    if (position == 0)
    {
        NewNode->data = element;
        NewNode->next = head;
        head = NewNode;
        
        return head;
    }
    
    struct Node* TempNode_0 = head;
    struct Node* TempNode_1 = NULL;
    
    if (position == -1)
    {
        while (TempNode_0 != NULL)
        {
            TempNode_1 = TempNode_0;
            TempNode_0 = TempNode_0->next;
        }
        TempNode_1->next = NewNode;
        NewNode->data = element;
        NewNode->next = NULL;
        
        return head;
    }
    
    int k = 0;
    while ((TempNode_0 != NULL) && (k < position))
    {
        k++;
        TempNode_1 = TempNode_0;
        TempNode_0 = TempNode_0->next;
    }
    if (k == position)
    {
        TempNode_1->next = NewNode;
        NewNode->data = element;
        NewNode->next = NULL;
    }
    else
    {
        printf("Can't insert new node \n");
    }

    return head;
    
}


struct Node* DeleteNodeAtPositionInList(struct Node *head, int position)
{
    //  position  = 0  head node
    //  position  = -1 last node
    //
    if (position == 0)
    {
        struct Node *TempNode = head, *TempNode2;
        TempNode2 = TempNode->next;
        free(TempNode);
        head = TempNode2;
        
        return head;
    }
    
    struct Node *NextNode = head, *PrevNode = NULL;
    if (position == -1)
    {
        while(NextNode->next != NULL)
        {
            PrevNode = NextNode;
            NextNode = NextNode->next;
        }
        free(NextNode);
        PrevNode->next = NULL;
        
        return head;
    }
    
    int k = 0 ;
    while ((NextNode->next != NULL) && (k < position))
    {
        k++;
        PrevNode = NextNode;
        NextNode = NextNode->next;
    }
    
    if (k == position)
    {
        PrevNode->next = NextNode->next;
        free(NextNode);
    }
    else
    {
        printf("Can't find position in list \n");
    }
    
    return head;
}

struct Node* DeleteLinkedList(struct Node * head)
{
    //  Delete whole linked list
    struct Node *TempNode;
    
    while (head != NULL)
    {
        TempNode = head;
        head = head->next;
        free(TempNode);
    }
    
    return head;
}
