/*
Nama Program    :Memutar matriks
Npm             :140810250049
Tanggal         :15 Oktober 2025
Waktu Awal      :01:30
Waktu Akhir     :
Deskripsi       :Pak Dengklek memberikan Anda sebuah matriks berukuran 
N×M. Cetak kembali matriks tersebut setelah diputar 
90 derajat searah jarum jam!
*/

#include <iostream>
using namespace std;

typedef int array[100][100];

void banyakData(int &n, string tipe);
void inputData(array a, int baris, int kolom);
void pindah(int &a, int &b);
int putarMatriks(array a, int baris, int kolom);

int main(){
    array a;
    int kolom, baris;

    banyakData(baris, "baris");
    banyakData(baris, "kolom");
    putarMatriks(a, baris, kolom);   
}

void banyakData(int &n, string tipe){
    cout << "Masukkan batas " << tipe << ": ";
    cin >> n;
}

void inputData(array a, int baris, int kolom){
    cout << "Masukkan nilai untuk array : ";
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cin >> a[i][j];
        }
    }
}

void pindah(int &a, int &b){
    int hasil = a;
    a = b;
    b = hasil;
}

int putarMatriks(array a, int baris, int kolom){
    pindah(kolom, baris);

    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    } 
}