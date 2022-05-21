#include "child.h"
#include "set.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}
address_child alokasi_child(string x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void dealokasi(address_child &P) {
    P = NULL;
}

void insertLast(List_child &L, address_child P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void insertChild(List_child &L, address_child P) {
    if(findElm(L, info(P)) != NULL) {
        cout << "Gagal menambahkan, Barang sudah ada" << endl;
    } else  {
        insertLast(L, P);
        cout << "(" << info(P) << ") berhasil ditambahkan" << endl;
    }
}

void deleteFirst(List_child &L, address_child &P) {
    if(first(L) == last(L)) {
        P = first(L);
        first(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}
void deleteLast(List_child &L, address_child &P) {
    P = last(L);
    last(L) = prev(P);
    next(last(L)) = NULL;
    prev(P) = NULL;
}
void deleteAfter(address_child Prec, address_child &P) {
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteChild(List_child &L, address_child P, address_child &Q) {
    if(first(L) == NULL) {
        cout << "Data Barang Kosong" << endl;
    } else if(first(L) == last(L)) {
        deleteFirst(L, Q);
    } else {
        if(P == first(L)) {
            deleteFirst(L, Q);
        } else if(P == last(L)) {
            deleteLast(L, Q);
        } else {
            address_child Prec = first(L);
            while(next(Prec) == P) {
                Prec = next(Prec);
            }
            deleteAfter(Prec, Q);
        }
    }
}
address_child findElm(List_child L, string x) {
    address_child P = first(L);
    while(P != NULL) {
        if(lowercase(info(P)) == lowercase(x)) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
void printInfo(List_child L) {
    if(first(L) == NULL) {
        cout << "kosong" << endl;
    } else {
        address_child P = first(L);
        while(P != NULL) {
            cout << "(" << info(P)  << ")";
            if(next(P) != NULL) {
                cout << ", ";
            }
            P = next(P);
        }
        cout << endl;
    }
}

int hitungChild(List_child L) {
    address_child P = first(L);
    int i = 0;
    while(P != NULL) {
        i++;
        P = next(P);
    }
    return i;
}
