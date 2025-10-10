/*
Nama Program     :Susunan Zigzag
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :10 Oktober 2025
Waktu Awal       :14:32
Waktu Selesai    :15:53
Deskripsi        :Program untuk menyusun elemen array bilangan bulat dalam pola **zig-zag**.  
Pola dimulai dengan perbandingan **ascending (naik)**, lalu **descending (turun)** secara bergantian.
*/

void pindah(int &a, int&b){
    int hasil = a;
    a = b;
    b = hasil;
}

#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int nilai[n];

    for(int i = 0; i < n; i++){
        cin >> nilai[i];
    }

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(nilai[i] > nilai[i + 1]){
                pindah(nilai[i], nilai[i + 1]);
            }
        } else {
            if(nilai[i] < nilai[i + 1]){
                pindah(nilai[i], nilai[i + 1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << nilai[i] << " ";
    }
}