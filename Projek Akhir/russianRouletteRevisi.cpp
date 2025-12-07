/*
Nama program    :Russian Roulette Revisi
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :27 November 2025
Waktu awal      :16:21
Waktu akhir     :17:16
Deskripsi       :
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int jumlahPemain = 5;

int inputJumlahTembakan(int pemain){
    int jumlahTembakan;
    cout << "Pemain ke-" << pemain << " akan menembak berapa kali? ";
    cin >> jumlahTembakan;
    return jumlahTembakan;
}

int prosesTembakanRussianRoulette(int &chamberAktif, int posisiPeluru, int jumlahTembakan, int pemain){
    for(int i = 0; i < jumlahTembakan; i++){
        cout << "DOR" << endl;
        if(chamberAktif == posisiPeluru){
            return pemain;
        }
        chamberAktif = (chamberAktif + 1) % 30;
    }
    return 0;
}

int mainGameRussianRoulette(){
    int posisiPeluru = rand() % 30;
    int chamberAktif = 0;

    int giliran = 0;
    while(true){
        int pemain = (giliran % jumlahPemain) + 1;
        giliran++;
        
        int tembak = inputJumlahTembakan(pemain);
        int kalah = prosesTembakanRussianRoulette(chamberAktif, posisiPeluru, tembak, pemain);

        if(kalah != 0){
            return kalah;
        }
    }
}

int main(){
    srand(time(0));
    int kalah = mainGameRussianRoulette();
    cout << "Pemain " << kalah << " kalah!" << endl;
}