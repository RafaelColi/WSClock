#include "pagelist.h"

page* search(pagelist* pagelist, int id) {
    if(pagelist == NULL) {
        return NULL;
    }
    if(isEmpty(pagelist)) {
        return NULL;
    } else {
        int index = pagelist->begin;
        for(int i = 0; i < size(pagelist); i++) {
            page* temp = pagelist->pages[index];

            if(temp->id == id) {
                return temp;
            } 

            index++;

            if(index == cap(pagelist)) {
                index = 0;
            }
        }
    }

    return NULL;
}

int cap(pagelist* pagelist) {
    return pagelist->cap;
}

pagelist* createPagelist(int n) {
    pagelist* temp = (pagelist*) calloc(1, sizeof(pagelist));
    temp->pages = (page**) calloc(n, sizeof(page*));
    temp->cap = n;
    temp->begin = -1;
    return temp;
}

int isFull(pagelist* pagelist) {
    if(pagelist == NULL) {
        return 0;
    }

    if(size(pagelist) == cap(pagelist)) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(pagelist* pagelist) {
    if(pagelist == NULL) {
        return -1;
    }

    if(size(pagelist) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void printPagelist(pagelist* pagelist) {
    if(pagelist == NULL || isEmpty(pagelist)) {
        return;
    } else {
        printf("PRINTING PAGELIST...\n");
        int index = pagelist->begin;
        for(int i = 0; i < size(pagelist); i++) {
            printPage(pagelist->pages[index]);
            index++;

            if(index == cap(pagelist)) {
                index = 0;
            }
        }
    }
}

void insertPage(page* page, pagelist* pagelist) {
    if(pagelist == NULL) {
        return;
    }

    if(isEmpty(pagelist)) {
        pagelist->begin = 0;

        pagelist->pages[pagelist->end] = page;
        pagelist->end += 1;
        return;
    }

    if(isFull(pagelist)) {
        pagelist->pages[pagelist->arrow] = page;
    } else {
        pagelist->pages[pagelist->end] = page;
        pagelist->end += 1;

        if(pagelist->end == cap(pagelist)) {
            pagelist->end = 0;
        }
    }

    return;
}

void liberarpagelist(pagelist** pagelist) {
    if(pagelist == NULL) {
        return;
    }

    free((*pagelist)->pages);
    free(*pagelist);
    *pagelist = NULL;
}


int size(pagelist* pagelist) {
    if(pagelist->begin == -1) {
        return 0;
    }

    if(pagelist->end > pagelist->begin) {
        return pagelist->end - pagelist->begin;
    } else {
        return pagelist->end - pagelist->begin + cap(pagelist);
    }
}