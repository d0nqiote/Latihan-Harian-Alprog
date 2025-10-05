/*
Nama Program    :Menentukan bonus pegawai
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal Dibuat  :5 Oktober 2025
Waktu Awal      :00:16
Waktu Akhir     :
Deskripsi       :Buat program C++ yang meminta input string
dan memeriksa apakah string tersebut
palindrom (dibaca sama dari depan maupun
belakang). Gunakan loop untuk
membandingkan karakter dari awal dan akhir
string.
*/

#include <iostream>
using namespace std;

int main(){
    string kata;
    cin >> kata;
    int n = kata.length();
    int hasil = 0;

    for(int i = 0; i < kata.length(); i++){
        hasil++;
        if(kata[i] != kata[n - i - 1]){
            break;
        }
    }

    if(hasil == n){
        cout << "Palindrom";
    } else {
        cout << "Bukan Palindrom";
    }

}