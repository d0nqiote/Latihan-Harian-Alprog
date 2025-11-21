/*
Nama Program    :Detect Capital
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :21 November 2025
Waktu Awal      :22:46
Waktu Akhir     :
Deskripsi       :We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.
*/

#include <iostream>
using namespace std;

bool allCapital(string s){
    for(char c : s){
        if(!isupper(c)) return false;
    }
    return true;
}

bool allLower(string s){
    for(char c : s){
        if(!islower(c)) return false;
    }
    return true;
}

bool firstLetter(string s){
    if(!isupper(s[0])) return false;
    for(int i = 1; i < s.size(); i++){
        if(!islower(s[i])) return false;
    }
    return true;
}

int main(){
    string word;
    cout << "Input a word to be checked: ";
    cin >> word;

    if(allCapital(word) || allLower(word) || firstLetter(word)){
        cout << "true";
    } else {
        cout << "false";
    }
}