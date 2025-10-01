/*
Nama program    :Menghitung uang
Nama            :Farah Nadia Aqila
NPM             :140810250049
Tanggal dibuat  :30 September 2025
Waktu awal      :16:
Waktu akhir     :16:
Deskripsi       :Misalkan uang sebanyak Rp10.000 disimpan di bank dengan sistem bunga berbunga dengan besar bunga 11% per tahun. Berapa banyak uang setelah 30 tahun?
*/

#include <iostream>
using namespace std;

int pangkat(int basis, int pangkat){
    int hasil = 1;
    for(int i = 1; i <= pangkat; i++){
        hasil = hasil * basis;
    }   
    return hasil;
}

float uang(float n){
    if(n == 0) return 10000;
    float hasil = uang(n - 1) + 0.11 * uang (n - 1);
    return hasil;
}

int main(){
    float n; cin >> n;
    cout << uang(n);
}