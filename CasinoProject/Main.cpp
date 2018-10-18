#include <iostream>
#include <string>

using namespace std;


void startProgram();

void setName(string *playerName) {
	cout << "Please enter your name" << endl;
	getline(cin, *playerName);
}

void setWallet(float *wallet) {
	cout << "How much money is in your wallet today? Asking for a friend..." << endl;
	cin >> *wallet;
}



void decide(char *decision) {
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

void chooseGame() {
	string choice;
	int numChoice;
	getline(cin, choice);
	stringstream geek(choice);

	switch (numChoice) {
	case 1: cout << "You picked 1!" << endl;
		break;
	case 2: cout << "You picked 2!" << endl;
		break;
	case 3: cout << "You picked 3!" << endl;
		break;
	default: { cout << "That was not an option" << endl;
		//chooseGame();
		break;
		}
	}
}

void startProgram() {
	int x, gameChoice;
	int *gameChoicePointer = &gameChoice;
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
	cout << "Are you ready to begin?" << endl;
	decide(decisionPointer);
	cout << "Please choose from the following options." << endl;
	cout << "1) Coin Flip" << endl;
	cout << "2) Casino War" << endl;
	cout << "3) BlackJack" << endl;
	chooseGame();
	cin >> x;
}

int main()
{	
	startProgram();
	return 0;
}

