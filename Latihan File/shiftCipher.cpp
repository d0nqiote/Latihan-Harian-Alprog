/*
Nama Program     :Shift Chiper
Nama             :Farah Nadia Aqila
NPM              :140810250049
Tanggal Dibuat   :11 November 2025
Waktu Awal       :16:54
Waktu Selesai    :17:13
Deskripsi        :Buatlah program untuk melakukan enkripsi shift chiper suatu file teks (dengan asumsi semua karakter huruf adalah huruf kapital).
*/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){
    ofstream file;

    string f;
    string s;
    int n;
    cout << "Masukkan kata yang akan dienkripsi         : "; getline(cin, s);
    cout << "Masukkan jumlah pergeseran huruf           : "; cin >> n;
    cin.ignore();
    cout << "Masukkan nama file untuk hasil enkripsi    : "; getline(cin, f);

    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i])){
            if(islower(s[i])){
                s[i] = (s[i] - 'a' + n) % 26 + 'a';
            } else if(isupper(s[i])){
                s[i] = (s[i] - 'A' + n) % 26 + 'A';
            }
        } else if(isdigit(s[i])){
            s[i] = (s[i] - '0' + n) % 10 + '0';
        }
    }

    file.open(f);
    file << "Hasil enkripsi : " << s << endl;    
}
