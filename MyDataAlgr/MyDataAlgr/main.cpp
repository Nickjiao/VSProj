#include "basix.h"
#include "MySort.h"
int main(int argc,char *argv[]){
	srand(time(0));
	const int SIZE = 100;
	int *arr;
	arr = new int[SIZE];
	int i = 0;
	cout<<"����ǰ���飺"<<endl;
	randomIintArr(arr,SIZE);
	BasicNumSort(arr,SIZE);
	cout<<"������������飺"<<endl;
	printArr(arr,SIZE);

	cout<<"����ǰ���飺"<<endl;
	randomIintArr(arr,SIZE);
	if(!QuickSort(arr,SIZE))
	{
		cout<<"��������������������"<<endl;
	}
	cout<<"������������飺"<<endl;
	printArr(arr,SIZE);

	cout<<"����ǰ���飺"<<endl;
	randomIintArr(arr,SIZE);
	quicksort(arr,0,SIZE-1);
	cout<<"������������飺"<<endl;
	printArr(arr,SIZE);
	delete []arr;
	cin.get();
	return 0;
}
