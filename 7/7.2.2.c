#include<stdio.h>
#include<stdlib.h>

#define MAKS 5

typedef char itemType;
typedef struct siswa Node;
struct siswa{
    itemType item;
    int priority;
    Node *next;
};

Node *head = NULL, *p, *hapus;

void menu();
void alokasi();
void enqueue();
itemType dequeue();
int empty();
void fifo();

int main(){
    menu();
    return 0;
}


void menu(){
    int pil;
    do{
    printf("MENU PRIORITY QUEUE using SLL:\n");
    printf("1. Mengisi Queue \n");
    printf("2. Mengambil isi Queue \n");
    printf("3. Menampilkan isi Queue  \n");
    printf("4. Keluar\n");
    printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pil);
        switch (pil)
        {
        case 1 :
            enqueue();
            break;
        case 2 :
            printf("item yang anda ambil adalah %c\n", dequeue());
            break;
        case 3 :
            fifo();
            break;
        case 4 :
            printf("BYE!\n");
            exit(0);
            break;

        default:
            break;
        }

    }while(pil != 4);
}

void alokasi(){
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("alokasi memori gagal\n");
        exit(0);
    }else{
        printf("masukkan data anda : ");
        scanf(" %c", &p->item);
        printf("Nilai prioitasnya : ");
        scanf("%d", &p->priority);
    }

}
void enqueue(){
    alokasi();
    Node *cari, *pc;
    int stop = 0;
    cari = head;
    if(head == NULL){
        head = p;
    }else{
    if(p->priority < cari->priority){
        p->next = cari;
        head = p;
    }
    else{
    while(p->priority > cari->priority){
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

void fifo(){
    if(empty()){
        printf("\n\nDATA KOSONG... TIDAK ADA DATA YANG DITAMPILKAN\n\n");
    }
    else{
        Node *baca;
        baca = head;
        printf("Data\tPrioritas\n");
        while(baca != NULL){
            printf("%c\t",baca->item);
            printf("%d\t\n",baca->priority);
            baca = baca->next;
        }

    }
}

itemType dequeue(){
    itemType temp;
    hapus = head;
    if(head->next == NULL){
        head = NULL;
    }else{
        head = hapus->next;
    }
    temp = hapus->item;
    free(hapus);
    hapus = NULL;
    return temp;
}

int empty(){
    return head == NULL;
}
