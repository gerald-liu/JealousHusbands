/**	
 *	File:	state.cpp
 *	Author: Gerald Liu
 *	Date: 	Feb 25, 2018
 */

#include "state.h"

State::State(int h, int w, int b, int t, State* p) : husband{ h }, wife{ w }, boat{ b }, tripNum{ t }, prev{ p } {}

State::~State() { 
	if (!next.empty()) for (unsigned int i = 0; i < next.size(); i++) if (next[i] != nullptr) delete next[i];
}

void State::print() const { cout << tripNum << "\t< "  << husband << ", " << wife << ", " << boat << " >\n"; }

void State::store(vector<State*>& solution) {
	if (prev == nullptr) return;
	else prev->store(solution);

	solution.push_back(this);
}

void State::move(bool forth, vector<vector<int>>& moves, int numCouples, vector<vector<State*>>& solutions) {
	int h = 0, w = 0, b = 0;
	int numMoves = moves.size();
    for (int i = 0; i < numMoves; i++) {
        if (forth) {
            h = this->husband - moves[i][0];
            w = this->wife - moves[i][1];
            b = this->boat - 1;
        }
        else {
            h = this->husband + moves[i][0];
            w = this->wife + moves[i][1];
            b = this->boat + 1;
        }
        
        if (h < 0 || h > numCouples || w < 0 || w > numCouples || (h > 0 && h < numCouples && h != w)) {
			this->next.push_back(nullptr);
            continue;
        }
        
        this->next.push_back(new State(h, w, b, this->tripNum + 1, this));

		if (h == 0 && w == 0 && b == 0) {
			vector<State*> solution;
			this->next[i]->store(solution);
			solutions.push_back(solution);
            continue;
        }

		for (const State* s = this->next[i]->prev; s != nullptr; s = s->prev) {
			if (s->husband == h && s->wife == w && s->boat == b) {
				delete this->next[i];
				this->next[i] = nullptr;
				break;
			}
		}
	}

    bool deadEnd = true;
    int i = 0;
    for (; i<numMoves; i++) {
        if (this->next[i] != nullptr) {
            deadEnd = false;
            break;
        }
    }
    if (deadEnd) return;
    else for (; i<numMoves; i++)
		if (this->next[i] != nullptr && !(next[i]->husband == 0 && next[i]->wife == 0 && next[i]->boat == 0))
			this->next[i]->move(!forth, moves, numCouples, solutions);
}