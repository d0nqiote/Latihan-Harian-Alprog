/*
Nama program    :Game Projek Akhir
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :09 November
Waktu awal      :10:23
Waktu akhir     :
Deskripsi       :Projek Akhir Praktikum Algoritma Pemrograman Semester 1
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int jumlahPemain = 5;
struct balanceScale{
    int nilai;
    float gap;
};
struct game{
    string nama;
    int poin = 0;
};

void outputBalanceScale(balanceScale pemain[], game projekAkhir[], game urutanAwal[]);

int mainGameRussianRoulette(int laras[], game urutanAwal[], game projekAkhir[]);
void outputRussianRoulette(game projekAkhir[], int pemainKalah);

int main(){
    srand((unsigned)time(0));
    game urutanAwal[jumlahPemain];

    //game pertama balance scale
    balanceScale pemain[jumlahPemain];
    game projekAkhir[jumlahPemain];
    outputBalanceScale(pemain, projekAkhir, urutanAwal);

    //game ketiga russian roulette
    int laras[30];
    int hasil = mainGameRussianRoulette(laras, urutanAwal, projekAkhir);
    outputRussianRoulette(projekAkhir, hasil);
}

//game pertama
void inputAngkaBalanceScale(balanceScale pemain[], game projekAkhir[]){
    cout << "Masukkan angka pilihan anda (0-100)" << endl;
    for(int i = 0; i < jumlahPemain; i++){
        cout << "Masukkan nilai dan nama pemain ke-" << i + 1 << " : ";
        cin >> pemain[i].nilai >> projekAkhir[i].nama;
    }
    cout << "\t\t\t\tSELESAI" << endl;
    cout << string(80, '=');
    cout << endl << endl << endl;
}
void swap(balanceScale &a, balanceScale &b){
    balanceScale temp = a; 
    a = b; 
    b = temp;
}
float hitungBalanceScale(balanceScale pemain[]){
    int hasil = 0;
    for(int i = 0; i < jumlahPemain; i++){
        hasil += pemain[i].nilai;
    }
    return hasil /(float)jumlahPemain * 0.8;
}
void jarakBalanceScale(balanceScale pemain[]){
    float mean = hitungBalanceScale(pemain);
    for(int i = 0; i < jumlahPemain; i++){
        float gapSementara = pemain[i].nilai - mean;

        if(gapSementara < 0){
            pemain[i].gap = gapSementara * -1;
        } else {
            pemain[i].gap = gapSementara;
        }
    }
}
void sortingBalanceScale(balanceScale pemain[], game projekAkhir[]){
    for(int i = 1; i < jumlahPemain; i++){
        for(int j = i; j >= 1; j--){
            if(pemain[j].gap > pemain[j-1].gap){
                swap(pemain[j], pemain[j-1]);
                swap(projekAkhir[j], projekAkhir[j-1]);
            } else {
                break;
            }
        }
    }
}
void poinBalanceScale(game projekAkhir[]){
    projekAkhir[0].poin = 0;
    projekAkhir[1].poin = 5;
    projekAkhir[2].poin = 10;
    projekAkhir[3].poin = 15;
    projekAkhir[4].poin = 20;
}
void outputBalanceScale(balanceScale pemain[], game projekAkhir[], game urutanAwal[]){
    ofstream file("GameProjekAkhir.txt");
    inputAngkaBalanceScale(pemain, projekAkhir);
    
    for(int i = 0; i < jumlahPemain; i++){
        urutanAwal[i] = projekAkhir[i];
    }

    jarakBalanceScale(pemain);
    sortingBalanceScale(pemain, projekAkhir);
    poinBalanceScale(projekAkhir);

    file << "=== HASIL PERMAINAN BALANCE SCALE ===" << endl << endl;

    file << left << setw(25) << "Nama Pemain"
         << setw(10) << "Nilai"
         << " |     "  
         << left << setw(25) << "Nama Pemain"
         << setw(10) << "Poin"
         << endl;

    file << string(74, '=') << endl;

    for (int i = 0; i < jumlahPemain; i++) {
        file << left << setw(25) << projekAkhir[i].nama
             << setw(10) << pemain[i].nilai
             << " |     "   
             << left << setw(25) << projekAkhir[i].nama
             << setw(10) << projekAkhir[i].poin
             << endl;
    }

    file << string(74, '=') << endl;

    file << "Nilai Balance Scale : " << fixed << setprecision(2) << hitungBalanceScale(pemain) << endl << endl;
}

//game ketiga
bool allZero(int laras[]){
    for(int i = 0; i < 30; i++){
        if(laras[i] != 0){
            return false;
        }
    }
    return true;
}
void resetLarasRussianRoulette(int laras[]){
    for (int i = 0; i < 30; i++) {
        laras[i] = 0;
    }
}
void acakPeluruRussianRoulette(int laras[]){
    resetLarasRussianRoulette(laras);
    int index = rand() % 30;
    laras[index] = 1;
}
void geserPeluruRussianRoulette(int laras[]){
    for(int j = 0; j < 29; j++){
            laras[j] = laras[j+1];
        }
    laras[29] = 0;
}
int inputJumlahTembakanRussianRouelette(int pemain, game projekAkhir[]){
    int jumlahTembakan;
    cout << projekAkhir[pemain - 1].nama << " ingin menembak berapa kali? ";
    cin >> jumlahTembakan;
    return jumlahTembakan;
}
int prosesTembakanRussianRoulette(int laras[], int jumlahTembakan, int pemain){
    for(int i = 0; i < jumlahTembakan; i++){
        cout << "DOR" << endl;

        if(laras[0] == 1){
            return pemain;
        }
        geserPeluruRussianRoulette(laras);
    }
    return 0;
}
void poinRussianRoulette(game projekAkhir[], int pemainKalah){
    projekAkhir[pemainKalah - 1].poin -= 10;
}
int mainGameRussianRoulette(int laras[], game urutanAwal[], game projekAkhir[]){
    acakPeluruRussianRoulette(laras);

    int giliran = 0;
    while(!allZero(laras)){
        int pemain = (giliran % jumlahPemain) + 1;
        giliran++;

        int jumlahTembakan = inputJumlahTembakanRussianRouelette(pemain, urutanAwal);
        int pemainKalah = prosesTembakanRussianRoulette(laras, jumlahTembakan, pemain);

        if(pemainKalah != 0){
            poinRussianRoulette(projekAkhir, pemainKalah);
            cout << "\t\t\t\tSELESAI" << endl;
            cout << string(80, '=');
            return pemainKalah;
        }
    }

    return 0;
}
void outputRussianRoulette(game projekAkhir[], int pemainKalah){
    ofstream file("GameProjekAkhir.txt", ios::app);

    file << endl << endl;
    file << "=== HASIL PERMAINAN RUSSIAN ROULETTE ===" << endl << endl;
    file << "Player ke-" << pemainKalah << " kehilangan 10 poin!" << endl;
    file << left << setw(25) << "Nama Pemain"
         << setw(10) << "Poin" << endl;

    file << string(35, '=') << endl;

    for (int i = 0; i < jumlahPemain; i++) {

        file << left << setw(25) << projekAkhir[i].nama
             << setw(10) << projekAkhir[i].poin << endl;
    }

    file << string(35, '=') << endl;
}