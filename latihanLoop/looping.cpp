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

void palindromHuruf(string kata){
    cin >> kata;
    int n = kata.length();
    int hasil = 0;

    for(int i = 0; i < kata.length(); i++){
        if(kata[i] == kata[n - i - 1]){
            hasil++;
        } else{
            break;
        }
    }
    if(hasil == kata.length()){
        cout << kata << " adalah palindrom";
    } else{
        cout << kata << " bukan palindrom";
    }
}

int main(){
    string kata;
    palindromHuruf(kata);
}