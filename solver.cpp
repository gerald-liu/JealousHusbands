/**
 *	File:	solver.cpp
 *	Author: Gerald Liu
 *	Date: 	Feb 28, 2018
 */

#include "solver.h"

Solver::Solver() : boatSize{ 0 }, numCouples{ 0 }, print{ -1 } {}

Solver::~Solver() {
	if (!solutions.empty()) delete solutions[0][0]->prev;
	moves.clear(); moves.shrink_to_fit();
	solutions.clear(); solutions.shrink_to_fit();
}

unsigned int Solver::printBestSolutions() const {
	cout << "\nNumber of solutions: " << solutions.size() << "\nBest Solutions:\n";
	unsigned int i = 0;
	for (; i < solutions.size(); i++) {
		if (i > 0 && solutions[i].size() > solutions[i - 1].size()) {
			cout << "\nNumber of best solutions: " << i << "\n";
			return i;
		}
		cout << "\nSolution " << i + 1 << " :\n";
		for (unsigned int j = 0; j < solutions[i].size(); j++) solutions[i][j]->print();
	}
	return i;
}

void Solver::printSolutions() {
	cout << "\n==== Solution Format ====\nOn the starting side:\nTrip#\t< # of Husbands, # of Wives, # of Boats >\n";
	
	cout << "Print solutions: (1 for best, else for all)\n";
	cin >> print;
	if (!cin) { cin.clear(); cin.ignore(256, '\n'); }
	if (print != 1) print = 0;

	unsigned int i = this->printBestSolutions();
	if (print || i == solutions.size()) return;

	cout << "\nOther Solutions:\n";
	for (; i < solutions.size(); i++) {
		cout << "\nSolution " << i + 1 << " :\n";
		for (unsigned int j = 0; j < solutions[i].size(); j++) solutions[i][j]->print();
	}
}

void Solver::set() {
	do {
		cout << "Boat size: (2 or 3)\n";
		cin >> boatSize;
		if (!cin) { cin.clear(); cin.ignore(256, '\n'); }
	} while (boatSize != 2 && boatSize != 3);

	do {
		cout << "Number of couples: (> 0)\n";
		cin >> numCouples;
		if (!cin) { cin.clear(); cin.ignore(256, '\n'); }
	} while (numCouples <= 0);

	for (int i = 1; i <= boatSize; i++) {
		for (int j = 0; j <= i; j++) {
			vector<int> move;
			move.push_back(j);
			move.push_back(i - j);
			moves.push_back(move);
		}
	}
}

bool Solver::solve() {
	State* root = new State{ numCouples, numCouples, 1, 0, nullptr };
	root->move(true, moves, numCouples, solutions);

	if (solutions.size() == 0) return false;

	sort(solutions.begin(), solutions.end(),
		[](const vector<State*> & a, const vector<State*> & b) { return a.size() < b.size(); });
	return true;
}

void Solver::clean() {
	if (!solutions.empty()) delete solutions[0][0]->prev;
	moves.clear(); moves.shrink_to_fit();
	solutions.clear(); solutions.shrink_to_fit();
	boatSize = 0, numCouples = 0, print = -1;
}