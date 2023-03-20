#include<stdio.h>
#include<stdlib.h>

typedef struct siswa Node;
struct siswa{
    int no;
    char nama[20];
    float nilai;
    Node *next;
};
Node *head = NULL, *p;
void before(){
    Node *bef, *pbef;
    bef = head;
    int key;
    if(head == NULL){
        printf("Harus mengisi field dulu sebelum melakukan before\n");
    }else{
        printf("masukkan key yang dicari ? ");
        scanf("%d", &key);

        if(head == NULL){
            head = p;
        }else{
            bef = head;
        while(bef->no != key){
            if(bef->next == NULL){
                printf("ga ada di field\n");
                break;
            }else{
                pbef = bef;
                bef = bef->next;
            }
        }
        p->next = bef;
        pbef->next = p;
    }
    }
}

void akhir(){
    Node *tail;
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
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("Alokasi Memori Gagal\n");
    }else{
        printf("no : ");
        scanf("%d", &p->no);
        printf("nama :");
        scanf(" %[^\n]%*c", p->nama);
        fflush(stdin);
        printf("nilai :");
        scanf("%f", &p->nilai);
        p->next = NULL;
    }
}

void tampil(){
    Node *baca;
    baca = head;
    while(baca->next != NULL){
        printf("%d\t", baca->no);
        printf("%s\t", baca->nama);
        printf("%f\n", baca->nilai);
    }
}

int main(){
    printf("Linked List untuk aplikasi INSERT before\n");
    printf("Membentuk Linked list dg Insert before\n");

    char jawab;
    do{
        alokasi();
        fflush(stdin);
        akhir();
        printf("apakah lagi?[y/t] : ");
        scanf(" %c", &jawab);
        fflush(stdin);
        printf("\n");
    
    } while(jawab == 'y' || jawab == 'Y');
    printf("apakah ingin melakukan before ?[y/t] ");
    scanf(" %c", &jawab);
    fflush(stdin);
    while(jawab == 'y' || jawab == 'Y'){

        alokasi();
        before();
        tampil();
        scanf(" %c", &jawab);
        fflush(stdin);
    }
    tampil();
    return 0;
}