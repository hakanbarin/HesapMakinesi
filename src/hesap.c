#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hesap.h"
#include "calculation.h"


hesap *hesap_new(int sayi1, int sayi2, int (*islem)(int, int))
{
    hesap *new = (hesap *)malloc(sizeof(hesap));
    new->sayi1 = sayi1;
    new->sayi2 = sayi2;
    new->islem = islem;
    new->sonuc = new->islem(new->sayi1, new->sayi2);
    new->next = NULL;
    return new;
}

hesap *hesap_append(hesap *start,hesap* tail)
{
    if(start == NULL){
        return tail;
    }
    start->next = hesap_append(start->next, tail);
    return start;
}

void hesap_delete(hesap *start)
{
    //recursive
    if(start != NULL){
        hesap_delete(start->next);
        printf("duzgun sekilde temizlendi\n");
        free(start);
    }
    /*   İTERATİF YÖNTEM
    hesap *iter;
    while(start != NULL){
        iter = start;
        start = start->next;
        free(iter);
    }
    */
}

hesap *hesap_find(hesap *start, int number1, int number2, int (*islem)(int, int))
{
    if(start == NULL){
        return NULL;
    }
    if(((number1 == start->sayi1 && number2 == start->sayi2) || (number1 == start->sayi2 && number2 == start->sayi1)) && (islem == start->islem)) {
        printf("bu islemi daha önce yaptin: SONUC %d\n", start->sonuc);
        return start;
    }
    return hesap_find(start->next, number1, number2, islem);
/*
    hesap *iter = start;
    while (iter != NULL)
    {
        if (((number1 == iter->sayi1 && number2 == iter->sayi2) || (number1 == iter->sayi2 && number2 == iter->sayi1)) && (decisionf == iter->islem))
        {
            printf("bu islemi daha önce yaptin: SONUC %d\n", iter->sonuc);
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
*/
}


/*
hesap *kayit(hesap *coming_node, int number1, int number2, char decision)
{   
    hesap *find = hesap_find(coming_node, number1, number2, neyapcam(decision));
    
    if(find != NULL){
        return find;
    }
    return hesap_append(coming_node, number1, number2, neyapcam(decision));
    if (coming_node == NULL){

        coming_node = hesap_new(number1, number2, decision); // coming_node'a adres atandı.
        return coming_node;
    }
    else {
        return hesap_append(coming_node, number1, number2, decision);
    }
}
*/






    //https://stackoverflow.com/questions/58757213/if-two-pointers-point-to-the-same-memory-address-do-you-only-need-to-use-freep


// CACHE KISMI
/*
hesap *kayit_olustur(hesap *agac, int gelen1, int gelen2, char gelenkarar)
{

    hesap *iter = agac;
    while (iter != NULL)
    {
        if (((gelen1 == iter->sayi1 && gelen2 == iter->sayi2) || (gelen1 == iter->sayi2 && gelen2 == iter->sayi1)) && (gelenkarar == iter->islem))
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
        yeni->islem = gelenkarar;
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
        yeni->islem = gelenkarar;
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
