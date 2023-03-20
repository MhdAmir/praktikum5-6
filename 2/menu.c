#include<stdio.h>
#include<stdlib.h>

typedef struct siswa Node;
struct siswa{
    int nilai;
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

        while(after->nilai != key) {
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
    }else if(head->next == NULL){
        awal();
    } else {
        before = head;
        while(before->nilai != key) {
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
        scanf("%d", &p->nilai);
    }
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
int main(){
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
            if(head == NULL){
                printf("harus input nilai pada field dengan awal / akhir terlebih dahulu \n");
                break;
            }else{
            alokasi();
            after();
            tampil(); 
            break;
            }
        case 4:
            if(head == NULL){
                printf("harus input nilai pada field dengan awal / akhir terlebih dahulu \n");
                break;
            }else{
                alokasi();
                before();
                tampil(); 
            break;
            }
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
