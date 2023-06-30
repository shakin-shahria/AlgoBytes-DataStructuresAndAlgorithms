
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int data[100], n, i,j,a,temp, key;
    printf("enter array size: ");
    scanf("%d",&n);
    srand(time(NULL));
    for (i=0; i<n; i++){

          data[i]= rand()%100+1;

    }

    printf("Values: \n");
    for (i=0; i<n; i++){


        printf("%d\n", data[i]);


    }


    printf("Bubble sort: ");


       for(i=0; i<n-1; i++){

           for(j=0; j<n-1; j++){


                 if(data[j+1]<data[j]){


                    temp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;

                 }


           }


       }

         for(i=0; i<n; i++){


               printf("%d\n",data[i]);




         }



         printf("Enter the key: \n");
                scanf("%d, &key");


                int l,r,mid;

              l=0, r=n-1;
              mid= (l+r)/2;
              while(l<r){


                  if (key== data[mid]){


                    printf("%d", mid);

                  }



                 if (key < data[mid]){

                    r=mid-1;


                  }

                else{


                   l=mid+1;


                }

              }

          }




