//============================================================================
// Name        : marsExploration.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char s;
	int count = 0;
	const string match ="SOS";
	unsigned int i = 0;
	s = cin.get();
	while((int)s!=-1){
		if (s!=match[i%match.size()])
			count++;
        i++;
		s = cin.get();
	}
	cout<<count;
	return 0;
}
