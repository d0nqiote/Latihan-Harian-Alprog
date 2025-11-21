/*
Nama Program    :Count Numbers with Unique Digits
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :21 November 2025
Waktu Awal      :22:31
Waktu Akhir     :22:41
Deskripsi       :Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m;
    cout << "Input angka untuk pangkat      : ";
    cin >> m;

    int n = pow(10, m);
    int total = 0;
    for(int i = 0; i < n; i++){
        if(i % 11 != 0 && i != 0){
            total++;
        }
    }

    cout << "Jumlah angka tanpa angka unik  : " << total;
}