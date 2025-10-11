/*
Nama Program     :Contains Duplicate
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :11 Oktober 2025
Waktu Awal       :10:37
Waktu Selesai    :10:47
Deskripsi        :Diberikan sebuah larik integer `nums`, kembalikan `true` jika ada nilai yang muncul **setidaknya dua kali** di dalam larik, dan kembalikan `false` jika setiap elemennya unik.
*/

#include <iostream>
using namespace std;

typedef char data[100];

void banyakData(int &n){
    cout << "Masukkan banyak data dalam array : ";
    cin >> n;
}

void array(data nilai, int n){
    for(int i = 0; i < n; i++){
        cin >> nilai[i];
    }
}

void cekArray(data nilai, int n){
    int hasil = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nilai[i] == nilai[j]){
                hasil++;
            }
        }
    }
    if(hasil > 0){
            cout << "true";
        } else{
            cout << "false";
        }
}

int main(){
    int n;
    data nilai;

    banyakData(n);
    array(nilai, n);
    cekArray(nilai, n);
}