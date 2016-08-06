# include <iostream>
# include <fstream>
# include <string.h>
# include <iomanip>
using namespace std;
ofstream fileOutput;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void sort_vpp(int vpp[], int id[], int weight[], int value[], int n)
{
	int i, j, max_index;
	for (i = 0; i < n-1; i++)
	{
		max_index = i;
		for (j = i+1; j < n; j++)
			if (vpp[j] > vpp[max_index])
				max_index = j;
		swap(&vpp[max_index], &vpp[i]);
		swap(&id[max_index], &id[i]);
		swap(&weight[max_index], &weight[i]);
		swap(&value[max_index], &value[i]);
	}
}

void sort(int vpp[], int id[], float fraction[], int weight[], int value[], int n)
{
	int i, j, min_index;
	float temp;
	for (i = 0; i < n-1; i++)
	{
		min_index = i;
		for (j = i+1; j < n; j++)
			if (id[j] < id[min_index])
				min_index = j;
		swap(&vpp[min_index], &vpp[i]);
		swap(&id[min_index], &id[i]);
		swap(&weight[min_index], &weight[i]);
		swap(&value[min_index], &value[i]);
		temp=fraction[i];
		fraction[i]=fraction[min_index];
		fraction[min_index]=temp;
	}
}

void fractionalKnapsack(int W, int id[], int weight[], int value[], int n)
{
	int vpp[30];
	float fraction[30];
	int i;
	int cost=0;
	for(i=0;i<n;i++)
	{
		vpp[i]= value[i]/weight[i];
	}
	sort_vpp(vpp,id,weight,value,n);
	for(i=0;i<n;i++)
	{
		if(weight[i]<W)
		{
			fraction[i]=1.00;
			W=W-weight[i];
			cost=cost+value[i];
		}
		else if(W==0)
		{
			fraction[i]=0.00;
		}
		else if(weight[i]>W)
		{
			fraction[i]= ((float)W/(float)weight[i]);
			cost=cost+(value[i]*((float)W/(float)weight[i]));
			W=0;
		}
	}
	sort(vpp,id,fraction,weight,value,n);
	for(i=0;i<n;i++)
	{
		fileOutput<<fixed<<setprecision(2)<<fraction[i];
		if(i<n-1)
		{
			fileOutput<<',';
		}
	}
	fileOutput<<'\n';
	fileOutput<<cost;
}

int main(int argc,char *argv[])
{
	int  i;
	string line;
	int y=1, count=0, id=0, arr1[200], arr2[200], arr3[200], arr4[200];
	ifstream fileInput;
	fileInput.open(argv[1],ios::in);
	fileOutput.open(argv[2]);
	while (getline(fileInput,line))
		count++;
	fileInput.close();
	fileInput.open(argv[1],ios::in);
	for(y=1;y<=count-1;y++)
        {
	        for( i = 0; i < 3; ++i)
        	{
           		fileInput >> arr1[i];
        	}
          	arr4[id]=arr1[0];
          	arr2[id]=arr1[1];
           	arr3[id]=arr1[2];  
           	id++; 
        }
	float W;
	fileInput>>W;
	fractionalKnapsack(W,arr4,arr2,arr3,count-1);
	return(0);
}

