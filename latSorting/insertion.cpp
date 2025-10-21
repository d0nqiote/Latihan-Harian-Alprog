/*
Nama Program    :Insertion sorting ascending
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :21 Oktober 2025
Waktu Awal      :11:10
Waktu Akhir     :11:52
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

    for(int i = 1; i < n; i++){                 //elemen kedua karena elemen pertama dianggap sudah tersusun

        for(int j = i; j > 0 ; j--){            //membandingkan dengan elemen sebelumnya
            if(array[j-1] > array[j]){          //elemen sebelum sebelumnya lebih besar tidak sama elemen saat ini, kalau iya harus dipindah
                pindah(array[j-1], array[j]);
            } else{
                break;                          //ini break kalau misalnya elemen j-1 udah lebih kecil dari j
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}