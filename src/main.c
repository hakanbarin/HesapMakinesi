//while (isspace(karar = getchar())); 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculation.h"
#include "hesap.h"
#include <signal.h>
hesap *global = NULL;

void temizleme(int sayi){
    printf("cikiyorum\n ");
    hesap_delete(global);
    exit(EXIT_SUCCESS);
}



int main(){
    signal(SIGINT ,temizleme);
    // get_inputs();
    getinputs_forever(&global);




/*while(getchar() != '\n'){
}
*/

}

//basit tcp serverı, baslagıç echo server, client

//leatcodeda kod yaz