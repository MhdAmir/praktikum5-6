#include<stdio.h>
struct date
{
    int d,m,y;
};

struct data{
    int gaji;
    char nama[100], gender;
    struct date bd;
};
void input(int N, struct data *emp){
    for(int i = 0; i < N; i++){
        printf("Pegawai ke-%d\n", i+1);
        printf("Nama\t\t:");
        scanf("%s", emp[i].nama);
        fflush(stdin);
        printf("tanggal lahir\t\t:(dd/mm/yy)");
        scanf("%d-%d-%d", &emp[i].bd.d, &emp[i].bd.m, &emp[i].bd.y);
        fflush(stdin);
        printf("Jenis Kelamin\t\t:[l/p]");
        scanf(" %c", &emp[i].gender);
        fflush(stdin);
        printf("Gaji/bln\t\t:");
        scanf("%d", &emp[i].gaji);
        fflush(stdin);
        printf("\n");
    }   
}
void tampil(int N, struct data *emp){
    printf("Data pegawai yang telah di inputkan\n");
    printf("--------------------------------------\n");
    
    for(int i = 0 ; i < N ; i++){
        printf("No ID : %d\n", i+1);
        printf("Tgl Lahir : %d-%d-%d\n", emp[i].bd.d, emp[i].bd.m, emp[i].bd.y);
        if(emp[i].gender == 'l'){
            printf("Jenis Kelamin : Laki-laki\n");
        }else if(emp[i].gender == 'p'){
            printf("Jenis Kelamin : Perempuan\n");
        }
        printf("Gaji/bln : Rp.%d.00\n", emp[i].gaji);
        printf("--------------------------------------\n");

    }
}
int main(){
    int N;
    printf("Berapa jumlah pegaawai ? ");
    scanf("%d", &N);
    struct data emp[N];
    input(N, &emp[0]);
    tampil(N, &emp[0]);

    return 0;
}