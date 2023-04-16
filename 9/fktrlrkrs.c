#include<stdio.h>

int faktor(int);

int main(){
    int n, fakt;
    scanf("%d", &n);
    fakt = faktor(n);
    printf("faktorial dari %d = %d\n", n, fakt);
    return 0;
}

int faktor(int n){
    int fakt = 1;
    if(n > 0){
        fakt = n * faktor(n-1);
    }else{
        return fakt;
    }
}