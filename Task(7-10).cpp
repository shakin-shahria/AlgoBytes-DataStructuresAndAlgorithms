
#include <stdio.h>
#include <stdlib.h>

struct node         //structure of doubly Node
{
  int data;
  struct node *prev;
  struct node *next;
} *head, *last;

void list (int n)       //print list of nodes
{
  int i, data;
  struct node *new_node;
  if (n >= 1)
    {
      head = (struct node *) malloc (sizeof (struct node));
      printf ("Enter data of node 1 : ");
      scanf ("%d", &data);
      head->data = data;
      head->prev = NULL;
      head->next = NULL;
      last = head;
      for (i = 2; i <= n; i++)
      {
          new_node = (struct node *) malloc (sizeof (struct node));
          printf ("\nEnter data of node %d : ", i);
          scanf ("%d", &data);
          new_node->data = data;
	  new_node->prev = last;
	  new_node->next = NULL;
	  last->next = new_node;
	  last = new_node;
    }}
}

void print_List ()
{
  struct node *temp;
  int n = 1;
  if (head == NULL)
    {
      printf ("\nList is empty\n");
    }
  else
    {
      temp = head;
      printf ("The Doubly Linked List is :\n");
      while (temp != NULL)      // Print the list
	{
	  printf ("%d   ", temp->data);
	  n++;
	  temp = temp->next;        // Move the cur ptr to next node
	}
    }
}
// Function to insert node at the beginning of the doubly linked list

void insert_Beginning (int data)
{
  struct node *new_node;
  if (head == NULL)
    {
      printf ("Please enter data for node \n");
    }
  else
    {
      new_node = (struct node *) malloc (sizeof (struct node));
      new_node->data = data;
      new_node->next = head;
      new_node->prev = NULL;
      head->prev = new_node;	// Link prev add field of head with new_node
      head = new_node;		// Make the new node as head node
    }
}


void reverseList()
{
    struct node *current, *temp;

    current = head;
    while(current != NULL)
    {



        temp = current->next;
        current->next = current->prev;
        current->prev = temp;


        current = temp;
    }

    temp = head;
    head = last;
    last = temp;

    printf("LIST REVERSED SUCCESSFULLY.\n");
}


void last_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        ptr = head;
        if(ptr->next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}


int main ()
{
  int n, data, ch;
  head = last = NULL;
  printf ("Enter the size of linked list : \n");	// Input the size of nodes
  scanf ("%d", &n);
  list (n);
  print_List ();
  while(1)
    {
        printf("\n 1.Insert_beggning. 2.reverse_list. 3.delete_last.\n---------\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
             printf ("\nEnter data for insert at the beginning :\n ");
             scanf ("%d", &data);
             insert_Beginning (data);
             print_List ();
        }

      else  if(ch == 2)
      {

        reverseList();
        print_List ();

      }

      else  if(ch == 3)
      {

        last_delete();
        print_List ();

      }


  return 0;

}

}
