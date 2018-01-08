//============================================================================
// Name        : KConcatMaxSubArray.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

long long findMaxSub(long long n, long long k, long long arr[]) {
	long long maxSoFar = std::numeric_limits<long long>::min();
	long long maxEndingHere = 0;
	long long j;
	long long l = 0;
	long long max3 = 0;
	long long max2 = 0;
	if (k > 2) {
		l = n * 3;
	} else {
		l = n * 2;
	}
	for (long long i = 0; i < l; i++) {
		j = i % n;
		maxEndingHere += arr[j];
		if (maxSoFar < maxEndingHere) {
			maxSoFar = maxEndingHere;
		}
		if ((i + 1) == n) {
			max2 = maxSoFar;
		}
		if ((i + 1) == (2 * n)) {
			max3 = maxSoFar;
		}
		if (maxEndingHere < 0) {
			maxEndingHere = 0;
		}
	}
	long long max1 = maxSoFar;
	if (k == 1) {
		return max2;
	}
	if (max3 > max2) {
		if (k == 2) {
			return max3;
		} else {
			if (max1 > max3) {
				return max1 + ((max1 - max3) * (k - 3));
			} else {
				return max3;
			}
		}
	}
	return max2;
}
int main() {
	long long n, k, T;
	cin >> T;
	for (long long i = 0; i < T; i++) {
		cin >> n >> k;
		long long arr[n];
		for (long long i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << findMaxSub(n, k, arr) << endl;
	}

	return 0;
}
