#include "wsclock.h"
#define TAU 13

void miss(pagelist* pagelist, int id) {
    page* page = createPage(id);
    insertPage(page, pagelist);
}

void wsclock(pagelist* pagelist, int id) {
    if(isEmpty(pagelist) || !isFull(pagelist)) {
        miss(pagelist, id);
        return;
    } else {
        page* temp = search(pagelist, id);

        if(temp != NULL) {
            load(temp);
            return;
        }

        int index = pagelist->arrow;
        for(int i = 0; i < size(pagelist); i++) {
            temp = pagelist->pages[index];

            if(temp->R == 1) {
                temp->R = 0;
                temp->time += 1;
            } else if(temp->R == 0) {
                if(temp->time > TAU && temp->M == 0) {
                    miss(pagelist, id);
                    return;
                } else if(temp->time > TAU && temp->M == 1) {
                    write(temp);
                } 
            }

            index++;

            if(index == cap(pagelist)) {
                index = 0;
            }

            pagelist->arrow = index;
        }
    }

    return;
}

void load(page* page) {
    page->R = 1;
    page->time += 1;

    return;
}

void write(page* page) {
    printf("Escrevendo no disco");

    page->M = 0;
}