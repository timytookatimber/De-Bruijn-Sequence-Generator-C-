/*
	Michael Wdowiak
	I just translated the example from the Wikipedia article on De Brujin sequences
	from python to c++ and added some other stuff
*/
#include <iostream>
#include <cmath>
#include <chrono>

void deBrujin(int k, int n, int t, int p, int a[], int sequence[]);
int i = 0;

int main() {
	int k;						//'alphabet' size
	int n;						//length of sequence
	int t = 1;					//these two need to be 
	int p = 1;					//equal to '1' at the start
	char c;

	std::cout << "Enter alphabet size: \n";
	std::cin >> k;
	std::cout << "Enter length: \n";
	std::cin >> n;

	int * a;					//this array needs to be k*n size
	a = new int[k * n];		
	int * sequence;				//this array needs to be k^n size
	sequence = new int[std::pow(k, n)];

	for (int i = 0; i < (k * n); i++) {				//make all values 0 in first array
		a[i] = 0;
	}
	for (int i = 0; i < std::pow(k, n); i++) {		//make all values 0 in second array
		sequence[i] = 0;
	}

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	deBrujin(k, n, t, p, a, sequence);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	std::cout << "Duration: " << duration << " micro-seconds\n";

	//print the array
	std::cout << "Would you like to print sequence? (y/n)\n";
	std::cin >> c;

	if (c == 'y' || c == 'Y') {
		std::cout << "Sequence array: \n";
		t1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < std::pow(k, n); i++) {
			std::cout << sequence[i] << " ";
		}
		t2 = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << "\nTime to print: " << duration << " micro-seconds\n";
	}

	delete[] a;
	delete[] sequence;

	std::cout << "Memory cleared, Goodbye";
	return 0;
}

//where the magic happens
void deBrujin(int k, int n, int t, int p, int a[], int sequence[]) {
	
	if (t > n) {
		if (n % p == 0) {
			for (int j = 1; j < p + 1; j++) {
				sequence[i] = a[j];
				i++;
			}
		}
	}
	else {
		a[t] = a[t - p];
		deBrujin(k, n, t + 1, p, a, sequence);
		for (int j = a[t - p] + 1; j < k; j++) {
			a[t] = j;
			deBrujin(k, n, t + 1, t, a, sequence);
		}
	}
}