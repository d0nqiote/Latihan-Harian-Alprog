/*
Nama Program     :Menghitung Jumlah Karakter
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :11 November 2025
Waktu Awal       :16:23
Waktu Selesai    :16:41
Deskripsi        :Buatlah program untuk menghitung jumlah karakter tertentu dalam sebuah file. Input berupa nama file dan karakter yang akan dihitung. Karakter tidak case-sensitive.
*/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){
    string s;
    char c;
    cout << "Masukkan nama file yang akan dibuka    : "; getline(cin, s);
    cout << "Masukkan huruf yang akan dicari        : "; cin >> c;

    ifstream file;
    file.open(s);
    char n;
    int jumlah = 0;
    while(file.get(n)){
        if(tolower(n) == c){
            jumlah++;
        }
    }

    cout << "Jumlah huruf " << c << " ada sebanyak            : " << jumlah;
}
