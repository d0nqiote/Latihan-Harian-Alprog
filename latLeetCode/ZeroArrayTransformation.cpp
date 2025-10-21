/*
Nama Program    :Zero Array Transformation
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :16 Oktober 2025
Waktu Awal      :13:46
Waktu Akhir     :
Deskripsi       :
*/

#include <iostream>
using namespace std;

typedef int data[100];

int main(){
    cout << "Semua yang diinput harus lebih besar sama dengan 0";

    int a; 
    cout << "Batas data buat array : "; cin >> a;

    data nilai;
    cout << "Masukkan nilai ke dalam array : ";
    for(int i = 0; i < a; i++){
        cin >> nilai[i];
    }

    int m, n;
    cout << "Masukkan baris untuk queries : "; cin >> m;
    cout << "Masukkan kolom untuk queries : "; cin >> n;

    int queries[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> queries[i][j];
        }
    }

    for(int i = 0; i < m; i++){         
        for(int j = 0; j < n; j++){
            if(i == queries[i][j]){
                for(int k = 0  ; k < a; k++){
                    if(nilai[k] != 0){
                        nilai[k]--;
                    } else {
                        nilai[k] = nilai[k];
                    }
                }
            }
        }
    }

}