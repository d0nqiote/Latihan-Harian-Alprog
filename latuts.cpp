#include <iostream>
using namespace std;

typedef int data[100];

void banyakData(int &n);
void target(int &a);
void array(data nilai, int n);
void jumlah(data nilai, int n, int target);
void hapus(data nilai, int n, int target);
void pindah(int &a, int &b);

int main(){
    int n, a;
    data nilai;

    banyakData(n);
    array(nilai, n);
    target(a);
    hapus(nilai, n, a);

}

void banyakData(int &n){
    cout << "Masukkan banyak data untuk array : ";
    cin >> n;
}

void target(int &a){
    cout << "Masukkan nilai target : ";
    cin >> a;
}

void array(data nilai, int n){
    cout << "Masukkan nilai ke dalam array : ";
    for(int i = 0; i < n; i++){
        cin >> nilai[i];
    }
}

void jumlah(data nilai, int n, int target){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nilai[j] + nilai[i] == target){
                cout << "[" << j << ", " << i << "]";
                break;
            }
        }
    }
}

void pindah(int &a, int &b){
    int hasil = a;
    a = b;
    b = hasil;
}

void hapus(data nilai, int n, int target){
    int hasil = n;
    for(int i = 0; i < hasil;){
        if(nilai[i] == target){
            for(int j = i; j < hasil - 1; j++){
                nilai[j] = nilai[j+1];
            } 
            hasil--;
        } else {
            i++;
        }
    }
    
    cout << hasil << endl;
    cout << "[";
    for(int i = 0; i < n; i++){
        if(i < hasil){
            cout << nilai[i];
        } else {
            cout << "_";
        }
        if(i != hasil - 1){
            cout << ", ";
        }
    }
    cout << "]";
}