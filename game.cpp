/*
Nama program    :Balance Scale
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :09 November 2025
Waktu awal      :22:33
Waktu akhir     :
Deskripsi       :Projek Akhir Praktikum Alprog
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int jumlahPemain = 5;

struct pemain{
    string nama;
    int poin = 0;
};

struct balanceScale{
    pemain game1;
    int nilai;
    float gap;
};

void inputAngka (balanceScale player[]){
    cout << "Masukkan angka pilihan anda (0-100)" << endl;
    for(int i = 0; i < 5; i++){
        cout << "Masukkan nilai dan nama pemain ke-" << i + 1 << " : ";
        cin >> player[i].nilai >> player[i].game1.nama;
    }
}

void swap(balanceScale &a, balanceScale &b){
    balanceScale temp = a; 
    a = b; 
    b = temp;
}

float intiGame1(balanceScale player[]){
    int hasil = 0;
    for(int i = 0; i < 5; i++){
        hasil += player[i].nilai;
    }
    return hasil /5.0 * 0.8;
}

void jarak(balanceScale player[]){
    float mean = intiGame1(player);
    for(int i = 0; i < 5; i++){
        float gapSementara = player[i].nilai - mean;

        if(gapSementara < 0){
            player[i].gap = gapSementara * -1;
        } else {
            player[i].gap = gapSementara;
        }
    }
}

void sorting(balanceScale player[]){
    for(int i = 1; i < 5; i++){
        for(int j = i; j >= 1; j--){
            if(player[j].gap > player[j-1].gap){
                swap(player[j], player[j-1]);
            } else {
                break;
            }
        }
    }
}

void point(balanceScale player[]){
    sorting(player);

    player[0].game1.poin += 0;
    player[1].game1.poin += 10;
    player[2].game1.poin += 20;
    player[3].game1.poin += 30;
    player[4].game1.poin += 40;
}

void outputData(ofstream &file, balanceScale player[]){
    file << left << setw(20) << "Nama player" 
         << right << setw(10) << "Nilai"
         << right << setw(10) << "Poin" << endl;
    file << "------------------------------------------" << endl;
    
    for (int i = 0; i < 5; i++) {
        file << left << setw(20) << player[i].game1.nama
             << right << setw(10) << player[i].nilai
             << right << setw(10) << player[i].game1.poin << endl;
    }
    file << "------------------------------------------" << endl;
}

void output1(balanceScale player[]){
    ofstream file("BalanceScale.txt");

    inputAngka(player);
    jarak(player);
    sorting(player);
    point(player);
    outputData(file, player);

    file << "Nilai Balance Scale      : " << fixed << setprecision(2) << intiGame1(player) << endl;
}

int main(){
    //game 1
    balanceScale player[5];
    output1(player);

    //game 2
}