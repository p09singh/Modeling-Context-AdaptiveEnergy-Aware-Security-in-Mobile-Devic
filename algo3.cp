//////////////////////////////////////////////////////////////////
//	Order of input should be n, the number of security levels	//
//	followed by n values, of the security benefits,				//
//	followed by n values of the power consumption,				//
//	followed by B, the security required						//
//	followed by epsilon, the margin of approximation			//
//////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int n, B;
double eps;
int * b;
int * ps;
int ** A;

int * bnew;
int K;

void input() {
	cin>>n;

	b=(int *)malloc(n*sizeof(int));
	bnew=(int *)malloc(n*sizeof(int));
	ps=(int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++) {
		cin>>b[i];
	}
	for(int i=0; i<n; i++) {
		cin>>ps[i];
	}

	cin>>B;
	cin>>eps;

	return;
}

void approximation_routine() {
	K=(eps*B)/n;
	for(int i=0; i<n; i++) {
		bnew[i]=b[i]/K;
	}
	
	A = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; ++i)	{
		A[i] = (int *)malloc((K+1) * sizeof(int));
	}
}

void fptas() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<=K; j++) {
			A[i][j]=INT_MAX;
		}
	}


	for(int i=0; i<n; i++) {
		for(int x=0; x<=K; x++) {
			if(i==0&&x==bnew[0]) {
				A[i][x]=ps[0];
				continue;
			}
			if(bnew[i] <= x) {
				A[i][x] = min(A[i-1][x], A[i-1][x-bnew[i]]+ps[i]);
				continue;
			}
		
			A[i][x] = A[i-1][x];
		}
	}

	cout<<A[n-1][K];
	
	return;
}

int main(int argc, char const *argv[])
{
	input();
	approximation_routine();
	fptas();
	return 0;
}