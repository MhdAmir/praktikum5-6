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
    printf("Linked List untuk aplikasi INSERT After\n");
    printf("Membentuk Linked list dg Insert After\n");

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
    printf("apakah ingin melakukan after ?[y/t] ");
    scanf(" %c", &jawab);
    fflush(stdin);
    while(jawab == 'y' || jawab == 'Y'){

        alokasi();
        after();
        tampil();
        scanf(" %c", &jawab);
        fflush(stdin);
    }
    tampil();
    return 0;
}