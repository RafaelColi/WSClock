#ifndef WSCLOCK_H
#define WSCLOCK_H

#include <stdlib.h>
#include <stdio.h>
#include "page.h"
#include "pagelist.h"

void miss(pagelist* pagelist, int id);

void wsclock(pagelist* pagelist, int id);

void load(page* page);

void write(page* page);
#endif