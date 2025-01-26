#ifndef HESAP_H
#define HESAP_H

typedef struct hesap {
    int sayi1;
    int sayi2;
    char karar;
    int sonuc;
    struct hesap *next; 
} hesap;


int topla(int a, int b);
int cikar(int a, int b);
int carpma(int a, int b);
int bolme(int a, int b);
int mod(int a, int b);
int neyapcam (char karar, int sayi1, int sayi2);
hesap *kayit_olustur(hesap*, int, int, char);

#endif