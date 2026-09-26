#include <stdio.h>
int main() {
// This program demonstrates type conversion in C.
printf("Problem 1");
    int a1=10,b1=3;
    float c1;
    c1 = a1/b1;
    printf("The value of c1 is %f\n",c1);

    printf("Problem 2");
    int a2=10;
    float b2=3;
    float c2;
    c2 = a2/b2;
    printf("The value of c2 is %f\n",c2);

    printf("Problem 3");
    int a3=10,b3=3;
    float c3;
    c3 = (float)a3/b3;
    printf("The value of c3 is %f\n",c3);

    printf("Problem 4");
    int a4=10,b4=3;
    float c4;
    c4 = a4/(float)b4;
    printf("The value of c4 is %f\n",c4);

    return 0;
}