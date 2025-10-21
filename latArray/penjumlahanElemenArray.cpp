/*
Nama Program    :Menambah satu indeks terakhir
Npm             :140810250049
Tanggal         :15 Oktober 2025
Waktu Awal      :00:40
Waktu Akhir     :
Deskripsi       :You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
*/

#include <iostream>
using namespace std;

typedef int array[100];

void banyakData(int &n);
void inputData(array a, int n);
void jumlah(array a, int n);

int main(){
    array a;
    int n;

    banyakData(n);
    inputData(a, n);
    jumlah(a, n);
}

void banyakData(int &n){
    cout << "Masukkan banyak data untuk array : ";
    cin >> n;
}

void inputData(array a, int n){
    cout << "Masukkan nilai untuk array : ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void jumlah(array a, int n){

    int simpan = 1;
    for(int i = n - 1; i >= 0; i--){
        int hasil = a[i] + simpan;
        a[i] = hasil % 10;
        simpan = hasil / 10;
    }

    if(simpan != 0){
        for(int i = n; i > 0; i--){
            a[i] = a[i - 1];
        }
        a[0] = simpan;
        n++;
    }

    cout << "[";
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n - 1){
            cout << ", ";
        }
    }
    cout << "]";
}