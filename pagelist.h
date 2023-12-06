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
    int clear;
    int write;
} pagelist;

pagelist* createPagelist(int n);

void printPagelist(pagelist* pagelist);

void insertPage(page* page, pagelist* pagelist);

page* search(pagelist* pagelist, int id);

int isEmpty(pagelist* pagelist);

int isFull(pagelist* pagelist);

int size(pagelist* pagelist);

int cap(pagelist* pagelist);
#endif