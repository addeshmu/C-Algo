//============================================================================
// Name        : Rectangle.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

string Rectangle(int a,int  b,int c, int d){
	if ((a==b) && (b==c) && (c==d)){
		return "YES";
	}
	if (((a==b)&&(c==d))||((a==c)&&(b==d))||((a==d)&&(b==c))){
		return "YES";
	}
	return "NO";
}
int main() {
	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<Rectangle(a,b,c,d);
	}
	return 0;
}
