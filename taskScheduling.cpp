# include <iostream>
# include <fstream>
# include <string.h>
using namespace std;
ofstream fileOutput;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)     
		for (j = 0; j < n-i-1; j++) 
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

struct task
{
	int deadlock, cost, itd;
}task[20],temp;

int main(int argc,char *argv[])
{
	int i,j,n,p[20],count=0,c=0,ans[20],ex[10],penalty=0,temp1=1,x=0;
	string line;
	int y=1, no_of_lines=0, id=0, arr1[200];
	ifstream fileInput;
	fileInput.open(argv[1],ios::in);
	fileOutput.open(argv[2]);
	while (getline(fileInput,line))
		no_of_lines++;
	fileInput.close();
	fileInput.open(argv[1],ios::in);
	for(y=1;y<=no_of_lines;y++)
        {
        	for( i = 0; i < 3; ++i)
        	{
            		fileInput >> arr1[i];
        	}
        	task[id].deadlock=arr1[1];
        	task[id].cost=arr1[2];  
		task[id].itd=arr1[0];
           	id++; 
           	p[id]=-1;
        }
	n=no_of_lines;      
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(task[i].cost<task[j].cost)
			{
				temp=task[i];
				task[i]=task[j];
				task[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(p[task[i].deadlock]==-1)
		{
			p[task[i].deadlock]=0;
			ans[count++]=task[i].itd;
		}
		else
		{
			c=task[i].deadlock;
			temp1=1;
			while(c>0)
			{
				if(p[c]==-1)
				{
					temp1=0;
					p[c]=0;
					ans[count++]=task[i].itd;
					break;
				}
				c--;
			}
			if(temp1==1)
			{
				ex[x++]=task[i].itd;
				penalty=penalty+task[i].cost;
			}
		}
	}
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(task[ans[i]].deadlock>=task[ans[j]].deadlock)
			{
				temp1=ans[i];
				ans[i]=ans[j];
				ans[j]=temp1;
			}
		}
	}
	int arr2[200], arr3[200], d=0, e=0, knt=0, v=x;
	for(i=0;i<count;i++)
	{
		arr2[d]=ans[i];
		d++;
	}
	for(i=0;i<x;i++)
	{
		arr3[e]=ex[i];
		e++;
	}
	bubbleSort(arr2,count);
	for(i=0;i<count;i++)
	{
		fileOutput<<arr2[i]<<",";
	}
	bubbleSort(arr3,x);
	for(i=0;i<x;i++)
	{
		fileOutput<<arr3[i];
		if(knt<v-1)
		{
			fileOutput<<",";
			knt++;
		}
	}
	fileOutput<<"\n"<<penalty;
	return 0;
}
