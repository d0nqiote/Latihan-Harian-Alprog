/*
Nama Program    :Palindrom kata
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal Dibuat  :8 Oktober 2025
Deskripsi       :Raka ingin membuat program untuk mengecek apakah sebuah kata merupakan palindrom atau tidak.
Palindrom adalah kata yang dibaca sama dari depan maupun dari belakang (contoh: katak, level, madam).

Buatlah program yang meminta pengguna untuk memasukkan sebuah kata tanpa spasi, menyimpannya ke dalam array karakter, kemudian mengecek apakah kata tersebut palindrom.
*/

#include <iostream>
using namespace std;

int main(){
    string kata;
    cin >> kata;
    int n = kata.length();

    int hasil = 0;

    for(int i = 0; i < n; i++){
        if(kata[i] == kata[n - i - 1]){
            hasil++;
        } else{
            break;
        }
    }

    if(hasil == n){
        cout << "Kata tersebut adalah palindrom";
    } else {
        cout << "Kata tersebut bukan palindrom";
    }
}