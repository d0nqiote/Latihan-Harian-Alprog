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
    ifstream file("answer.txt");
    string answer[100];
    int i = 0;
    
    while(i < 100 && file >> answer[i]){
        i++;
    }

    index = rand() % i;

    return answer[index];
}

void hint(int index, string &h1, string &h2, string &h3){
    ifstream file("hint.txt");
    string hint;

    for(int i = 0; i < index * 3; i++){
        getline(file, hint);
    }

    getline(file, h1);
    getline(file, h2);
    getline(file, h3);
}

int main(){
    ofstream file("HangWord.txt");
    file << "=============================================\n";
    file << "               THE HANGING WORD              \n";
    file << "=============================================\n\n";
    file << "A secret word hides in the dark.\n";
    file << "Each wrong guess brings you closer to the rope.\n";
    file << "You have 6 chances to survive.\n\n";
    file << "Guess wisely…\n";
    file << "Before the darkness wins.\n\n";
    file << "=============================================\n\n";
    file << endl << endl;

    srand(time(0));
    string word;
    int index;
    word = answer(index);

    file << "Here is the secret word!!!" << endl;
    string answer(word.length(), '_');
    file << answer << endl;

    char guess;
    int live = 6;
    string h1, h2, h3;
    hint(index, h1, h2, h3);

    do{
        cout << "What is your guessed letter? ";
        cin >> guess;
        file << endl;
        file << "Player guessed: " << guess << endl;
        file.flush();

        bool found = false;
        for(int i = 0; i < word.length(); i++){
            if(guess == word[i]){
                answer[i] = guess;
                found = true;
            }
        }

        if(!found){
            live--;
            file << "Wrong guess! Lives left: " << live << endl;

        switch (live) {
            case 5:
                file << "-------------" << endl;
                for (int i = 0; i < 7; i++) {
                    file << "|" << endl;
                }
                break;

            case 4:
                file << "-------------" << endl;
                for (int i = 0; i < 7; i++) {
                    if (i < 2)
                        file << "|           |" << endl;
                    else
                        file << "|" << endl;
                }
                break;

            case 3:
                file << h1 << endl;
                file << "-------------" << endl;
                file << "|           |" << endl;
                file << "|           |" << endl;
                file << "|           O" << endl;
                for (int i = 0; i < 5; i++)
                    file << "|" << endl;
                break;

            case 2:
                file << h2 << endl;
                file << "-------------" << endl;
                file << "|           |" << endl;
                file << "|           |" << endl;
                file << "|           O" << endl;
                file << "|           |" << endl;
                for (int i = 0; i < 3; i++)
                    file << "|" << endl;
                break;

            case 1:
                file << h3 << endl;
                file << "-------------" << endl;
                file << "|           |" << endl;
                file << "|           |" << endl;
                file << "|           O" << endl;
                file << "|          /|\\" << endl;
                for (int i = 0; i < 3; i++)
                    file << "|" << endl;
                break;

            case 0:
                file << "-------------" << endl;
                file << "|           |" << endl;
                file << "|           |" << endl;
                file << "|           O" << endl;
                file << "|          /|\\" << endl;
                file << "|          / \\" << endl;
                file << "|" << endl;
                file << "GAME OVER!" << endl;
                break;
        }

        } else{
            file << answer << endl;
        }
    } while (live != 0 && answer != word);

    cout << endl;
    if(answer == word){
        file << "YOU ARE THE REAL WINNER!!" << endl;
    } else {
        file << "GAME OVER. The word was : " << word << endl;
    }

    file.close();
}