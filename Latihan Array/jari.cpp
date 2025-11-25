/*
Nama program    :
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :10 November 2025
Waktu awal      :19:11
Waktu akhir     :22:57
Deskripsi       :
*/

#include <iostream>

using namespace std;

struct data{
    int kanan;
    int kiri;
};

void combine(data pemain[], int idx){
    int temp = pemain[idx].kanan + pemain[idx].kiri;
    pemain[idx].kiri = temp;
    pemain[idx].kanan = 0;
}   

void split(data pemain[], int idx){
    int temp = pemain[idx].kiri;
    int mid = temp / 2;
    pemain[idx].kiri = mid;
    pemain[idx].kanan = temp - mid;
}

void eliminasi(struct data pemain[]) {
    for (int i = 0; i < 2; i++) {
        pemain[i].kanan = 1;
        pemain[i].kiri = 1;
    }

    int giliran = 0;
    char lawan, sendiri;
    string pilihan;
    do{
        cout << "--- Giliran pemain " << giliran + 1 << " ---" << endl;
        cout << "P1: L(" << pemain[0].kiri << ") R(" << pemain[0].kanan << ")" << endl;
        cout << "P2: L(" << pemain[1].kiri << ") R(" << pemain[1].kanan << ")" << endl;


        cout << "Ingin menambah jari lawan yang mana? (L/R)" << endl;
        cin >> lawan;
        cout << "Memakai tangan yang mana? (L/R)" << endl;
        cin >> sendiri;

        lawan = toupper(lawan);
        sendiri = toupper(sendiri);

        int serang = giliran;
        int target = 1 - giliran;

        int jariSendiri;
        if(sendiri == 'L'){
            jariSendiri = pemain[serang].kiri;
        } else if (sendiri == 'R') {
            jariSendiri = pemain[serang].kanan;
        }

        if(jariSendiri == 0){
            cout << "Pilih jari lain" << endl;
            continue;
        }

        if (lawan == 'L') {
            pemain[target].kiri = (pemain[target].kiri + jariSendiri) % 5;
        } else if (lawan == 'R') {
            pemain[target].kanan = (pemain[target].kanan + jariSendiri) % 5;
        }

        if ((lawan == 'L' && pemain[target].kiri == 0) || (lawan == 'R' && pemain[target].kanan == 0)) {
        cout << "Tangan lawan sudah mati, pilih tangan lain!" << endl;
        continue;
        }

        cout << "Mau SPLIT / COMBINE / NEXT? " << endl;
        cin >> pilihan;
        if(pilihan == "SPLIT"){
            split(pemain, serang);
        } else if (pilihan == "COMBINE"){
            combine(pemain, serang);
        } else if (pilihan == "NEXT"){
            cout << "Lanjut giliran pemain berikutnya" << endl; 
        }

        giliran = 1 - giliran;

    } while ((pemain[0].kiri != 0 || pemain[0].kanan != 0) && (pemain[1].kiri != 0 || pemain[1].kanan != 0));
}

void pemenang(data pemain[]){
    cout << "--- Permainan Selesai ---" << endl;
    if(pemain[0].kiri == 0 && pemain[0].kanan == 0){
        cout << "Pemain 2 menang!!!" << endl;
    } else {
        cout << "Pemain 1 menang!!!" << endl;
    }
}

int main(){
    data pemain[2];
    eliminasi(pemain);
    pemenang(pemain);
}