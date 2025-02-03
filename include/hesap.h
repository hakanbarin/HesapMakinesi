#ifndef HESAP_H
#define HESAP_H


typedef struct hesap {
    int sayi1;
    int sayi2;
    int (*islem)(int,int);
    int sonuc;
    struct hesap *next; 
} hesap;



hesap *hesap_new(int, int, int (*islem)(int, int));
hesap *hesap_append(hesap *, hesap*);
void hesap_delete(hesap *);
hesap *hesap_find(hesap *, int, int, int (*islem)(int, int));
// hesap *kayit(hesap *, int, int, char);




//hesap *kayit_olustur(hesap*, int, int, char);

#endif