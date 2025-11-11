/*
Nama program    :Balance Scale
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :09 November 2025
Waktu awal      :14:23
Waktu akhir     :16:02
Deskripsi       :Contestants choose a number between 0 and 100;
The average of the numbers everyone selected is multiplied by 0.8;
The person whose number is the closest to that result is the winner. The other players each lose a point. A scale above their heads is filled with sulfuric acid (硫酸).
A new rule is introduced for every player eliminated.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct data{
    string nama;
    int nilai;
    float gap;
};


void jumlah(int &n, string jenis){
    cout << "Masukkan jumlah " << jenis << endl;
    cin >> n;
}

void inputAngka(data pemain[], int n){
    cout << "Masukkan angka pilihan anda (0-100)" << endl;
    for(int i = 0; i < n; i++){
        cout << "Masukkan nilai dan nama pemain ke-" << i + 1 << " : ";
        cin >> pemain[i].nilai >> pemain[i].nama;
    }
}

void swap(int &a, int &b){
    int temp = a; 
    a = b; 
    b = temp;
}

float balanceScale(data pemain[], int n){
    int hasil = 0;
    for(int i = 0; i < n; i++){
        hasil += pemain[i].nilai;
    }
    return hasil /(float)n * 0.8;
}

void jarak(data pemain[], int n){
    float mean = balanceScale(pemain, n);
    for(int i = 0; i < n; i++){
        pemain[i].gap = pemain[i].nilai - mean;
    }
}

void sorting(data pemain[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j >= 1; j--){
            if(pemain[j].gap > pemain[j-1].gap){
                swap(pemain[j], pemain[j-1]);
            } else {
                break;
            }
        }
    }
}

string eliminasi(data pemain[], int n){
    float mean = balanceScale(pemain, n);
    string tereliminasi = pemain[0].nama;
    int jarakTerjauh = pemain[0].nilai - mean;

    if(jarakTerjauh < 0){
        jarakTerjauh = -jarakTerjauh;
    }    

    for(int i = 0; i < n; i++){
        float jarak = pemain[i].nilai - mean;
        if(jarak < 0){
            jarak = -jarak;
        }

        if(jarak > jarakTerjauh){
            jarakTerjauh = jarak;
            tereliminasi = pemain[i].nama;
        }
    }
    return tereliminasi;
}

void outputData(ofstream &file, data pemain[], int n){
    file << left << setw(20) << "Nama Pemain" 
         << right << setw(10) << "Nilai" << endl;
    file << "------------------------------------" << endl;
    
    for (int i = 0; i < n; i++) {
        file << left << setw(20) << pemain[i].nama
             << right << setw(10) << pemain[i].nilai << endl;
    }
    file << "------------------------------------" << endl;
}

int main(){
    ofstream file("BalanceScale.txt");
    int n;
    jumlah(n, "pemain");
    file << "Jumlah pemain : " << n << endl;

    data pemain[n];
    inputAngka(pemain, n);
    jarak(pemain, n);
    sorting(pemain, n);
    outputData(file, pemain, n);

    file << "Nilai Balance Scale      : " << fixed << setprecision(2) << balanceScale(pemain, n) << endl;
    file << "Pemain yang tereliminasi : " << eliminasi(pemain, n) << endl;
}