/*
Nama Program     :Walking Steve
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :9 Oktober 2025
Waktu Awal       :11:02
Waktu Selesai    :11:120
Deskripsi        :Program untuk menggerakkan karakter “Steve” pada bidang koordinat 2D berdasarkan input arah (`U`, `D`, `L`, `R`).
*/


#include <iostream>
using namespace std;

int main(){
    int x, y;
    cout << "Masukkan posisi di x: "; cin >> x;
    cout << "Masukkan posisi di y: "; cin >> y;
    
    int n;
    cout << "Berapa langkah steve berjalan? "; cin >> n;

    char arah[4];
    for(int i = 0; i < 4; i++){
        cout << "Arah Steve berjalan? \nU = up \nD = down \nL = left \nR = right" << endl;
        cin >> arah[i];
    }

    for(int i = 0; i < n; i++){
        char langkah = arah[i % 4];

        if(langkah == 'U'){
            y += 1; 
        } else if(langkah == 'D'){
            y -= 1;
        }
        else if(langkah == 'R'){
            x += 1;
        }
        else if(langkah == 'L'){
            x -= 1;
        }
    } 

    cout << "Steve sekarang berada di " << x << ", " << y;
}