/*
Nama program    :Deret Geometri
Nama            :Farah Nadia Aqila
NPM             :140810250049
Tanggal dibuat  :30 September 2025
Waktu awal      :16:06
Waktu akhir     :16:31
Deskripsi       :Koloni bakteri dimulai dari lima buah bakteri. Setiap bakteri, membelah diri menjadi dua bakteri baru setiap satu jam. Berapa jumlah bakteri baru sesudah 4 jam?
*/

#include <iostream>
using namespace std;

int deret(int n){
    if(n == 0) return 5;
    return 2 * deret(n - 1);
}

int main(){
    int n; cin >> n;  
    for(int i = 1; i <= 4; i++){
        cout << "Jam ke " << i << " banyak bakteri = " << deret(i) << endl; 
    }
}

