/*
Nama program    :Pengimplementasian rumus f(n) = 2f(n-1) + 4, untuk n > 0
Nama            :Farah Nadia Aqila
NPM             :140810250049
Tanggal dibuat  :30 September 2025
Waktu awal      :15:42
Waktu akhir     :15:53
*/

#include <iostream>
using namespace std;

int fungsiN(int n){
    if(n == 0) return 3;
    return 2 * fungsiN(n - 1) + 4;
}

int main(){
    int n; cin >> n;
    cout << fungsiN(n);
}