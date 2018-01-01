//============================================================================
// Name        : findSpecificSubsequence.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void findSpecificSub(string s,const string sub){
	int sl = (int)s.size();
	int subl = (int)sub.size();
	int i=0,j=0;
	bool flag = false;
	while(i<sl and j<subl){
		if (s[i] == sub[j]) {
			i++;
			j++;
		}else{
			i++;
		}
		if (j==subl){
			flag = true;
			break;
		}
	}
	if(flag){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

}
int main() {
	int t;
	cin>>t;
	for (int i=0; i<t;i++) {
		string s;
		const string sub = "hackerrank";
		cin>>s;
		findSpecificSub(s,sub);
	}
	return 0;
}
