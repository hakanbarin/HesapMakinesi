#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hesap.h"
#include "calculation.h"

// HESAPLAMA KISMI
static int topla(int a, int b)
{
    return a + b;
}

static int cikar(int a, int b)
{
    return a - b;
}

static int carpma(int a, int b)
{
    return a * b;
}

static int bolme(int a, int b)
{
    return a / b;
}

static int mod(int a, int b)
{
    return a % b;
}
// HESAPLAMA KISMI





// KARAR VERİLİP İŞLEM YAPILAN KISIM
static int (*neyapcam(char karar))(int,int)
{
    switch (karar)
    {
    case '+':
        return topla;
    
    case '-':
        return cikar;
    
    case '*':
        return carpma;
    
    case '/':
        return bolme;
    
    case '%':
        return mod;
    
    default:
        return NULL;
    }

}



/*
    int a;
    int (*islem[5])(int, int) = {topla, cikar, carpma, bolme, mod};

    if (karar == '+')
    {
        a = islem[0](sayi1, sayi2);
        printf("%d\n", a);
        return a;
    }
    else if (karar == '-')
    {
        a = islem[1](sayi1, sayi2);
        printf("%d\n", a);
        return a;
    }

    else if (karar == '*')
    {
        a = islem[2](sayi1, sayi2);
        printf("%d\n", a);
        return a;
    }
    else if (karar == '/')
        if (sayi2 == 0)
            printf("0 a bölünmez la\n");
        else
        {
            a = islem[3](sayi1, sayi2);
            printf("%d\n", a);
            return a;
        }

    else if (karar == '%')
        if (sayi2 == 0)
            printf("0 a bölünmez la\n");
        else
        {
            a = islem[4](sayi1, sayi2);
            printf("%d\n", a);
            return a;
        }
    else
        printf("yapacaginiz islemi yanlis girdiniz \n");
}
*/
// KARAR VERİLİP İŞLEM YAPILAN KISIM





// İNPUT ALIP FONKSİYONLARA GÖNDEREN KISIM
void get_inputs()
{
    hesap *ilk = NULL;
    int number1, number2, calculation_number;
    char decision;

    printf("kac islem \n");
    scanf("%d", &calculation_number);

    while (calculation_number)
    {

        if (scanf("%d", &number1) != 1)
        {
            printf("1. sayiyi yanlis girdin\n");

            continue; // Döngünün başına dön
        }

        while(isspace(decision = getchar()));

        if (scanf("%d", &number2) != 1)
        {
            printf("2. sayiyi yanlis girdin\n");
            continue;
        }
        hesap *kontrol = hesap_find(ilk, number1, number2, neyapcam(decision));
        if(kontrol == NULL){
            hesap *yenihesap = hesap_new(number1, number2, neyapcam(decision));

            ilk = hesap_append(ilk, yenihesap);

            printf("%d %c %d %d\n",number1,decision,number2,yenihesap->sonuc);

            calculation_number--;
        }
/*
        if (kontrol !=NULL && kontrol == ilk){
            printf("%d",kontrol->sonuc);
            
        }
*/  
    }
hesap_delete(ilk);
}


void getinputs_forever(hesap** ilk)
{
    int number1, number2;
    char decision;


    while (1)
    {

        if (scanf("%d", &number1) != 1)
        {
            printf("1. sayiyi yanlis girdin\n");

            continue; // Döngünün başına dön
        }

        while(isspace(decision = getchar()));

        if (scanf("%d", &number2) != 1)
        {
            printf("2. sayiyi yanlis girdin\n");
            continue;
        }
        hesap *kontrol = hesap_find(*ilk, number1, number2, neyapcam(decision));
        if(kontrol == NULL){
            hesap *yenihesap = hesap_new(number1, number2, neyapcam(decision));

            *ilk = hesap_append(*ilk, yenihesap);

            printf("%d %c %d %d\n",number1,decision,number2,yenihesap->sonuc);
        }
/*
        if (kontrol !=NULL && kontrol == ilk){
            printf("%d",kontrol->sonuc);
            
        }
*/  
    }
}

// İNPUT ALIP FONKSİYONLARA GÖNDEREN KISIM

