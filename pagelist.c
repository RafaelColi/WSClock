#include "pagelist.h"

int search(pagelist* pagelist, page* page) {
    
}

int cap(pagelist* pagelist) {
    return pagelist->cap;
}

pagelist* createPagelist(int n) {
    pagelist* temp = (pagelist*) calloc(1, sizeof(pagelist));
    temp->pages = (page**) calloc(n, sizeof(page*));
    temp->cap = n;
    temp->begin = -1;
    temp->end = 0;
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

void exibirpagelist(pagelist* pagelist) {
    if(pagelist == NULL || isEmpty(pagelist)) {
        return;
    } else {
        int index = pagelist->begin;
        for(int i = 0; i < size(pagelist); i++) {
            printf("%d ", pagelist->pages[index]);
            index++;

            if(index == cap(pagelist)) {
                index = 0;
            }
        }
    }
}

void imprimirpagelistNVezes(pagelist* pagelist, int n) {
    if(pagelist == NULL) {
        return;
    }

    if(isEmpty(pagelist)){
        printf("pagelist Vazia");
    } else {
        printf("[");
        for(int i = 1; i <= n; i++) {
            int index = pagelist->begin;
            for(int j = 1; j <= size(pagelist); j++) {
                if(i == n && j == size(pagelist)) {
                    printf("%d]", pagelist->pages[index]);
                } else {
                    printf("%d, ", pagelist->pages[index]);
                }

                index++;

                if(index == cap(pagelist)) {
                    index = 0;
                }
            }
        }
    }
}

void insertPage(page* page, pagelist* pagelist) {
    if(isFull(pagelist)) {
        return;
    } 

    if(pagelist == NULL) {
        return;
    }

    if(isEmpty(pagelist)) {
        pagelist->begin = pagelist->end = 0;
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