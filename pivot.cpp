/*
Nama Program    :Mencari di indeks keberapa jumlah di sebelah kiri indeks = jumlah di sebelah kanan indeks
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :15 Oktober 2025
Waktu Awal      :00:14
Waktu Akhir     :00:27
Deskripsi       :Given an array of integers nums, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Return the leftmost pivot index. If no such index exists, return -1.
*/

#include <iostream>
using namespace std;

typedef int array[100];

void banyakData(int &n);
void inputData(array a, int n);
void pivot(array a, int n);

int main(){
    array a;
    int n;

    banyakData(n);
    inputData(a, n);
    pivot(a, n);
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

void pivot(array a, int n){
    for(int i = 0; i < n; i++){ //pivotnya di mana

        int hasilKiri = 0;
        for(int j = 0; j < i; j++){ //jumlah di sebelah kiri pivot
            hasilKiri += a[j];
        }

        int hasilKanan = 0;
        for(int j = i + 1; j < n; j++){ //jumlah di sebelah kiri pivot
            hasilKanan += a[j];
        } 

        if(hasilKiri == hasilKanan){
            cout << i;
        } else{
            cout << "-1";
        }
    }
}