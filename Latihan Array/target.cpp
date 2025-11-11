#include <iostream>
using namespace std;

typedef int array[100];

void inputNilai(int &n, string tipe){
    cout << "Besar " << tipe << " : ";
    cin >> n;
}

void inputArray(array nilai, int n){
    for (int i = 0; i < n; i++){
        cin >> nilai[i];
    }
}

void cariTarget(array nilai, int n, int target){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(nilai[i] + nilai[j] == target){
                cout << "[" << nilai[i] << ", " << nilai[j] << "]";
            }
            break;
        }
    }
}

int main(){
    int n, target;
    inputNilai(n, "array");
    
    array nilai;
    inputArray(nilai, n);

    inputNilai(target, "target");
    cariTarget(nilai, n, target);
}