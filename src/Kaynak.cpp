#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

int main() {

	
	char start{}; // Start screen

	cout << "Hangman by miaf" << endl;
	cout << "_______________   " << endl;
	cout << "|        }        " << endl;
	cout << "|        O        " << endl;
	cout << "|        |        " << endl;
	cout << "|     /  |  \\    " << endl;
	cout << "|    /   |    \\  " << endl;
	cout << "|       / \\      " << endl;
	cout << "|      /   \\     " << endl;
	cout << "|                 " << endl;
	cout << "_______________   " << endl;
	cout << "Press any key to start\n";
	cin >> start;

	// Game options variables etc.

	int tries = {6}; // The number of attempts to guess correctly
	char Guess;
	bool Correct = false;
	char PreviousGuess[7]; // an array of guesses
	PreviousGuess[0] = '\0';
	for (int i = 1; i < 6; i++)
	{
		PreviousGuess[i] = '-';
	}
	PreviousGuess[6] = '\0';
	string Word; // This is the word what players guess
	string WordList[199]; // It's an array covers 100 strings
	srand(time(NULL)); // Creates a random seed for get a random word from the array

	// Get random word
	ifstream RandomWord; // This file stream reads in the variable
	RandomWord.open("Words.txt"); //Reads in the file named "Words.txt"

	// Game configs

	for (int i = 0; i < 199; i++) {
		RandomWord >> WordList[i]; // Modifies the array with words from the list
		//cout << WordList[i] << endl; // For testing
	}

	int RandomNum = rand() % 200; // returns a random number between 0-199
	Word = WordList[RandomNum];
	cout << Word << endl; // For testing
	RandomWord.close();

	//Mystery word
	string MysteryWord(Word.length(), '*'); // MysteryWord replaces each letter of word with "*"
	//cout << MysteryWord << endl; // Test the MysteryWord


	while (tries >= 0) {

		Correct = false;

		//Display the informations about the game to player.
		cout << "You need to guess this word: \n\n";
		cout << MysteryWord << endl;
		cout << "There are " << MysteryWord.length() << " letters in the word. \n\n";
		cout << "You have " << tries << " guesses left." << endl;
		if (PreviousGuess[0] == '\0')
		{
			cout << endl;
		}
		else
		{
			cout << "You have guessed: " << PreviousGuess << endl;
		}
		cout << "Guess a letter: ";
		cin >> Guess;

		//Check the guess
		if (Word == MysteryWord)
		{
			cout << "\n\nCongratulations! You found the word correct: " << MysteryWord << endl;
			break;
		}

		for (int i = 0; i < MysteryWord.length(); i++) {
			if (Word[i] == Guess)
			{
				MysteryWord[i] = Guess;
				Correct = true;
			}
		}
		if (Correct == false)
		{
			tries--;
			cout << "Sorry, " << Guess << " is not part of the word.." << endl;
		}
		else
		{
			cout << "Congratulations! " << Guess << " is one of the letters!" << endl;
		}

		switch (tries)
		{
		case 6:
		{
			cout << "_______________   " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "_______________   " << endl;
			break;
		}
		case 5:
		{
			cout << "_______________   " << endl;
			cout << "|        }        " << endl;
			cout << "|        O        " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "_______________   " << endl;
			if (Correct == false)
			{
				PreviousGuess[0] = Guess;
			}
			break;
		}
		case 4:
		{
			cout << "_______________   " << endl;
			cout << "|        }        " << endl;
			cout << "|        O        " << endl;
			cout << "|        |        " << endl;
			cout << "|        |        " << endl;
			cout << "|        |        " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "_______________   " << endl;
			if (Correct == false)
			{
				PreviousGuess[1] = Guess;
			}
			break;
		}
		case 3:
		{
			cout << "_______________   " << endl;
			cout << "|        }        " << endl;
			cout << "|        O        " << endl;
			cout << "|        |        " << endl;
			cout << "|     /  |        " << endl;
			cout << "|    /   |        " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "_______________   " << endl;
			if (Correct == false)
			{
				PreviousGuess[2] = Guess;
			}
			break;
		}
		case 2:
		{
			cout << "_______________   " << endl;
			cout << "|        }        " << endl;
			cout << "|        O        " << endl;
			cout << "|        |        " << endl;
			cout << "|     /  |  \\    " << endl;
			cout << "|    /   |   \\   " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "|                 " << endl;
			cout << "_______________   " << endl;
			if (Correct == false)
			{
				PreviousGuess[3] = Guess;
			}
			break;
		}
		case 1:
		{
			cout << "_______________   " << endl;
			cout << "|        }        " << endl;
			cout << "|        O        " << endl;
			cout << "|        |        " << endl;
			cout << "|     /  |  \\    " << endl;
			cout << "|    /   |   \\   " << endl;
			cout << "|       /         " << endl;
			cout << "|      /          " << endl;
			cout << "|                 " << endl;
			cout << "_______________   " << endl;
			if (Correct == false)
			{
				PreviousGuess[4] = Guess;
			}
			break;
		}
		case 0:
		{
			cout << "_______________   " << endl;
			cout << "|        }        " << endl;
			cout << "|        O        " << endl;
			cout << "|        |        " << endl;
			cout << "|     /  |  \\    " << endl;
			cout << "|    /   |   \\   " << endl;
			cout << "|       / \\      " << endl;
			cout << "|      /   \\     " << endl;
			cout << "|                 " << endl;
			cout << "_______________   " << endl;
			tries = -1;
			cout << "Game Over";
			break;
		}
		default:
			cout << "ERROR";
		}
	}
	return 0;
}