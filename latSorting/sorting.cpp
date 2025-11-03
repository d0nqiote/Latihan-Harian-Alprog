#include <iostream>
using namespace std;

void banyakElemen(int &n){
    cin >> n;
}

void inputArray(int array[], int n){
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int array[], int n){
    for(int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void insertionSort(int array[], int n){
    for(int i = 1; i < n; i++){
        int key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void selectionSort(int array[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;

        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }

        swap(array[i], array[min]);
    }
}

void output(int array[], int n){
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}

int main(){
    int n;
    banyakElemen(n);
    int array[n];
    inputArray(array, n);
    selectionSort(array, n);
    output(array, n);
}