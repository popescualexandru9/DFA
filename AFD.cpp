#include "pch.h"
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "dfa.h"


int main()
{
	dfa A;
	int nrWords;
	A.transitionMatrix();

	std::cout << "Cate cuvinte vrei sa citesti? \nRaspuns: ";
	std::cin >> nrWords;

	for (int i = 0; i < nrWords; i++)
	{
		A.acceptor();
		std::cout << "\n";
	}
}


