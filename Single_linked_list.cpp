#include<stdio.h>
#include<stdlib.h>
struct Node{

   int data;
   struct Node *link;

}
*b_Node;
void creat_linked_list(int n);
void display_list();

int main(){
int n;
printf("Enter the number of nodes: ");
scanf("%d",&n);
creat_linked_list( n);
printf("data in the list: \n");
display_list();
return 0;
}

void creat_linked_list(int n){


        int num,i;
        struct Node *x_Node, *tmp;


           b_Node= (struct Node *) malloc(sizeof (struct Node));

           if(b_Node == NULL){
               printf ("Memory not located");
            }

           else{
                printf("Enter the value for node 1: ");
                scanf("%d", &num);
                b_Node -> data= num;
                b_Node -> link= NULL;
                tmp= b_Node;

                for(i=2; i<= n; i++){

                    x_Node =(struct Node *)malloc (sizeof (struct Node));
                    if (x_Node == NULL){
                        printf(" Memory is not located");
                        break;
                    }
                    else {

                        printf("Enter value for node %d: ", i);
                        scanf("%d",&num);
                        x_Node-> data= num;
                        x_Node -> link= NULL;
                        tmp -> link = x_Node;
                        tmp = tmp -> link;
                    }
                  }
           }
}

void display_list(){

       struct Node *tmp;
       if(b_Node == NULL){

           printf("List in empty. ");

       }

       else{

           tmp = b_Node;

           while( tmp != NULL ){


                  printf("data= %d\n", tmp-> data);

                  tmp = tmp-> link;


           }

       }

}






