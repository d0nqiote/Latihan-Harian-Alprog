/*
Nama program    :Hangman Word
Nama            :Farah Nadia Aqila
Npm             :140810250049
Tanggal         :10 November 2025
Waktu awal      :08:22
Waktu akhir     :09:10
Deskripsi       :Start the game — choose a secret word and set lives (e.g. 6).
Display blanks for each letter (e.g. _ _ _ _).
Player guesses a letter.
Check the guess:
If correct → reveal the letter(s).
If wrong → reduce one life.
Show progress — updated word, guessed letters, and remaining lives.
Repeat until:
All letters are guessed → player wins
Lives reach 0 → player loses
Reveal the word and ask to play again.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream file("HangWord.txt");
    string word;
    cin >> word;

    string answer(word.length(), '_');
    cout << answer << endl;

    char guess;
    int live = 6;

    do{
        cout << "What is your guessed letter? ";
        cin >> guess;

        bool found = false;
        for(int i = 0; i < word.length(); i++){
            if(guess == word[i]){
                answer[i] = guess;
                found = true;
            }
        }

        if(!found){
            live--;
            cout << "Wrong guess! Lives left: " << live << endl;

        switch (live) {
            case 5:
                cout << "-------------" << endl;
                for (int i = 0; i < 7; i++) {
                    cout << "|" << endl;
                }
                break;

            case 4:
                cout << "-------------" << endl;
                for (int i = 0; i < 7; i++) {
                    if (i < 2)
                        cout << "|           |" << endl;
                    else
                        cout << "|" << endl;
                }
                break;

            case 3:
                cout << "-------------" << endl;
                cout << "|           |" << endl;
                cout << "|           |" << endl;
                cout << "|           O" << endl;
                for (int i = 0; i < 5; i++)
                    cout << "|" << endl;
                break;

            case 2:
                cout << "-------------" << endl;
                cout << "|           |" << endl;
                cout << "|           |" << endl;
                cout << "|           O" << endl;
                cout << "|           |" << endl;
                for (int i = 0; i < 3; i++)
                    cout << "|" << endl;
                break;

            case 1:
                cout << "-------------" << endl;
                cout << "|           |" << endl;
                cout << "|           |" << endl;
                cout << "|           O" << endl;
                cout << "|          /|\\" << endl;
                for (int i = 0; i < 3; i++)
                    cout << "|" << endl;
                break;

            case 0:
                cout << "-------------" << endl;
                cout << "|           |" << endl;
                cout << "|           |" << endl;
                cout << "|           O" << endl;
                cout << "|          /|\\" << endl;
                cout << "|          / \\" << endl;
                cout << "|" << endl;
                cout << "GAME OVER!" << endl;
                break;
        }

        } else{
            cout << answer << endl;
        }
    } while (live != 0 && answer != word);

    if(answer == word){
        cout << "YOU ARE THE REAL WINNER!!" << endl;
    } else {
        cout << "You sucks, the word was : " << word << endl;
    }
}