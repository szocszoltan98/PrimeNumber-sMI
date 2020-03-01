#include "SimpleBacktrack.h"
#include "ForwardChecking.h"
#include <time.h>
#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std;
int main()
{
	int S = 54, N = 2, P = 3;
	cout << "Simple backtrack:" << endl;
	clock_t tStart = clock();
	SimpleBacktrack simpleBacktrack;
	simpleBacktrack.allPrime(N, S, P);
	cout << "Time taken SIMPLE BACKTRACKING: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
	cout << "Number of calculations: " << simpleBacktrack.numberOfCalculations << "\n";
	cout << "\nForward checking: " << endl;
	tStart = clock();
	ForwardChecking forwardChecking;
	forwardChecking.allPrime(N, S, P);
	cout << "Time taken FORWARD CHECK BACKTRACKING: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
	cout << "Number of calculations: " << forwardChecking.numberOfCalculations << "\n";
	cin.get();

	return 0;
}