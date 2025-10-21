/*
Nama Program    :Selection sorting ascending
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :21 Oktober 2025
Waktu Awal      :10:24
Waktu Akhir     :10:56
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

    for(int i = 0; i < n; i++){
        int min = i;                            //awalnya min itu di indeks ke-i

        for(int j = i + 1; j < n; j++){
            if(array[min] > array[j]){          //ini kalau array di indeks ke-min lebih besar dari array di indeks ke-j
                min = j;
            }
        }

        pindah(array[i], array[min]);           //pindah array di-i sama array di-min yang minnya udah dicari paling kecil
    }

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}