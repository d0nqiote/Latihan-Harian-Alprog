/*
Nama program    :Russian Roulette
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :18 November 2025
Waktu awal      :11:13
Waktu akhir     : 
Deskripsi       :Playernya berdua
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



int main(){
    srand(time(0));
    int index = rand() % 6;
    cout << index + 1 << endl;

    int data[6] = {0, 0, 0, 0, 0, 0};
    data[index] = 1;
    for(int i = 0; i < 6; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    do{
        int i = 1;
        int n;
        cout << "Player ke-" << i << " ingin menembak berapa kali? ";
        cin >> n;
        
        if(index - n >= 0){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < 5; j++){
                    data[j] = data[j+1];
                }
            }
        } else if (data == 0) {
            cout << "ANDA TERELIMINASI";
            break;
        } else {
            cout << "ANDA TERELIMINASI";
            break;
        }
        
        for(int i = 0; i < 6; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    } while(data != 0);
}
