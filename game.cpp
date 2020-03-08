#include <iostream>
using namespace std;

// Game Board
char board[10] = { '0','1','2','3','4','5','6','7','8','9' };

void display(void);      //function for displaying board
int validate(int);       //function for checking correct place
void mark(int, int);     //function for marking the place
int checkWin(int);       //function for checking winnner
int checkDraw(void);     //function for checking draw game
void changeSign(int &);  //function for flipping turn
 
int main()               // Driver code
{
	cout << "TIC TAC TOE\n";
	int choice, w = 1, turn = 1;
	char p1 = 'X', p2 = 'O';
	
	while(w)
	{
		display();
		
		if(turn == 1) cout << "P1's turn(X): ";
		else cout << "P2's turn(O): ";
		cout << " Enter place: ";
		cin >> choice;
		
		if(validate(choice) == 1)
		{
			mark(turn, choice);
			
			if(checkWin(turn) == 1)
			{
				display();
				if(turn == 1) cout << "P1(X) won!!\n";
				else cout << "P2(O) won!!\n";
				w = 0;
			}
			
			if(checkDraw() == 1)
			{
				display();
				cout << "Match Drawn!!\n";
				w = 0;
			}
			
			changeSign(turn);
		}
		else cout << "Wrong choice...\n";
	}
	 
	return 0;
}

void display()
{
	cout << endl;
	cout << "---------\n";
	cout << "| " << board[1] << " " << board[2] << " " << board[3] << " |\n";
	cout << "| " << board[4] << " " << board[5] << " " << board[6] << " |\n";
	cout << "| " << board[7] << " " << board[8] << " " << board[9] << " |\n"; 
	cout << "---------\n";
	cout << endl;
}

int validate(int choice)
{
	switch(choice)
	{
		case 1: if(board[1] == 'X' || board[1] == 'O') return 0; break;
		case 2: if(board[2] == 'X' || board[2] == 'O') return 0; break;
		case 3: if(board[3] == 'X' || board[3] == 'O') return 0; break;
		case 4: if(board[4] == 'X' || board[4] == 'O') return 0; break;
		case 5: if(board[5] == 'X' || board[5] == 'O') return 0; break;
		case 6: if(board[6] == 'X' || board[6] == 'O') return 0; break;
		case 7: if(board[7] == 'X' || board[7] == 'O') return 0; break;
		case 8: if(board[8] == 'X' || board[8] == 'O') return 0; break;
		case 9: if(board[9] == 'X' || board[9] == 'O') return 0; break;
		default: return -1;
	}
	return 1;
}

void mark(int turn, int choice)
{
	if(turn == 1) board[choice] = 'X';
	else board[choice] = 'O';
}

int checkWin(int turn)
{
	char symb;
	if(turn == 1) symb = 'X';
	else symb = 'O';
	
	if(board[1] == symb && board[2] == symb && board[3] == symb) 
		return 1;
	if(board[4] == symb && board[5] == symb && board[6] == symb) 
		return 1;
	if(board[7] == symb && board[8] == symb && board[9] == symb) 
		return 1;
	if(board[1] == symb && board[5] == symb && board[9] == symb) 
		return 1;
	if(board[3] == symb && board[5] == symb && board[7] == symb) 
		return 1;
	if(board[1] == symb && board[4] == symb && board[7] == symb) 
		return 1;
	if(board[2] == symb && board[5] == symb && board[8] == symb) 
		return 1;
	if(board[3] == symb && board[6] == symb && board[9] == symb) 
		return 1;

	return 0;
}

int checkDraw()
{
	for(int i = 1; i < 10; i++)
		if(board[i] != 'X' && board[i] != 'O') return 0;
	return 1;
}

void changeSign(int &t)
{
	if(t == 1) t = 2;
	else t = 1;
}
