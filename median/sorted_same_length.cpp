//https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;

double gMedian(const vector<int>& xArray, int xStart, int n) 
{
	int lMedian = 0;
	if (n % 2) 
	{
		// odd 
		lMedian = xArray[xStart + n/2];
	}
	else 
	{
		// even
		lMedian = (xArray[xStart + n/2 -1] + xArray[xStart + n/2])/(double)2; 
	}
	
	return lMedian;	
}

double gMedianOfArray(const vector<int>& xArray1, 
		      int xStart1, 
		      const vector<int>& xArray2, 
		      int xStart2, 
		      int n) 
{
	if (n <= 0)
		return -1;
	if (n == 1) 
		return (xArray1[xStart1]+xArray2[xStart2])/(double)2;

	if (n == 2) 
		return (max(xArray1[xStart1], xArray2[xStart2]) + min (xArray1[xStart1+1], xArray2[xStart2+1]))/(double)2;

	double lMedian1 = gMedian(xArray1, xStart1, n); 
	double lMedian2 = gMedian(xArray2, xStart2, n);
	if (lMedian1 < lMedian2) 
	{
		if (n%2) 
			return gMedianOfArray(xArray1, xStart1+n/2, xArray2, xStart2, n/2+1);
		else 
			return gMedianOfArray(xArray1, xStart1+n/2-1, xArray2, xStart2, n/2+1);
	}
	else if (lMedian1 > lMedian2) 
	{
		if (n%2) 
			return gMedianOfArray(xArray1, xStart1, xArray2, xStart2+n/2, n/2+1);
		else 
			return gMedianOfArray(xArray1, xStart1, xArray2, xStart2+n/2-1, n/2+1);
	}
	
	return lMedian1;
}


int main() 
{
	std::ios_base::sync_with_stdio(false);
	vector<int> A1 = {8,10,12,20,24};
	vector<int> A2 = {5,9,11,25,26};
	cout<<gMedianOfArray(A1, 0, A2, 0, A1.size())<<endl;
}
