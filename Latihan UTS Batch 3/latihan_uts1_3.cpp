/*
Nama Program     :Two Sum
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :10 Oktober 2025
Waktu Awal       :23:00
Waktu Selesai    :23:41
Deskripsi        :Diberikan sebuah larik (array) integer `nums` dan sebuah integer `target`, kembalikan **indeks dari dua angka** yang jika dijumlahkan akan menghasilkan `target`.
Asumsikan bahwa setiap input akan memiliki **tepat satu solusi**, dan Anda tidak boleh menggunakan elemen yang sama dua kali.
*/

#include <iostream>
using namespace std;

typedef int array[100];

void inputNilai(int &n, string tipe){
    cout << "Besar " << tipe << " : ";
    cin >> n;
}

void inputArray(array nilai, int n){
    for (int i = 0; i < n; i++){
        cin >> nilai[i];
    }
}

void cariTarget(array nilai, int n, int target){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nilai[i] + nilai[j] == target){
                cout << "[" << nilai[j] << ", " << nilai[i] << "]";
                return;
            }
        }
    }
}

int main(){
    int n, target;
    inputNilai(n, "array");
    
    array nilai;
    inputArray(nilai, n);

    inputNilai(target, "target");
    cariTarget(nilai, n, target);
}