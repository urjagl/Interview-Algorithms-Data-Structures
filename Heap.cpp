// https://www.geeksforgeeks.org/heap-sort/
// https://www.geeksforgeeks.org/binary-heap/

// This code was referenced from :
//https://www.codeproject.com/Tips/816934/Min-Binary-Heap-Implementation-in-Cplusplus

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

class MinHeap{
public:
	vector<int> arrayHeap;
	MinHeap(int* arr, int len); //Constructor: converting an array into a heap
	MinHeap(vector<int>& v);
	MinHeap();
	void bubbleDown(int index);
	void bubbleUp(int index);
	void heapify();
	int parentIndex(int i){
		return (i-1)/2;
	}
	int leftChildIndex(int i){
		return (2*i)+1;
	}
	int rightChildIndex(int i){
		return (2*i)+2;
	}

	void deleteMin() //Root key
	int getMin() {return arrayHeap[0];}
	void insertKey(int k); //Insert a key k 

};

//Constructor: Building a Heap from a given array[] of given size

 MinHeap::MinHeap(const std::vector<int>& v){
 	heapify();
}

MinHeap::MinHeap(int* arr, int len){
	for(int i = 0; i < len; i++){
		arrayHeap[i] = arr[i];
	}
	heapify();
}

MinHeap::MinHeap(){}

void MinHeap::heapify(){
	int length = arrayHeap.size();
	for(int i = length-1; i >=0; i--){
		bubbleDown(i);
	}
}

void MinHeap::bubbleDown(int index){
	int length = arrayHeap.size();
	int minimumIndex = index;
	int leftIndex = leftChildIndex(index);
	int rightIndex = rightChildIndex(index);
	if(leftIndex >= length){
		return; //Index is a leaf, can't bubble down more
	}
	if(arrayHeap[index] > arrayHeap[leftIndex]){
		minimumIndex = leftIndex;
	}
	if(rightIndex < length) && 
		(arrayHeap[minimumindex] > arrayHeap[rightIndex]){
		minimumindex = rightIndex;
	}
	if(minimumindex != index){
		swap(arrayHeap[index], arrayHeap[minimumindex])
		bubbleDown(minimumindex);
	}
}

void MinHeap::bubbleUp(int index){
	if(index == 0){
		return;
	}
	int parInd = parentIndex(index);
	if(arrayHeap[parIndex] > arrayHeap[index]){
		swap(arrayHeap[parIndex],arrayHeap[index]);
		bubbleUp(parIndex);
	}
}

void MinHeap::insertKey(int key){
	int length = arrayHeap.size();
	arrayHeap[length] = key;
	bubbleUp(length);
}

void MinHeap::deleteMin(){
	int length = arrayHeap.size();
	if(length == 0){
		return;
	}
	arrayHeap[0] = arrayHeap[length-1];
	arrayHeap.pop_back();
	bubbleDown(0);
}

//HeapSort


// k-th largest Element in an array 



// Sort an almost sorted array 



// height of a heap/ Complete binary tree 






