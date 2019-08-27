/*************************************************************************
    > File Name: main.cpp
    > Author: tym
    > Mail: 
    > Created Time: Tue 27 Aug 2019 05:17:07 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"maxHeap.h"
using std::cout;
using std::endl;
int main()
{
	srand(time(NULL));
	int arr[20];
	cout<<"arr:"<<endl;
	for(int i = 0; i < 20; i++)
	{
		arr[i] = rand() % 1000;
		cout<<arr[i]<<", ";
	}
	cout<<endl;

	MaxHeap<int> mh(20);
	mh.init(arr, 20);
	mh.print();
	cout<<"heap:"<<endl;
	for(int j = 0; j < 20; j++)
	{
		cout<<mh.top()<<", ";
		mh.pop();
	}	
	cout<<endl;
	return 0;
}
