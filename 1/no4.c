#include<stdio.h>
#include<string.h>

typedef struct{
    char nama[100];
    float nilai;
}maks ;
typedef struct{
    int tugas, uts, uas;
    float akhir;
    char nama[100], grade;
}data ;

void input(int N, data *mhs, maks *rank){
    for(int i = 0; i < N; i++){
        printf("Mahasiswa ke-%d\n", i+1);
        printf("Nama\t\t:");
        scanf(" %[^\n]%*c", mhs->nama);
        // fflush(stdin);
        printf("Nilai tugas\t\t:");
        scanf("%d", &mhs->tugas);
        fflush(stdin);
        printf("Nilai uts\t\t:");
        scanf("%d", &mhs->uts);
        fflush(stdin);
        printf("Nilai uas\t\t:");
        scanf("%d", &mhs->uas);
        fflush(stdin);
        printf("\n");
        mhs->akhir = (mhs->tugas + mhs->uts + mhs->uas)/3; 
        
        if(mhs->akhir >= 80)
            mhs->grade = 'A';
        else if(mhs->akhir >=70)
            mhs->grade = 'B';
        else if(mhs->akhir >=60)
            mhs->grade = 'C';
        else if(mhs->akhir >=50)
            mhs->grade = 'D';
        else if(mhs->akhir < 50)
            mhs->grade = 'E';

        if(mhs->akhir > rank->nilai){
            rank->nilai = mhs->akhir;
            strcpy(rank->nama, mhs->nama);
        }
        *mhs++;
    }   
}
void tampil(int N, data *mhs, maks *rank){
    printf("Daftar Nilai\nMata kuliah konsep pemrograman\n");
    printf("--------------------------------------\n");
    printf("No\tNama\n\tMahasiswa\tTugas\tUTS\tUAS\tAkhir\tGrade\n");
    printf("--------------------------------------\n");
    for(int i = 0 ; i < N ; i++){
        printf("%d\t%s\t%d\t%d\t%d\t%g\t%c\n", i+1, mhs->nama, mhs->tugas, mhs->uts, mhs->uas, mhs->akhir, mhs->grade);
        *mhs++;
    }
    printf("--------------------------------------\n");
    printf("Total Mahasiswa = %d\n\n", N);
    printf("Nilai tertinggi\n");
    printf("Nama = %s\n", rank->nama);
    printf("Nilai = %g\n\n", rank->nilai);

}
int main(){
    int N;
    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d", &N);
    data mhs[N];
    maks rank;
    rank.nilai = 0;
    input(N, mhs, &rank);
    tampil(N, mhs, &rank);

    return 0;
}