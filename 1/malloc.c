#include<stdio.h>
#include<stdlib.h>
int main(){
    int a = 2, *ptr, index;
    char choice = 'y';
    ptr = (int*) malloc(sizeof(a));
    if(ptr == NULL){
        printf("GABISA CUY\n");
    } else{
        printf("SUKSES CUY\n");
        printf("lokasi : %p\n",ptr);
        while(choice == 'y'){
            printf("ENTRY : ");
            scanf("%d", &ptr[index]);
            printf("mau masukin lagi?(y/n)");
            scanf("%c", &choice);
            if(choice == 'y'){
                index++;
                realloc(ptr, (*));
            }
        }
    }
    return 0;
}