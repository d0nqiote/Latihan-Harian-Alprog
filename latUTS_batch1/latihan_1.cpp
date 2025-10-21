/*
Nama Program    :Penjumlahan pengurangan dua array dua dimensi
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal Dibuat  :8 Oktober 2025
Deskripsi       :Rani sedang belajar tentang operasi pada matriks dua dimensi. Ia ingin membuat program yang dapat menghitung penjumlahan dan pengurangan antara dua buah matriks A dan B.
Bantulah Rani membuat program yang meminta pengguna untuk memasukkan ukuran matriks (baris dan kolom), kemudian mengisi elemen-elemen matriks A dan B, lalu menampilkan hasil operasi penjumlahan dan pengurangannya.
*/

#include <iostream>
using namespace std; 

typedef int data[10][10];

void batas(int &baris, int &kolom){
    cout << "Masukkan jumlah baris: "; cin >> baris;
    cout << "Masukkan jumlah kolom: "; cin >> kolom;
}

void input(data nilai, int &baris, int &kolom){
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cin >> nilai[i][j];
        }
    }
}

void jumlah(data nilai1, data nilai2, int &baris, int &kolom){
    int hasil[baris][kolom] = {};
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            hasil[i][j] = nilai1[i][j] + nilai2[i][j];
        }
    }
    cout << "Hasil penjumlahan (A + B) : " << endl;
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

void kurang(data nilai1, data nilai2, int &baris, int &kolom){
    int hasil[baris][kolom] = {};
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            hasil[i][j] = nilai1[i][j] - nilai2[i][j];
        }
    }
    cout << "Hasil pengurangan (A - B) : " << endl;
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int baris, kolom;
    data nilai1, nilai2;

    batas(baris, kolom);
    cout << "Masukkan elemen matriks A: ";
    input(nilai1, baris, kolom);
    cout << "Masukkan elemen matriks B: ";
    input(nilai2, baris, kolom);
    jumlah(nilai1, nilai2, baris, kolom);
    kurang(nilai1, nilai2, baris, kolom);
}