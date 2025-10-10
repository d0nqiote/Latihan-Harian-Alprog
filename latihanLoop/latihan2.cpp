/*
Nama Program :Segitiga Pascal
Nama         :Farah Nadia Aqila
NPM          :140810250049
Tanggal Buat :12 September 2025
Deskripsi    :Buatlah program C++ untuk menghasilkan segitiga pascal dengan menggunakan loop. Program meminta input berupa jumlah baris NNN dan menghasilkan segitiga Pascal hingga NNN baris
*/

#include <iostream>
using namespace std;

int main(){
    int b, k, batas;
    int ujung = 1;
    cout << "Input: "; cin >> batas;
    cout << "\nOutput : \n";

    for(b = 0; b < batas; b++){
        for(k = 0; k <= b; k++){
            cout << ujung << " ";
            ujung = ujung * (b - k) / (k + 1);
        }
        cout << endl;
    }
} 