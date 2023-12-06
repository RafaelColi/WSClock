#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "wsclock.h"

int main() {
    time_t t;
    srand((unsigned) time(&t));

    int n = 5, id;


    pagelist* pagelist = createPagelist(n);
    while(1 == 1) {
        id = rand() % 10;
        printf("Processo requistando pagina ID %d\n", id);
        wsclock(pagelist, id);
        printPagelist(pagelist);
        getchar();
    }

    return 0;
}