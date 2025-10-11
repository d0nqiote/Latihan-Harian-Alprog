/*
Nama Program :Rata-rata suhu harian
Nama         :Farah Nadia Aqila
NPM          :140810250049
Tanggal Buat :12 September 2025
Deskripsi    :Buatlah program C++ yang menerima input suhu badan pasien sebanyak 24 kali lalu menghitung dan menampilkan rata-rata suhu harian.
*/

#include <iostream>
using namespace std;

int main(){
   int suhu, jumlah;
   jumlah = 0;
   for(int n = 1; n <= 24; n++){
    cout << "masukan suhu badan ke " << n << " : ";
    cin >> suhu;
    jumlah += suhu;
   }
   cout << "Rata-rata suhu selama 24 jam adalah : " << (float)jumlah/24;
}