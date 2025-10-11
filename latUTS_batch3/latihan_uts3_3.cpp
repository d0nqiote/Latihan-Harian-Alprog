/*
Nama Program     :Reverse String
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :11 Oktober 2025
Waktu Awal       :09:56
Waktu Selesai    :10:35
Deskripsi        :Tulis sebuah fungsi yang membalik sebuah string. String input diberikan sebagai sebuah larik karakter `char[]`.
Anda harus melakukan ini secara **in-place** (memodifikasi larik input secara langsung) dengan menggunakan memori tambahan $O(1)$.
*/

#include <iostream>
using namespace std;

typedef char data[100];

void pindah(char &a, char &b){
    char hasil = a;
    a = b;
    b = hasil;
}

void banyakData(int &n){
    cout << "Masukkan banyak data dalam array : ";
    cin >> n;
}

void array(data nilai, int n){
    for(int i = 0; i < n; i++){
        cin >> nilai[i];
    }
}

void balikArray(data &nilai, int n){
    for(int i = 0; i < n / 2; i++){
        pindah(nilai[i], nilai[n-i-1]);
    }

    for(int i = 0; i < n; i++){
        cout << nilai[i] << " ";
    }
}

int main(){
    int n;
    data nilai;

    banyakData(n);
    array(nilai, n);
    balikArray(nilai, n);
}