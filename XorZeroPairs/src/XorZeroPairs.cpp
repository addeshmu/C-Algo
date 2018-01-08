//============================================================================
// Name        : XorZeroPairs.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long n;
	cin >> n;
	long i = 0;
	long mc = 0;
	long num[n];
	while (i < n) {
		long temp;
		cin >> temp;
		num[i] = temp;
		i++;
	}
	sort(num, num + n);
	i = 0;
	long count;
	while (i < n) {
		count = 1;
		long j = i + 1;
		while (j < n && num[j] == num[i]) {
			j++;
			count++;
		}
		i = j;
		if (count > 1) {
			mc += ((count) * (count - 1)) / 2;
		}
	}

	cout << mc;
	return 0;
}
