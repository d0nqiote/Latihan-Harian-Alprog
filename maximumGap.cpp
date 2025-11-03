/*
Nama program    :Maximum Gap
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :03 November 2025
Waktu awal      :15:09
Waktu akhir     :15:27
Deskripsi       :Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.
*/

#include <iostream>
using namespace std;

typedef int arr[100];

void banyakElemen(int &n){
    cout << "Berapa banyak elemen dalam array : " << endl;
    cin >> n;
}

void inputArray(arr data, int n){
    cout << "Masukkan data ke dalam array : " << endl;
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }
}

int cariMax(arr data, int n){
    int maksimal = 0;
    for(int i = 0; i < n - 1; i++){
        if(data[i + 1] - data[i] > maksimal){
            maksimal = data[i + 1] - data[i];
        }
    }
    return maksimal;
}

void maxGap(arr data, int n){
    int maksimal = cariMax(data, n);
    cout << "Gap terbesar adalah " << maksimal;
}

int main(){
    int n;
    banyakElemen(n);
    arr data;
    inputArray(data, n);
    maxGap(data, n);
}