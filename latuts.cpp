/*
Nama Program     :Latihan Uts Praktikum
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :11=3 Oktober 2025
Waktu Awal       :17:20
Waktu Selesai    :
*/

#include <iostream>
using namespace std;

void posisi (int &n, char posisi);
void langkah(int &n);
void arah(char a[]);
void pindah(int &x, int &y, int n, char a[]);
void posisiAkhir(int n, char posisi);

int main(){
    int x, y, n;
    posisi(x, 'x');
    posisi(y, 'y');
    langkah(n);

    char a[4];
    arah(a);

    pindah(x, y, n, a);
    posisiAkhir(x, 'x');
    posisiAkhir(y, 'y');
}

void posisi (int &n, char posisi){
    cout << "Masukkan posisi Steve di " << posisi << " : ";
    cin >> n;
}

void langkah(int &n){
    cout << "Berapa banyak Steve melangkah? ";
    cin >> n;
}

void arah(char a[]){
    cout << "Arah Steve Melangkah : \n1. U(Up) \n2.D(Down) \n3.R(Right) \n4.L(Left)" << endl;
    for(int i = 0; i < 4; i++){ 
        cin >> a[i];
    }
}


void pindah(int &x, int &y, int n, char a[]){
    for(int i = 0; i < n; i++){
        char langkah = a[i % 4];
        if(langkah == 'U'){
            y += 1;
        } else if(langkah == 'D'){
            y -= 1;
        } else if(langkah == 'R'){
            x += 1;
        } else if (langkah == 'L'){
            x -= 1;
        }
    }
}

void posisiAkhir(int n, char posisi){
    cout << "Posisi akhir Steve di " << posisi << " : " << n << endl;
}