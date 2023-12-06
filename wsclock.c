#include "wsclock.h"
#define TAU 13

void miss(pagelist* pagelist, int id) {
    page* page = createPage(id);
    insertPage(page, pagelist);
}

void search(pagelist* pagelist, int id) {
    if(pagelist == NULL) {
        return -1;
    }

    if(isEmpty(pagelist)) {
        miss(pagelist, id);
        return;
    } else {
        int index = pagelist->arrow;
        for(int i = 0; i < size(pagelist); i++) {
            page* temp = pagelist->pages[index];

            if(temp->id == id) {
                load();
                break;
            } 

            if(temp->R == 1) {
                temp->R = 0;
                index++;
            } else if(temp->R == 0) {
                if(temp->time > TAU && temp->M == 0) {
                    page* new = createPage(id);
                    insertPage(new, pagelist);
                } else if(temp->time > TAU && temp->M == 1) {
                    write();
                    index++;
                } 
            }

            index++;

            if(index == cap(pagelist)) {
                index = 0;
            }
        }
    }

    miss();
    return;
}

void load() {

}

void write() {

}