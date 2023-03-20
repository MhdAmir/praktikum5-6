#include<stdio.h>
#include<stdlib.h>
typedef struct simpul node;
struct simpul{
    int nilai;
    node *next;
};
node *head = NULL, *p;

void awal(){
    if(head == NULL){
        head = p;
    }else{
        p->next = head;
        head = p;
    }
}
void alokasi(){
    p = (node *)malloc(sizeof(node));
    if(p == NULL){
        printf("alokasi memori gagal\n");
        exit(0);
    }else{
        scanf("%d", &p->nilai);
        p->next = NULL;
    }
}
void tampil(){
    node *baca;
    baca = head;
    printf("No\tNama\tNilai\n");
    while(baca != NULL){
        printf("%d\n",baca ->nilai);
        baca = baca->next;
    }
}

int main(){
    printf("Linked List untuk aplikasi INSERT DI Akhir\n");
    printf("Membentuk Linked list dg Insert di Akhir\n");
    int x;
    do{
        alokasi();
        fflush(stdin);
        awal();
        printf("apakah lagi?[1/0] : ");
        scanf("%d", &x);
        printf("\n");
    
    } while(x == 1);
    tampil();
    return 0;
}