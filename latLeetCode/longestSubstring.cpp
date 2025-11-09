/*
Nama program    :Longest Substring Without Repeating Characters
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :06 November 2025
Waktu awal      :00:50
Waktu akhir     :
Deskripsi       :Given a string s, find the length of the longest substring without duplicate characters.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<char> current;
    vector<char> longest;

    current.push_back(s[0]);

    for(char c : s){ 
        bool found = false;
        for(char v : current){
            if(v == c){
                found = true;
                break;
            }
        }
        
        if(found){
            if(current.size() > longest.size()){
                longest = current;
            }
            current.clear();
        }
        current.push_back(c);
    }
}