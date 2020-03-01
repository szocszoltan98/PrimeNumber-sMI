#include "ForwardChecking.h"
// CPP Program to print all N primes after
// prime P whose sum equals S 
#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std;


ForwardChecking::ForwardChecking()
{

}


ForwardChecking::~ForwardChecking()
{
}

// function to check prime number 
bool ForwardChecking::isPrime(int x)
{
	// square root of x 
	int sqroot = sqrt(x);
	bool flag = true;

	numberOfCalculations += 2;

	// since 1 is not prime number 
	if (x == 1) {
		++numberOfCalculations;
		return false;
	}


	// if any factor is found return false 
	for (int i = 2; i <= sqroot; i++)
		if (x % i == 0) {
			++numberOfCalculations;
			return false;
		}


	// no factor found 
	++numberOfCalculations;
	return true;
}

// function to display N primes whose sum equals S 
void ForwardChecking::display()
{
	int length = set.size();
	for (int i = 0; i < length; i++) {
		cout << set[i] << " ";
		++numberOfCalculations;
	}

	cout << "\n";
}

void ForwardChecking::checking(int index, int S, int total) {

	fill(statistic.begin(), statistic.end(), 0);
	++numberOfCalculations;
	for (int i = 0; i < prime.size(); i++) {
		if (total + prime[i] <= S) {
			statistic[i] = 1;
			numberOfCalculations += 2;
		}
		else {
			break;
		}
	}
}

// function to evaluate all possible N primes 
// whose sum equals S 
void ForwardChecking::primeSum(int total, int N, int S, int index)
{
	checking(index, S, total);
	// if total equals S And 
	// total is reached using N primes 
	if (total == S && set.size() == N)
	{
		// display the N primes 
		display();
		numberOfCalculations += 2;
		return;
	}

	// if total is greater than S 
	// or if index has reached last element 
	if (total > S || index == prime.size() || statistic[index] == 0) {
		numberOfCalculations += 2;
		return;
	}


	// add prime[index] to set vector 

	set.push_back(prime[index]);
	++numberOfCalculations;

	primeSum(total + prime[index], N, S, index + 1);
	++numberOfCalculations;


	if (!set.empty()) {
		set.pop_back();
		++numberOfCalculations;
	}

	primeSum(total, N, S, index + 1);
	++numberOfCalculations;


	// include the (index)th prime to total 


	// remove element from set vector 

	// exclude (index)th prime 

}

// function to generate all primes 
void ForwardChecking::allPrime(int N, int S, int P)
{
	// all primes less than S itself 
	for (int i = P + 1; i <= S; i++)
	{
		// if i is prime add it to prime vector 
		if (isPrime(i)) {
			prime.push_back(i);
			numberOfCalculations += 2;
		}
	}
	for (int i = 0; i <= prime.size(); i++) {
		statistic.push_back(1);
	}
	// if primes are less than N 

	if (prime.size() < N) {
		++numberOfCalculations;
		return;
	}

	primeSum(0, N, S, 0);
	++numberOfCalculations;
}


