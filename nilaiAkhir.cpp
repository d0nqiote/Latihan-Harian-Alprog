/*
Nama Program     :Nilai Akhir
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :11 November 2025
Waktu Awal       :20:09
Waktu Selesai    :
Deskripsi        :Buatlah program untuk menghitung nilai akhir mahasiswa yang diberikan pada file dengan metode weighted average. Jumlah nilai yang akan dihitung sebanyak 5.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    string fileInput;
    string fileOutput;
    int jumlahMahasiswa;
    float bobotNilai[5];

    cout << "Masukkan nama file yang akan diolah  : "; cin >> fileInput;
    cout << "Masukkan nama file untuk hasil olah  : "; cin >> fileOutput;
    cout << "Masukkan jumlah mahasiswa            : "; cin >> jumlahMahasiswa;
    cout << "Masukkan bobot nilai (untuk 5 nilai) : ";
    for(int i = 0; i < 5; i++){
        cin >> bobotNilai[i];
    }

    ifstream infile(fileInput);
    ofstream outfile(fileOutput);
    if (!infile.is_open()) {
        cout << "Gagal membuka file input!" << endl;
        return 1;
    }
    if (!outfile.is_open()) {
        cout << "Gagal membuat file output!" << endl;
        return 1;
    }

    for(int i = 0; i < jumlahMahasiswa; i++){
        string nama;
        infile >> nama;

        float hasilAkhir = 0;
        for(int j = 0; j < 5; j++){
            float nilai;
            infile >> nilai;
            hasilAkhir += bobotNilai[j] * nilai;
        }
        outfile << nama << " " << fixed << setprecision(2) << hasilAkhir << endl;
    }

    infile.close();
    outfile.close();
}