/*
Nama Program    :Word Frequency
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :22 November 2025
Waktu Awal      :11:02
Waktu Akhir     :11:43
Deskripsi       :Write a bash script to calculate the frequency of each word in a text file words.txt.
For simplicity sake, you may assume:
words.txt contains only lowercase characters and space ' ' characters.
Each word must consist of lowercase characters only.
Words are separated by one or more whitespace characters.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ifstream inputFile("wordFrequency.txt");
    string s;
    vector<string> word;
    while(inputFile >> s){
        word.push_back(s);
    }
    
    for(int i = 0; i < word.size(); i++){
        
        bool sudahAda = false;
        for(int j = 0; j < i; j++){
            if(word[i] == word[j]){
                sudahAda = true;
                break;
            }
        }
        if(sudahAda){
            continue;
        }

        int count = 0;
        for(int j = 0; j < word.size(); j++){
            if(word[i] == word[j]){
                count++;
            }
        }

        cout << word[i] << " " << count << endl;
    }

}
