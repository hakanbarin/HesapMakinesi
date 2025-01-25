#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int topla(int a, int b){
    return a + b;
}


int cikar(int a, int b){
    return a - b;
}


int carpma(int a, int b){
    return a * b;
}


int bolme(int a, int b){
    return a / b;
}

int mod(int a, int b){
    return a % b;
}

int neyapcam (char karar, int sayi1, int sayi2){
int (*islem[5])(int, int) = {topla, cikar, carpma, bolme, mod};
if (karar == '+')
    printf("%d\n", islem[0](sayi1, sayi2));

else if (karar == '-')
    printf("%d\n", islem[1](sayi1, sayi2));

else if (karar == '*')
    printf("%d\n", islem[2](sayi1, sayi2));

else if (karar == '/')
    if(sayi2 == 0)
        printf("0 a bölünmez la\n");
    else
        printf("%d\n", islem[3](sayi1, sayi2));

else if (karar == '%')
    if(sayi2 == 0)
        printf("0 a bölünmez la\n");
    else
        printf("%d\n", islem[3](sayi1, sayi2));
else
    printf("emin misin? \n");
}
