#include <iostream>
#include <ctime>
#include "MySort.h"
int main(int argc,char *argv[]){
	srand(time(0));
	using std::cin;
	using std::cout;
	using std::endl;
	const int SIZE = 100;
	int *arr;
	arr = new int[SIZE];
	int i = 0;
	cout<<"排序前数组："<<endl;
	for(i = 0;i < SIZE;i++)
	{
		arr[i] = rand()%(200-100+1) + 100;
		if((i + 1)%10 == 0)
			cout<<arr[i]<<endl;
		else
			cout<<arr[i]<<" ";
	}
	BasicNumSort(arr,SIZE);
	cout<<"基数排序后数组："<<endl;
	for(i = 0;i < SIZE;i++)
	{
		if((i + 1)%10 == 0)
			cout<<arr[i]<<endl;
		else
			cout<<arr[i]<<" ";
	}
	cin.get();
	return 0;
}
