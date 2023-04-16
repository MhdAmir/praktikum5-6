#include <stdio.h>
#include <string.h>
#define MAX 100
typedef char ItemType;
typedef struct
{
    char item[MAX]; 
    int count;           
} Stack;

void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop(Stack *);
int drjt(char x);
void konversi_cetak(char[], Stack *);


int main()
{
    Stack tumpukan;
    char tampung[MAX], jawab;
    puts("MENGUBAH NOTASI INFIX MENJADI PSOTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do
    {
        InitializeStack(&tumpukan);
        fflush(stdin);
        printf("Masukan ekspresi dalam notasi infix : ");
        scanf(" %[^\n]%*c", tampung);
        printf("Ungkapan postfixnya = ");
        konversi_cetak(tampung, &tumpukan);
        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf(" %c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));
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

int drjt(char x) 
{
    if (x == '(')
        return 0;
    else if ((x == '+') || (x == '-'))
        return 1;
    else if ((x == '*') || (x == '/'))
        return 2;
    else if (x == '^')
        return 3;
    else
        return -1; 
}

void konversi_cetak(char temp[], Stack *s)
{
    int i, pjg, valid = 1;
    char kar, smtr;
    pjg = strlen(temp);
    for (i = 0; i < pjg; i++)
    {
        kar = temp[i]; 

        if(kar == '('){
            Push(kar, s);
        }else if((kar >= 48 &&kar <= 57) || (kar >= 65 && kar <= 90) ||(kar >= 97&& kar <= 122)){
            printf("%c", kar);
        }else if(kar == '+' || kar == '-' || kar == '/' || kar == '*' || kar == '^'){
            if((Empty(s) || (drjt(kar) > drjt(s->item[s->count]))))
                Push(kar, s);
            else{
                do
                {
                    smtr = Pop(s);
                    printf("%c", smtr);
                } while (drjt(kar) < drjt(s->item[s->count]));
                Push(kar, s);
            }
            
        }else if(kar == ')'){
            while (s->item[s->count] != '(')
            {
                smtr = Pop(s);
                printf("%c", smtr);
                
            }
            Pop(s);
        }else{
            valid = 0;
            printf("salah masukkan\n");
        }
    }     

    if ((valid != 0) && (!Empty(s)))
    {
        smtr = Pop(s);
        printf("%c", smtr);
    }
}