#include "MySort.h"

void randomIintArr(int *arr,int n){
	int i = 0;
	for(i = 0;i < n;i++)
	{
		arr[i] = rand()%(500-100+1)+100;
		if((i + 1)%10 == 0)
			cout<<arr[i]<<endl;
		else
			cout<<arr[i]<<" ";
	}
}

void printArr(const int *arr,int n){
	int i = 0;
	for(i = 0;i < n;i++)
	{
		if((i + 1)%10 == 0)
			cout<<arr[i]<<endl;
		else
			cout<<arr[i]<<" ";
	}
}

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

void Swap(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void Qsort(int *arr,int left,int right){
	if(left < right)
	{
 		int basic = arr[left];
		int i = left,j = right;
		while(i < j)
		{
			while(i <= right && arr[i] <= basic)
				i++;
			while(j >= left && arr[j] > basic)
				j--;
			if(i < j)
			{
				Swap(arr+i,arr+j);
			}
			else
				break;
		}
		Swap(arr+j,arr+left);
		Qsort(arr,left,j-1);
		Qsort(arr,j + 1,right);
	}
	else
		return;
}

int QuickSort(int *arr,int n){
	if(!arr)
		return 0;
	Qsort(arr,0,n-1);
	return 1;
}

void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int choose_pivot(int i,int j )
{
   return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
   int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j)
                swap(&list[i],&list[j]);
      }
     // 交换两个元素的位置
      swap(&list[m],&list[j]);
     // 递归地对较小的数据序列进行排序
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);
   }
}