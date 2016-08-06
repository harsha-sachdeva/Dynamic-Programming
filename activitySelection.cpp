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
 
void print(int id[],int s[], int f[], int n)
{
	int i,j;
	i=0;
	fileOutput<<id[0];
	for (j = 1; j < n; j++)
	{
		if (s[j] >= f[i])
		{
			fileOutput<<","<<id[j];
			i=j;
		}  
	}
}

int main(int argc,char *argv[])
{
	string line;
	int y=1, i, j, n=0, id=0, arr1[200], arr2[200], arr3[200], arr4[200];
	ifstream fileInput;
	fileInput.open(argv[1],ios::in);
	fileOutput.open(argv[2]);
	while (getline(fileInput,line))
	n++;
	fileInput.close();
	fileInput.open(argv[1],ios::in);
	for(y=1;y<=n;y++)
        {
        	for( i = 0; i < 3; ++i)
        	{
            		fileInput >> arr1[i];
        	}
         arr2[id]=arr1[1];
         arr3[id]=arr1[2]; 
         arr4[id]=arr1[0]; 
         id++; 
         }
	for (i = 0; i < n-1; i++)  
	{   
		for (j = 0; j < n-i-1; j++) 
        	{
        		if (arr3[j] > arr3[j+1])
             		{
             			swap(&arr3[j], &arr3[j+1]);
             			swap(&arr2[j],&arr2[j+1]);
              			swap(&arr4[j],&arr4[j+1]);
             		}
         	}
        }
    	print(arr4,arr2,arr3,n);
    	return 0;
}
