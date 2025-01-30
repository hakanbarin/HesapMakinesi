#ifndef HESAP_H
#define HESAP_H



typedef struct hesap {
    int sayi1;
    int sayi2;
    char karar;
    int sonuc;
    struct hesap *next; 
} hesap;




//hesap *kayit_olustur(hesap*, int, int, char);

#endif