# include <iostream>
# include <fstream>
# include <string.h>
using namespace std;
ofstream of;
int matrix[100][100];
int select[100][100];

int max(int arr, int weight) 
{ 
	return (arr > weight)? arr : weight; 
}

int knapsack(int nItems, int size, int weights[], int values[])
{
	int i,j;
	for (i=1;i<=nItems;i++)
	{
        	for (j=0;j<=size;j++)
		{
            		if (weights[i-1]<=j)
			{
                		matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                		if (values[i-1]+matrix[i-1][j-weights[i-1]]>matrix[i-1][j])
                   			 select[i][j]=1;
                		else
                   			select[i][j]=-1;
           		 }
          		else
			{
               			select[i][j] = -1;
                		matrix[i][j] = matrix[i-1][j];
            		}
        	}
    	}
	return matrix[nItems][size];
}

void print(int item, int size, int weights[])
{
int count=0;
int n=item;
	while (item>0)
	{
        	if (select[item][size]==1)
		{
            		of<<"0";
			count++;
            		item--;
            		size -= weights[item];
        	}
        	else
		{
			of<<"1";
            		item--;
			count++;
       		}
		if(count<n)
		{
			of<<",";
		}
	}
	return;
}

int main(int argc,char *argv[])
{
	string line;
	int y=1;
	int i;
	int count=0;
	int id=0;
	int arr[200];
	int weight[200]; 
	int value[200];
	ifstream in;
	in.open(argv[1],ios::in);
	of.open(argv[2]);
	while (getline(in,line))
	count++;
	in.close();
	in.open(argv[1],ios::in);
	for(y=1;y<=count-1;y++)
        {
	        for( i = 0; i < 3; ++i)
       		{
            		in >> arr[i];
        	}
          	weight[id]=arr[1];
           	value[id]=arr[2];  
           	id++; 
        }
    	int W;
    	in>>W;
    	int j;
    	j=knapsack(count-1,W,weight,value);
    	print(count-1,W,weight);
    	of<<"\n"<<j;
    	return 0;
}
