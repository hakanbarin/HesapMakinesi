#ifndef HESAP_H
#define HESAP_H



typedef struct hesap {
    int sayi1;
    int sayi2;
    char karar;
    int sonuc;
    struct hesap *next; 
} hesap;


void get_inputs();
int topla(int, int);
int cikar(int, int );
int carpma(int, int);
int bolme(int, int);
int mod(int, int);
int neyapcam (char karar, int sayi1, int sayi2);
hesap *kayit_olustur(hesap*, int, int, char);

#endif