#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void iterasi();
int rekursi(int);
int rekursitail(int, int);

time_t t1, t2;

int main(){
    menu();
    return 0;
}

void menu(){
    int pil;
    printf("MENU PILIHAN FAKTORIAL : \n");
    printf("1. Iterasi \n");
    printf("2. Rekursi \n");
    printf("3. Rekursi Tail \n");
    printf("4. Keluar \n\n");
    printf("Masukkan Pilihan : \n");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1 :
        time(&t1);
        iterasi();
        time(&t2);

        printf("waktu komputasi : %ld", t2-t1);

        break;
    case 2 :
        time(&t1);
        int n, fakt;
        scanf("%d", &n);
        fakt = rekursi(n);
        printf("faktorial dari %d = %d\n", n, fakt);
        time(&t2);

        printf("waktu komputasi : %ld", t2-t1);

        break;
    case 3 :
        time(&t1);
        fakt = 1;
        scanf("%d", &n);
        fakt = rekursitail(n, fakt);
        printf("faktorial dari %d = %d\n", n, fakt);
        time(&t2);

        printf("waktu komputasi : %ld", t2-t1);
        break;

    case 4 :
        printf("THANKS, BYE !!!");
        exit(0);
        break;

    default:
        break;
    }
}

void iterasi(){
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

int rekursi(int n){
    int fakt = 1;
    if(n > 0){
        fakt = n * rekursi(n-1);
    }else{
        return fakt;
    }

}

int rekursitail(int n, int fakt){
    if(n > 0){
        fakt = fakt * n;
        rekursitail(n-1, fakt);
    }else{
        return fakt;
    }
}