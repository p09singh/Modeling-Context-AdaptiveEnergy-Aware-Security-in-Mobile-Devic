//////////////////////////////////////////////////////////////////
//	Order of input should be n, the number of security levels	//
//	followed by n values of the security benefits,				//
//	followed by n values of the power consumption,				//
//	followed by B, the security required						//
//////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <fstream>

using namespace std;

// #define cin fin
// #define cout fout

int n, B;
int * b;
int * ps;
int ** A;


const int inf=1e7;

void input() {
	cin>>n;

	b=(int *)malloc(n*sizeof(int));
	ps=(int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++) {
		cin>>b[i];
	}
	for(int i=0; i<n; i++) {
		cin>>ps[i];
	}

	cin>>B;

	A = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; ++i)	{
		A[i] = (int *)malloc((B+1) * sizeof(int));
	}
	return;
}

void dpalgorithm() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<=B; j++) {
			A[i][j]=inf;
		}
	}


	for(int i=0; i<n; i++) {
		for(int x=0; x<=B; x++) {
			if(i==0&&x==b[0]) {
				A[i][x]=ps[0];
				continue;
			}
			if(i==0)
				continue;
			if(b[i] <= x) {
				A[i][x] = min(A[i-1][x], A[i-1][x-b[i]]+ps[i]);
				continue;
			}
		
			A[i][x] = A[i-1][x];
		}
	}

	cout<<A[n-1][B];
	return;
}

int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	input();
	dpalgorithm();
	return 0;
}