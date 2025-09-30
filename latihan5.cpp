/*
Nama Program :Faktorial
Nama         :Farah Nadia Aqila
NPM          :140810250049
Tanggal Buat :12 September 2025
Deskripsi    :Buatlah program C++ untuk menghitung faktorial dari sebuah bilangan tanpa menggunakan fungsi terpisah
*/

#include <iostream>
using namespace std;

int main(){
   int n;
   cout << "Masukkan bilangan untuk dihitung faktorialnya (Maks 256) : "; cin >> n;
   int faktorial = n;
   for(int i = n - 1; i >0; i--){
    faktorial *= i;
   }
   cout << "Faktorial dari " << n << " adalah : " << faktorial;  
}