#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int d,m,y;
} date;

bool sameday(date day1, date day2){
    if(day1.d == day2.d && day1.m == day2.m && day1.y == day2.y){
        return true;
    }
    else
        return false;
}

int main(){
    date d1, d2;
    printf("masukin d1[dd/mm/yy];");
    scanf("%d/%d/%d", &d1.d, &d1.m, &d1.y);
    printf("masukin d2[dd/mm/yy];");
    scanf("%d/%d/%d", &d2.d, &d2.m, &d2.y);
    
    if(sameday(d1,d2)== true){
        printf("sama\n");
    }else{
        printf("beda\n");
    }
    return 0;
}