#include<stdio.h>
#include<stdlib.h>


typedef struct simpul node;
struct simpul{
    int nilai;
    node *next;
};
node *head, *p ,*hapus, *nilai;

void alokasi(){
    p = (node *) malloc(sizeof(node));
    printf("masukkan nilai : ");
    scanf("%d", &p->nilai);
    p->next = NULL;
}
void akhir(){
    node *tail;
    if(head == NULL){
        head = p;
    }
    else{
        tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = p;
        tail = tail->next;
    }
}
void hapus_akhir(){
    node *ph;
    hapus = head;
    if(head->next == NULL){
        head = NULL;
    }else{
        while(hapus->next != NULL){
            ph = hapus;
            hapus = hapus->next;
        }
    }
    free(hapus);
    hapus = NULL;
    ph->next = NULL;
}

void tampil(){
    node *baca;
    baca = head;
    printf("nilai pada SSL : \n");
    while(baca != NULL){
        printf("%d\n", baca->nilai);
        baca = baca->next;
    }
    printf("\n");
}

int main(){
    char kond;
    printf("Program SLL hapus awal :\n");
    
    do{
        fflush(stdin);
        alokasi();
        akhir();
        tampil();
        printf("apakah lagi [y/n] ? ");
        fflush(stdin);
        scanf(" %c", &kond);
        
    }while(kond == 'y' || kond =='Y');

    hapus_akhir();
    tampil();

    return 0;
}