#include "SimpleBacktrack.h" 
#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std;


SimpleBacktrack::SimpleBacktrack()
{
}


SimpleBacktrack::~SimpleBacktrack()
{
}

// function to check prime number 
bool SimpleBacktrack::isPrime(int x)
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
void SimpleBacktrack::display()
{
	int length = set.size();
	for (int i = 0; i < length; i++)
	{
		cout << set[i] << " ";
		++numberOfCalculations;
	}

	cout << "\n";
}

// function to evaluate all possible N primes 
// whose sum equals S 
void SimpleBacktrack::primeSum(int total, int N, int S, int index)
{
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
	if (total > S || index == prime.size()) {
		numberOfCalculations += 2;
		return;
	}


	// add prime[index] to set vector 
	set.push_back(prime[index]);
	++numberOfCalculations;

	// include the (index)th prime to total 
	primeSum(total + prime[index], N, S, index + 1);
	++numberOfCalculations;

	// remove element from set vector 
	set.pop_back();
	++numberOfCalculations;

	// exclude (index)th prime 
	primeSum(total, N, S, index + 1);
	++numberOfCalculations;
}

// function to generate all primes 
void SimpleBacktrack::allPrime(int N, int S, int P)
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

	// if primes are less than N 
	if (prime.size() < N) {
		++numberOfCalculations;
		return;
	}

	primeSum(0, N, S, 0);
	++numberOfCalculations;
}


