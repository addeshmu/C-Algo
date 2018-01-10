//============================================================================
// Name        : MaxScore.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
vector<ll> v;

// inefficient recursive
bool recurseFind(ll level, ll max, ll **arr) {

	for (ll i = n - 1; i >= 0; i--) {
		ll temp = arr[level][i];
		if (temp > max) {
			if (level + 1 == n) {
				v.push_back(temp);
				return true;
			}
			if (recurseFind(level + 1, temp, arr)) {
				v.push_back(temp);
				return true;
			}
		} else {
			if (level + 1 == n) {
				return false;
			}
		}
	}
	return false;
}
// efficient DP
void makeMapAndFindPath(ll **arr, ll n) {
	ll res[n - 1][n];
	bool flag;
	ll sum;
	// save for each digit just lesser number index from previous row
	for (ll i = n - 1; i >= 1; i--) {
		for (ll j = n - 1; j >= 0; j--) {
			ll k = n - 1;
			while (k >= 0 && arr[i - 1][k] >= arr[i][j]) {
				k--;
			}
			if (k >= 0) {
				res[i - 1][j] = k;
			} else {
				res[i - 1][j] = -1;
			}
		}
	}

	// traverse map to find strictly lesser path;
	for (int i = n - 1; i >= 0; i--) {
		sum = arr[n - 1][i];
		flag = true;
		ll t = n - 2;
		ll j = i;
		while (t >= 0) {
			if (res[t][j] == -1) {
				flag = false;
				break;
			}
			ll index = res[t][j];
			sum += arr[t][index];
			t--;
			j = index;
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		cout << sum << endl;
	} else {
		cout << -1 << endl;
	}

}
int main() {
	ll t;
	cin >> t;
	while (t > 0) {
		cin >> n;
		ll temp;
		ll **arr = new ll*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new ll[n];
			for (int j = 0; j < n; j++) {
				cin >> temp;
				arr[i][j] = temp;
			}
			sort(arr[i], arr[i] + n);
		}
		makeMap(arr, n);
		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
		t--;
	}
	return 0;
}
