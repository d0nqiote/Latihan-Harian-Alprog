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
#include <cstdlib>
#include <ctime>
using namespace std;

string answer(int &index){
    ifstream cout("answer.txt");
    string answer[100];
    int i = 0;
    
    while(i < 100 && cout >> answer[i]){
        i++;
    }

    index = rand() % i;

    return answer[index];
}

void hint(int index, string &h1, string &h2, string &h3){
    ifstream cout("hint.txt");
    string hint;

    for(int i = 0; i < index * 3; i++){
        getline(cout, hint);
    }

    getline(cout, h1);
    getline(cout, h2);
    getline(cout, h3);
}

int main(){
    cout << endl << endl << endl;
    cout << "=============================================\n";
    cout << "               THE HANGING WORD              \n";
    cout << "=============================================\n\n";
    cout << "A secret word hides in the dark.\n";
    cout << "Each wrong guess brings you closer to the rope.\n";
    cout << "You have 6 chances to survive.\n\n";
    cout << "Guess wisely… \n";
    cout << "Before the darkness wins.\n\n";
    cout << "=============================================\n\n";
    cout << endl;

    srand(time(0));
    string word;
    int index;
    word = answer(index);

    cout << "Here is the secret word!!!" << endl;
    string answer(word.length(), '_');
    cout << answer << endl;

    char guess;
    int live = 6;
    string h1, h2, h3;
    hint(index, h1, h2, h3);

    do{
        cout << "What is your guessed letter? ";
        cin >> guess;
        cout << endl;
        cout << "Player guessed: " << guess << endl;
        cout.flush();

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
                cout << answer << endl;
                cout << "-------------" << endl;
                for (int i = 0; i < 7; i++) {
                    cout << "|" << endl;
                }
                break;

            case 4:
                cout << answer << endl;
                cout << "-------------" << endl;
                for (int i = 0; i < 7; i++) {
                    if (i < 2)
                        cout << "|           |" << endl;
                    else
                        cout << "|" << endl;
                }
                break;

            case 3:
                cout << answer << endl;
                cout << h1 << endl;
                cout << "-------------" << endl;
                cout << "|           |" << endl;
                cout << "|           |" << endl;
                cout << "|           O" << endl;
                for (int i = 0; i < 5; i++)
                    cout << "|" << endl;
                break;

            case 2:
                cout << answer << endl;
                cout << h2 << endl;
                cout << "-------------" << endl;
                cout << "|           |" << endl;
                cout << "|           |" << endl;
                cout << "|           O" << endl;
                cout << "|           |" << endl;
                for (int i = 0; i < 3; i++)
                    cout << "|" << endl;
                break;

            case 1:
                cout << answer << endl;
                cout << h3 << endl;
                cout << "-------------" << endl;
                cout << "|           |" << endl;
                cout << "|           |" << endl;
                cout << "|           O" << endl;
                cout << "|          /|\\" << endl;
                for (int i = 0; i < 3; i++)
                    cout << "|" << endl;
                break;

            case 0:
                cout << answer << endl;
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

    cout << endl;
    if(answer == word){
        cout << "YOU ARE THE REAL WINNER!!" << endl;
    } else {
        cout << "GAME OVER. The word was : " << word << endl;
    }
}