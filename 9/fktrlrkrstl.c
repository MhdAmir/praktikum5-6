#include<stdio.h>

int faktor(int, int);

int main(){
    int n, fakt = 1;
    scanf("%d", &n);
    fakt = faktor(n, fakt);
    printf("faktorial dari %d = %d\n", n, fakt);
    return 0;
}

int faktor(int n, int fakt){
    if(n > 0){
        fakt = fakt * n;
        faktor(n-1, fakt);
    }else{
        return fakt;
    }
}