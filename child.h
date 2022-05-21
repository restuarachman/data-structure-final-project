#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct elmlist_child *address_child;

struct elmlist_child{
    string info;
    address_child next;
    address_child prev;
};

struct List_child{
    address_child first;
    address_child last;
};

void createList(List_child &L);
address_child alokasi_child(string x);
void dealokasi(address_child &P);
void insertLast(List_child &L, address_child P);
void insertChild(List_child &L, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(address_child Prec, address_child &P);
void deleteChild(List_child &L, address_child P, address_child &Q);
address_child findElm(List_child L, string x);
void printInfo(List_child L);
int hitungChild(List_child L);

#endif // CHILD_H_INCLUDED
