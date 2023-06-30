
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head;

void init()
{
    head=NULL;

}

void insertitem(int element)
{

    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));
    New->value=element;
    New->next=NULL;
    New->next=head;
    head=New;
    struct node *tail;
    tail=(struct node*)malloc(sizeof(struct node));
    tail->next= NULL;

}
void print()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur=head;
    int count;
    count=0;
    while(cur!=NULL)
    {
        printf("%d->",cur->value);
        count++;
        cur=cur->next;
    }
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}

void insertlast(int ele)
{
     struct node *New, *tail;
     tail=(struct node*)malloc(sizeof(struct node));
     tail->value= NULL;
     tail->next= NULL;
     tail=(struct node*)malloc(sizeof(struct node));
     tail->value= NULL;
     tail->next= NULL;
     tail= head;
     if(tail->next != NULL)
     {
      tail=  tail->next;
     }
     New = (struct node*)malloc(sizeof(struct node));

        New->value = ele;
        New->next = NULL;
        tail->next= New;
        tail = New;
        printf("DATA INSERTED SUCCESSFULLY\n");

}

void deleteitem(int ele)
{
     struct node *tail;       //tail node that points the last node of the list
     tail=(struct node*)malloc(sizeof(struct node));
     tail->value= NULL;
     tail->next= NULL;
     tail= head;
     if(tail->next != NULL)
     {
      tail=  tail->next;
     }
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->value!=ele)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
    prev->next=cur->next;
    free(cur);
}

node* getitem(int ele)
{
    struct node* i;

    for( i= head ; i!=NULL; i= i-> next)
    {

        if(i -> value == ele)
        {
            return i;
        }
    }
    return NULL;

}

node* prev_search ()
{
    if(head==NULL)
    {
        printf("list is empty and nothing to delete\n");
    }

    struct node* cur=head;
    struct node* prev=NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    while(cur!= NULL)
    {
        cur=cur->next;
        prev=cur;

    }
    return prev;

}

void deletelast()
{

    struct node*location = prev_search();
    struct node*sour= location->next;
    delete (sour);
    printf("last item is deleted\n");



}

int main()
{

    init();

    int ch,element;
    while(1)
    {
        printf("\n 1. Insert  item. 2. Insert Last. 3. print. 4.delete item. 5.get item. 6.delete last\n---------\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertitem(element);
        }


        else if(ch==2)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d",&le);
            insertlast(le);
        }

        else if(ch==3)
        {
            print();
        }
        else if(ch==4)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d",&de);
            deleteitem(de);
        }

        else if (ch==5)

        {
            int se,reply;
            printf("enter element to search ");
            scanf("%d",&se);
            getitem(se);

        }

        else if(ch==6)
        {
            deletelast();
        }
    }


}
