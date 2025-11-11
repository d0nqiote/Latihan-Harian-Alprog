
#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;

    int nilai[n];
    for(int i = 0; i < n; i++){
        cin >> nilai[i];
    }

    for(int i = 0; i < n; i++){

        int indeks = n;
        for(int j = 0; j < i;){
            if(nilai[j] == nilai[i]){
                nilai[j] = nilai[j+1];
            } else{
                j++;
            }
        }

        
    }
}