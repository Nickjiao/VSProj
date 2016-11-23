#include "MySort.h"

int GetNum(int n,int p){
	while(p)
	{
		n /= 10;
		p--;
	}
	return n%10;
}

int FindMax(int *arr,int n){
	if(!arr)
		return 0;
	int m = arr[0];
	for(int i = 1;i < n;i++)
	{
		if(arr[i] > m)
			m = arr[i];
	}
	return m;
}

int BasicNumSort(int *arr,int n){
	int **BasicArr = new int*[10];
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		BasicArr[i] = new int[1+n];
		BasicArr[i][0] = 0;
	}
	int max = FindMax(arr,n);
	if(max == 0)
		return 0;
	int p = 0;
	while(max)
	{
		max /= 10;
		p++;
	}
	int j = 0,k = 0;int t = 0;int s = 0;
	for(i = 0;i < p;i++)
	{
		for(k = 0;k < n;k++)
		{
			t = GetNum(arr[k],i);
			BasicArr[t][0]++;
			s = BasicArr[t][0];
			BasicArr[t][s] = arr[k];
		}
		k = 0;
		for(j = 0;j < 10;j++)
		{
			for(t = 1;t <= BasicArr[j][0];t++)
			{
				arr[k++] = BasicArr[j][t];
			}
			BasicArr[j][0] = 0;
		}
	}
	return 0;
}