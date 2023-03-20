#include<stdio.h>
#include<stdlib.h>

typedef struct siswa Node;
struct siswa{
    int no;
    float nilai;
    char nama[20];
    Node *next;
};

void awal();
void akhir();
void after();
void before();
void alokasi();
void hapus_awal();
void hapus_akhir();
void hapus_stlh();
void hapus_ttt();
void bebaskan();
void tampil();
void menu();
void menuInsr();
void menuDel();


Node *head = NULL, *p, *hapus;

int main()
{
    menu();   
    return 0;
}

void menu(){
    int jawab;
    do{
        printf("Menu SLL\n");
        printf("1. Insert\n2. Delete\n3. Keluar\n");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &jawab);
        switch(jawab){
            case 1:
                menuInsr();
                break;
            case 2:
                menuDel();
                break;
            case 3:
                exit(0);
            default:
                printf("\n\nMenu tidak tersedia\n\n");
                break;
        }
    }while(jawab != 3);
}

void menuInsr(){
    int pilIns;
    printf("Menu Inser\n1. Awal\n2. Akhir\n3. Sebelum\n4. Sesudah\n");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &pilIns);
    if(pilIns < 1 || pilIns > 4){
        printf("Menu tidak tersedia\n");
    }else{
        alokasi();
    switch(pilIns){
        case 1:
            awal();
            break;
        case 2:
            akhir();
            break;
        case 3:
            if(head==NULL){
                printf("SLL masih kosong, tidak bisa insert after\n");
                break;
            }
            before();
            break;
        case 4:
            if(head==NULL){
                printf("SLL masih kosong, tidak bisa insert before\n");
                break;
            }
            after();
            break;
    }
    }
    tampil();
}

void menuDel(){
    int pilDel;
    printf("Menu Delete\n1. Awal\n2. Akhir\n3. Tertentu\n4. After\n");
    if(head == NULL){
        printf("Belum ada data\n--------------\n\n");
    }
    else{
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilDel);

        switch(pilDel){
            case 1:
                hapus_awal();
                break;
            case 2:
                hapus_akhir();
                break;
            case 3:
                hapus_ttt();
                break;
            case 4:
                hapus_stlh();
                break;
            default:
                printf("Menu tidak tersedia\n------------\n\n");
                break;
        }
        
        tampil();
        }
}

void awal(){
    if(head == NULL){
        head = p;
    }else{
        p->next = head;
        head = p;
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

void after()
{
    Node *after;
    int key;

    printf("Disisipkan setelah? ");
    scanf("%d", &key);
    
    if(head == NULL) {
        printf("Kamu harus inputkan field terlebih dahulu\n");
    } else {
        after = head;

        while(after->no != key) {
            if(after->next == NULL) {
                printf("Key tidak ada\n");
                break;
            } else {
                after = after->next; 
            }
        }

        p->next = after->next;

        after->next = p;
    }
}

void before()
{
    Node *before, *prevBefore;
    int key;

    printf("Disisipkan sebelum? ");
    scanf("%d", &key);
    
    if(head == NULL) {
        printf("Kamu harus inputkan field terlebih dahulu\n");
    }else if(head->no == key){
        awal();
    } else {
        before = head;
        while(before->no != key) {
            if(before->next == NULL) {
                printf("Key tidak ada\n");
                break;
            } else {
                prevBefore = before;
                before = before->next; 
            }
        } 
        p->next = before;
        prevBefore->next = p;

    }
}

void hapus_awal(){
    hapus = head;
    if(head->next == NULL){
        head = NULL;
    }else{
        head = hapus->next;
    }
    bebaskan();
    
}
void hapus_stlh(){
    Node *ph;
    int key;
    printf("masukkan setelah nilai apa yang ingin di hapus : ");
    scanf("%d", &key);
    
    hapus = head;

    if(head == NULL){
        printf("Kamu harus inputkan field terlebih dahulu\n");
    }
    else{
        hapus = head;
        while(hapus->no != key){
            if(hapus->next == NULL){
                printf("%d ga ada di SLL\n", key);
            }else{
                ph = hapus;
                hapus = hapus->next;
            }
        }
        if(hapus->next == NULL){
            printf("\n!!!!!\nga ada no setelah %d\n!!!!!!\n", hapus->no);
        }else{
            ph = hapus;
            hapus = hapus->next;

            ph->next = hapus->next;
            bebaskan();
        }
    }
}

void hapus_ttt(){
    Node *ph;
    int key;
    printf("masukkan no yang ingin di hapus : ");
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
        bebaskan();
    }

}
void hapus_akhir(){
    Node *ph;
    int flag = 1;
    hapus = head;
    if(head->next == NULL){
        head = NULL;
        flag = 0;
    }else{
        while(hapus->next != NULL){
            ph = hapus;
            hapus = hapus->next;
        }
    }
    if(flag == 1){
        bebaskan();
        ph->next = NULL;
    }
}

void bebaskan(){

    free(hapus);
    hapus = NULL;
}
void alokasi(){
    p = (Node *) malloc(sizeof(Node));
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
    Node *baca;
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
