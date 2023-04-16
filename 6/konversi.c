#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef char ItemType;
typedef struct
{
    char item[MAX]; 
    int count;           
} Stack;

void menu(Stack *);
void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop(Stack *);
void binr(int, Stack *);
void tampil(Stack *);
void oktal(int, Stack *);
void heksades(int, Stack *);


int main(){
    Stack tumpuk;
    menu(&tumpuk);
    return 0;
}

void menu(Stack *S){
    int nilai, pilih;
    printf("KONVERSI BILANGAN DESIMAL\n");
    printf("Masukkan bil desimal yg akan dikonversi : ");
    scanf("%d", &nilai);
    
    do{
        InitializeStack(S);
        printf("\nMENU KONVERSI :\n");
        printf("1. BINER\n2.OKTAL\n3.HEKSADESIMAL\n4.Keluar\n\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            binr(nilai, S);
            break;
        
        case 2:
            oktal(nilai, S);
            break;

        case 3:
            heksades(nilai, S);
            break;

        case 4:
            printf("Terima Kasih!\n");
            exit(0);
            break;

        default:
            printf("SALAH INPUT\nMenu tidak ada\n");
            break;
        }
    }while(pilih != 4);
}

void binr(int x, Stack *S){
    while(x>0){
        Push(x%2, S);
        x = x/2;
    }
    tampil(S);
}
void oktal(int x, Stack *S){
    while(x>0){
        Push(x%8, S);
        x = x/8;
    }
    tampil(S);
}
void heksades(int x, Stack *S){
    
    while(x>0){
        Push(x%16, S);
        x = x/16;
    }
    tampil(S);
}


void InitializeStack(Stack *S)
{
    S->count = 0;
}

int Empty(Stack *S)
{
    return (S->count == 0);
}

int Full(Stack *S)
{
    return (S->count == MAX);
}

void Push(ItemType x, Stack *S)
{
    if (Full(S)) 
        printf("Stack penuh! Data tidak dapat masuk!");
    else
    {
        S->item[S->count] = x;
        ++(S->count);
    }
}

ItemType Pop(Stack *S)
{
    ItemType x;
    if (Empty(S))
    { 
        printf("STACK KOSONG!");
        return 0;
    }
    else
    {
        --(S->count);
        x = (S->item[S->count]);
        return x;
    }
}

void tampil(Stack *S){
    printf("-------------\n");
     while(S->count != 0){
        printf("%x", Pop(S));
    }    
    printf("\n-------------\n");
}
