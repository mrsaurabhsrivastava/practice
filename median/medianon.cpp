
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;

int gQuickSelect(vector<int>& xArray, int xStart, int xEnd, int xK) 
{
	int lPivot = xEnd;
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
	if (lSwapIndex == xK) 
	{
		return xArray[lSwapIndex];
	}
	else if (lSwapIndex > xK) 
	{
		// go in left array 
		return gQuickSelect(xArray, xStart, lSwapIndex-1, xK);
	}
	else if (lSwapIndex < xK) 
	{
		// go in right array 
		return gQuickSelect(xArray, lSwapIndex+1, xEnd, xK);
	}
}

double gMedian(const vector<int>& xArray) 
{
	vector<int> lArray = xArray;
	// Method quick select
	if (lArray.size()%2) 
	{
		int k = lArray.size()/2;
		return (double) gQuickSelect(lArray, 0, xArray.size()-1, k);

	}
	else 
	{
		int k = xArray.size()/2;
		int k1 = xArray.size()/2 -1;
		int kth = gQuickSelect(lArray, 0, lArray.size()-1, k);
		int k1th = gQuickSelect(lArray, 0, lArray.size()-1, k1);
		return (kth + k1th) / (double) 2;
	}
	
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	vector<int> lArray;
	while (1) 
	{
		int l;
		cin>>l;
		lArray.push_back(l);
		cout<<gMedian(lArray)<<endl;
	}
}
