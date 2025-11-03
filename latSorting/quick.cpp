/*
Program     :quick Sort
Waktu awal  :13:49
Waktu akhir :
*/

#include <iostream>
using namespace std;

typedef int array[100];

void input(int &n){
    cin >> n;
}

void inputArray(array data, int n){
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }
}

int partition(array data, int l, int r){  
    int pivot = data[l];
    int i = l;
    int j = r;

    while(i < j){
        do{
            i++;
        } while(data[i] <= pivot);

        do{
            j--;
        } while(data[j] > pivot);
    }

    if(i < j){
        swap(data[i], data[j]);
    }
    
    swap(data[l], data[j]);
    return j;
}    

void quickSort(array data, int l, int r){
    if(l < r){
        int j = partition(data, l, r);
        quickSort(data, l, j);
        quickSort(data, j + 1, r);
    }
}

int main(){
    int n;
    input(n);
    array data;
    inputArray(data, n);

    quickSort(data, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}