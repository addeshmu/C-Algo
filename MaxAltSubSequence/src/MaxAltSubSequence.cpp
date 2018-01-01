//============================================================================
// Name        : MaxAltSubSequence.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<map>
#include<vector>
using namespace std;

string removeSeq(string s) {
	string ss = "";
	int i = 0;
	int l = (int) s.size();
	char prev = s[i];
	while (i < l) {
		if (i + 1 < l) {
			if (s[i + 1] != s[i]) {
				ss += s[i];
				i++;
			} else {
				prev = s[i];
				while (prev == s[i]) {
					i++;
				}
			}
		}else{
			ss+=s[i];
			i++;
		}
	}
	return ss;
}
map<char,vector<int> >  makemap(string s){
	map<char,vector<int> > mp;
	int l = (int)s.size();
	for (int i =0;i<l;i++){
		if (mp.find(s[i])!=mp.end()){
			mp[s[i]].push_back(i);
		}else{
			vector<int> temp;
			mp.insert(make_pair(s[i],temp));
			mp[s[i]].push_back(i);
		}
	}
	return mp;
}
void printMaxAltLength(string s){
	if (s==""){
		cout<< 0;
		return;
	}
	map<char,vector<int> > mp;
	mp= makemap(s);
	int max = 0;
	map<char,vector<int> >::iterator it,bt;
	for(it=mp.begin();it!=mp.end();it++){
		for(bt=mp.begin();bt!=mp.end();bt++){
			if (bt->first==it->first)
				continue;
			int length = 0;
			vector<int>::iterator vt = it->second.begin(),ct = bt->second.begin();
			vector<int> temp1,temp2;
			if (*vt<*ct){
				temp1 = it->second;
				temp2 = bt->second;
			}else{
				temp1 = bt->second;
				temp2 = it->second;
			}
			vt = temp1.begin();
			ct = temp2.begin();
			int prevvt = -999999 ;
			int prevct = -999999;
            bool flag =true;
			while(vt!=temp1.end() && ct!=temp2.end()){

				if (*vt<*ct && (prevct<*vt||prevvt>*ct)) {
					length += 2;
					prevct=*ct;
					prevvt=*vt;
					vt++;
					ct++;
				}else{
                    flag = false;
					length = 0;
					break;
				}

			}
            if(flag && vt!=temp1.end()){
                int x = *vt;
                vt++;
                if (vt==temp1.end()&& prevct<x) {
                    length++;
                }else{
                    length = 0;
                }
            }
            if(flag && ct!=temp2.end()){
                int x = *ct;
                ct++;
                if (ct==temp1.end()&& prevvt<x) {
                    length++;
                }else{
                    length = 0;
                }
            }
			if(length>max) {
				max = length;
			}
		}
	}
	cout<<max;
}
int main() {
	string s;
    int n;
    cin>>n;
	cin >> s;
	s = removeSeq(s);
	printMaxAltLength(s);
	return 0;
}
