/**
 *	File:	state.h
 *	Author: Gerald Liu
 *	Date: 	Feb 25, 2018
 */

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>

using namespace std;

class State {
public:
    int husband, wife, boat; // number on the wrong side
    int tripNum; // trip number
    State* prev; // parent nodes
	vector<State*> next; // children nodes

    State(int h, int w, int b, int t, State* p);
    ~State();
    void print() const;
	void store(vector<State*>& solution);
    void move(bool forth, vector<vector<int>>& moves, int numCouples, vector<vector<State*>>& solutions);
};

#endif