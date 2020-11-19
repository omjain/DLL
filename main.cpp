//
//  main.cpp
//  FDS 9
//  Created by Om Jain on 03/11/20.
//  DLL
//

#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int roll;
  char div[10];
  int marks;
  struct Node *next;
  struct Node *prev;
};
typedef struct Node NODE;

NODE *create()
{
    NODE *head, *temp = nullptr, *first = 0;
  int a = 0;
  printf("Enter no. of nodes\n");
  scanf("%d", &a);
  for (int i = 0; i < a; i++)
  {
    head = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter Roll\n");
    scanf("%d", &head->roll);
    printf("\nEnter Division\n");
    scanf("%s",head->div);
    printf("\nEnter Marks\n");
    scanf("%d", &head->marks);
    if (first != 0)
    {
      temp->next = head;
      head->prev = temp;
      temp = head;
    }
    else
    {
      head->prev = NULL;
      first = temp = head;
    }
    fflush(stdin);
  }
  temp->next = NULL;
  return first;
}

void traversal(NODE *ptr)
{
  int i = 1;
    printf("Index\tRoll\tDivison\tMarks\n");
  while (ptr != NULL)
  {
   
    printf("%d\t\t%d\t\t%s\t\t%d\n",i,ptr->roll,ptr->div,ptr->marks);
    ptr = ptr->next;
    i++;
  }
}

NODE *insertstart(NODE *head)
{
  NODE *insert;
  insert = (NODE *)malloc(sizeof(NODE));
  printf("\nEnter Roll\n");
  scanf("%d", &insert->roll);
  printf("\nEnter Division\n");
  scanf("%s",insert->div);
  printf("\nEnter Marks\n");
  scanf("%d", &insert->marks);
  insert->next = head;
  insert->prev = NULL;
  return insert;
}
NODE *insertend(NODE *head)
{
  NODE *insert;
  NODE *p = head;
  while (p->next != NULL)
  {
    p = p->next;
  }
  insert = (NODE *)malloc(sizeof(NODE));
  printf("\nEnter Roll\n");
  scanf("%d", &insert->roll);
  printf("\nEnter Divison\n");
  scanf("%s",insert->div);
  printf("\nEnter Marks\n");
  scanf("%d", &insert->marks);
  insert->next = NULL;
  insert->prev = p;
  p->next = insert;
  return head;
}
NODE *insertany(NODE *head, int index)
{
  NODE *insert;
  NODE *p = head;
  int i = 1;
  insert = (NODE *)malloc(sizeof(NODE));
  while (i < index)
  {
    p = p->next;
    i++;
  }
  NODE *q = p->prev;
  printf("\nEnter Roll\n");
  scanf("%d", &insert->roll);
  printf("\nEnter Divison\n");
  scanf("%s",insert->div);
  printf("\nEnter Marks\n");
  scanf("%d",&insert->marks);
  insert->next = p;
  insert->prev = q;
  p->prev = insert;
  q->next = insert;
  return head;
}
NODE *deletestart(NODE *head)
{
  NODE *p = head->next;
  NODE *q = head;
  p->prev = NULL;
  head = p;
  free(q);
  return head;
}
NODE *deletelast(NODE *head)
{
  NODE *p = head;
  while (p->next != NULL)
  {
    p = p->next;
  }
  NODE *q = p->prev;
  q->next = NULL;
  free(p);
  return head;
}
NODE *deleteany(NODE *head, int index)
{
  NODE *p = head;
  int i = 1;
  while (i < index)
  {
    p = p->next;
    i++;
  }
  NODE *pre = p->prev;
  NODE *n = p->next;
  pre->next = n;
  n->prev = pre;
  free(p);
  return head;
}
void reversal(NODE *head)
{
  NODE *p = head;
  int i = 1;
  while (p->next != NULL)
  {
    p = p->next;
  }
  printf("Index\tRoll\tDivision\tMarks\n");
  while (p->prev != NULL)
  {
    if (i == 1)
    {
      printf("%d\t\t%d\t\t%s\t\t%d\n",i,p->roll,p->div,p->marks);
      i++;
    }
    p = p->prev;
   
    printf("%d\t%d\t%s\t%d\n",i,p->roll,p->div,p->marks);
    i++;
  }
}
NODE *modify(NODE *head, int index)
{
  NODE *p = head;
  int i = 1;
  while (i < index)
  {
    p = p->next;
    i++;
  }
  printf("Enter Roll\n");
  scanf("%d", &p->roll);
  printf("\nEnter Division\n");
  scanf("%s",p->div);
  printf("\nEnter Marks\n");
  scanf("%d", &p->marks);
  return head;
}


int main()
{
    NODE *head = nullptr;
    int ch=0, in = 0, end = 1;
  while (end != 0)
  {
    printf("Enter your option\n1.Create A record list\n2.Insert at Head\n3.Insert anywhere\n4.Insert at End\n5.Display Record \n6.Display from end(reversal)\n7.Delete Head\n8.Delete Any Node\n9.Delete End Node\n10.Update any node\n11.Exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:                                  //create main list
            head = (NODE *)malloc(sizeof(NODE));
            head = create();
            break;
        case 2:
            head = insertstart(head);
            break;
        case 3:
            in = 0;
            printf("Enter the index");
            scanf("%d", &in);
            head = insertany(head, in);
            break;
        case 4:
            head = insertend(head);  
            break;
        case 5:
            traversal(head);  //display
            break;
        case 6:
            reversal(head);       //display from end
            break;
        case 7:
            head = deletestart(head);
            break;
        case 8:
            in = 0;
            printf("enter the index");
            scanf("%d", &in);
            head = deleteany(head, in);
            break;
        case 9:
            head = deletelast(head);
            break;
        case 10:
            modify(head, in);
            break;
    case 11:
            end = 0;
            break;
    }
  }
  return 0;
}
