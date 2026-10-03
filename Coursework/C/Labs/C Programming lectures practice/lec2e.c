#include <stdio.h>
int main() {
// This program demonstrates type conversion in C.
printf("Problem 1 ");
    int a1=10,b1=3;
    float c1;
    c1 = a1/b1;
    printf("The value of c1 is %f\n",c1);

    printf("Problem 2 ");
    int a2=10;
    float b2=3;
    float c2;
    c2 = a2/b2;
    printf("The value of c2 is %f\n",c2);

    printf("Problem 3 ");
    int a3=10,b3=3;
    float c3;
    c3 = (float)a3/b3;
    printf("The value of c3 is %f\n",c3);

    printf("Problem 4 ");
    int a4=10,b4=3;
    float c4;
    c4 = a4/(float)b4;
    printf("The value of c4 is %f\n",c4);

    printf("Problem 5 ");
    unsigned int a5=1000;
    int b5=-1;
    if(a5>b5)
        printf("a5 is BIG\n");
    else
        printf("a5 is SMALL\n");

    printf("Problem 6 ");
    int a6=1000;
    int b6=-1;
    if(a6>b6)
        printf("a6 is BIG\n");
    else
        printf("a6 is SMALL\n");

    printf("Problem 7 ");
    unsigned int a7=1000;
    unsigned int b7=-1;
    if(a7>b7)
        printf("a7 is BIG\n");
    else
        printf("a7 is SMALL\n");

    printf("Problem 8 ");
    int a8=1000;    
    unsigned int b8=-1;
    if(a8>b8)
        printf("a8 is BIG\n");
    else
        printf("a8 is SMALL\n");

    printf("Problem 9 ");
    unsigned int a9=1000;
    if(a9>-1)
        printf("a9 is SMALL\n");
    else
        printf("a9 is BIG\n");

    printf("Problem 10 ");
    int a10=1000;
    if(a10>-1U)
        printf("a10 is BIG\n");
    else
        printf("a10 is SMALL\n");
    return 0;
}