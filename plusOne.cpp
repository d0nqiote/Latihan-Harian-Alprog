/*
Nama program    :Plus One
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :05 November 2025
Waktu awal      :23:38
Waktu akhir     :
Deskripsi       :You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> data;
    int n;

    cout << "Masukkan angka (akhiri dengan -1)" << endl;
    while(cin >> n && n != -1){
        data.push_back(n);
    }

    int simpan = 1;
    for(int i = data.size(); i >= 0; i--){
        data[i] += simpan;
        if(data[i] > 9){
            data[i] = 0;
            simpan = 1;
        } else {
            simpan = 0;
            break;
        }
    }

    cout << "[";
    for(int i = 0; i < data.size(); i++) {
        cout << data[i];
        if(i != data.size() - 1){ 
            cout << ", ";
        }
    }
    cout << "]";
}