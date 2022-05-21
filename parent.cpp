#include "parent.h"
#include "set.h"

void createList(List_parent &L) {
    first(L) = NULL;
}
address_parent alokasi_parent(string x) {
    address_parent P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(item(P));
    return P;
}
void dealokasi(address_parent &P) {
    P = NULL;
}
void insertLast(List_parent &L, address_parent P) {
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = first(L);
    } else {
        address_parent Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}
void insertParent(List_parent &L, address_parent P) {
    if(findElm(L, info(P)) != NULL) {
        cout << "Gagal menambahkan, Toko sudah ada" << endl;
    } else {
        insertLast(L, P);
    }
}
void deleteFirst(List_parent &L, address_parent &P) {
    if(next(first(L)) == first(L)) {
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    } else {
        P = first(L);
        address_parent Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        first(L) = next(P);
        next(Q) = first(L);
        next(P) = NULL;
    }
}
void deleteLast(List_parent &L, address_parent &P) {
    address_parent Q = first(L);
    while(next(next(Q)) != first(L)) {
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = first(L);
    next(P) = NULL;
}
void deleteParent(List_parent &L, address_parent Q, address_parent &P) {
    if(first(L) == NULL) {
        cout << "data toko kosong" << endl;
    } else if(next(first(L)) == first(L)) {
        deleteFirst(L, P);
    } else {
        if(Q == first(L)) {
            deleteFirst(L, P);
        } else if(next(Q) == first(L)) {
            deleteLast(L, P);
        } else {
            address_parent Prec = first(L);
            while(next(Prec) != Q) {
                Prec = next(Prec);
            }
            deleteAfter(L, Prec, P);
        }
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P) {
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

address_parent findElm(List_parent L, string x) {
    if (first(L) != NULL) {
        address_parent P = first(L);
        do {
            if(lowercase(info(P)) == lowercase(x)) {
                return P;
            }
            P = next(P);
        } while(P != first(L));
    }
    return NULL;
}

void printInfo(List_parent L) {
    if(first(L) == NULL) {
        cout << "Data Toko Kosong" << endl;
    } else {
        address_parent P = first(L);
        cout << "Daftar Toko : " << endl;
        do {
            cout << "Nama toko : " << info(P) << endl;
            cout << "Barang    : ";
            printInfo(item(P));
            cout << endl;
            P = next(P);
        } while(P != first(L));
    }
}
