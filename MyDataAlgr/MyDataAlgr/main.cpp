#include "basix.h"
#include "MySort.h"
int main(int argc,char *argv[]){
	srand(time(0));
	const int SIZE = 100;
	int *arr;
	arr = new int[SIZE];
	int i = 0;
	cout<<"排序前数组："<<endl;
	randomIintArr(arr,SIZE);
	BasicNumSort(arr,SIZE);
	cout<<"基数排序后数组："<<endl;
	printArr(arr,SIZE);

	cout<<"排序前数组："<<endl;
	randomIintArr(arr,SIZE);
	if(!QuickSort(arr,SIZE))
	{
		cout<<"不能输入空数组进行排序。"<<endl;
	}
	cout<<"快速排序后数组："<<endl;
	printArr(arr,SIZE);

	cout<<"排序前数组："<<endl;
	randomIintArr(arr,SIZE);
	quicksort(arr,0,SIZE-1);
	cout<<"快速排序后数组："<<endl;
	printArr(arr,SIZE);
	delete []arr;
	cin.get();
	return 0;
}
