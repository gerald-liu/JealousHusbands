/*	File:	main.cpp
 *	Author: Gerald Liu
 *	Date: 	Feb 25, 2018
 */


#include <algorithm>
#include "state.h"

unsigned int printBestSolutions(vector<vector<State*>>& solutions) {
	cout << "\nNumber of solutions: " << solutions.size() << "\nBest Solutions:\n";
	unsigned int i = 0;
	for (; i < solutions.size(); i++) {
		if (i > 0 && solutions[i].size() > solutions[i - 1].size()) {
			cout << "\nNumber of best solutions: " << i << "\n";
			return i;
		}
		cout << "\nSolution " << i + 1 << " :\n";
		solutions[i][solutions[i].size() - 1]->print();
	}
	return i;
}

void printAllSolutions(vector<vector<State*>>& solutions) {
	unsigned int i = printBestSolutions(solutions);
	if (i == solutions.size()) return;
	cout << "\nOther Solutions:\n";
	for (; i < solutions.size(); i++) {
		cout << "\nSolution " << i + 1 << " :\n";
		solutions[i][solutions[i].size() - 1]->print();
	}
}

int main() {
	cout << "======= Jealous Husbands Solver =======\n";

	int boatSize;
	do {
		cout << "Boat size: (2 or 3)\n";
		cin >> boatSize;
		if (!cin) {
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (boatSize != 2 && boatSize != 3);

	int numCouples;
	do {
		cout << "Number of couples: (> 0)\n";
		cin >> numCouples;
		if (!cin) {
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (numCouples <= 0);

	vector<vector<int>> moves;
	for (int i = 1; i <= boatSize; i++) {
		for (int j = 0; j <= i; j++) {
			vector<int> move;
			move.push_back(j);
			move.push_back(i - j);
			moves.push_back(move);
		}
	}

	vector<vector<State*>> solutions;

	State init(numCouples, numCouples, 1, 0, nullptr);
	init.move(true, moves, numCouples, solutions);

	if (solutions.size() == 0) {
		cout << "\nNo solutions possible!\n";
		return 0;
	}

	sort(solutions.begin(), solutions.end(), 
		[](const vector<State*> & a, const vector<State*> & b) { return a.size() < b.size(); });

	int print;
	do {
		cout << "Print solutions: (0 for all, 1 for best)\n";
		cin >> print;
		if (!cin) {
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (print != 0 && print != 1);

	cout << "\n==== Solution Format ====\nOn the starting side:\nTrip#\t< # of Husbands, # of Wives, # of Boats >\n";

	if (print) printBestSolutions(solutions);
	else printAllSolutions(solutions);
  
	return 0;
}
