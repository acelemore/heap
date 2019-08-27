/*************************************************************************
    > File Name: maxHeap.h
    > Author: tym
    > Mail: 
    > Created Time: Mon 26 Aug 2019 04:15:59 PM CST
 ************************************************************************/

#ifndef _MAXHEAP_H
#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;

template<typename T>
class MaxHeap
{
public:
	MaxHeap(int initArrLenth = 20);
	~MaxHeap(){delete heap;}
	bool empty() const {return heapSize == 0;}
	int size() const {return heapSize;}
	const T& top();
	void pop();
	void print();
	void push(const T &element);
	void init(T *dataArr, int arrSize);
protected:
	int heapSize;
	std::vector<T> *heap;
};


template<typename T> 
MaxHeap<T>::MaxHeap(int initArrLenth)
{
	if(1 > initArrLenth)
	{
		throw 1;
	}
	//为了方便计算根节点从1开始，数组多申请一位
	heap = new std::vector<T>(initArrLenth + 1);
	heapSize = 0;
}

template<typename T> 
void MaxHeap<T>::print()
{
	cout<<"heap struct:"<<endl;
	for(int i = 0; i<= heapSize; ++i)
	{
		cout<<heap->at(i)<<", ";
	}
	cout<<endl;
}


template<typename T>
const T& MaxHeap<T>::top()
{
	if(0 == heapSize)
		throw 1;
	return heap->at(1);
}

template<typename T>
void MaxHeap<T>::pop()
{
	if(heapSize == 0)
		return;
	T lastElement = heap->at(heapSize);
	heap->erase(heap->begin() + heapSize);
	heapSize--;
	int currentNode = 1, child = 2;
	while(child <= heapSize)
	{
		if(child < heapSize && heap->at(child) < heap->at(child + 1))
			child++;
		if(lastElement >= heap->at(child))
			break;
		heap->at(currentNode) = heap->at(child);
		currentNode = child;
		child = child * 2;
	}
	heap->at(currentNode) = lastElement;
}


template<typename T>
void MaxHeap<T>::push(const T& element)
{
	heapSize++;
	int newNode = heapSize;
	while(newNode != 1 && heap->at(newNode/2)<element)
	{
		if(newNode >= heap->size())
			heap->insert(heap->begin()+newNode, heap->at(newNode/2));
		else
			heap->at(newNode) = heap->at(newNode/2);
		newNode =  newNode/2;
	}
	if(newNode >= heap->size())
		heap->insert(heap->begin() + newNode, element);
	else
		heap->at(newNode) = element;
}


template<typename T>
void MaxHeap<T>::init(T *dataArr, int arrSize)
{
	if(NULL == dataArr || (1 > arrSize))
		return;
	delete heap;
	heap = new std::vector<T>(arrSize + 1);
	for(int i = 0; i < arrSize; i++)
	{
		heap->insert(heap->begin() + i + 1, dataArr[i]);
	}
	heapSize = arrSize;
	for(int root = heapSize/2; root >= 1; root--)
	{
		T rootElement = heap->at(root);
		int child = 2 * root;
		while(child <= heapSize)
		{
			if((child < heapSize) && (heap->at(child) < heap->at(child + 1)))
				child++;
			if(rootElement >= heap->at(child))
				break;
			heap->at(child/2) = heap->at(child);
			child = child*2;
		
		}
		heap->at(child/2) = rootElement;
	}
}




#define _MAXHEAP_H
#endif
