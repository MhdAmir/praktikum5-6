#include<stdio.h>

int main(){
    int n, faktor = 1;
    scanf("%d", &n);
    printf("\n");
    for(int i = n; i >= 1 ; i--){
        printf("proses := %d * %d = ", faktor, i);
        faktor = faktor * i;
        printf("%d\n", faktor);
    }
    printf("\nfaktorial dari %d = %d\n", n, faktor);
}