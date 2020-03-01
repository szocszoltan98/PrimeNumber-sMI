#pragma once
#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std;
class ForwardChecking
{
private: vector<int> set;
		 vector<int> prime;
		 bool isPrime(int x);
		 vector <int> statistic;
public:
	ForwardChecking();
	~ForwardChecking();
	void display();
	void primeSum(int total, int N, int S, int index);
	void allPrime(int N, int S, int P);
	void checking(int index, int S, int total);
	int numberOfCalculations = 0;
};