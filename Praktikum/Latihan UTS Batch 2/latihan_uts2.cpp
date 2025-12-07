/*
Nama Program     :Menghitung kata terakhir dalam kalimat
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :10 Oktober 2025
Waktu Awal       :14:00
Waktu Selesai    :14:08
Deskripsi        :Menentukan jumlah huruf dari kata terakhir dalam sebuah kalimat menggunakan deteksi karakter ASCII spasi (`32`).
*/


#include <iostream>
using namespace std;

int main(){
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    int n = kalimat.length();
    int hasil = 0;

    for(int i = n - 1; i >= 0; i--){
        if(kalimat[i] == ' '){
            break;
        } else {
            hasil++;
        }
    }
    cout << "Panjang kata terakhir adalah " << hasil;
}