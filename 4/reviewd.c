#include<stdio.h>
#include<stdlib.h>

typedef struct siswa Node;
struct siswa{
    int no;
    float nilai;
    char nama[20];
    Node *next;
};

void alokasi();
void hapus_ttt();
void tampil();
void menu();
void nyari();
void Instrrt();
void rata2();
void hapus_awal();
void bebaskan();


Node *head = NULL, *p, *hapus;

int main()
{
    menu();   
    return 0;
}


void menu(){
    int jawab = 1;
    while(jawab>0 || jawab < 5){
        printf("Menu UTAMA\n");
        printf("1. Penambahan Secara Terurut\n2. Pencarian data\n3. Penghapusan data\n4. Nilai rata rata kelas\n5. Keluar\n");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &jawab);
        switch(jawab){
            case 1:
                Instrrt();
                break;
            case 2:
                nyari();
                break;
            case 3:
                if(head == NULL){
                    printf("\nga ada data di SLL\n\n");
                }else
                hapus_ttt();
                break;
            case 4:
                if(head == NULL){
                    printf("\nga ada data di SLL\n\n\n");
                }else
                rata2();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nMenu tidak tersedia\n\n");
                break;
        }
        if(jawab == 1 || jawab == 3){
            tampil();
        }
    }
}
void Instrrt(){
    Node *cari, *pc;
    alokasi();
    int stop = 0;
    cari = head;
    if(head == NULL){
        head = p;
    }else{
    if(p->no <= cari->no){
        p->next = cari;
        head = p;
    }
    else{
        while(p->no > cari->no){
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
void nyari(){
    Node *cari;
    int key, banyak = 0;
    cari = head;
    printf("masukkan data yang mau dicari : ");
    scanf("%d", &key);
    while(cari!= NULL){
        if(cari->no == key){
            banyak++;
        }
        cari = cari->next;
    }
    printf("data %d ketemu sebanyak %d kali\n", key, banyak);
}
void hapus_ttt(){
    Node *ph;
    int key, stop = 0;
    printf("masukkan nilai yang ingin di hapus : ");
    scanf("%d", &key);
    
    hapus = head;
    if(hapus->no == key){
        hapus_awal();
    }else{
        while(hapus->no != key){
            if(hapus->next == NULL){
                printf("%d ga ada di SLL\n", key);
                stop = 1;
                break;
            }else{
                ph = hapus;
                hapus = hapus->next;
            }
        }
        if(stop == 0){
            ph->next = hapus->next;
            bebaskan(); 
        }
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
    }
}

void tampil(){
    Node *baca;
    baca = head;
    printf("\n-----------------------------\n");
    printf("No\tNama\tNilai\n");
    while(baca!=NULL){
        printf("%d\t", baca->no);
        printf(" %s\t", baca->nama);
        printf("%g\n\n", baca->nilai);
        baca = baca->next;

    }
    printf("\n-----------------------------\n\n");
}

void rata2(){
    Node *n;
    int banyak = 0, jumlah = 0;
    float mean = 0;
    n = head;
    while(n != NULL){
        banyak ++;
        jumlah = jumlah + n->nilai;
        n = n->next;
    }
    mean = jumlah/banyak;
    printf("\nrata rata dari kelas : %g\n\n", mean);
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
void bebaskan(){
    free(hapus);
    hapus = NULL;
}