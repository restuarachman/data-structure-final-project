#include "set.h"
#include "parent.h"

string lowercase(string str) {
    (transform(str.begin(), str.end(), str.begin(), ::tolower));
    return str;
}
void back(string &pilih, string str) {
    cout << str <<" [Y/N] ";
    cin >> pilih;
    pilih = lowercase(pilih);
    while(pilih != "n" && pilih != "y") {
        cout << "INVALID INPUT" << endl;
        cout << str <<" [Y/N] ";
        cin >> pilih;
        pilih = lowercase(pilih);
    }
    cout << endl;
}
void menu(string &pilih) {
    cout << "+-------------------- Main menu --------------------+" << endl;
    cout << "| 1. Tambah data toko                               |" << endl;
    cout << "| 2. Tambah data barang                             |" << endl;
    cout << "| 3. Hubungkan toko dengan barang                   |" << endl;
    cout << "| 4. Hapus data toko                                |" << endl;
    cout << "| 5. Hapus data barang                              |" << endl;
    cout << "| 6. Lihat daftar toko beserta barang yang dijual   |" << endl;
    cout << "| 7. Lihat barang yang dijual toko tertentu         |" << endl;
    cout << "| 8. Lihat toko yang menjual barang tertentu        |" << endl;
    cout << "| 9. Toko paling lengkap, dan toko paling sedikit   |" << endl;
    cout << "| 0. Keluar                                         |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    cout << "Pilih : ";
    cin >> pilih;
}

void inputLetters(string &str, string n){
    char c;
    cout << n;
    do {
        getline(cin, str);
    } while(str == "");
    for (int i = 0; i < str.length(); i++) {

        c = str.at(i);
        if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || (c >= '0' && c <= '9') || (c == ' ')) ) {

             cout << "Invalid!, Terdapat spesial karakter" << endl;

             cout << n;
             do {
                 getline(cin, str);
             } while(str == "");
             i = 0;
        }
     }
}

void inputNumber(int &n, string str) {
    bool thisInt = false;
    do {
        cout << str;
        if(!(cin >> n)) {
            // jika user memasukan n selain integer
            cout << "silahkan masukan nomor saja" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            thisInt = true;
        }
    } while(!thisInt);
}
