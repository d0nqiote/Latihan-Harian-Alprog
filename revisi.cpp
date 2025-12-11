/*
Nama program    :Game Projek Akhir REVISI
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :09 Desember 2025
Waktu awal      :22:44
Waktu akhir     :21:19 (11 Desember 2025)
Deskripsi       :Projek Akhir Praktikum Algoritma Pemrograman Semester 1 REVISI
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <cctype>
using namespace std;

const int jumlahPemain = 5;
const int NAMA = 20;
const int POIN = 8;
const int TOTAL = NAMA + POIN;

struct game {
    string nama;
    int poin = 0;
};
struct balanceScale{
    int nilai;
    float gap;
};


//fungsi semua game
void delay(double detik){
    this_thread::sleep_for(chrono::milliseconds(int(detik*1000)));
}
void clearTerminal(int detik=0){
    if(detik > 0) delay(detik);

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void displayAkhirGame(){
    cout << "\n\t\t\t\tSELESAI\n";
    cout << string(80, '=') << "\n\n";
}
void swapPlayer(game &a, game &b){
    game temp = a; 
    a = b; 
    b = temp;
}
int cariIndexByNama(game arr[], const string &nama){
    for(int i = 0; i < jumlahPemain; i++){
        if(arr[i].nama == nama) return i;
    }
    return -1;
}
void tambahPoin(game projekAkhir[], const string &nama, int poin){
    int idx = cariIndexByNama(projekAkhir, nama);
    if(idx != -1){
        projekAkhir[idx].poin += poin;
    }
}
void tampilHasilAkhir(ostream &out, game arr[]){
    out << left << setw(NAMA) << "Nama Pemain"
        << right << setw(POIN) << "Poin" << "\n";
    out << string(TOTAL, '=') << "\n";
    for(int i = 0; i < jumlahPemain; i++){
        out << left << setw(NAMA) << arr[i].nama
            << right << setw(POIN) << arr[i].poin << "\n";
    }
    out << string(TOTAL, '=') << "\n";
}
void sortByPoin(game pemain[]) {
    for (int i = 1; i < jumlahPemain; ++i) {
        game key = pemain[i];
        int j = i - 1;

        while (j >= 0 && pemain[j].poin < key.poin) {
            pemain[j + 1] = pemain[j];
            j--;
        }
        pemain[j + 1] = key;
    }
}
void printRankingToFile(ofstream &file, game projekAkhir[]) {
    game ranking[jumlahPemain];

    for(int i = 0; i < jumlahPemain; i++){
        ranking[i] = projekAkhir[i];
    }

    sortByPoin(ranking);
    tampilHasilAkhir(file, ranking);
}


//Balance Scale
void rulesBS(){
    clearTerminal();
    cout << right << setw(60) << "==========================\n"
                 << setw(60) << "        GAME 1          \n"
                 << setw(61) << "===== BALANCE SCALE ======\n\n"
         << "Game ini adalah permainan penentuan peringkat berdasarkan seberapa dekat nilai pemain\n"
         << "  dengan nilai patokan (Balance Scale).\n\n"
         << "RULES:\n"
         << "  1) Masukkan nama 5 pemain.\n"
         << "  2) Masukkan nilai masing-masing pemain.\n"
         << "  3) Program menghitung patokan\n"
         << "  4) Program menghitung selisih tiap pemain\n"
         << "  5) Pemain diurutkan dari selisih terkecil ke terbesar.\n"
         << "  6) Poin diberikan berdasarkan peringkat selisih (yang paling kecil paling besar poin).\n";

    cout << "\nPerhitungan Point:\n";
    cout << " - Rank 1              : +20\n";
    cout << " - Rank 2              : +15\n";
    cout << " - Rank 3              : +10\n";
    cout << " - Rank 4              : +5\n";
    cout << " - Rank 5              : +0\n";

    cout << "\nTekan ENTER untuk lanjut...";
    cin.ignore(10000, '\n');
    cin.get();
}
void inputBS(balanceScale pemain[], game projekAkhir[], game urutanAwal[], int nilaiAwal[]){
    for (int i = 0; i < jumlahPemain; i++){ 
        cout << "Masukkan nama pemain ke-" << i + 1 << "    : ";
        cin >> projekAkhir[i].nama;
        
        cout << "Masukkan nilai pemain ke-" << i + 1 << "   : ";
        cin >> pemain[i].nilai;

        cout << endl;
        urutanAwal[i] = projekAkhir[i];
        nilaiAwal[i] = pemain[i].nilai;
    }     
}
float meanBS(balanceScale pemain[]){
    float total = 0;
    for (int i = 0; i < jumlahPemain; i++){
        total += pemain[i].nilai;
    }
    return (total / float(jumlahPemain)) * 0.8;
}
void gapBS(balanceScale pemain[], float mean){
    for (int i = 0; i < jumlahPemain; i++){
        float gapSementara = pemain[i].nilai - mean;
        pemain[i].gap = (gapSementara < 0) ? -gapSementara : gapSementara;
    }
}
void swapBS(balanceScale &a, balanceScale &b){
    balanceScale temp = a;
    a = b;
    b = temp;
}
void sortGapBS(balanceScale pemain[], game projekAkhir[]){
    for (int i = 1; i < jumlahPemain; i++){
        balanceScale tempB = pemain[i];
        game tempG = projekAkhir[i];

        int j = i - 1;
        while (j >= 0 && pemain[j].gap > tempB.gap){
            pemain[j + 1] = pemain[j];
            projekAkhir[j + 1] = projekAkhir[j];
            j--;
        }

        pemain[j + 1] = tempB;
        projekAkhir[j + 1] = tempG;
    }
}
void mainGameBS(balanceScale pemain[],game projekAkhir[], game urutanAwal[], int nilaiAwal[]){
    inputBS(pemain, projekAkhir, urutanAwal, nilaiAwal);
    float rata = meanBS(pemain);
    gapBS(pemain, rata);

    balanceScale rankBS[jumlahPemain];
    game rankGame[jumlahPemain];
    for(int i = 0; i < jumlahPemain; i++){
        rankBS[i] = pemain[i];
        rankGame[i] = projekAkhir[i];
    } 

    sortGapBS(rankBS, rankGame);

    tambahPoin(projekAkhir, rankGame[0].nama, 20);
    tambahPoin(projekAkhir, rankGame[1].nama, 15);
    tambahPoin(projekAkhir, rankGame[2].nama, 10);
    tambahPoin(projekAkhir, rankGame[3].nama, 5);
    tambahPoin(projekAkhir, rankGame[4].nama, 0);
}
void printBS(balanceScale pemain[], game projekAkhir[], game urutanAwal[], int nilaiAwal[]){
    ofstream file("GameProjekAkhir.txt");
    mainGameBS(pemain, projekAkhir, urutanAwal, nilaiAwal);

    file << "=== HASIL PERMAINAN BALANCE SCALE ===" << endl << endl;
    printRankingToFile(file, projekAkhir);

    clearTerminal(1);
}
void gameBalanceScale(balanceScale pemain[], game projekAkhir[], game urutanAwal[], int nilaiAwal[]){
    printBS(pemain, projekAkhir, urutanAwal, nilaiAwal);
    clearTerminal(1.5);
    displayAkhirGame();
}


//Russian Roulette
void rulesRR(){
    clearTerminal();
     cout << right << setw(60) << "==========================\n"
                 << setw(60) << "        GAME 2          \n"
                 << setw(61) << "==== RUSSIAN ROULETTE ====\n\n"
         << "Game ini adalah permainan keberuntungan dengan revolver virtual yang memiliki 30 chamber.\n"
         << "  Satu peluru dipilih acak, dan pemain yang terkena peluru dinyatakan kalah.\n\n"
         << "RULES:\n"
         << "  1) Posisi peluru dipilih acak dari 30 chamber.\n"
         << "  2) Pemain bermain bergiliran sesuai urutan pemain.\n"
         << "  3) Saat giliran, pemain memilih jumlah tembakan (1-30).\n"
         << "  4) Setiap tembakan, chamber aktif maju 1 langkah.\n"
         << "  5) Jika chamber aktif tepat di posisi peluru, pemain itu kalah dan game selesai.\n";

    cout << "\nPerhitungan Point:\n";
    cout << " - Kalah: -30\n";
    cout << " - (Pemain lain tidak mendapat poin tambahan)\n";

    cout << "\nTekan ENTER untuk lanjut...";
    cin.ignore(10000, '\n');
    cin.get();
}
int inputRR(int giliran, game urutanAwal[]){
    int jumlahTembakan;
    while (true){
        cout << urutanAwal[giliran].nama << " akan menembak berapa kali? (1-30) : ";
        cin >> jumlahTembakan;

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input harus angka!\n";
            continue;
        }

        if (jumlahTembakan >= 1 && jumlahTembakan <= 30){
            break;
        }

        cout << "Pilih angka dari 1 - 30!\n";
    }
    return jumlahTembakan;
}
int tembakanRR(int &chamberAktif, int posisiPeluru, int jumlahTembakan, int pemain){
    for (int i = 0; i < jumlahTembakan; i++){
        cout << "DOR!" << endl;
        delay(0.5);

        if (chamberAktif == posisiPeluru){
            return pemain;  // pemain kalah
        }

        chamberAktif = (chamberAktif + 1) % 30;
    }
    cout << endl;
    return -1; // pemain selamat
}
int poinRR(game projekAkhir[], int pemainKalah){
    projekAkhir[pemainKalah].poin -= 30;
    return pemainKalah;
}
int mainGameRR(game projekAkhir[], game urutanAwal[]){
    int posisiPeluru = rand() % 30;
    int chamberAktif = 0;

    int giliran = 0;
    int pemainKalah = 0;
    while (true){
        int pemain = giliran % jumlahPemain; 
        int kalah = tembakanRR(chamberAktif, posisiPeluru, inputRR(pemain, urutanAwal), pemain);

        if (kalah != -1){
            pemainKalah = kalah; 
            break;
        }

        giliran++;
    }

    string namaKalah = urutanAwal[pemainKalah].nama;

    int indexKalah = 0;
    for (int i = 0; i < jumlahPemain; i++){
        if (projekAkhir[i].nama == namaKalah){
            indexKalah = i;
            break;
        }
    }

    poinRR(projekAkhir, indexKalah);
    
    return indexKalah;
}
void printRR(game projekAkhir[], int indexKalah){
    ofstream file("GameProjekAkhir.txt", ios::app);

    file << endl << "=== HASIL PERMAINAN RUSSIAN ROULETTE ===" << endl << endl;
    file << projekAkhir[indexKalah].nama
         << " kalah dan kehilangan 30 poin!\n\n";

    printRankingToFile(file, projekAkhir);
}
void gameRussianRoulette(game projekAkhir[], game urutanAwal[]){
    int indexKalah = mainGameRR(projekAkhir, urutanAwal);
    printRR(projekAkhir, indexKalah);
    clearTerminal(1.5);
    displayAkhirGame();
}


//Hang Word
void rulesHW(){
    clearTerminal();
     cout << right << setw(60) << "=======================\n"
                 << setw(60) << "        GAME 3        \n"
                 << setw(61) << "====== HANG WORD ======\n\n"
         << "Game ini adalah permainan tebak kata dan pemain harus menebak sebelum nyawa habis.\n\n"
         << "RULES:\n"
         << "  1) Setiap pemain bermain satu per satu.\n"
         << "  2) Nyawa awal tiap pemain = 6.\n"
         << "  3) Pemain boleh menebak:\n"
         << "     - Satu huruf atau Satu kata.\n"
         << "  4) Tebakan hanya boleh huruf.\n"
         << "  5) Jika menebak huruf yang sama lagi, diminta menebak ulang (tidak mengurangi nyawa).\n"
         << "  6) Jika tebakan salah, nyawa berkurang 1.\n"
         << "  7) Menang jika kata berhasil ditebak sebelum nyawa 0.\n"
         << "     Kalah jika nyawa = 0.\n";

    cout << "\nPerhitungan Point:\n";
    cout << " - Menang: +50\n";
    cout << " - Kalah : -50\n";

    cout << "\nTekan ENTER untuk lanjut...";
    cin.ignore(10000, '\n');
    cin.get();
}
int indeksHW(){
    return rand() % 100;
}
string bacaJawabanHW(int indeks) {
    ifstream in("answer.txt");
    string jawabanHW[100];

    for(int i = 0; i < 100; i++){
        getline(in, jawabanHW[i]);
    }

    return jawabanHW[indeks];
}
void bacaHintHW(int indeks, string &h1, string &h2, string &h3) {
    ifstream in("hint.txt");
    string hint;

    for(int i = 0; i < indeks * 3; i++){
        getline(in, hint);
    }

    getline(in,h1); 
    getline(in,h2); 
    getline(in,h3);
}
void tampilGambarHW(int nyawa, string hint1, string hint2, string hint3, string jawabanPemain){
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
string inputTebakanHW(int pemain, game urutanAwal[]){
    while (true){
        cout << "Tebakan " << urutanAwal[pemain].nama << "  : ";

        string tebakanPemain;
        cin >> tebakanPemain;

        
        for(int i = 0; i < tebakanPemain.length(); i++){
            tebakanPemain[i] = tolower(tebakanPemain[i]); 
        }

        bool semuaHuruf = true;
        for (char c : tebakanPemain){
            if (c < 'a' || c > 'z'){
                semuaHuruf = false;
                break;
            }
        }

        if (!semuaHuruf){
            cout << "Input hanya boleh huruf (a-z)" << endl << endl;
            continue;
        }

        if (tebakanPemain.length() >= 1){
            return tebakanPemain;
        }
    }
}
bool cekJawabanHW(string tebakanPemain, string &jawabanPemain, string jawabanHW) {
    bool found = false;

    //input 1 huruf
    if (tebakanPemain.length() == 1) {
        char huruf = tebakanPemain[0];
        for (int i = 0; i < jawabanHW.length(); i++) {
            if (huruf == jawabanHW[i]) {
                jawabanPemain[i] = huruf;
                found = true;
            }
        }
    }

    //input 1 kata
    if (tebakanPemain.length() == jawabanHW.length()) {
        if (tebakanPemain == jawabanHW) {
            jawabanPemain = jawabanHW;
            found = true;
        }
    }

    return found;
}
void listTebakan(string tebakanPemain, int banyakTebakan, char hurufDitebak[]){
    if (tebakanPemain.length() == 1){
        hurufDitebak[banyakTebakan] = tebakanPemain[0];
    }
}
bool cekTebakanPemainHW(string tebakanPemain, int banyakTebakan, char hurufDitebak[]){
    bool found = false;
    if (tebakanPemain.length() == 1){
        for(int i = 0; i < banyakTebakan; i++){
            if(tebakanPemain[0] == hurufDitebak[i]){
                return true;
            }
        }
    }
    return false;
}
void poinHW(game projekAkhir[], game urutanAwal[], int pemain, bool menang){
    if(menang){
        tambahPoin(projekAkhir, urutanAwal[pemain].nama, +50);
    }
    else {
        tambahPoin(projekAkhir, urutanAwal[pemain].nama, -50);
    }
}
void mainGameHW(game projekAkhir[], game urutanAwal[]){
    int nyawa;

    for(int i = 0; i < jumlahPemain; i++){
        nyawa = 6;
        int banyakTebakan = 0;
        char hurufDitebak[26] = {0};

        int indeks = indeksHW();
        string jawabanHW = bacaJawabanHW(indeks);
        string hint1, hint2, hint3;
        bacaHintHW(indeks, hint1, hint2, hint3);
        
        string jawabanPemain(jawabanHW.length(), '_');
        cout << urutanAwal[i].nama << " silakan bermain" << endl;;
        cout << "Kata yang harus ditebak adalah: " << jawabanPemain << endl << endl;

        while(nyawa > 0 && jawabanPemain != jawabanHW){
            string tebakanPemain = inputTebakanHW(i, urutanAwal);
            
            if (!cekTebakanPemainHW(tebakanPemain, banyakTebakan, hurufDitebak)){
                listTebakan(tebakanPemain, banyakTebakan, hurufDitebak);
                banyakTebakan++;
            } else {
                cout << "Huruf sudah pernah ditebak, tebak huruf lain!" << endl << endl;
                continue;
            }

            bool jawabanPemainBenar = cekJawabanHW(tebakanPemain, jawabanPemain, jawabanHW);        
            if (!jawabanPemainBenar){
                nyawa--;
                cout << endl << "Tebakan salah, sisa nyawa: " << nyawa << endl;
                tampilGambarHW(nyawa, hint1, hint2, hint3, jawabanPemain);
            } else {
                cout << "Jawaban    : " << jawabanPemain << endl;
            }
        }

        cout << endl << endl;

        bool menang = (jawabanPemain == jawabanHW);
        poinHW(projekAkhir, urutanAwal, i, menang);
        if(!menang){
            cout << "Kamu kalah! Kata yang harus ditebak adalah: " << jawabanHW << endl;
            cout << endl << endl;
        }
    }
}
void printHW(game projekAkhir[]){
    ofstream file("GameProjekAkhir.txt", ios::app);

    file << endl << endl;
    file << "=== HASIL PERMAINAN HANG WORD ===" << endl << endl;
    printRankingToFile(file, projekAkhir);
}
void gameHW(game projekAkhir[], game urutanAwal[]){
    mainGameHW(projekAkhir, urutanAwal);
    printHW(projekAkhir);
    clearTerminal(1.5);
    displayAkhirGame();
}


int main(){
    int n = jumlahPemain;
    balanceScale pemain[n];
    game projekAkhir[n];
    game urutanAwal[n];
    int nilaiAwal[n];

    srand((unsigned)time(0));

    //Balance Scale
    rulesBS();
    gameBalanceScale(pemain, projekAkhir, urutanAwal, nilaiAwal);


    //russian roulette
    rulesRR();
    gameRussianRoulette(projekAkhir, urutanAwal);


    //hang man
    rulesHW();
    gameHW(projekAkhir, urutanAwal);
}