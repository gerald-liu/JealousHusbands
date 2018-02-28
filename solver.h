/**
 *	File:	solver.h
 *	Author: Gerald Liu
 *	Date: 	Feb 28, 2018
 */

#ifndef SOLVER_H
#define SOLVER_H

#include <algorithm>
#include "state.h"

using namespace std;

class Solver {
public:
	int boatSize, numCouples, print;
	vector<vector<int>> moves;
	vector<vector<State*>> solutions;

	Solver();
	~Solver();
	unsigned int printBestSolutions() const;
	void printSolutions();
	void set();
	bool solve();
	void clean();
};

#endif