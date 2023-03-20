#include<stdio.h>
#include<stdlib.h>

typedef struct siswa Node;
struct siswa{
    int nilai;
    Node *next;
};

void alokasi();
void hapus_ttt();
void tampil();
void menu();
void nyari();
void Instrrt();
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
        printf("1. Penambahan Secara Terurut\n2. Pencarian data\n3. Penghapusan data\n4. Keluar\n");
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
                    printf("data masih kosong\n");
                }else{
                hapus_ttt();
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\bebaskann\nMenu tidak tersedia\n\n");
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
    if(p->nilai <= cari->nilai){
        p->next = cari;
        head = p;
    }
    else{
        while(p->nilai > cari->nilai){
            if(cari->next == NULL){
                cari->next = p;
                stop = 1;
                break;

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
        if(cari->nilai == key){
            banyak++;
        }
        cari = cari->next;
    }
    printf("\n\ndata %d ketemu sebanyak %d kali\n\n", key, banyak);
}
void hapus_ttt(){
    Node *ph;
    int key, flag=1;
    printf("Masukkan node yang ingin dihapus: ");
    scanf("%d",&key);

    hapus=head;
    if(hapus->nilai==key)
        hapus_awal();
    else
    {
        while(hapus->nilai!=key)
        {
            if(hapus->next==NULL)
            {
                printf("Node %d tidak ada dalam SLL.\n\n",key);
                flag=0;
                break;
            }
            else
            {
                ph=hapus;
                hapus=hapus->next;
            }
        }
        if(flag){
        ph->next=hapus->next;
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
        scanf("%d", &p->nilai);
    }
}

void tampil(){
    Node *baca;
    baca = head;
    printf("\n--------\n");
    printf("Nilai\n");
    while(baca != NULL){
        printf("%d\t\n",baca->nilai);
        baca = baca->next;
    }
    printf("\n--------\n");
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