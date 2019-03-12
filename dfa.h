#ifndef DFA	
#define DFA
#include <iostream>
#include <set>


class dfa {
	std::set<int> states;
	std::set<char> alpha;
	std::set<int> finalStates;
	int transitions[256][256];

	int startState;
	int nrWords;
	int nrStates;
	int nrAlpha;
	int nrFinalStates;
	int nrTransitions;

public:

	dfa();

	void transitionMatrix();
	void acceptor();
	int numberWords() { return nrWords; }
};


#endif