/*
Nama program    :Menghitung uang
Nama            :Farah Nadia Aqila
NPM             :140810250049
Tanggal dibuat  :1 Oktober 2025
Waktu awal      :07:21
Waktu akhir     :08:03
Deskripsi       :Misalkan uang sebanyak Rp10.000 disimpan di bank dengan sistem bunga berbunga dengan besar bunga 11% per tahun. Berapa banyak uang setelah 30 tahun?
*/

#include <iostream>
using namespace std;

float uang(float n){
    if(n == 0) return 10000;
    float hasil = uang(n - 1) + 0.11 * uang (n - 1);
    return hasil;
}

int main(){
    float n; cin >> n;
    cout << uang(n);
}