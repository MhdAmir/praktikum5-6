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



void alokasi(){
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("alokasi memori gagal\n");
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
    printf("No\tNama\tNilai\n");
    while(baca != NULL){
        printf("%d\t",baca->no);
        printf("%s\t",baca->nama);
        printf("%g\t\n",baca->nilai);
        baca = baca->next;
    }
}
int main(){
    // printf("Linked List untuk aplikasi INSERT DI Akhir\n");
    // printf("Membentuk Linked list dg Insert di Akhir\n");
    int insert; 
    char x;
    do{
        printf("menu INSERT :\n1.\tAwal \n2.\tAkhir\n3.\tAfter\n4.\tBefore\n5.\tKeluar\n");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &insert);
        switch (insert)
        {
        case 1:
            alokasi();
            fflush(stdin);
            awal();
            tampil(); 
            break;
        case 2:
            alokasi();
            fflush(stdin);
            akhir();
            tampil(); 
            break;
        case 3:
            alokasi();
            after();
            tampil(); 
            break;
        case 4:
            alokasi();
            before();
            tampil(); 
            break;
        
        case 5:
            tampil(); 
            exit(0);

        default:
            printf("inputan salah\n");
            break;
        }
        printf("\n");   
        
        printf("apakah lagi?[y/n] : ");
        scanf(" %c", &x);
        printf("\n");   
    } while(x == 'y' || x =='Y');
    return 0;
}
