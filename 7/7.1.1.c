#include<stdio.h>
#include<stdlib.h>

#define MAKS 5

typedef char itemType;
typedef struct {
    itemType item[MAKS];
    int count;
    int front;
    int rear;
}queue;


void menu(queue *q);
void inisial(queue *q);
void enqueue(queue *q);
itemType dequeue(queue *q);
int empty(queue *q);
int full(queue *q);
void fifo(queue *q);

int main(){
    queue antri;
    inisial(&antri);
    menu(&antri);
    return 0;
}


void menu(queue *q){
    int pil;
    do{
    printf("MENU QUEUE using ARRAY:\n");
    printf("1. Mengisi Queue <ENQUEUE>\n");
    printf("2. Mengambil isi Queue <DEQUEUE>\n");
    printf("3. Menampilkan isi Queue -> FIFO \n");
    printf("4. Keluar\n");
    printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pil);
        switch (pil)
        {
        case 1 :
            enqueue(q);
            break;
        case 2 :
            printf("item yang anda ambil adalah %c\n", dequeue(q));
            break;
        case 3 :
            fifo(q);
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


void inisial(queue *q){
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}


void enqueue(queue *q){
    itemType isi;
    printf("masukkan data anda : ");
    scanf(" %c", &isi);
    if(full(q)){
        printf("ANTRIAN PENUH, TIDAK DAPAT MENYIMPAN DATA ! \n");
    }else{
        q->item[q->rear] = isi;
        q->rear = (q->rear+1) % MAKS;
        q->count++;
    }
}

void fifo(queue *q){
    int mulai = 1;
    printf("------------\n");
    for(int i = q->front; mulai <= q->count; (i++)%MAKS){
        printf("%c\n", q->item[i]);
        mulai++;
    }
    printf("------------\n");
}

itemType dequeue(queue *q){
    itemType temp;
    if(empty(q)){
        printf("ANTRIAN KOSONG, TIDAK DAPAT MENGAMBIL DATA\n");
        return ' ';
    }else{
        temp = q->item[q->front];
        q->front = (q->front+1) % MAKS;
        q->count--;
        return temp;
    }

}


int empty(queue *q){
    return q->count == 0;
}


int full(queue *q){
    return q->count == MAKS;
}
