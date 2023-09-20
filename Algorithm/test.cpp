#include <stdint.h>
#include <stdio.h>
#include <iostream>

int main(void){
    char t = 0b01111111;
    char a = 1;
    char b = 128;

    printf("%d\n", (t + a));
    printf("%d\n", (char)(t + a));

    printf("%d\n", (b + a));
    printf("%d\n", (char)(b + a));

    printf("%d\n", (t + a) == b);
    printf("%d\n", (char)(t + a) == b);
    printf("%d\n", (t + a + a));
}