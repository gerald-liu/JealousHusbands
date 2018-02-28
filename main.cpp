/**
 *	File:	main.cpp
 *	Author: Gerald Liu
 *	Date: 	Feb 28, 2018
 */

#include "solver.h"

bool again() {
	int again = 0;
	cout << "\n\nEnter 1 for another case, else to exit\n";
	cin >> again;
	if (!cin) { cin.clear(); cin.ignore(256, '\n'); }
	if (again != 1) again = 0;
	return again;
}

int main() {
	cout << "======= Jealous Husbands Solver =======\n";
	Solver s;

	while (true) {
		s.set();

		if (!s.solve()) cout << "\nNo solutions possible!\n";
		else s.printSolutions();

		if (again()) s.clean();
		else break;
	}

    return 0;
}