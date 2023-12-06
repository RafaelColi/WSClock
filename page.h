#ifndef PAGE_H
#define PAGE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int R;
    int M;
    int time;
} page;

page* createPage(int id);

void printPage(page* page);

#endif