#include<stdio.h>
#include<stdlib.h>

typedef struct simpul node;
struct simpul{
    int no;
    float nilai;
    char nama[20];
    node *next;
};
node *head, *p ,*hapus, *nilai;

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

void hapus_awal(){
    hapus = head;
    if(head->next == NULL){
        head = NULL;
    }else{
        head = hapus->next;
    }
    free(hapus);
    hapus = NULL;
}

void hapus_Ttt(){
    node *ph;
    int key;
    printf("masukkan nilai yang ingin di hapus : ");
    scanf("%d", &key);
    
    hapus = head;
    if(head->no == key){
        hapus_awal();
    }else{
        while(hapus->no != key){
            if(hapus->next == NULL){
                printf("%d ga ada di SLL\n", key);
            }else{
            ph = hapus;
            hapus = hapus->next;
            }
        }
        ph->next = hapus->next;
        free(hapus);
        hapus = NULL;
    }
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
            tail = tail->next;
            
    }
}

void tampil(){
    node *baca;
    baca = head;
    printf("\n-----------------------------\n");
    while(baca!=NULL){
        printf("no : %d\n", baca->no);
        printf("nama : %s\n", baca->nama);
        printf("nilai : %g\n\n\n", baca->nilai);
        baca = baca->next;

    }
    printf("\n-----------------------------\n\n");
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

    hapus_Ttt();
    tampil();

    return 0;
}