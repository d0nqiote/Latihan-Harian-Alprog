/*
Nama program    :Hangman Word
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :6 Desember 2025
Waktu awal      :21:00
Waktu akhir     :23:00 7 Desember 2025
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int jumlahPemain = 5;

struct game{
    string nama;
    int poin = 0;
};

int indeksHangWord(){
    srand(time(0));
    return rand() % 100;
}

string masukkanJawabanHangWord(int indeks){
    ifstream in("answer.txt");
    string jawabanHangWord[100];

    for(int i = 0; i < 100; i++){
        getline(in, jawabanHangWord[i]);
    }

    return jawabanHangWord[indeks];
}

void masukkanHintHangWord(int indeks, string &hint1, string &hint2, string &hint3){
    ifstream in("hint.txt");
    string hint;

    for(int i = 0; i < indeks * 3; i++){
        getline(in, hint);
    }

    getline(in, hint1);
    getline(in, hint2);
    getline(in, hint3);
}

void gambarHangWord(int nyawa, string hint1, string hint2, string hint3, string jawabanPemain){
    switch(nyawa){
        case 6 :
            cout << jawabanPemain << endl << endl;
            for (int i = 0; i < 7; i++) {
                cout << "|" << endl;
            }
            break;
        case 5:
            cout << jawabanPemain << endl;
            cout << "-------------" << endl;
            for (int i = 0; i < 7; i++) {
                cout << "|" << endl;
            }
            cout << endl;
            break;
        case 4:
            cout << jawabanPemain << endl;
            cout << "-------------" << endl;
            for (int i = 0; i < 7; i++) {
                if (i < 2)
                    cout << "|           |" << endl;
                else
                    cout << "|" << endl;
            }
            break;
        case 3:
            cout << jawabanPemain << endl;
            cout << hint1 << endl;
            cout << "-------------" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|           O" << endl;
            for (int i = 0; i < 5; i++)
                cout << "|" << endl;
            break;
        case 2:
            cout << jawabanPemain << endl;
            cout << hint2 << endl;
            cout << "-------------" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|           O" << endl;
            cout << "|           |" << endl;
            for (int i = 0; i < 3; i++)
                cout << "|" << endl;
            break;
        case 1:
            cout << jawabanPemain << endl;
            cout << hint3 << endl;
            cout << "-------------" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|           O" << endl;
            cout << "|          /|\\" << endl;
            for (int i = 0; i < 3; i++)
                cout << "|" << endl;
            break;
        case 0:
            cout << jawabanPemain << endl;
            cout << "-------------" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|           O" << endl;
            cout << "|          /|\\" << endl;
            cout << "|          / \\" << endl;
            cout << "|" << endl;
            cout << "GAME OVER!" << endl;
            break;
    }
}

char inputTebakanHangWord(int pemain, game projekAkhir[]){
    char tebakanPemain;
    cout << "Tebakan " << projekAkhir[pemain].nama << ": ";
    cin >> tebakanPemain;
    return tebakanPemain;
}

bool cekJawabanHangWord(char tebakanPemain, string &jawabanPemain, string jawabanHangWord){
    bool foundjawaban = false;
    for(int i = 0; i < jawabanHangWord.length(); i++){
        if(tebakanPemain == jawabanHangWord[i]){
            jawabanPemain[i] = tebakanPemain;
            return true;
        }
    }
    return false;
}

void hurufYangSudaDitebak(char tebakanPemain, int banyakTebakan, char hurufDitebak[]){
    hurufDitebak[banyakTebakan] = tebakanPemain;
}

bool cekTebakanPemainHangWord(char tebakanPemain, int banyakTebakan, char hurufDitebak[]){
    bool found = false;
    for(int i = 0; i < banyakTebakan; i++){
        if(tebakanPemain == hurufDitebak[i]){
            return true;
        }
    }
    return false;
}

void sortByPoin(game projekAkhir[]){
    for(int i = 1; i < 5; i++){
        for(int j = i; j >= 1; j--){
            if(projekAkhir[j].poin > projekAkhir[j-1].poin){
                swap(projekAkhir[j], projekAkhir[j-1]);
            } else {
                break;
            }
        }
    }
}

void poinHangWord(game &pemain, bool menang){
    if (menang){
        pemain.poin += 50; 
        cout << "Kamu menang!" << endl;
        cout << pemain.nama << " mendapatkan 50 poin!!!";
        cout << endl << endl;
    } else {
        pemain.poin -= 20;
        cout << "Kamu kalah!" << endl;
        cout << pemain.nama << " kehilangan 20 poin!!!";
        cout << endl << endl;
    }
}

void mainGameHangWord(game projekAkhir[]){
    int nyawa;

    for(int i = 0; i < 5; i++){
        nyawa = 6;
        int banyakTebakan = 0;
        char hurufDitebak[26] = {0};

        int indeks = indeksHangWord();
        string jawabanHangWord = masukkanJawabanHangWord(indeks);
        string hint1, hint2, hint3;
        masukkanHintHangWord(indeks, hint1, hint2, hint3);
        
        string jawabanPemain(jawabanHangWord.length(), '_');
        cout << projekAkhir[i].nama << " silakan bermain" << endl;;
        cout << "Kata yang harus ditebak adalah: " << jawabanPemain << endl << endl;

        while(nyawa > 0 && jawabanPemain != jawabanHangWord){
            char tebakanPemain = inputTebakanHangWord(i, projekAkhir);
            
            if (!cekTebakanPemainHangWord(tebakanPemain, banyakTebakan, hurufDitebak)){
                hurufYangSudaDitebak(tebakanPemain, banyakTebakan, hurufDitebak);
                banyakTebakan++;
            } else {
                cout << "Huruf sudah pernah ditebak, tebak huruf lain!" << endl << endl;
                continue;
            }

            if (!cekJawabanHangWord(tebakanPemain, jawabanPemain, jawabanHangWord)){
                nyawa--;
                cout << endl << "Tebakan salah, sisa nyawa: " << nyawa << endl;
                gambarHangWord(nyawa, hint1, hint2, hint3, jawabanPemain);
            } else {
                cout << "Jawaban    : " << jawabanPemain << endl;
            }

        }

        bool menang = (jawabanPemain == jawabanHangWord);
        poinHangWord(projekAkhir[i], menang);
        if(!menang){
            cout << "Kamu kalah! Kata yang harus ditebak adalah: " << jawabanHangWord << endl;
            cout << endl << endl;
        }
    }
}

int main(){
    int indeks;
    string hint1, hint2, hint3;
    game projekAkhir[5];
    projekAkhir[0].nama = {"andi"};
    projekAkhir[1].nama = {"bina"};
    projekAkhir[2].nama = {"candra"};
    projekAkhir[3].nama = {"dion"};
    projekAkhir[4].nama = {"eri"};

    mainGameHangWord(projekAkhir);

    ofstream file("HangWord.txt");
    sortByPoin(projekAkhir);

    file << left << setw(25) << "Nama Pemain"
                 << setw(10) << "Poin" << endl;

    file << string(35, '=') << endl;

    for (int i = 0; i < jumlahPemain; i++) {
        file << left << setw(25) << projekAkhir[i].nama
                     << setw(10) << projekAkhir[i].poin << endl;
    }
}