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

void insertfirst(int element)
{
    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));
    New->value=element;
    New->next=NULL;
    New->next=head;
    head=New;
}

//Task-----------------------------1

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
//Task----------------------------2
 void delet(){
 struct node *current= head;
 struct node *next= NULL;
 current = head;

while( current != 0 ) {


    next = current->next;
    delete current;
    current = next;
}

head= NULL;

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


int main()
{
    init();
    while(1)
        {
            int se,reply,ch,element;
            printf("\n 1.insert-value. 2.get. 3.delete. 4.print.\n---------\n");
            scanf("%d",&ch);

          if(ch==1)
          {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
          }

        if(ch==2)
          {
            printf("enter element to get: ");
            scanf("%d",&se);
            getitem(se);
          }

        else if(ch==3)

          {
            delet();

          }

        else if(ch==4)

        {
            print();
        }

}

}
