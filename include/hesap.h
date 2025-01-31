#ifndef HESAP_H
#define HESAP_H



typedef struct hesap {
    int sayi1;
    int sayi2;
    char karar;
    int sonuc;
    struct hesap *next; 
} hesap;



hesap *hesap_new(int, int, char);
hesap *hesap_append(hesap *, int, int, char);
hesap *hesap_delete(hesap *);
hesap *hesap_find(hesap *, int, int, char);
hesap *kayit(hesap *, int, int, char);




//hesap *kayit_olustur(hesap*, int, int, char);

#endif