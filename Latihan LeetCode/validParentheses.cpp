/*
Nama program    :Valid Parentheses
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :08 Desember 2025
Waktu awal      :21:30
Waktu akhir     :22:13
Deskripsi       :Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream>
#include <vector>
using namespace std;

bool benar(string s) {
    vector<char> kurung;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            kurung.push_back(c);
        else {
            if (kurung.empty()) return false;
            if (c == ')' && kurung.back() != '(') return false;
            if (c == ']' && kurung.back() != '[') return false;
            if (c == '}' && kurung.back() != '{') return false;
            kurung.pop_back();
        }
    }
    return kurung.empty();
}

int main(){
    string s;
    bool leetCode = benar(s);
    if(leetCode){
        cout << "true";
    } else {
        cout << "false";
    }
}