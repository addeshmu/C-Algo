//============================================================================
// Name        : StrangeFunction.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Ansi-style
//============================================================================

#include <iostream>
#include  <math.h>
using namespace std;

long long findSingleSum(long long t){
	long long sum =0;
	while(t>9){
		sum += t%10;
		t = t/(long long)10;
	}
	sum+=t;
	if (sum>9)
		return findSingleSum(sum);
	return sum;
}
int solve(long long A,long long N)
{
   long long res=1;
   while(N)
   {
        if(N%2==1)
        {
            res=res*findSingleSum(A);
            res=findSingleSum(res);
        }
        A=findSingleSum(findSingleSum(A)*findSingleSum(A));
        N/=2;
   }
   return res;
}
int main() {
	long long n;
	cin>>n;
	for (long long i=0;i<n;i++){
		long long t, p;
		cin>>t>>p;

		cout<<solve(t,p)<<endl;
	}
	return 0;
}
