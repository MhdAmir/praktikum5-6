#include<stdio.h>

int main(){
    int a[10]= {1,2,3,4,5};
    int i = 0;
    while(a[i] != 0){
        i++;
    }
    printf("%d",i);
    return 0;
}