#include<stdio.h>
#include<stdlib.h>

#define MAKS 5

typedef int itemType;
typedef struct siswa Node;
struct siswa{
    itemType nilai;
    Node *next;
};

Node *head = NULL, *p, *hapus;

void alokasi();
void Mutama();
void alokasi();
void tampil();
void PUSH();
itemType POP();


int main(){
    Mutama();
    return 0;
}

void Mutama(){
    int jawab;
    do{
        printf("\nMenu STACK using SLL :\n");
        printf("1. Mengisi Stack (PUSH)\n2. Mengambil isi Stack (POP)\n3. Menampilkan isi stack -> LIFO\n4. Keluar\n\n");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &jawab);
        switch(jawab){
            case 1:
                PUSH();
                break;
            case 2:
                if(head == NULL){
                    printf("\nTIDAK ADA STACK, STACK KOSONG!!!!\n\n");
                }else{
                    printf("\nItem yang anda ambil adalah %d\n\n", POP());
                }
                break;
            case 3:
                tampil();
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

void tampil(){
    Node *baca;
    baca = head;
    printf("Nilai\n");
    while(baca != NULL){
        printf("%d\t\n",baca->nilai);
        baca = baca->next;
    }
}

void PUSH(){
    alokasi();
    if(head == NULL){
        head = p;
    }else{
        p->next = head;
        head = p;
    }
}


void alokasi(){
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("alokasi memori gagal\n");
        exit(0);
    }else{
        printf("masukkan data : ");
        scanf("%d", &p->nilai);
        p->next = NULL;
    }   
}

itemType POP(){
    int isi;
    hapus = head;
    if(head->next == NULL){
        head = NULL;
    }else{
        head = hapus->next;
    }
    isi = hapus->nilai;
    free(hapus);
    hapus = NULL;
    return isi;

    
}
