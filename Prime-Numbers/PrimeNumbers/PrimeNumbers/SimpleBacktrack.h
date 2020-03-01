#pragma once
#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std;

class SimpleBacktrack
{
private: vector<int> set;
		 vector<int> prime;
		 bool isPrime(int x);
		 vector <int> statistic;
public:
	SimpleBacktrack();
	~SimpleBacktrack();
	void display();
	void primeSum(int total, int N, int S, int index);
	void allPrime(int N, int S, int P);
	int numberOfCalculations = 0;
};

