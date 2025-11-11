/*
Nama Program    :Pencarian jumlah munculnya angka dalam suatu array
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal Dibuat  :8 Oktober 2025
Deskripsi       :Fina ingin membuat program untuk menghitung berapa kali setiap angka muncul di dalam sebuah array.
Program akan meminta jumlah elemen, kemudian pengguna memasukkan angka satu per satu. Setelah itu, program akan menampilkan berapa kali setiap angka muncul.
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Masukkan jumlah elemen: "; cin >> n;
    
    int data[n];
    for(int i = 0; i < n; i++){
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    for(int i = 0; i < n; i++){

        int udahHitung = 0;
        for(int j = 0; j < i; j++){
            if(data[i] == data[j]){
                udahHitung++;
                break;
            }
        } if(udahHitung == 1){
            continue;
        }

        int hitung = 0;
        for(int j = 0; j < n; j++){
            if(data[i] == data[j]){
                hitung++;
            }
        }

        cout << "Angka " << data[i]<< " muncul " << hitung << " kali";
        cout << endl;
    }
            
}
