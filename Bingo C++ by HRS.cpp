#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cstring>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;
string playerName1, playerName2;
int gameId;
int score1=0, score2= 0;
// here is function declaration.
void mainMenu();
void gameStart();
int playerOne(int arrayOne[5][5]);
int playerTwo(int arrayTwo[5][5]);
void gameInstructions();
void exitGame();
int inputValues(int arrayOne[5][5], int arrayTwo[5][5]);
int inputValues2(int arrayOne[5][5], int arrayTwo[5][5]);
int winCondition(int arrayOne[5][5], int arrayTwo[5][5]);
int winCondition2(int arrayOne[5][5], int arrayTwo[5][5]);
int fileHandling();
int fileHandlingInput();
//here is main function start.
int main() {
	system("Color 70");
	mainMenu();
	system("pause");
	return 0;
}
//here is the definations of functions.
void mainMenu() { /*it is the main menu in which user select which operation
	he wanna perform*/
	char selection;
	cout << "a)Play Game." << endl;
	cout << "b)Game History." << endl;
	cout << "c)How To Play." << endl;
	cout << "d)Exit." << endl;
	cin >> selection;
	switch (selection) {
	case 'a':case 'A':
		///game id generator
		srand(time(0));
		gameId = rand() % 10000;
		cout << "Please Enter the name of Player One:";
		cin.ignore();
		getline(cin, playerName1);
		cout << "Please Enter the name of Player Two:";
		getline(cin, playerName2);
		system("CLS");
		gameStart();
		break;
	case 'b':case 'B':
		fileHandlingInput();
		break;
	case 'c':case 'C':
		gameInstructions();
		mainMenu();
		break;
	case 'd':case 'D':
		exitGame();
		break;
	}
}
void gameStart() {/*its the funcution in which game begans and toss*/
	int arrayOne[5][5], arrayTwo[5][5];
	int a = 0;
	playerOne(arrayOne);
	playerTwo(arrayTwo);
	cout << "Tossing-------------";
	Sleep(1000);
	system("CLS");
	if (arrayOne[0][0]%2==0) {
		do {
			inputValues(arrayOne, arrayTwo);
			winCondition(arrayOne, arrayTwo);
			inputValues2(arrayOne, arrayTwo);
			winCondition2(arrayOne, arrayTwo);
			a++;
		} while (a < 25);
	}
	else {
		do {
			
			inputValues2(arrayOne, arrayTwo);
			winCondition2(arrayOne, arrayTwo);
			inputValues(arrayOne, arrayTwo);
			winCondition(arrayOne, arrayTwo);
			a++;
		} while (a < 25);

    }
}
int playerOne(int arrayOne[5][5]) {//its the function to store player one grid.
	int num = 0;
	int c = 0, a = 0;
	bool condition = true;
	srand(time(0));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			condition = true;
			while (condition == true) {
				num = rand() % 25 + 1;
				//To check number will not repeat
				while (a < 25) {
					for (int k = 0; k < 5; k++) {
						for (int l = 0; l < 5; l++) {
							if (num != arrayOne[k][l]) {
								c++;
								a++;
							}
							a++;
						}
					}
				}
				//store that num which not repetative in array
				if ((num >= 1 && num <= 25 && c == 25)) {
					arrayOne[i][j] = num;
					a = 0; c = 0;
					condition = false;
				}
				else {
					a = 0; c = 0;
				}
			}
		}
	}
	return 0;
}
int playerTwo(int arrayTwo[5][5]) {//its the function to store player two grid;
	int num2 = 0;
	int c = 0, a = 0;
	bool condition = true;
	srand(time(0));
	for (int i = 0; i < 5; i++) {
		//i do this to avoid both number grid  same.
		num2 = rand() % 25 + 2;
		for (int j = 0; j < 5; j++) {
			condition = true;
			while (condition == true) {
				num2 = rand() % 25 + 1;
				//To check number will not repeat
				while (a < 25) {
					for (int k = 0; k < 5; k++) {
						for (int l = 0; l < 5; l++) {
							if (num2 != arrayTwo[k][l]) {
								c++;
								a++;
							}
							a++;
						}
					}
				}
				//store that num which not repetative in array
				if ((num2 >= 1 && num2 <= 25 && c == 25)) {
					arrayTwo[i][j] = num2;
					a = 0; c = 0;
					condition = false;
				}
				else {
					a = 0; c = 0;
				}
			}
		}
	}
	return 0;
}
void gameInstructions() {//its the function which contain the game instruction(How top play)
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << " How To Play" << endl;
	cout << " 1. First make a two 5*5 grid if two players are playing." << endl;
	cout << " 2. Generate random numbers in the two grids." << endl;
	cout << " 3. Player 1 speak a random number(1-25) so both players cut the same number from their grid and vice versa." << endl;
	cout << " 4. Shout 'bingo' if any player wins." << endl;
	cout << " 5. If game draws both players have to play again and again until one wins." << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}
void exitGame() {//its the exit function.
	cout << "--------------------------------------" << endl;
	cout << "Your Game Is Exit(-See You Next Time-)" << endl;
	cout << "--------------------------------------" << endl;
	exit(10);
}
int inputValues(int arrayOne[5][5], int arrayTwo[5][5]) {//function to get values from player one.
	//to display grid one and take values.
	system("Color 06");
	cout << "\t\t\t\t\t" << "-------------------------" << endl;
	cout << "\t\t\t\t\t" << "|       BINGO GAME      |" << endl;
	cout << "\t\t\t\t\t" << "-------------------------" << endl;
	cout << endl;
	cout << "Grid of player 1:"<<"\t\t\t"<<"----Game ID:"<<gameId<< endl;
	cout << endl;
	cout << "Score:"<<score1;
	cout << endl;
	for (int a = 0; a < 5; a++) {
		cout << "\t\t\t\t\t";
		for (int b = 0; b < 5; b++) {
			cout << ' ' << '|' << setw(2) << arrayOne[a][b] << '|';
		}
		cout << endl;
	}
	int value1,inc=0;
	bool condition = true;
	cout << playerName1 << " Enter Your Turn: ";
	cin >> value1;
	//to check the wrong input.
	while (condition == true){

	if (value1 >= 1 && value1<= 25) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (value1 == arrayOne[i][j]) {
					inc = inc + 1;
				}
			}
		}
		if(inc!=0)
		condition = false;
		else {
			cout << "You entered value that already used" << endl;
			cout << "Enter again: ";
			cin >> value1;
		}
	}
	else {
		cout << "You Enter a wrong Input(Number):"<<endl;
		cout << "Enter again:";
		cin >> value1;
	}
}
	//to update value in grid one.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arrayOne[i][j] == value1) {
				arrayOne[i][j] = 0;
			}
		}
	}
	//to update value in grid two.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arrayTwo[i][j] == value1) {
				arrayTwo[i][j] = 0;
			}
		}
	}
	system("CLS");
	return 0;
}
int inputValues2(int arrayOne[5][5], int arrayTwo[5][5]) {//function to get values from player two.
	system("Color 04");
	cout << "\t\t\t\t\t" << "-------------------------" << endl;
	cout << "\t\t\t\t\t" << "|       BINGO GAME      |" << endl;
	cout << "\t\t\t\t\t" << "-------------------------" << endl;
	cout << endl;
	cout << "Grid of player 2:" << "\t\t\t" << "----Game ID:" << gameId << endl;
	cout << endl;
	cout << "Score:" << score2;
	cout << endl;
	for (int a = 0; a < 5; a++) {
		cout << "\t\t\t\t\t";
		for (int b = 0; b < 5; b++) {
			cout << ' ' << '|' << setw(2) << arrayTwo[a][b] << '|';
		}
		cout << endl;
	}
	int value1,inc=0;
	bool condition = true;
	cout <<playerName2<<" Enter Your Turn: ";
	cin >> value1;
	//for checking wrong input
	while (condition == true) {
		if (value1 >= 1 && value1 <= 25) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (value1 == arrayOne[i][j]) {
						inc = inc + 1;
					}
				}
			}
			if(inc!=0)
			condition = false;
			else {
				cout << "You entered value that already used" << endl;
				cout << "Enter again: ";
				cin >> value1;
			}
		}
		else {
			cout << "You Enter a wrong Input(Number):" << endl;
			cout << "Enter again:";
			cin >> value1;
		}
    }
	//to update value in grid 1.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arrayOne[i][j] == value1) {
				arrayOne[i][j] = 0;
			}
		}
	}
	//to update value in grid 2.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arrayTwo[i][j] == value1) {
				arrayTwo[i][j] = 0;
			}
		}
	}
	system("CLS");
	return 0;
}

int winCondition(int arrayOne[5][5], int arrayTwo[5][5]) {//function to check player one winning condition.
	int con1 = 0, con2 = 0, con3 = 0,sum1=0;
	int a = 0;
	//for rows condition
	for (int i = 0; i < 1; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //1
	}
	a = 0;
	for (int i = 1; i < 2; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //2
	}
	a = 0;
	for (int i = 2; i < 3; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //3
	}
	a = 0;
	for (int i = 3; i < 4; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //4
	}
	a = 0;
	for (int i = 4; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //5
	}
	a = 0;
	//for column condition.
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 1; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //1
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 1; j < 2; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //2
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 2; j < 3; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //3
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 3; j < 4; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //4
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 4; j < 5; j++) {
			if (arrayOne[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //5
	}
	//for diagnol condition.
	a = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) {
				if (arrayOne[i][j] == 0) {
					a = a + 1;
				}
			}
		}
	}
	if (a == 5) {
		con3 = con3 + 1; //1
	}
	if (arrayOne[4][0] == 0 && arrayOne[3][1] == 0 && arrayOne[2][2] == 0 && arrayOne[1][3] == 0 && arrayOne[0][4] == 0) {
		con3 = con3 + 1; //2
	}
	//////////
	sum1= con1 + con2 + con3;
	score1 = sum1 * 10; // for adding score
	if (sum1>= 5) {
		cout << playerName1 << " won the game." << endl;
		cout <<"score=" << score1<<endl;
		cout << "-------------------------------"<<endl;
		cout << endl;
		fileHandling();//for store history
		mainMenu();
		exit(1);
	}
	else {
		sum1= 0;
	}
	return 0;
}
int winCondition2(int arrayOne[5][5], int arrayTwo[5][5]) {//function to check player two winning condition
	int con1 = 0, con2 = 0, con3 = 0, sum1 = 0;
	int a = 0;
	//for rows condition
	for (int i = 0; i < 1; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //1
	}
	a = 0;
	for (int i = 1; i < 2; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //2
	}
	a = 0;
	for (int i = 2; i < 3; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //3
	}
	a = 0;
	for (int i = 3; i < 4; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //4
	}
	a = 0;
	for (int i = 4; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con1 = con1 + 1; //5
	}
	a = 0;
	//for column condition.
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 1; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //1
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 1; j < 2; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //2
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 2; j < 3; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //3
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 3; j < 4; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //4
	}
	a = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 4; j < 5; j++) {
			if (arrayTwo[i][j] == 0) {
				a = a + 1;
			}
		}
	if (a == 5) {
		con2 = con2 + 1; //5
	}
	//for diagnol condition.
	a = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) {
				if (arrayTwo[i][j] == 0) {
					a = a + 1;
				}
			}
		}
	}
	if (a == 5) {
		con3 = con3 + 1; //1
	}
	if (arrayTwo[4][0] == 0 && arrayTwo[3][1] == 0 && arrayTwo[2][2] == 0 && arrayTwo[1][3] == 0 && arrayTwo[0][4] == 0) {
		con3 = con3 + 1; //2
	}
	sum1 = con1 + con2 + con3;
	score2 = sum1 * 10; // for adding score
	if(sum1 >= 5) {
		cout <<playerName2<<" won the game." << endl;
		cout << "score=" << score2<<endl;
		cout << "-------------------------------------"<<endl;
		cout << endl;
		fileHandling();//for store history
		mainMenu();
		exit(1);
	}
	else {
		sum1 = 0;
	}
	return 0;
}
int fileHandling() { //function to store data in file.
	ofstream output;
	output.open("History.txt",ios::app);
	if (!output.is_open()) {
		cout << "File NOt Found";
		exit(1);
	}
	output << endl;
	output << "Game ID:" << gameId;
	output << endl;
	output << "Names:" << playerName1<< "\t\t\t\t" <<playerName2;
	output << endl;
	output << "Score:" << score1<< "\t\t\t\t" <<score2;
	output << endl;
	if (score1 >=50) {
		output << "winner:"<<playerName1;
		output << endl;
	}
	if(score2>=50) {
		output << "winner:"<<playerName2;
		output << endl;
	}
	output <<"-------------------------------------------";
	output.close();
	return 0;
}
int fileHandlingInput() {
	ifstream input;
	input.open("History.txt");
	char c;
	while (!input.eof()) {
		input.get(c);
		cout << c;
	}
	cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Do u wanna erase your History(Y/N)" << endl;
	char R;
	ofstream output;
	cin >> R;
	if (R == 'Y' || R == 'y') {
		output.open("History.txt", ios::trunc);
		output.close();
		cout << "Congrats! History removed."<<endl;
	}
	input.close();
	mainMenu();
	return 0;
}
///22F-3088(M-Harris-Tariq)--------------1st semester project; 