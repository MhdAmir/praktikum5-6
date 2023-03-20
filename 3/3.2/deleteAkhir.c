#include<stdio.h>
#include<stdlib.h>
typedef struct simpul node;
struct simpul{
    int no;
    float nilai;
    char nama[20];
    node *next;
};

node *ph, *p, *head, *hapus;

void bebaskan(){
    free(hapus);
    hapus = NULL;
}
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
    }
}
void deleteAkhir(){
    hapus = head;
    if(head->next == NULL){
        head = NULL;
    }
    else {
        while(hapus->next != NULL){
            ph = hapus;
            hapus = hapus->next;
        }
        ph->next = NULL;
    }
    bebaskan();
}
void alokasi(){
    p = (node *) malloc(sizeof(node));
    if(p == NULL){
        printf("gagal alokasi\n");
        exit(0);
    }else{
    printf("masukkan no : ");
    scanf("%d", &p->no);
    printf("masukkan nama : ");
    scanf(" %[^\n]%*c", p->nama);
    printf("masukkan nilai : ");
    scanf("%f", &p->nilai);
    p->next = NULL;

    }
}
void tampil(){
    node *baca;
    baca = head;
    while(baca!=NULL){
        printf("no : %d\n", baca->no);
        printf("nama : %s\n", baca->nama);
        printf("nilai : %g\n", baca->nilai);
        baca = baca->next;
    }
}
int main(){
    printf("SSL - Delete Awal\nMembentuk linked list dg Insert di akhir\n\n");
    char kondisi = 'Y';
    do{ 
        fflush(stdin);
        alokasi();
        akhir();
        printf("apakah mau lagi[y/n]? ");
        fflush(stdin);
        scanf(" %c", &kondisi);
        printf("\n");
    }while(kondisi == 'y' || kondisi == 'Y');

    printf("mau hapus awal[y/n]? ");
    scanf(" %c", &kondisi);

    while(kondisi == 'y' || kondisi == 'Y'){
        deleteAkhir();
        tampil();
        printf("mau hapus awal[y/n]? ");
        fflush(stdin);
        scanf(" %c", &kondisi);
    }
    return 0;
}