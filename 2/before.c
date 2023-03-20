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
    printf("Input angka: ");
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

void before()
{
    Node *before, *prevBefore;
    int key;

    printf("Disisipkan sebelum? ");
    scanf("%d", &key);
    
    if(head == NULL) {
        head = p;
    } else {
        before = head;
        while(before->data != key) {
            if(before->next == NULL) {
                printf("Key tidak ada\n");
            } else {
                prevBefore = before;
                before = before->next; 
            }
        } 
        p->next = before;
        prevBefore->next = p;

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
        printf("Input lagi? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));

    output();

    alokasi();
    before();
    output();

    return 0;
}
