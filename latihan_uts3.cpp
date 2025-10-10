/*
Nama Program     :Surat Cinta (Caesar Cipher)
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :10 Oktober 2025
Waktu Awal       :14:00
Waktu Selesai    :
Deskripsi        :Program untuk mengenkripsi teks menggunakan metode **Caesar Cipher**.  
Setiap huruf akan digeser sejauh `n` huruf berikutnya di tabel ASCII.
*/

#include <iostream>
using namespace std;

int main(){
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    int n; cin >> n;

    for(int i = 0; i < kalimat.length(); i++){
        if(kalimat[i] != ' '){
            kalimat[i] = kalimat[i] + n;
        } else{
            kalimat[i] = kalimat[i];
        }
    }
    cout << kalimat;
}