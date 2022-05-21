#include "parent.h"
#include "set.h"

List_parent toko;
List_child item;

// print dengan nomor barang
void pilihBarang(List_child L) {
    cout << "Barang : " << endl;
    address_child P = first(L);
    int i = 1;
    while(P != NULL) {
        cout << i++ << ". " << info(P) << endl;
        P = next(P);
    }
    cout << endl;
}

// print dengan nomor toko
void pilihToko(List_parent L) {
    cout << "Toko : " << endl;
    address_parent P = first(L);
    int i = 1;
    do{
        cout << i++ << ". " << info(P) << endl;
        P = next(P);
    } while(P != first(L));
    cout << endl;
}

// mengambil info element ke-num
string takeNumberBarang(List_child L, int num) {
    if(num > 0) {
        address_child P = first(L);
        num--;
        while(num-- && P != NULL) {
            P = next(P);
        }
        if(P != NULL) {
            return info(P);
        }
    }
    return "";
    // String tidak bisa mereturn null, jadi return ""
}

// mengambil element ke-num
address_parent takeNumberToko(List_parent L, int num) {
    if(num > 0) {
        address_parent P = first(L);
        if(num == 1) {
            return first(L);
        }
        num = num - 2;
        do {
            P = next(P);
        } while(P != first(L) && num--);
        if(P != first(L)) {
            return P;
        }
    }
    return NULL;
}

int main() {
    string pilih, str;
    int n;

    address_parent p1, pOut;
    address_child c1, c2, cOut;

    createList(toko);
    createList(item);

    // input output pilih
    menu(pilih);
    while(pilih != "0") {
        cout << endl;
        if(pilih == "1") {
            cout << "Tambah data toko : " << endl;
            cin.ignore();
            do {
                inputLetters(str, "Nama Toko : ");
                insertParent(toko, alokasi_parent(str));
                back(pilih, "Tambah data lagi ?");
            } while(pilih == "y");
            cin.ignore();
        } else if(pilih == "2") {
            cout << "Tambah data barang : " << endl;
            do {
                inputLetters(str, "Nama barang : ");
                insertChild(item, alokasi_child(str));
                back(pilih, "Tambah data lagi ?");
            } while(pilih == "y");
            cin.ignore();
        } else if(pilih == "3") {
            // terdapat beberapa pilihan lagi jika ingin menambahkan barang
            cout << "Tambah barang pada toko : " << endl;
            cout << "1. Tambah barang pada toko" << endl;
            cout << "2. Tambah toko pada barang" << endl;
            cout << "0. Kembali" << endl;
            cout << "pilih : ";
            cin >> pilih;
            cin.get();
            if(pilih == "1") {
                cout << "Hubungkan toko dengan barang : " << endl;
                printInfo(toko);
                if(first(toko) == NULL) {
                     cout << "mohon untuk tambahkan toko terlebih dahulu" << endl;
                } else {
                    // mencari toko yang di inputkan
                    cout << "pilih nama toko : ";
                    getline(cin, pilih);
                    p1 = findElm(toko, pilih);

                    // juka tidak null maka menjalankan proses pilih nomor
                    if(p1 != NULL && first(item) != NULL) {
                        // print nomor barang
                        pilihBarang(item);
                        // melakukan insertChild, berhenti ketika menekan -1
                        do {
                            inputNumber(n, "pilih no barang (tekan -1 untuk keluar) : ");
                            // melakukan pengambilan info element barang / nama barang sesuai nomor barang
                            str = takeNumberBarang(item, n);
                            if(str != "") {
                                // melakukan proses connect/insert
                                c1 = alokasi_child(str);
                                insertChild(item(p1), c1);
                            } else if(n != -1) {
                                cout << "Barang tidak ditemukan!" << endl;
                            }
                        } while(n != -1);
                        cin.ignore();
                    } else if(p1 == NULL) {
                        // jika nama toko tidak ditemukan
                        cout << "toko " << pilih << " tidak ditemuukan!" << endl;
                    } else {
                        // jika barang masih kosong
                        cout << "Barang masih kosong, mohon untuk tambahkan barang terlebih dahulu" << endl;
                    }
                }
            } else if(pilih == "2") {
                cout << "Tambah toko pada barang : " << endl;
                if(first(item) == NULL) {
                     cout << "Barang masih kosong, mohon untuk tambahkan barang terlebih dahulu" << endl;
                } else {
                    // memilih barang sesuai nomor yang di printkan
                    cout << "Barang : ";
                    printInfo(item);
                    cout << "pilih nama Barang : ";
                    getline(cin, str);

                    // mencari elment barand dengan info str di list item
                    c1 = findElm(item, str);
                    if(c1 == NULL) {
                        cout << str << " tidak ditemukan!" << endl;
                    } else {
                        // jika c1 ada, melakukan insert selama user menekan -1
                        pilihToko(toko);
                        do {
                            inputNumber(n, "pilih no barang (tekan -1 untuk keluar) : ");
                            p1 = takeNumberToko(toko, n);
                            if(p1 != NULL) {
                                // jika pilihan user valid/nomor barang ada maka melakukan insert / konek
                                c1 = alokasi_child(str);
                                insertChild(item(p1), c1);
                            } else if(n != -1) {
                                cout << "Toko tidak ditemukan!" << endl;
                            }
                        } while(n != -1);
                        cin.ignore();
                    }
                }
            } else if(pilih != "0") {
                // jika user melakukan input selain 1, 2, dan 0
                cout << "Pilihan Tidak Valid!" << endl;
            }

        } else if(pilih == "4") {
            cout << "Hapus data toko : " << endl;
            if(first(toko) != NULL) {
                cout << "nama toko : ";
                cin.ignore();
                getline(cin, str);
                p1 = findElm(toko, str);
                if(p1 != NULL) {
                    deleteParent(toko, p1, pOut);
                    dealokasi(pOut);
                } else {
                    cout << str << " tidak ditemukan!" << endl;
                }
            } else {
                // *didalam procedure printInfo jika toko kosong maka akan mengoutpukan "toko kosong"
                printInfo(toko);
                cin.ignore();
            }

        } else if(pilih == "5") {
            // nomor 1 hanya melakukan disconect pada barang dan toko
            // nomor 2 menghapus barang sehingga jika barang tsb ada di toko maka barang di toko tsb akan ikut terhapus
            cout << "Hapus data barang : " << endl;
            cout << "1. Hapus barang pada toko tertentu" << endl;
            cout << "2. Hapus barang pada semua toko" << endl;
            cout << "0. Kembali" << endl;
            cout << "Pilih : ";
            cin >> pilih;

            if(pilih == "1") {
                  // agar getline dibawahnya bisa terbaca
                cin.ignore();
                // user menginputkan nama toko lalu melakukan pencarian nama toko pada list toko
                if(first(toko) != NULL) {
                    cout << "Nama Toko : ";
                    getline(cin, str);
                    p1 = findElm(toko, str);
                    if(p1 == NULL) {
                        cout << "Toko tidak ditemukan!" << endl;
                    } else if(first(item(p1)) == NULL) {
                        cout << "Barang pada toko " << str << " masih kosong" << endl;
                    } else {
                        // jika p1 ditemukan pada list toko maka user akan diminta melakukan input nama barang
                        // lalu prgoram akan melakukan pencarian barang yang diinputkan user pada list item;
                        cout << "Barang : ";
                        printInfo(item(p1));
                        cout << "Nama Barang : ";
                        getline(cin, str);
                        c1 = findElm(item(p1), str);

                        if(c1 != NULL) {
                            deleteChild(item(p1), c1, cOut);
                        } else {
                            cout << str << " tidak ditemukan!" << endl;
                        }
                    }
                } else {
                    cout << "data toko kosong " << endl;
                }

            } else if(pilih == "2") {
                // nomor 2 menghapus barang sehingga barang yang ada ditoko tertentu ikut terhapus
                // print daftar barang pada list item
                cout << "Barang : ";
                printInfo(item);

                // jika barang tidak kosong
                if(first(item) != NULL) {
                    // input nama barang

                    cout << "Nama barang : ";
                    cin.ignore();
                    getline(cin, str);

                    // cari di list item
                    c1 = findElm(item, str);

                    if(c1 != NULL) {
                        // jika c1 ketemu hapus pada list item;
                        deleteChild(item, c1, cOut);
                        dealokasi(cOut);

                        // proses dibawah ini melakukan penghapusan item pada toko (item(toko)) yang memiliki nama (str)
                        if(first(toko) != NULL) {
                            p1 = first(toko);
                            // melakukan pencarian dimuai dari first list item toko
                            do {
                                c1 = findElm(item(p1), str);

                                // jika pada p1 terdapat item dengan info = str maka lakukan delete item tsb
                                if(c1 != NULL) {
                                    deleteChild(item(p1), c1, cOut);
                                    dealokasi(cOut);
                                }
                                p1 = next(p1);
                            } while(p1 != first(toko));
                        }
                    } else {
                        cout << str << " tidak ditemukan!" << endl;
                    }
                } else {
                    cin.ignore();
                }
            } else if(pilih != "0") {
                cout << "Pilihan Tidak Valid!" << endl;
                cin.ignore();
            } else {
                cin.ignore();
            }


        } else if(pilih == "6") {
            cout << "Lihat daftar toko beserta barang yang dijual : " << endl;
            printInfo(toko);
            cout << "Barang yang terdaftar di list item : " << endl;
            printInfo(item);
            cin.ignore();
        } else if(pilih == "7") {
            cout << "Lihat barang yang dijual toko tertentu : " << endl;
            // melihat barang yang dujualn toko tertentu
            cin.ignore();
            if(first(item) == NULL) {
                cout << "Barang kosong" << endl;
            } else {

                // melakukan pencarian toko dan mengoutputkan barnagnya
                do {
                    cout << "Nama toko : ";
                    getline(cin, str);
                    p1 = findElm(toko, str);
                    if(p1 != NULL) {
                        cout << "Barang    : ";
                        printInfo(item(p1));

                    } else {
                        cout << str << " tidak ditemukan!" << endl;
                    }
                    back(pilih, "lihat barang lagi ?");
                    cin.get();
                } while(pilih == "y");
            }
        } else if(pilih == "8") {
            cout << "Lihat toko yang menjual barang tertentu : " << endl;
            if(first(item) == NULL) {
                 cout << "data barang masih kosong, mohon untuk tambahkan barang terlebih dahulu" << endl;
                 cin.ignore();
            } else if(first(toko) == NULL) {
                 cout << "Data toko masih kosong, mohon untuk tambahkan barang terlebih dahulu" << endl;
            } else {
                // inputkan nama barang;
                cout << "Nama barang : ";
                cin.ignore();
                getline(cin, str);

                // mencari nama barang di list item
                c1 = findElm(item, str);
                if(c1 != NULL) {
                    // jika str ditemukan pada list item maka selanjutnya mengoutpukan toko yang menjual barang str;
                    bool Found = false;
                    cout << "Toko yang menjual " << str << " : ";

                    // proses pencarian
                    p1 = first(toko);
                    do {
                        // mencari str pada item (p1)
                        c2 = findElm(item(p1), str);
                        if(c2 != NULL) {
                            Found = true;
                            cout << info(p1) << ", ";
                        }
                        p1 = next(p1);
                    } while(p1 != first(toko));
                    cout << endl;
                    if(!Found) {
                        // jika tidak ada toko yang menjual barang str maka ini dilakukan
                        cout << "Tidak ada toko yang menjual [" << str << "]" << endl;
                    }

                } else {
                    // jika str tidak ada didalam list item;
                    cout << str << " tidak ditemukan!" << endl;
                }
            }
        } else if(pilih == "9") {
            cout << "Toko paling lengkap dan toko paling sedikit : " << endl;
            if(first(toko) != NULL) {

                // inisialisasi
                p1 = first(toko);
                int jumItem = hitungChild(item(p1));
                int MAX = jumItem;
                int MIN = jumItem;
                address_parent pMax = p1;
                address_parent pMin = p1;

                // mencari min dan max
                do {
                    jumItem = hitungChild(item(p1));
                    if(jumItem > MAX) {
                        MAX = jumItem;
                        pMax = p1;
                    }
                    if(jumItem < MIN) {
                        MIN = jumItem;
                        pMin = p1;
                    }
                    p1 = next(p1);
                } while(p1 != first(toko));
                cout << "Toko paling lengkap : " << info((pMax));

                // mencari jumlah item yang sama dengan pMax
                // jika ketemu maka outputkan
                p1 = first(toko);
                do {
                    int jumItem = hitungChild(item(p1));
                    if(jumItem == MAX && p1 != pMax) {
                        cout << ", " << info(p1);
                    }
                    p1 = next(p1);
                } while(p1 != first(toko));
                cout << endl;
                cout << "Jumlah barang : " << MAX;
                cout << endl;

                cout << "Toko paling sedikit : " << info((pMin));

                // mencari jumlaah item yang sama denan pMin
                // jika ketemu maka outputkan
                p1 = first(toko);
                do {
                    int jumItem = hitungChild(item(p1));
                    if(jumItem == MIN && p1 != pMin) {
                        cout << ", " << info(p1);
                    }
                    p1 = next(p1);
                } while(p1 != first(toko));
                cout << endl;
                cout << "Jumlah barang : " << MIN;
                cout << endl;
            } else {
                printInfo(toko);
            }
            cin.ignore();

        } else {
            // jika user melakukan input selain 1, 2, 3, 4, 5, 6 , 7, 8, 9, dan 0;
            cout << "PILIHAN TIDAK VALID" << endl;
        }
        cout << "Press enter to continue. ";
        // agar getline selanjutnya dapat dibaca jiga proses looping berlanjut
        cin.ignore();
        cout << endl;
        menu(pilih);
    }
    cout << "Terimakasih telah menggunakan program kami" << endl;
    cout << "copyright 2020" << endl;

    return 0;
}

