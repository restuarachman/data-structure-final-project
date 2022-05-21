#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include "child.h"

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define item(P) P->item

typedef struct elmlist_parent *address_parent;

struct elmlist_parent{
    string info;
    address_parent next;
    List_child item;
};

struct List_parent {
    address_parent first;
};

void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertParent(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
void deleteParent(List_parent &L, address_parent Q, address_parent &P);

address_parent alokasi_parent(string x);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, string x);
void printInfo(List_parent L);

#endif // PARENT_H_INCLUDED
