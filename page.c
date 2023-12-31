#include "page.h"
#include <time.h>

page* createPage(int id) {
    page* temp = (page*) calloc(1, sizeof(page));

    time_t t;
    srand((unsigned) time(&t));

    temp->id = id;
    temp->M = rand() % 2;
    temp->R = rand() % 2;

    return temp;
}

void printPage(page* page) {
    printf("[ID: %d| TIME: %d| R: %d| M: %d]\n", page->id, page->time, page->R, page->M);
    return;
}