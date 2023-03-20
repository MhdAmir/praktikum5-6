#include<stdio.h>


typedef struct {
    int d, m, y;
}Date;
typedef struct {
    Date bd;
}Student;
//sama 2
//lebih 3
//kurang 1
int isYounger(Student stud1, Student stud2){
    if(stud1.bd.d == stud2.bd.d && stud1.bd.m == stud2.bd.m && stud1.bd.y == stud2.bd.y){
        return 2;
    }
    else if(stud1.bd.y == stud2.bd.y){
        if(stud1.bd.m == stud2.bd.m){
            if(stud1.bd.d > stud2.bd.d){
                return 3;
            }else{
                return 1;
            }
        }
        else if(stud1.bd.m > stud2.bd.m){
            return 3;
        }else{
            return 1;
        }
    }
}
int main(){
    Student stud1, stud2;
    printf("masukkan tanggal lahir stud1[dd-mm-yyyy]\t:");
    scanf("%d-%d-%d", &stud1.bd.d, &stud1.bd.m, &stud1.bd.y);
    printf("masukkan tanggal lahir stud1[dd-mm-yyyy]\t:");
    scanf("%d-%d-%d", &stud2.bd.d, &stud2.bd.m, &stud2.bd.y);
    
    if(isYounger(stud1,stud2) == 1){
        printf("USIA >>> stud1 kurang dari stud2\n");
    }else if(isYounger(stud1,stud2) == 2){
        printf("USIA >>> stud1 sama stud2\n");
    }else if(isYounger(stud1,stud2) == 3){
        printf("USIA >>> stud1 lebih dari stud2");
    }
    return 0;
}