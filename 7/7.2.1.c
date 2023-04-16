#include<stdio.h>
#include<stdlib.h>

#define MAKS 5

typedef int itemType;
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
void tampil(queue *q);
void minmax(queue *q);
void cari(queue *q);

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
    printf("1. Tambah Data\n");
    printf("2. Hapus Data\n");
    printf("3. Tampilkan data min & max\n");
    printf("4. Cari data\n");
    printf("5. Cetak isi Queue\n");
    printf("6. Keluar\n");
    printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pil);
        switch (pil)
        {
        case 1 :
            enqueue(q);
            break;
        case 2 :
            printf("item yang anda hapus adalah %d\n", dequeue(q));
            break;
        case 3 :
            minmax(q);
            break;
        case 4 :
            cari(q);
            break;
        case 5 :
            tampil(q);
            break;
        case 6 :
            printf("BYE!\n");
            exit(0);
            break;

        default:
            break;
        }

    }while(pil != 6);
}


void inisial(queue *q){
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}


void enqueue(queue *q){
    itemType isi;
    printf("masukkan data anda : ");
    scanf(" %d", &isi);
    if(full(q)){
        printf("ANTRIAN PENUH, TIDAK DAPAT MENYIMPAN DATA ! \n");
    }else{
        q->item[q->rear] = isi;
        q->rear = (q->rear+1) % MAKS;
        q->count++;
    }
}

void tampil(queue *q){
    int mulai = 1;
    printf("------------\n");
    for(int i = q->front; mulai <= q->count; (i++)%MAKS){
        printf("%d\n", q->item[i]);
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

void minmax(queue *q){
    int min = q->item[q->front], max = q->item[q->front], mulai = 1;
    for(int i = q->front; mulai <= q->count; (i++)%MAKS){
        // printf("%d\n", q->item[i]);
        if(min > q->item[i]){
            min = q->item[i];
        }
        if(max < q->item[i]){
            max = q->item[i];
        }
        mulai++;
    }
    printf("\nData terkecil = %d\n", min);
    printf("Data terBESAR = %d\n", max);

}
void cari(queue *q){
    int data;
    printf("\ndata yang dicari : ");
    scanf("%d", &data);
    int banyak = 0, mulai = 1;
    for(int i = q->front; mulai <= q->count; (i++)%MAKS){
        // printf("%d\n", q->item[i]);
        if(data == q->item[i]){
            banyak ++;
        }
        mulai++;
    }
    if(banyak == 0){
        printf("%d tidak ada dalam Queue\n", data);
    }else{
        printf("banyak data %d = %d\n", data, banyak);

    }
}


int empty(queue *q){
    return q->count == 0;
}


int full(queue *q){
    return q->count == MAKS;
}
