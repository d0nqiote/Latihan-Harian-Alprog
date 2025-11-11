/*
Nama Program    :House Robber
Nama            :Farah Nadia Aqila
Tanggal         :30 Oktober 2025
Waktu Awal      :13:24
Waktu Akhir     :14:30
Deskripsi       :You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef int rumah[100];

void banyakElemen(int &n){
    cout << "Banyak rumah dalam satu komplek : ";
    cin >> n;
}

void inputArray(rumah curian, int n){
    for(int i = 0; i < n; i++){
        cout << "Masukkan curian untuk rumah ke-" << i + 1 << " : ";
        cin >> curian[i];
    }
}

int hasilCurian(rumah curian, int n){
    if(n == 0) return 0;
    if(n == 1) return curian[1];

    int hasil[100];
    hasil[0] = curian[0];
    hasil[1] = max(curian[0], curian[1]);

    for(int i = 2; i < n; i++){
        hasil[i] = max(hasil[i - 1], hasil[i - 2] + curian[i]);
    }

    return hasil[n - 1];
}

int main(){
    int n;
    banyakElemen(n);
    rumah curian;
    inputArray(curian, n);

    cout << "Harta yang berhasil dicuri sebanyak : " << hasilCurian(curian, n);
}