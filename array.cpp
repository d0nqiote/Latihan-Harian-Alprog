/*
Nama Program     :Nilai mahasiswa
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :3 Oktober 2025
Waktu Awal       :07:30
Waktu Selesai    :11:01
*/

#include <iostream>
#include <iomanip>
using namespace std;

void ukuran(int &n){
    cout << "Banyak siswa adalah : ";
    cin >> n;
}

void input(string siswa[], float nilai[], int n){
    for(int i = 0; i < n; i++){
        cout << "Masukkan nama siswa ke-" << i + 1 << "\t :";
        cin >> siswa[i];
        cout << "Masukkan nilai siswa tersebut \t :";
        cin >> nilai[i];
        cout << endl;
    }
}

void output(string siswa[], float nilai[], int n){
    cout << "Nama Mahasiswa" << setw(10) << "|" << setw(15) << "Nilai" << endl;
    cout << "---------------------------------------" << endl; 
    for(int i = 0; i < n; i++){
        cout << left << setw(10) << siswa[i];
        cout << right << setw(25) << nilai[i];
        cout << endl;
    }
}

void mean(float nilai[], float n){
    float jumlah = 0;
    for (int i = 0; i < n; i++){
        jumlah += nilai[i];
    }
    cout << "Rata-rata nilai : " << jumlah / n;
    cout << endl;
}

void max(float nilai[], string siswa[], int n){
    int maks = -999;
    string mahasiswa = " ";
    for(int i = 0; i < n; i++){
        if(maks < nilai[i]){
            maks = nilai[i];
            mahasiswa = siswa [i];
        }
    }
    cout << "\nNilai tertinggi : " << maks << ", yaitu " << mahasiswa;
}

void min(float nilai[], string siswa[], int n){
    int min = 999;
    string mahasiswa = "";
    for(int i = 0; i < n; i++){
        if(min > nilai[i]){
            min = nilai[i];
            mahasiswa = siswa[i];
        }
    }
    cout << "\nNilai terendah  : " << min << ", yaitu " << mahasiswa;
}

int main(){
    int n;
    ukuran(n);

    string siswa[n];
    float nilai[n];

    input(siswa, nilai, n);
    output(siswa, nilai, n);
    mean(nilai, n);
    max(nilai, siswa, n);
    min(nilai, siswa, n);
}