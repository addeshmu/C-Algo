//============================================================================
// Name        : HelloWorld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Initiate.h"
#include <vector>
using namespace std;

int main() {
	string s;
	int *i;
	vector<int> *v = new vector<int>();
	for (int i=0;i<50;i++){
		v->push_back(i*i+i-i*i);
	}
	vector<int>::iterator it;
	for (it = v->begin();it!=v->end();it++) {
		cout<<*it<<endl;
	}
	int m  = 10;
	i = &m;
	cout<<i<<endl<<*i;
	cin>>s;
	Initiate init(s);
	init.showVal();
	return 0;
}
