#include <iostream>
using namespace std;

void countsort(int arr[], int n) {
    int maxval = arr[0];                    // mencari nilai maksimum
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxval)
            maxval = arr[i];
    }

    int* cntArr = new int[maxval + 1];      // membuat array count dan inisialisasi dengan 0
    for (int i = 0; i <= maxval; i++)
        cntArr[i] = 0;

    for (int i = 0; i < n; i++)             // menghitung frekuensi tiap elemen
        cntArr[arr[i]]++;


    for (int i = 1; i <= maxval; i++)       // menghitung prefix sum
        cntArr[i] += cntArr[i - 1];

    
    int* ans = new int[n];                  // membuat array hasil output
    for (int i = n - 1; i >= 0; i--) {
        ans[cntArr[arr[i]] - 1] = arr[i];
        cntArr[arr[i]]--;
    }

    
    for (int i = 0; i < n; i++)             // menyalin hasil kembali ke array asli
        arr[i] = ans[i];

                                            // dealokasi memori
    delete[] cntArr;
    delete[] ans;
}

int main() {
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    countsort(arr, n);
    for (int i = 0; i < n; i++)              // mencetak hasil
        cout << arr[i] << " ";

    return 0;
}
