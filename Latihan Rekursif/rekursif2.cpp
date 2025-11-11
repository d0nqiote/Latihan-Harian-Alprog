/*
Nama program    :Rekursif newton raphson
Nama            :Farah Nadia Aqila
NPM             :140810250049
Tanggal dibuat  :30 September 2025
Waktu awal      :07:15
Waktu akhir     :07:55
*/

#include <iostream>
using namespace std;

float akar(float n, float tebakan, float i){
    if(i == 0) return tebakan;
    float hasil = 0.5 * (tebakan + n / tebakan);
    return akar(n, hasil, i - 1);
}

int main(){
    float n; cin >> n;
    float hasil = akar(n, n / 2, 10);
    cout << "Akar dari " << n << " adalah : " << hasil;
}