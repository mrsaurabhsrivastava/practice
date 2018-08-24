//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/1
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;
template <typename T> 
T get() 
{
	T result;
	cin>>result;
	return result;
}

class minHeap
{
	public:
	minHeap(int xCapacity) : dCapacity(xCapacity) , dCurrSize(0) {dArray = new int[dCapacity];}
	
	int getRoot();
	void insert(int x);
	private:
	void heapify(int index); 
	int dCapacity;
	int* dArray;
	int dCurrSize;
};

int minHeap::getRoot() 
{
	if (dCapacity > dCurrSize) 
		return -1;
	else 
		return dArray[0];
}

void minHeap::insert(int x) 
{
	if (dCapacity == dCurrSize) 
	{
		if (x > getRoot()) 
		{
			dArray[0] = x;
			heapify(0);
		}
	}
	else 
	{
		dArray[dCurrSize] = x;
		int index = dCurrSize;
		dCurrSize++;
		int parent = (index-1)/2; 
		while(parent >= 0 && dArray[parent] > dArray[index]) 
		{
			swap(dArray[parent], dArray[index]);
			index = parent;
			parent = (index-1)/2;
		}
	}
}

void minHeap::heapify(int index) 
{
	int left = 2*index + 1;
	int right = 2*index + 2;
	int i = index;
	if (dCurrSize > left && dArray[left] < dArray[i]) 
		i = left;
	if (dCurrSize > right && dArray[right] < dArray[i]) 
		i = right;
	
	if (i != index) 
	{
		swap(dArray[index], dArray[i]);
		heapify(i);	
	}
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	int lTest = get<int>();
	FOR(i, lTest) 
	{
		int k = get<int>();
		int n = get<int>();
		minHeap lHeap(k);
		FOR(j, n) 
		{
			int el = get<int> ();
			lHeap.insert(el);
			cout<<lHeap.getRoot()<<" ";
		}
		cout<<"\n";
	}
}
