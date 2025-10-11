/*
Nama Program    :Looping
Nama            :Farah Nadia Aqila
NPM             :140810250049
Tanggal Dibuat  :5 Oktober
*/

#include <iostream>
using namespace std;

void pangkat(int basis, int kali){ //awal pengerjaan : 07:05, akhir pengerjaan : 07:19
    cout << "Masukkan basis     : "; cin >> basis;
    cout << "Masukkan panngkat  : "; cin >> kali;
    int hasil = 1;
    for(int i = 1; i <= kali; i++){
        hasil *= basis;
    }
    cout << "Hasil " << basis << " pangkat " << kali << " adalah " << hasil; 
}

void faktorial(int n){ //awal pengerjaan :07:21, akhir pengerjaan : 07:31
    int hasil = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        hasil += hasil * i;
    }
    cout << hasil;
}

void bintangKaki(int n){ //awal pengerjaan 07:34, akhir pengerjaan : 08:04
    cin >> n;
    for(int i = 1; i <= n; i++){ //baris
        for(int h = 1; h <= n; h++){ //banyak segitiga
            for(int j = 1; j <= n - i; j++) cout << " "; //spasi kiri
            for(int j = 1; j <= 2 * i - 1; j++) cout << "*"; //bintang
            for(int k = 1; k <= n - i; k++) cout << " "; //spasi kanan
            cout << " ";
        }
        cout << endl;
    }
}


int main(){
    int n;
    bintangKaki(n);
}