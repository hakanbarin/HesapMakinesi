#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hesap.h"


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
    
    int a;
    int (*islem[5])(int, int) = {topla, cikar, carpma, bolme, mod};

        if (karar == '+'){
            a = islem[0](sayi1, sayi2);
            printf("%d\n", a);
            return a;
        }
        else if (karar == '-'){
            a = islem[1](sayi1, sayi2);
            printf("%d\n", a);
            return a;
        }

        else if (karar == '*'){
            a = islem[2](sayi1, sayi2);
            printf("%d\n", a);
            return a;
        }
        else if (karar == '/')
            if(sayi2 == 0)
                printf("0 a bölünmez la\n");
            else{
            a = islem[3](sayi1, sayi2);
            printf("%d\n", a);
            return a;
        }

        else if (karar == '%')
            if(sayi2 == 0)
                printf("0 a bölünmez la\n");
            else
            {
            a = islem[4](sayi1, sayi2);
            printf("%d\n", a);
            return a;
        }
        else
            printf("selametle usta \n");
}


hesap *kayit_olustur(hesap* agac, int gelen1, int gelen2, char gelenkarar) {

        hesap *yeni = (hesap *)malloc(sizeof(hesap));
        yeni->next = NULL;
        yeni->sayi1 = gelen1;
        yeni->sayi2 = gelen2;
        yeni->karar = gelenkarar;
        yeni->sonuc = neyapcam(gelenkarar, gelen1, gelen2);
        printf("%d\n", yeni->sonuc);
        return yeni;
}


/*
hesap *kayit_olustur(hesap* agac, int gelen1, int gelen2, char gelenkarar){
    hesap *iter = agac;
    while(iter != NULL){
        if((gelen1 == iter->sayi1 && gelen2 == iter->sayi2) || (gelen1 == iter->sayi2 && gelen2 == iter->sayi1)) {
            printf("bu islemi daha önce yaptin la sonuc %d\n", iter->sonuc);
            return agac;
        }
        iter = iter->next;
    }

    if(agac == NULL){
        hesap * yeni = (hesap *)malloc(sizeof(hesap));
        yeni->sayi1 = gelen1;
        yeni->sayi2 = gelen2;
        yeni->karar = gelenkarar;
        yeni->sonuc = neyapcam(gelenkarar, gelen1, gelen2);
        printf("sonuc %d\n", yeni->sonuc);
        yeni->next = NULL;
        return yeni;
    }
        
    else if(agac->next == NULL){
        agac->next = kayit_olustur(agac->next, gelen1, gelen2, gelenkarar);
        return agac;
    }
    else{
        hesap * iter = agac;
        while(iter->next != NULL){
            iter = iter->next;
        }
        iter->next = kayit_olustur(iter->next, gelen1, gelen2, gelenkarar);
        return agac;
    }
    
}

    
*/
