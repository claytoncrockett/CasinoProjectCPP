#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void startProgram();

float coinFlip(float bet) {
	srand((unsigned int)time(NULL));
	int flipChance = rand() % 2;
	int numChoice;
	string coinSides[2] = { "HEADS!", "TAILS!" };
	string choice;
	string result = coinSides[flipChance];
	cout << "Welcome to Coin Flip!" << endl;
	cout << "Please type 1 for heads, or 2 for tails" << endl;
	getline(cin, choice);
	stringstream choiceToNum(choice);
	choiceToNum >> numChoice;
	if (--numChoice == flipChance) {
		cout << "It landed on " << result << "  You win $" << bet << endl;
		return bet;
	}
	else {
		cout << "It landed on " << result << "  You lose :(" << endl;
		return (bet * -1);
	}

}

void setName(string *playerName) {
	cout << "Please enter your name" << endl;
	getline(cin, *playerName);
}

void setWallet(float *wallet) {
	cout << "How much money is in your wallet today? Asking for a friend..." << endl;
	cin >> *wallet;
}



void decide(char *decision) {
	cout << "Are you ready to begin?" << endl;
	cin >> *decision;
	cin.ignore();
	if (*decision == 'y') {
		cout << "Good! Let's get started.";
	}
	else {
		cout << "You did not type y.  Starting over..\n";
		startProgram();
	}
}

void endGame(float *wallet, string *playerName) {
	int x;
	cout << playerName << " you finished with " << wallet << " in your pocket.  Bye!";
	cin >> x;
}

void chooseGame(float *wallet, string *playerName) {
	cout << "Please choose from the following options " << *playerName << ".  You have " << *wallet << " in your wallet." << endl;
	cout << "1) Coin Flip" << endl;
	cout << "2) Casino War" << endl;
	cout << "3) BlackJack" << endl;
	cout << "Or type q to quit" << endl;

	string choice = "";
	int numChoice = 0;
	getline(cin, choice);
	if (choice.compare("q") == 0)
		endGame(wallet, playerName);
	stringstream geek(choice);

	geek >> numChoice;

	switch (numChoice) {
	case 1: {cout << "You picked 1! Transferring you to our professional coin flipper." << endl;
		*wallet += coinFlip(5);
		chooseGame(wallet, playerName);
		}
	case 2: cout << "You picked 2! Prepare for war." << endl;
		break;
	case 3: cout << "You picked 3! Blackjack time." << endl;
		break;
	default: { cout << "That was not an option. Please type 1, 2, or 3." << endl;
		chooseGame(wallet, playerName);
		break;
		}
	}
}

void startPlaying(float *wallet, string *playerName) {
	int  gameChoice;
	int *gameChoicePointer = &gameChoice;
	chooseGame(wallet, playerName);
}

void startProgram() {
	int x;
	float wallet;
	float *walletPointer = &wallet;
	char decision = 'y';
	char *decisionPointer = &decision;
	string playerName;
	string *playerNamePointer = &playerName;
	cout << "Welcome to the Casino! A few things before we get started..." << endl;
	setName(playerNamePointer);
	setWallet(walletPointer);
	cout << "Ok, so your name is " << playerName << ", and you have $" << wallet << " in your wallet right now." << endl;
	decide(decisionPointer);
	startPlaying(walletPointer, playerNamePointer);
	cin >> x;
}

int main()
{	
	startProgram();
	return 0;
}

