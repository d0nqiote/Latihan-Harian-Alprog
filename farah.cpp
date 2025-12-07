/*
Nama program    :Game Projek Akhir
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :09 November
Waktu awal      :10:23
Waktu akhir     :
Deskripsi       :Projek Akhir Praktikum Algoritma Pemrograman Semester 1
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int jumlahPemain = 5;
struct balanceScale{
    int nilai;
    float gap;
};
struct game{
    string nama;
    int poin = 0;
};

void displayAkhirGame();
void swap(balanceScale &a, balanceScale &b);
void swap(game &a, game &b);
void sortByPoin(game projekAkhir[]);
void clearTerminal();

//balance scale
void inputAngkaBalanceScale(balanceScale pemain[], game projekAkhir[]);
float hitungBalanceScale(balanceScale pemain[]);
void jarakBalanceScale(balanceScale pemain[]);
void sortingBalanceScale(balanceScale pemain[]);
void poinBalanceScale(game projekAkhir[]);
void outputBalanceScale(balanceScale pemain[], game projekAkhir[], game urutanAwal[]);
void gameBalanceScale(game projekAkhir[], game urutanAwal[], balanceScale pemain[]);

//russian roulette
int inputJumlahTembakan(int pemain, game urutanAwal[]);
int prosesTembakanRussianRoulette(int &chamberAktif, int posisiPeluru, int jumlahTembakan, int pemain);
int mainGameRussianRoulette(game urutanAwal[]);
int poinRussianRoulette(game projekAkhir[], game urutanAwal[], int pemainKalah);
void outputRussianRoulette(game projekAkhir[], int pemainKalah);
void gameRussianRoulette(game projekAkhir[], game urutanAwal[]);

int indeksHangWord();
string masukkanJawabanHangWord(int indeks);
void masukkanHintHangWord(int indeks, string &hint1, string &hint2, string &hint3);
void gambarHangWord(int nyawa, string hint1, string hint2, string hint3, string jawabanPemain);
char inputTebakanHangWord(int pemain, game projekAkhir[]);
bool cekJawabanHangWord(char tebakanPemain, string &jawabanPemain, string jawabanHangWord);
void hurufYangSudaDitebak(char tebakanPemain, int banyakTebakan, char hurufDitebak[]);
bool cekTebakanPemainHangWord(char tebakanPemain, int banyakTebakan, char hurufDitebak[]);
void sortByPoin(game projekAkhir[]);
void poinHangWord(game &pemain, bool menang);
void mainGameHangWord(game projekAkhir[], game urutanAwal[]);
void outputHangWord(game projekAkhir[]);
void gameHangWord(game projekAkhir[], game urutanAwal[]);

int main() {
    srand((unsigned)time(0));
    game urutanAwal[jumlahPemain];
    balanceScale pemain[jumlahPemain];
    game projekAkhir[jumlahPemain];

    //game pertama balance scale
    gameBalanceScale(projekAkhir, urutanAwal, pemain);

    //game ketiga russian roulette
    gameRussianRoulette(projekAkhir,urutanAwal);

    //game kelima hang word
    gameHangWord(projekAkhir, urutanAwal);
}

//fungsi semua
void displayAkhirGame(){
    cout << "\t\t\t\tSELESAI" << endl;
    cout << string(80, '=') << endl << endl << endl;
}
void swap(balanceScale &a, balanceScale &b){
    balanceScale temp = a; 
    a = b; 
    b = temp;
}
void swap(game &a, game &b){
    game temp = a;
    a = b;
    b = temp;
}
void sortByPoin(game projekAkhir[]){
    for(int i = 1; i < jumlahPemain; i++){
        for(int j = i; j >= 1; j--){
            if(projekAkhir[j].poin > projekAkhir[j-1].poin){
                swap(projekAkhir[j], projekAkhir[j-1]);
            } else {
                break;
            }
        }
    }
}
void clearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear"); 
    #endif
}

//game pertama
void inputAngkaBalanceScale(balanceScale pemain[], game projekAkhir[]){
    cout << "Masukkan angka pilihan anda (0-100)" << endl;
    for(int i = 0; i < jumlahPemain; i++){
        cout << "Masukkan nilai dan nama pemain ke-" << i + 1 << " : ";
        cin >> pemain[i].nilai >> projekAkhir[i].nama;
    }
}
float hitungBalanceScale(balanceScale pemain[]){
    int hasil = 0;
    for(int i = 0; i < jumlahPemain; i++){
        hasil += pemain[i].nilai;
    }
    return hasil /(float)jumlahPemain * 0.8;
}
void jarakBalanceScale(balanceScale pemain[]){
    float mean = hitungBalanceScale(pemain);
    for(int i = 0; i < jumlahPemain; i++){
        float gapSementara = pemain[i].nilai - mean;

        if(gapSementara < 0){
            pemain[i].gap = gapSementara * -1;
        } else {
            pemain[i].gap = gapSementara;
        }
    }
}
void sortingBalanceScale(balanceScale pemain[]){
    for(int i = 1; i < jumlahPemain; i++){
        for(int j = i; j >= 1; j--){
            if(pemain[j].gap > pemain[j-1].gap){
                swap(pemain[j], pemain[j-1]);
            } else {
                break;
            }
        }
    }
}
void poinBalanceScale(game projekAkhir[]){
    projekAkhir[0].poin = 0;
    projekAkhir[1].poin = 5;
    projekAkhir[2].poin = 10;
    projekAkhir[3].poin = 15;
    projekAkhir[4].poin = 20;
}
void outputBalanceScale(balanceScale pemain[], game projekAkhir[], game urutanAwal[]){
    ofstream file("GameProjekAkhir.txt");
    inputAngkaBalanceScale(pemain, projekAkhir);
    
    for(int i = 0; i < jumlahPemain; i++){
        urutanAwal[i] = projekAkhir[i];
    }

    jarakBalanceScale(pemain);
    sortingBalanceScale(pemain);
    poinBalanceScale(projekAkhir);
    sortByPoin(projekAkhir);

    file << "=== HASIL PERMAINAN BALANCE SCALE ===" << endl << endl;

    file << left << setw(25) << "Nama Pemain"
         << setw(10) << "Nilai"
         << " |     "  
         << left << setw(25) << "Nama Pemain"
         << setw(10) << "Poin"
         << endl;

    file << string(74, '=') << endl;

    for (int i = 0; i < jumlahPemain; i++) {
        file << left << setw(25) << urutanAwal[i].nama
             << setw(10) << pemain[i].nilai
             << " |     "   
             << left << setw(25) << projekAkhir[i].nama
             << setw(10) << projekAkhir[i].poin
             << endl;
    }

    file << string(74, '=') << endl;

    file << "Nilai Balance Scale : " << fixed << setprecision(2) << hitungBalanceScale(pemain) << endl << endl;
}
void gameBalanceScale(game projekAkhir[], game urutanAwal[], balanceScale pemain[]){
    outputBalanceScale(pemain, projekAkhir, urutanAwal);
    displayAkhirGame();
    clearTerminal();
}

//game ketiga
int inputJumlahTembakan(int pemain, game urutanAwal[]){
    int jumlahTembakan;
    cout << urutanAwal[pemain].nama << " akan menembak berapa kali? ";
    cin >> jumlahTembakan;
    return jumlahTembakan;
}
int prosesTembakanRussianRoulette(int &chamberAktif, int posisiPeluru, int jumlahTembakan, int pemain){
    for(int i = 0; i < jumlahTembakan; i++){
        cout << "DOR" << endl;

        if(chamberAktif == posisiPeluru){
            return pemain; //buat yang kalah
        }

        chamberAktif = (chamberAktif + 1) % 30;
    }
    return -1; //ga mati
}
int mainGameRussianRoulette(game urutanAwal[]){
    int posisiPeluru = rand() % 30;
    int chamberAktif = 0;

    int giliran = 0;
    while(true){
        int pemain = giliran % jumlahPemain;
        string namaPemain = urutanAwal[pemain].nama;
        
        int tembak = inputJumlahTembakan(pemain, urutanAwal);
        int kalah = prosesTembakanRussianRoulette(chamberAktif, posisiPeluru, tembak, pemain);

        if(kalah != -1){
            return kalah;
        }

        giliran++;
    }
}
int poinRussianRoulette(game projekAkhir[], game urutanAwal[], int pemainKalah){
    string namaKalah = urutanAwal[pemainKalah].nama;

    for(int i = 0; i < jumlahPemain; i++){
        if(projekAkhir[i].nama == namaKalah){
            projekAkhir[i].poin -= 10;
            return i;
        }
    }

    return -1;
}
void outputRussianRoulette(game projekAkhir[], int pemainKalah){
    ofstream file("GameProjekAkhir.txt", ios::app);
    sortByPoin(projekAkhir);

    file << endl << endl;
    file << "=== HASIL PERMAINAN RUSSIAN ROULETTE ==="
         << endl << endl;

    file << projekAkhir[pemainKalah].nama
         << " kalah dan kehilangan 10 poin!" 
         << endl << endl;

    file << left << setw(25) << "Nama Pemain"
                 << setw(10) << "Poin" << endl;

    file << string(35, '=') << endl;

    for (int i = 0; i < jumlahPemain; i++) {
        file << left << setw(25) << projekAkhir[i].nama
                     << setw(10) << projekAkhir[i].poin << endl;
    }

    file << string(35, '=') << endl;
}
void gameRussianRoulette(game projekAkhir[], game urutanAwal[]) {
    int pemainKalah = mainGameRussianRoulette(urutanAwal);
    int indexKalah = poinRussianRoulette(projekAkhir, urutanAwal, pemainKalah);
    outputRussianRoulette(projekAkhir, indexKalah);
    displayAkhirGame();
}


//game kelima
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
void mainGameHangWord(game projekAkhir[], game urutanAwal[]){
    int nyawa;

    for(int i = 0; i < jumlahPemain; i++){
        nyawa = 6;
        int banyakTebakan = 0;
        char hurufDitebak[26] = {0};

        int indeks = indeksHangWord();
        string jawabanHangWord = masukkanJawabanHangWord(indeks);
        string hint1, hint2, hint3;
        masukkanHintHangWord(indeks, hint1, hint2, hint3);
        
        string jawabanPemain(jawabanHangWord.length(), '_');
        cout << urutanAwal[i].nama << " silakan bermain" << endl;;
        cout << "Kata yang harus ditebak adalah: " << jawabanPemain << endl << endl;

        while(nyawa > 0 && jawabanPemain != jawabanHangWord){
            char tebakanPemain = inputTebakanHangWord(i, urutanAwal);
            
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
            clearTerminal();
        }

        bool menang = (jawabanPemain == jawabanHangWord);
        poinHangWord(projekAkhir[i], menang);
        if(!menang){
            cout << "Kamu kalah! Kata yang harus ditebak adalah: " << jawabanHangWord << endl;
            cout << endl << endl;
        }
    }
}
void outputHangWord(game projekAkhir[]){
    ofstream file("GameProjekAkhir.txt", ios::app);
    sortByPoin(projekAkhir);

    file << endl << endl;
    file << "=== HASIL PERMAINAN HANG WORD ==="
         << endl << endl;

    file << left << setw(25) << "Nama Pemain"
                 << setw(10) << "Poin" << endl;

    file << string(35, '=') << endl;

    for (int i = 0; i < jumlahPemain; i++) {
        file << left << setw(25) << projekAkhir[i].nama
                     << setw(10) << projekAkhir[i].poin << endl;
    }

    file << string(35, '=') << endl;
}
void gameHangWord(game projekAkhir[], game urutanAwal[]){
    mainGameHangWord(projekAkhir, urutanAwal);
    outputHangWord(projekAkhir);
    displayAkhirGame();
    clearTerminal();
}