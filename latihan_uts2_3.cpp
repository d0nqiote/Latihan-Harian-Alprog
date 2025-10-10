/*
Nama Program     :Remove Element
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :10 Oktober 2025
Waktu Awal       :23:45
Waktu Selesai    :00:14 (11 Oktober 2025)
Deskripsi        :Diberikan sebuah larik integer `nums` dan sebuah integer `val`, hapus semua kemunculan `val` dari `nums` secara **in-place** (tanpa membuat array baru). Urutan elemen yang tersisa tidaklah penting.

Kembalikan `k`, yaitu jumlah elemen yang tersisa setelah penghapusan.
*/

#include <iostream>
using namespace std;

typedef int array[100];

void inputNilai(int &n, string tipe){
    cout << tipe << " : ";
    cin >> n;
}

void inputArray(array nilai, int n){
    for (int i = 0; i < n; i++){
        cin >> nilai[i];
    }
}


void hapus(array nilai, int n, int hapus){}

int main(){
    int n, hapus;
    inputNilai(n, "Data");
    inputNilai(hapus, "Hapus");
    
    array nilai;
    inputArray(nilai, n);

    int hasil = n;
    for(int i = 0; i < hasil;){
        if(nilai[i] == hapus){
            for(int j = i; j < hasil - 1; j++){
                nilai[j] = nilai[j+1];
            }
             hasil--;
        } else {
            i++;
        }
    }

    cout << hasil << endl;
    cout << "[";
    for(int i = 0; i < n; i++){
        if(nilai[i] != hapus){
            cout << nilai[i];
        } else {
            cout << "_";
        }
        if(i != n - 1){
            cout << ", ";
        }
    }
    cout << "]";
}