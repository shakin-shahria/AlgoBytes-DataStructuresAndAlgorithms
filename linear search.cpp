#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int mian(){

    int data[100], n, i, key;
    printf("enter array size: ");
    scanf("%d",&n);
    srand(time(NULL));
    for (i=0; i<n; i++){

          data[100]= rand()%100+1;

    }

    printf("Values: ");
    for (i=0; i<n; i++){


        printf("%d", data[i]);


    }




    return 0;

}
