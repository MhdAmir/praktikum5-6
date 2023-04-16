#include<stdio.h>

void ntozero(int , int );

int main(){
    int n;
    scanf("%d", &n);
    ntozero(n, 0);
}

void ntozero(int n, int i){
    if(i <= n){
        printf("%d ", i);
        ntozero(n, i+1);
    }else{
        printf("\n");
    }
}