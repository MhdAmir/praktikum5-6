#include<stdio.h>

void ntozero(int );

int main(){
    int n;
    scanf("%d", &n);
    ntozero(n);
}

void ntozero(int n){
    if(n >= 0){
        printf("%d ", n);
        ntozero(n-1);
    }else{
        printf("\n");
    }
}