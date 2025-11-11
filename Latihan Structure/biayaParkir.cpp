/*
Nama Program     :Biaya parkir
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :24 Oktober 2025
Waktu Awal       :20:05
Waktu Selesai    :21:30
Deskripsi        :Buatlah program untuk mencari jumlah biaya parkir mobil / motor dari selisih 2 waktu (datang dan pulang) dengan aturan 1 jam pertama = Rp. 3000/Rp.2000 dan per jam berikutnya = Rp. 3000 / Rp.2000.
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct parkir{
    int jam;
    int menit;
    int detik;
    string kendaraan;
    int harga;
};

void masukParkir(parkir &datang){
    cout << "Jam berapa datang buat parkir?     : "; cin >> datang.jam;
    cout << "Menit berapa datang buat parkir?   : "; cin >> datang.menit;
    cout << "Detik berapa datang buat parkir?   : "; cin >> datang.detik;
}

void pulangParkir(parkir &pulang){
    cout << "Jam berapa pulang dari parkir?     : "; cin >> pulang.jam;
    cout << "Menit berapa pulang dari parkir?   : "; cin >> pulang.menit;
    cout << "Detik berapa pulang dari parkir?   : "; cin >> pulang.detik;
}


void lamaParkir(parkir datang, parkir pulang, parkir &durasi) {
    if (pulang.detik < datang.detik) {
        pulang.detik += 60;
        pulang.menit -= 1;
    }
    durasi.detik = pulang.detik - datang.detik;

    if (pulang.menit < datang.menit) {
        pulang.menit += 60;
        pulang.jam -= 1;
    }
    durasi.menit = pulang.menit - datang.menit;


    if (pulang.jam < datang.jam) {
        pulang.jam += 24;               //kalau lewat tengah malam
    }
    durasi.jam = pulang.jam - datang.jam;
}

void bayarParkir(parkir durasi, parkir &bayar){
    bayar.kendaraan = "";
    cout << "Pakai kendaraan apa (mobil/motor)? : ";
    cin >> bayar.kendaraan;

    int totalJam = durasi.jam;
    if(durasi.menit > 0 || durasi.detik > 0){
        totalJam += 1;
    }

    bayar.harga = 0;
    if(bayar.kendaraan == "mobil"){
        if(totalJam <= 1){
            bayar.harga = 2000;
        }
        else {
            bayar.harga += 3000 * (totalJam - 1) + 2000;
        }
    }
    
    else if (bayar.kendaraan == "motor"){
        if(totalJam <= 1){
            bayar.harga = 3000;
        }
        else {
            bayar.harga += 2000 * (totalJam - 1) + 3000;
        }
    }
}

void tampilProgramParkir(parkir datang, parkir pulang, parkir durasi, parkir bayar) {
    cout << left << setw(25) << "Jam Datang" << " = "
         << setw(2) << datang.jam << " : "
         << setw(2) << datang.menit << " : "
         << setw(2) << datang.detik << endl;

    cout << left << setw(25) << "Jam Pulang" << " = "
         << setw(2) << pulang.jam << " : "
         << setw(2) << pulang.menit << " : "
         << setw(2) << pulang.detik << endl;

    cout << left << setw(25) << "Lama Parkir" << " = "
         << setw(2) << durasi.jam << " : "
         << setw(2) << durasi.menit << " : "
         << setw(2) << durasi.detik << endl;

    cout << left << setw(25) << "Jenis kendaraan" << " = "
         << setw(2) << bayar.kendaraan << endl;

    cout << left << setw(25) << "Bayar" << " = Rp."
         << setw(2) << bayar.harga; 
}

int main(){
    parkir datang;
    parkir pulang;
    parkir durasi;
    parkir harga;

    masukParkir(datang);
    pulangParkir(pulang);
    lamaParkir(datang, pulang, durasi);
    bayarParkir(durasi, harga);
    tampilProgramParkir(datang, pulang, durasi, harga);
}