#include <iostream>
#include <fstream> 
using namespace std;
void printOptimal(int** s, int i, int j);
ofstream out; 

int main(int argc,char* argv[])
{
	int c,len=0,*P,n,Psize;
	ifstream infile(argv[1]);
	out.open(argv[2]);	
	infile>>c;
	while(!infile.eof())
	{
		len++;
		infile>>c;
	}
	infile.close();
 
	Psize = len;
	n=Psize-1;   
	
	P = new int[Psize];
	ifstream in(argv[1]);
	for(int i = 0; i < Psize; i++)
	{ 
		in>>P[i];
	}
 
	int **m;
	m = new int*[n];  
	for(int i =1; i <=n; i++)
	{
		m[i] = new int[n]; 
	}
 
	int ** s;
	s = new int*[n];
	for(int i=1; i<=(n); i++)
	{
		s[i]=new int[n];
	}
	for(int l = 2; l <= n; l++)
	{
		for(int i = 1; i<=n-l + 1; i++)
		{
			int j = i+ l-1;   
			int tCost;
			int k = i;
			int mCost = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
			int key = i;
			for(; k<=j-1; k++)
			{
				tCost = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
				if(tCost<mCost)
				{
					mCost = tCost;
					key = k;
				}
			}
			m[i][j] = mCost;
			s[i][j] = key;
		}
	}

	printOptimal(s, 1, n);
	return 0;
}
 
void printOptimal(int** s, int i, int j)
{
	if(i==j)
	{
		out<<"A"<<i;
	}
	else
	{
		out<<"(";
		printOptimal(s,i, s[i][j]);
		printOptimal(s, s[i][j] + 1, j);
		out<<")";
	}
}
