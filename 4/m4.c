#include<stdio.h>
#include<stdlib.h>

typedef struct simpul node;
struct simpul{
    int nilai;
    node *next;
};

node *head = NULL, *p;

void alokasi();
void Instrrt();
void tampil();
void nyari();
void hapus();

int main(){
    char jawab;
    do{
        alokasi();
        fflush(stdin);
        Instrrt();
        tampil();
        printf("mau lagi[y/n]? ");
        scanf(" %c", &jawab);

    }while(jawab == 'y' || jawab == 'Y');
    return 0;
}

void alokasi(){
    p = (node *)malloc(sizeof(node));
    printf("masukkan nilai baru : ");
    scanf("%d", &p->nilai);
    p->next = NULL;
}

void Instrrt(){
    node *cari, *pc;
    int stop = 0;
    cari = head;
    if(head == NULL){
        head = p;
    }else{
    if(p->nilai < cari->nilai){
        p->next = cari;
        head = p;
    }
    else{
    while(p->nilai > cari->nilai){
        if(cari->next == NULL){
            cari->next = p;
            stop = 1;
            
        }else{
            pc = cari;
            cari = cari->next;
        }
    }
    if(stop == 0){
        p->next = cari;
        pc->next = p;
    }
    }
    }
}

void tampil(){
    node *baca;
    baca = head;
    while(baca != NULL){
        printf("%d\n", baca->nilai);
        baca = baca->next;
    }
}
