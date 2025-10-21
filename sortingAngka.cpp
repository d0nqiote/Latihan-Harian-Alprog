/*
Nama Program    :Sorting warna
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :21 Oktober 2025
Waktu Awal      :18:15
Waktu Akhir     :18:24
*/

#include <iostream>
using namespace std;

void pindah(string &a, string &b){
    string hasil = a;
    a = b;
    b = hasil;
}

int warnakeAngka(string warna){
    if (warna == "merah") return 1;
    if (warna == "kuning") return 2;
    if (warna == "biru") return 3;
    return 0;
}

void sorting(string warna[], int n){
    for(int i = 0; i < n - 1; i++){                 //buat berapa kali nyusunnya
        for(int j = 0; j < n - i - 1; j++){         //buat perbandingan semua elemennya
            if(warnakeAngka(warna[j]) > warnakeAngka(warna[j+1])){
                pindah(warna[j], warna[j+1]);
            }
        }
    }
}

int main(){
    int n; cin >> n;

    string array[n];
    for(int i = 0; i < n; i++){
        getline(cin, array[i]);
    }

    sorting(array, n);

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}