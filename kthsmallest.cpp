
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

int gRandomSelect(vector<int>& xArray, int xStart, int xEnd, int k) 
{
	int lPivot = xStart + rand() % (xEnd-xStart+1);
	swap(xArray[lPivot], xArray[xEnd]);
	lPivot = xEnd;
	int lSwapIndex = xStart;
	for (int i = xStart; i < xEnd; i++) 
	{
		if (xArray[i] < xArray[lPivot])
		{
			swap(xArray[i], xArray[lSwapIndex]);
			lSwapIndex++;
		}
	}
	swap(xArray[lSwapIndex], xArray[lPivot]);
	if (lSwapIndex == k) 
		return xArray[lSwapIndex];
	else if (lSwapIndex > k) 
		return gRandomSelect(xArray, xStart, lSwapIndex-1, k);
	else 
		return gRandomSelect(xArray, lSwapIndex+1, xEnd, k);

}

int kthElement(vector<int>& xArray, int k) 
{
	return gRandomSelect(xArray, 0, xArray.size()-1, k);
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int lTest = get<int>();
	FOR(i, lTest)
	{
		vector<int> lArray;
		int lNum = get<int>();
		lArray.resize(lNum, -1);
		FOR(j, lNum)
		{
			lArray[j] = get<int>();
		}
		int k = get<int>();
		cout<<kthElement(lArray, k-1)<<"\n";
	}
}
