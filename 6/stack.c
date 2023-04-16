#include<stdio.h>
#define MAKS 5

typedef char item;
typedef struct{
    item data[MAKS];
    int index;
}stack;

void inisial(stack *s);
void dorong(item x, stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
item pop(stack *s);


int main(){
    stack tumpuk;
    item isi;
    char jawab;
    
    inisial(&tumpuk);
    do{
        printf("masukkan data : ");
        scanf(" %c", &isi);
        dorong(isi, &tumpuk);
        printf("mau lagi [y/n]? ");
        scanf(" %c", &jawab);

    }while(jawab == 'y' || jawab == 'Y');

    printf("---------------\n");
    while(tumpuk.index != 0){
        printf("%c\n", pop(&tumpuk));
    }    
    printf("---------------\n");

    return 0;
}

void dorong(item x, stack *s){
    if(isFull(s)){
        printf("stack sudah penuh tidak bisa mengisi lagi\n");
    }else{
        s->data[s->index] = x;
        s->index ++;
    }
}

int isEmpty(stack *s){
    return s->index == 0 ? 1 : 0;
}
int isFull(stack *s){
    return s->index == MAKS ? 1 : 0;
}

void inisial(stack *s){
    s->index = 0;    
}

item pop(stack *s){
    item isi;
    if(isEmpty(s)){
        printf("stack kosong tidak ada data\n");
        return ' ';    
    }
    else{
        --s->index;
        isi = s->data[s->index];
        return isi;
    }
}
