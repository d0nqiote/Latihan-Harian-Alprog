/*
Nama Program    :Word Break
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :22 Oktober 2025
Waktu Awal      :08:11
Waktu Akhir     :09:23
Deskripsi       :Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

#include <iostream>
#include <string>
using namespace std;

void inputKalimat(string &kalimat){
    cout << "Masukkan kalimat       : ";
    cin >> kalimat;
}

void jumlahKata(int &n){
    cout << "Masukkan jumlah daftarKata   : ";
    cin >> n;
}

void inputKata(string daftarKata[], int n){
    cout << "Masukkan daftarKata          : ";
    for(int i = 0; i < n; i++){
        cin >> daftarKata[i];
    }

}

string gabunganKata(string daftarKata[], int n){
    string kataBaru = "";
    for(int i = 0; i < n; i++){
        const string &kata = daftarKata[i];
        kataBaru += kata;
    }
    return kataBaru;
}

void cekdaftarKata(string kalimat, string daftarKata[], int n){
    string kataBaru = gabunganKata(daftarKata, n);
    bool semuaBenar = true;
    int hasil = 0;

    for(int i = 0; i < kataBaru.length(); i++){
        if(kalimat[i] == kataBaru[i]){
            hasil++;
        } else{
            break;
        }
        

        if(hasil != kataBaru.length()){
            semuaBenar = false;
        }
    }

    if(semuaBenar){
        cout << "true";
    } else {
        cout << "false";
    }
}

int main(){
    string kalimat;
    inputKalimat(kalimat);    

    int n;
    jumlahKata(n);

    string daftarKata[n];
    inputKata(daftarKata, n);    

    cekdaftarKata(kalimat, daftarKata, n);
}