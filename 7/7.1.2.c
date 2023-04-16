#include<stdio.h>
#include<stdlib.h>

#define MAKS 5

typedef char itemType;
typedef struct siswa Node;
struct siswa{
    itemType item;
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
    printf("MENU QUEUE using SLL:\n");
    printf("1. Mengisi Queue <ENQUEUE>\n");
    printf("2. Mengambil isi Queue <DEQUEUE>\n");
    printf("3. Menampilkan isi Queue -> FIFO \n");
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
    }

}
void enqueue(){
    alokasi();
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

void fifo(){
    if(empty()){
        printf("\n\nDATA KOSONG... TIDAK ADA DATA YANG DITAMPILKAN\n\n");
    }
    else{
        Node *baca;
        baca = head;
        printf("Nilai\n");
        while(baca != NULL){
            printf("%c\t\n",baca->item);
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
