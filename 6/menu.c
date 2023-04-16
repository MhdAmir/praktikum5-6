#include<stdio.h>
#include<stdlib.h>

#define MAKS 5

typedef char item;
typedef struct{
    item data[MAKS];
    int index;
}stack;

void Mutama(stack *s);
void inisial(stack *s);
void tampil(stack *s);
void dorong(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
item pop(stack *s);


int main(){
    stack tumpuk;
    inisial(&tumpuk);
    Mutama(&tumpuk);
    return 0;
}

void Mutama(stack *s){
    int jawab;
    do{
        printf("Menu STACK using Array :\n");
        printf("1. Mengisi Stack (PUSH)\n2. Mengambil isi Stack (POP)\n3. Menampilkan isi stack -> LIFO\n4. Keluar\n\n");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &jawab);
        switch(jawab){
            case 1:
                dorong(s);
                break;
            case 2:
                printf("Item yang anda ambil adalah %c\n\n", pop(s));
                break;
            case 3:
                tampil(s);
                break;
            case 4:
                printf("\n\nBYE!\n\n");
                exit(0);
            default:
                printf("\n\nMenu tidak tersedia\n\n");
                break;
        }
    }while(jawab != 4);
}

void tampil(stack *s){
    int n;
    n = s->index;
    printf("------------\n");
    while(n != 0){
        --n;
        printf("%c\n", s->data[n]);
    }
    printf("------------\n");
}

void dorong(stack *s){
    item isi;
    printf("masukkan data anda :");
    scanf(" %c", &isi);
    if(isFull(s)){
        printf("stack sudah penuh tidak bisa mengisi lagi\n");
    }else{
        s->data[s->index] = isi;
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
