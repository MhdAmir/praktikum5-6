#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p;

void alokasi()
{
    int num;
    printf("Input angka yang ingin dimasukkan ke SSL : ");
    scanf("%d", &num);

    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Gagal\n");
        exit(0);
    } else {
        p->data = num;
        p->next = NULL;
    }

    
}

void akhir()
{
    Node *tail;
    
    if(head == NULL) {
        head = p;
    } else {
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
        tail = p;
    }

}

void after()
{
    Node *after;
    int key;

    printf("Disisipkan setelah? ");
    scanf("%d", &key);
    
    if(head == NULL) {
        head = p;
    } else {
        after = head;

        while(after->data != key) {
            if(after->next == NULL) {
                printf("Key tidak ada\n");
            } else {
                after = after->next; 
            }
        }

        p->next = after->next;

        after->next = p;
    }
}

void output()
{
    Node *baca;
    baca = head;

    printf("Isi dari SLL\n");
    while(baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}
int main()
{
    char jawab;

    do {
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Input lagi? [y/n] ");
        scanf(" %c", &jawab);
        fflush(stdin);
    } while ((jawab == 'y') || (jawab == 'Y'));

    output();
    printf("apakah ingin melakukan after ?[y/t] ");
    scanf(" %c", &jawab);
    fflush(stdin);
    while(jawab == 'y' || jawab == 'Y'){

        alokasi();
        after();
        output();
        printf("mau lagi[y/t] ? ");
        scanf(" %c", &jawab);
        fflush(stdin);
    }
    return 0;
}
