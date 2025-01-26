//while (isspace(karar = getchar())); 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/hesap.h"

int main(){


int kayitsayisi = 10;
int sayi1, sayi2,i;
char karar;



printf("işlem yapmak istediğiniz sayıları ve işlemi giriniz : \n");



hesap *ilk = (hesap *)malloc(sizeof(hesap));

scanf("%d", &sayi1);

while (isspace(karar = getchar())); 

scanf("%d", &sayi2);

kayit_olustur(ilk,sayi1, sayi2, karar);


/*while(getchar() != '\n'){
}
*/

}