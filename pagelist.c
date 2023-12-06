#include "pagelist.h"

int search(pagelist* pagelist, int e) {
    if(pagelist == NULL) {
        return -1;
    }

    if(isEmpty(pagelist)){
        return 0;
    } else {
        int index = pagelist->arrow;
        for(int i = 1; i < size(pagelist); i++) {
            if(pagelist->pages[index] == e) {
                return 1;
            }
            index++;

            if(index == cap(pagelist)) {
                index = 0;
            }
        }
    }
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

    if(size(pagelist) == pagelist->cap) {
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
        for(int i = 1; i <= size(pagelist); i++) {
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

int insertPage(pagelist* pagelist, int e) {
    if(isFull(pagelist)) {
        return 0;
    } 

    if(pagelist == NULL) {
        return -1;
    }

    if(isEmpty(pagelist)) {
        pagelist->begin = pagelist->end = 0;
    }

    pagelist->pages[pagelist->end] = e;
    pagelist->end += 1;

    if(pagelist->end == cap(pagelist)) {
        pagelist->end = 0;
    }

    return 1;
}

void liberarpagelist(pagelist** pagelist) {
    if(pagelist == NULL) {
        return;
    }

    free((*pagelist)->pages);
    free(*pagelist);
    *pagelist = NULL;
}

int removePage(pagelist* pagelist, int *v) {
    if(pagelist == NULL || v == NULL) {
        return -1;
    }

    if(isEmpty(pagelist)) {
        return 0;
    }

    *v = pagelist->pages[pagelist->begin];
    pagelist->begin++;

    if(pagelist->begin == cap(pagelist)) {
        pagelist->begin = 0;
    }

    if(pagelist->begin == pagelist->end) {
        pagelist->begin = -1;
        pagelist->end = 0;
    }
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