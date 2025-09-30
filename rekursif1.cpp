/*
Nama program    :Rekursif
Nama            :Farah Nadia Aqila
NPM             :140810250049
Tanggal dibuat  :30 September 2025
Waktu awal      :00:05
Waktu akhir     :01:34
*/

#include <iostream>
using namespace std;

int fibonacci(int n){ //bilangan fibonnaci
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci (n - 1) + fibonacci (n - 2);
}

int penulisan(int n){
    if(n <= 0) return 0;

    penulisan(n - 1);
    int hasil = fibonacci(n);
    cout << "Suku ke " << n << " nilainya " << hasil << endl;
    return hasil;
}


int main(){
    int n; cin >> n;
    cout << penulisan(n);
}