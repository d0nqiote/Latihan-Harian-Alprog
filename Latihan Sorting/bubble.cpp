/*
Nama Program    :Bubble sorting ascending
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :21 Oktober 2025
Waktu Awal      :13:32
Waktu Akhir     :14:01
*/

#include <iostream>
using namespace std;

void pindah(int &a, int &b){
    int hasil = a;
    a = b;
    b = hasil;
}

int main(){
    int n; cin >> n;

    int array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    for(int i = 0; i < n - 1; i++){                 //buat berapa kali nyusunnya
        for(int j = 0; j < n - i - 1; j++){         //buat perbandingan semua elemennya
            if(array[j] > array[j+1]){
                pindah(array[j], array[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}