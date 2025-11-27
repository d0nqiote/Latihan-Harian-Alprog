/*
Nama program    :Russian Roulette
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :18 November 2025 - 
Waktu awal      :11:13 (18 November 2025)
Waktu akhir     :17:33 (20 November 2025)
Deskripsi       :Pemainnya berdua
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

bool allZero(int data[]){
    for(int i = 0; i < 15; i++){
        if(data[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    srand(time(0));
    int index = rand() % 15;
    int data[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    data[index] = 1;

    int k = 3;
    while(!allZero(data)){
        int player = k % 3 + 1;
        int n;
        cout << "Player ke-" << player << " ingin menembak berapa kali? ";
        cin >> n;
        k++;

        bool safe = true;
        for(int i = 0; i < n; i++){
            cout << "DOR" << endl;
            Sleep(500);

            if(data[0] == 1){
                safe = false;
                break;
            }

            for(int j = 0; j < 14; j++){
                data[j] = data[j+1];
            }
            data[14] = 0;
        }

        if(!safe){
            cout << "YOU ARE LOSE";
            break;
        }
    }
}