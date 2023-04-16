#include<stdio.h>
#include<string.h>

void balik(char a[], int n);

int main(){
    int n;
    char kalimat[1000];
    scanf(" %[^\n]%*c", kalimat);
    n = strlen(kalimat)-1;
    balik(kalimat, n);
    return 0;
}

void balik(char a[], int n){
    if(n >= 0){
        printf("%c", a[n]);
        balik(a, n-1);
    }else{
        printf("\n");
    }
}


