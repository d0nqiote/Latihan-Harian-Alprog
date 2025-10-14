#include <iostream>
using namespace std;

typedef int array[100];

void inputNilai(int &n, string tipe){
    cout << tipe << " : ";
    cin >> n;
}

void inputArray(array nilai, int n){
    for (int i = 0; i < n; i++){
        cin >> nilai[i];
    }
}

int main(){
    int n, hapus;
    inputNilai(n, "Data");
    inputNilai(hapus, "Hapus");
    
    array nilai;
    inputArray(nilai, n);

    int hasil = n;
    for(int i = 0; i < hasil;){
        if(nilai[i] == hapus){
            for(int j = i; j < hasil - 1; j++){
                nilai[j] = nilai[j+1];
            }
            hasil -= 1;
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
        if(i != n - 1){
            cout << ", ";
        }
    }
    cout << "]";
}