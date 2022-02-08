#include <iostream>
#include <regex>
#include <sstream>
#include "solver.hpp"

using namespace std;

void playGame(int);

// play game again
void playAgainPrompt(int nobs)
{
	string user_response;

	do
	{
		cout << "Would you like to play again? y/n" << endl;
		getline(cin, user_response);
	} while ((user_response != "y") && (user_response != "n"));

	if (user_response == "y")
	{
		playGame(nobs);
	}
	else
	{
		return;
	}
}

void playGame(int nobs)
{
	string user_entry;
	bool solverSucces = false;
	Board board = generatePuzzle(nobs);
	regex rgx("[0-9]{1,}"); // For parsing user input
	smatch match;

	int input_int[3]; // Array for user input

	// Repeat until puzzle is solved
	do
	{
		board.printPuzzle();	  // print puzzle
		getline(cin, user_entry); // get user input

		// Check for user commands
		if (user_entry == "Solve" || user_entry == "solve")
		{
			solverSucces = solve(board, 0, 0);
			board.printPuzzle();
			break;
		}

		if (user_entry == "Clear" || user_entry == "clear")
		{
			board.clearPuzzle();
			continue;
		}

		// Assuming no special command, attempt to parse user input
		int count = 0;
		for (sregex_iterator i = sregex_iterator(user_entry.begin(), user_entry.end(), rgx);
			 i != sregex_iterator();
			 ++i)
		{
			smatch m = *i;
			input_int[count] = stoi(m.str());
			++count;
		}

		// If parse values are out of range... throw error and continue
		bool invalid = false;
		for (int i = 0; i < 3; i++)
		{
			if (!board.inBounds(input_int[i]))
			{
				invalid = true;
			}
		}

		if (invalid)
		{
			cout << "Values entered must be between 1 and " << 9 << endl;
			continue;
		}

		// Assign board value if feasible move
		if (board.feasibleUser((input_int[0] - 1), (input_int[1] - 1), input_int[2]) == true)
		{
			if (board.checkImmutable((input_int[0] - 1), (input_int[1] - 1)) == false)
			{
				board.assignValue((input_int[0] - 1), (input_int[1] - 1), input_int[2]);
			}
			else
			{
				cout << "You can't change that value!" << endl;
			}
		}
		else
		{
			cout << "Not feasible!" << endl;
		}

		// reset inputs to 0, will cause invalid message if unchanged on next round
		for (int i = 0; i < 3; i++)
		{
			input_int[i] = 0;
		}

	} while (!board.checkPuzzle());

	string user_response;

	if (solverSucces)
	{
		cout << "The puzzle is solved!" << endl;
		playAgainPrompt(nobs);
	}
	else
	{
		cout << "Could not solve puzzle based on pre-filled values" << endl;

		do
		{
			cout << "Would you like to clear and try to solve? y/n" << endl;
			getline(cin, user_response);

		} while ((user_response != "y") && (user_response != "n"));

		if (user_response == "y")
		{
			board.clearPuzzle();
			solve(board, 0, 0);
			board.printPuzzle();
			playAgainPrompt(nobs);
		}
	}
}

int main()
{
	system("CLS");

	int nobs = 10; // default number of prefilled spaces

	// Welcome message
	cout << "===========================================" << endl;
	cout << "============ Welcome to Sudoku! ===========" << endl;
	cout << "===========================================" << endl
		 << endl;
	;

	// Play game or run simulations
	playGame(nobs);

	return 0;
}
