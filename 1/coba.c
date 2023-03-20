#include<stdio.h>
#include <stdlib.h>
int main () {
int *p, *q;
int *r; int *s;
p = (int*) malloc(sizeof(int));
r = p; *p = 5;
p = (int*) malloc(sizeof(int));
q = p; s = r; *q = *s + 1;
*r = *p * 2;
printf("*p = %d,*q = %d,*r = %d, *s = %d\n",*p, *q, *r, *s);
free(r); 
r = NULL;
free(q); 
q = NULL;
printf("*p = %d,*q = %p,*r = %p, *s = %d\n",*p, q, r, *s);

}