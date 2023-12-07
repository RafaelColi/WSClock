#include "wsclock.h"
#define TAU 5

void miss(pagelist* pagelist, int id) {
    printf("Inserindo nova pagina na lista\n");
    page* page = createPage(id);
    insertPage(page, pagelist);
    printPage(page);
}

void wsclock(pagelist* pagelist, int id) {
    page* temp = search(pagelist, id);

    if(temp != NULL) {
        load(temp);
        return;
    }
    
    if(isEmpty(pagelist) || !isFull(pagelist)) {
        printf("Falta de pagina. Ha espaco na lista\n");
        miss(pagelist, id);
        return;
    } else {
        int index = pagelist->arrow;
        for(int i = 0; i < size(pagelist); i++) {
            temp = pagelist->pages[index];
            if(temp->M == 0) {
                pagelist->clear = index;
            }

            if(temp->R == 1) {
                temp->R = 0;
                temp->time += 1;
            } else if(temp->R == 0) {
                if(temp->time > TAU && temp->M == 0) {
                    miss(pagelist, id);
                    return;
                } else if(temp->time > TAU && temp->M == 1) {
                    write(temp);
                    pagelist->write += 1;
                } 
            }

            index++;

            if(index == cap(pagelist)) {
                index = 0;
            }

            pagelist->arrow = index;
            printf("Ponteiro -> ");
            printPage(pagelist->pages[pagelist->arrow]);
        }

        if(pagelist->write) {
            printf("Paginas no working set. Escrita escalonada. Repetindo varredura\n");
            wsclock(pagelist, id);
            pagelist->write = 0;
        } else {
            printf("Paginas no working set. Sem escrita escalonada\n");
            int aux = pagelist->arrow;
            pagelist->arrow = pagelist->clear;
            miss(pagelist, id);
            pagelist->arrow = aux;
        }
    }

    return;
}

void load(page* page) {
    printf("Pagina encontrada na lista. Carregando pagina\n");
    printPage(page);
    page->R = 1;
    page->time += 1;

    return;
}

void write(page* page) {
    printf("Escrevendo pagina no disco\n");
    printPage(page);

    page->M = 0;
}