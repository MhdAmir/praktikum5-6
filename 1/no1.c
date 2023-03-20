#include<stdio.h>

struct data{
    int tugas, uts, uas, akhir;
    char nama[100], grade;
};
void input(int N, struct data *mhs){
    for(int i = 0; i < N; i++){
        printf("Mahasiswa ke-%d\n", i+1);
        printf("Nama\t\t:");
        scanf("%s", mhs[i].nama);
        fflush(stdin);
        printf("Nilai tugas\t\t:");
        scanf("%d", &mhs[i].tugas);
        fflush(stdin);
        printf("Nilai uts\t\t:");
        scanf("%d", &mhs[i].uts);
        fflush(stdin);
        printf("Nilai uas\t\t:");
        scanf("%d", &mhs[i].uas);
        fflush(stdin);
        printf("\n");
        mhs[i].akhir = (int)(mhs[i].tugas + mhs[i].uts + mhs[i].uas)/3; 
        if(mhs[i].akhir >= 80)
        mhs[i].grade = 'A';
        else if(mhs[i].akhir >=70)
        mhs[i].grade = 'B';
        else if(mhs[i].akhir >=60)
        mhs[i].grade = 'C';
        else if(mhs[i].akhir >=50)
        mhs[i].grade = 'D';
        else if(mhs[i].akhir < 50)
        mhs[i].grade = 'E';
    }   
}
void tampil(int N, struct data *mhs){
    printf("Daftar Nilai\n Mata kuliah konsep pemrograman\n");
    printf("--------------------------------------\n");
    printf("No\tNama\n\t\tMahasiswa\tTugas\tUTS\tUAS\tAkhir\tGrade\n");
    printf("--------------------------------------\n");
    for(int i = 0 ; i < N ; i++){
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%c\n", i+1, mhs[i].nama, mhs[i].tugas, mhs[i].uts, mhs[i].uas, mhs[i].akhir, mhs[i].grade);
    }
    printf("--------------------------------------\n");
    printf("Total Mahasiswa = %d\n", N);
}
int main(){
    int N;
    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d", &N);
    struct data mhs[N];
    input(N, &mhs[0]);
    tampil(N, &mhs[0]);

    return 0;
}