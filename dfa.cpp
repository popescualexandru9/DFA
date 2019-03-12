#include "pch.h"
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "dfa.h"

std::ifstream fin("input.in");


dfa::dfa()
{
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
			transitions[i][j] = -1;

	fin >> nrStates;
	fin >> nrAlpha;

	for (int i = 0; i < nrStates; i++)
	{
		int currentState;
		fin >> currentState;
		states.insert(currentState);
	}

	for (int i = 0; i < nrAlpha; i++) {
		char currentLetter;
		fin >> currentLetter;
		alpha.insert(currentLetter);
	}

	fin >> startState;
	fin >> nrFinalStates;
	for (int i = 0; i < nrFinalStates; i++) {
		int fstate;
		fin >> fstate;
		finalStates.insert(fstate);
	}
}


void dfa::transitionMatrix()
{
	int x, y;
	char c;
	fin >> nrTransitions;

	for (int i = 0; i < nrTransitions; i++)
	{
		fin >> x >> c >> y;
		transitions[x][(int)c] = y;
	}
}

void dfa::acceptor()
{
	std::string word;
	std::cout << "Cuvantul: ";
	std::cin >> word;

	int currentState = startState, ok = 1;
	for (int i = 0; i < word.length(); i++)
	{
		currentState = transitions[currentState][word[i]];
		if (currentState == -1)
		{
			ok = 0;
			break;
		}
	}
	if (ok != 0)
	{
		const bool isFinal = finalStates.find(currentState) != finalStates.end();
		if (isFinal)
			std::cout << word << " is accepted.\n";
		else
			std::cout << word << " is rejected.\n";
	}
	else std::cout << word << " is rejected.\n";
}
