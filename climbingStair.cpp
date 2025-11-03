/*
Nama program    :Climbing Stairs
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :30 Oktober 2025
Waktu awal      :14:43
Waktu akhir     :14:59
Deskripsi       :You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top
*/

#include <iostream>
using namespace std;

void banyakAnakTangga(int &n){
    cout << "Berapa banyak anak tangga? " << endl;
    cin >> n;
}

int langkah(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    return langkah(n - 2) + langkah(n - 1);
}

int main(){
    int n;
    banyakAnakTangga(n);
    cout << "Banyaknya cara menaiki " << n << " anak tangga adalah : " << langkah(n);
}