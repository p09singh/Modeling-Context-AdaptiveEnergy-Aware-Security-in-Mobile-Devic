//////////////////////////////////////////////////////////////////
//	Order of input should be n, the number of security levels	//
//	followed by n values of the security benefits,				//
//	followed by n values of the power consumption,				//
//	followed by B, the security required						//
//	followed by E, maximum power cconsumption					//
//////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>

using namespace std;

struct security {
	int b;
	int ps;
};

int n, B;
struct security * S;
int E;

void input() {
	cin>>n;

	S=(struct security *)malloc(n*sizeof(struct security));
	
	for(int i=0; i<n; i++) {
		cin>>S[i].b;
	}
	for(int i=0; i<n; i++) {
		cin>>S[i].ps;
	}

	cin>>B;
	cin>>E;

	return;
}

bool mycompare(struct security x, struct security y) {
	return ((((double)x.b)/x.ps) > (((double)y.b)/y.ps));
}

void maxvaluealgo() {
	sort(S, S+n, mycompare);

	int totalsecurity=0, totalpower=0, i=0;
	while(totalpower<=E && i<n) {
		totalsecurity+=S[i].b;
		totalpower+=S[i].ps;
		i++;
	}

	i--;
	if(i==n-1) {
		if(totalpower<=E)
			cout<<totalsecurity;
		else
			cout<<max(totalsecurity-S[i].b, S[i].b);
	}
	else {
		cout<<max(totalsecurity-S[i].b, S[i].b);
	}

	return;
}


int main(int argc, char const *argv[])
{
	input();
	maxvaluealgo();
	return 0;
}