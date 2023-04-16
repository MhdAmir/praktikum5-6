#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
int palindrom(char temp[], Stack *);



int main(){
    Stack tumpuk;
    menu(&tumpuk);
    return 0;
}

void menu(Stack *S){
    char temp[MAX], jawab;
    printf("MENGECEK PALINDROM\n");
    
    do{
        InitializeStack(S);
        printf("Masukkan kata yang akan dicek : ");
        scanf(" %[^\n]%*c", temp);
        if(palindrom(temp, S) == 1){
            printf("%s adalah palindrom\n", temp);
        }else{
            printf("%s bukan palindrom\n", temp);
        }
        printf("\nMau coba lagi (y/t) ? ");
        scanf(" %c", &jawab);
        
    }while(jawab == 'y' || jawab == 'Y');
}

int palindrom(char temp[], Stack *S){
    char isi;
    for(int i = 0; i < strlen(temp); i++){
        Push(temp[i], S);
    }
    for(int i = 0; i < strlen(temp); i++){
        isi = Pop(S);
        if(temp[i] != isi){
            return 0;
        }
    }
    return 1;
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

