#ifndef PAGELIST_H
#define PAGELIST_H

#include "page.h"

typedef struct {
    int size;
    page** pages;
    int cap;
    int begin;
    int end;
    int arrow;
} pagelist;

void insertPage(page* page, pagelist* pagelist);


#endif