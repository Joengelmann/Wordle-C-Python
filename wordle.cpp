// Jonah Engelmann, Thursday January 12th. I worked by myself.

/* This program is a version of the game wordle. It works by picking a random
secret 5 letter word from a bank and then asks the user to input a guess. Then, 
the program will go through letter by letter determing if a: the the letter is 
in the word and in the right position, b: the letter is in the word but not in
the right positon, or c: the letter is not in the word at all. The goal of the 
game is obviously to guess the secret word and the user has 6 tries to do so.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

const string FILENAME = "wordbank.txt";
const int NUM_LETTERS = 5;
const int NUM_GUESSES = 6;


string getWord();
string getGuess(int prompt);
void process(string guess, string secret);

int main() { //runs the game
	string secret = getWord();
	string guess;
	for(int i=1;i<=NUM_GUESSES;i++){ //Play game
		guess = getGuess(i);
		if (guess == secret){
			break;
		}
		process(guess,secret); //check letters
	}
	if (guess == secret){
		cout<<"You guessed the word!"<<endl; // WooHoo!
	}
	else{
		cout<<"You didn't guess the secret word: "<< secret<<endl;
	}
	return 0;
}

string getGuess(int prompt) { //Gets the guess from the user
	cout<<"Guess #"<<prompt<<": "<<endl;
	string userguess;
	cin>>userguess;
	while(userguess.length() != NUM_LETTERS){
		cout<<"Your guess must be "<<NUM_LETTERS<< " letters long"<<endl;
		cin>>userguess;
	}
	for (int j = 0; j<userguess.length(); j=j+1){
		userguess[j] = toupper(userguess[j]);
	}
	return userguess;
}

void process(string guess, string secret){ // Processes the users guess
	for(int k = 0; k<= NUM_LETTERS-1; k++){
		if(guess[k]==secret[k]){
			cout<<guess[k]<<" is in position "<<k+1 <<endl;
		}
		else{
			bool inword = false;
			for(int l = 0; l<= NUM_LETTERS; l++){
				if(secret[l] == guess[k]){
					inword = true;
					break;
				}
			}
			if(inword){
				cout<<guess[k]<<" is in the word but not in position "<<k+1<<endl;
			}		 
			else{
				cout<<guess[k]<<" is not in the word"<<endl;
			}	
		}
	}
}

string getWord() { // Gets the secret word from the file
	ifstream f(FILENAME);
	vector<string> allWords;
	string word;
	while (getline(f,word)) {
		allWords.push_back(word);
	}
	f.close();
	srand(time(nullptr));
	word = allWords[rand()%allWords.size()];
	for (int i=0; i<word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}
