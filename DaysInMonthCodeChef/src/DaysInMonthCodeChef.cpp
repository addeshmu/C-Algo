//============================================================================
// Name        : DaysInMonthCodeChef.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int findDayDigit(string day) {

	transform(day.begin(), day.end(), day.begin(), ::toupper);

	if (day == "MON")
		return 1;
	if (day == "TUE")
		return 2;
	if (day == "WED")
		return 3;
	if (day == "THU")
		return 4;
	if (day == "FRI")
		return 5;
	if (day == "SAT")
		return 6;
	if (day == "SUN")
		return 7;
	return -1;

}
void outputDays(pair<int, string> pair) {
	int days = pair.first;
	string start = pair.second;

	int st = findDayDigit(start);
	vector<int> *dates = new vector<int>();
	vector<int>::iterator it;
	int md = days % 7;
	int con = (days - md) / 7;
	if (md == 0) {
		for (int i = 0; i < 7; i++) {
			dates->push_back(days / 7);
		}
	} else {
		for (int i = 0; i < 7; i++) {
			dates->push_back(con);
		}
		it = dates->begin() + st - 1;
		while (md != 0) {
			if (it == dates->end()) {
				it = dates->begin();
			}
			*it = *it + 1;
			it++;
			md--;
		}
	}
	it = dates->begin();
	while (it != dates->end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	delete dates;
}

int main() {
	long n;
	cin >> n;
	for (long i = 0; i < n; i++) {
		string start;
		int date;
		cin >> date >> start;
		outputDays(make_pair(date, start));
	}
	return 0;
}
