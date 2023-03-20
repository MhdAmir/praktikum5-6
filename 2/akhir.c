#include<stdio.h>
#include<stdlib.h>
typedef struct simpul node;
struct simpul{
    int nilai;
    node *next;
};
node *head = NULL, *p;

void akhir(){
    node *tail;
    if(head == NULL){
        head = p;
    }else{
        tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
            tail->next = p;
            tail = tail->next;
            
    }
}
void alokasi(){
    p = (node *)malloc(sizeof(node));
    printf("masukkan nilai : ");
    scanf("%d", &p->nilai);
    p->next = NULL;
}
void tampil(){
    node *baca;
    baca = head;
    while(baca != NULL){
        printf("%d\n",baca ->nilai);
        baca = baca->next;
    }
}

int main(){
    int x;
    do{
        alokasi();
        fflush(stdin);
        akhir();
        fflush(stdin);
        tampil();

        printf("apakah lagi?[1/0] : ");
        scanf("%d", &x);
    
    } while(x == 1);
    tampil();
    return 0;
}