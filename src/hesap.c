#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hesap.h"

hesap *hesap_new(int sayi1, int sayi2, char karar)
{
    hesap *new = (hesap *)malloc(sizeof(hesap));
    new->sayi1 = sayi1;
    new->sayi2 = sayi2;
    new->karar = karar;
    new->sonuc = neyapcam(karar, sayi1, sayi2);
    new->next = NULL;
    return new;
}

hesap *hesap_append(hesap *start, int number1, int number2, char decision)
{

    hesap *iter = start;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = hesap_new(number1, number2, decision);
    return start;
}

hesap *hesap_delete(hesap *start)
{
    hesap *iter = start; // iter 1 gidecek start temizlenecek sonra itere eşit olacak
    while (iter->next != NULL)
    {
        iter = iter->next;
        free(start);
        start = iter;
    }
    //https://stackoverflow.com/questions/58757213/if-two-pointers-point-to-the-same-memory-address-do-you-only-need-to-use-freep
    free(iter);
    return NULL;
}

hesap *hesap_find(hesap *start, int number1, int number2, char decision)
{

    hesap *iter = start;
    while (iter->next != NULL)
    {
        if (((number1 == iter->sayi1 && number2 == iter->sayi2) || (number1 == iter->sayi2 && number2 == iter->sayi1)) && (decision == iter->karar))
        {
            printf("bu islemi daha önce yaptin: SONUC %d\n", iter->sonuc);
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
}

hesap *kayit(hesap *coming_node, int number1, int number2, char decision)
{   
    hesap *find = hesap_find(coming_node, number1, number2, decision);
    if(find != NULL){
        return find;
    }

    if (coming_node == NULL){

        coming_node = hesap_new(number1, number2, decision); // coming_node'a adres atandı.
        return coming_node;
    }

    else if (coming_node->next == NULL){

        coming_node->next = hesap_new(number1, number2, decision);
        return coming_node;
    }
    else

        hesap_append(coming_node, number1, number2, decision);
        return coming_node; 
}

// CACHE KISMI
/*
hesap *kayit_olustur(hesap *agac, int gelen1, int gelen2, char gelenkarar)
{

    hesap *iter = agac;
    while (iter != NULL)
    {
        if (((gelen1 == iter->sayi1 && gelen2 == iter->sayi2) || (gelen1 == iter->sayi2 && gelen2 == iter->sayi1)) && (gelenkarar == iter->karar))
        {
            printf("bu islemi daha önce yaptin: SONUC %d\n", iter->sonuc);
            return NULL;
        }
        iter = iter->next;
    }

    if (agac == NULL)
    {
        hesap *yeni = (hesap *)malloc(sizeof(hesap));
        yeni->next = NULL;
        yeni->sayi1 = gelen1;
        yeni->sayi2 = gelen2;
        yeni->karar = gelenkarar;
        yeni->sonuc = neyapcam(gelenkarar, gelen1, gelen2);
        return yeni;
    }
    else if (agac->next == NULL)
    {
        agac->next = kayit_olustur(agac->next, gelen1, gelen2, gelenkarar);
        return agac;
    }
    else
    {
        hesap *iter = agac;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = kayit_olustur(iter->next, gelen1, gelen2, gelenkarar);
        return agac;
    }
}

// CACHE KISMI

*/
//---------------------------------------

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
