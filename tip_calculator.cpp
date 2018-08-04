#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void gQuickSort(int xDiffArray[], int xStart, int xEnd, int A[], int B[])  
{
	if (xStart >= xEnd) 
		return;
	int lPivot = xEnd;
	int lTmp = xStart;
	for (int i = xStart; i < xEnd; i++) 
	{
		if (xDiffArray[i] >= xDiffArray[lPivot]) 
		{
			swap(xDiffArray[lTmp], xDiffArray[i]);
			swap(A[lTmp], A[i]); 
			swap(B[lTmp], B[i]); 
			lTmp++;
		}
	}
	swap(xDiffArray[lTmp], xDiffArray[lPivot]);
	swap(A[lTmp], A[lPivot]);
	swap(B[lTmp], B[lPivot]);
	gQuickSort(xDiffArray, xStart, lTmp-1, A,B);
	gQuickSort(xDiffArray, lTmp+1, xEnd, A,B);
	return;	
}

bool gCompare(int i , int j) 
{
	if (i > j ) 
		return true;
	return false;
}

int gMaxTip(int A[], int B[], int n, int x, int y) 
{
	int lDiffArray[n];
	for (int i = 0; i < n; i++) 
	{
		lDiffArray[i] = abs(A[i]-B[i]);
	}
	gQuickSort(lDiffArray, 0, n-1, A, B);
	
	int lMaxTip = 0;
	for (int i = 0; i < n; i++) 
	{
		if (x == 0 && y == 0) 
			break;
		if (y == 0 || (x > 0 && A[i] >= B[i])) 
		{
			lMaxTip += A[i];
			x--;
		}
		else if (x == 0 || (y > 0 && B[i] >= A[i]))
		{
			lMaxTip += B[i];
			y--;
		}
			
	}
	return lMaxTip;
}

int main () 
{
	std::ios::sync_with_stdio(false);
	int lTestcase;
	cin>>lTestcase;
	vector<int> lResult;
	for (int i = 0; i < lTestcase; i++) 
	{
		int n,x,y;
		cin>>n>>x>>y;
		int A[n], B[n];
		for (int j = 0; j < n; j++)
		{
			cin>>A[j];
		}	
		for (int j = 0; j < n; j++)
		{
			cin>>B[j];
		}	
		lResult.push_back(gMaxTip(A,B,n,x,y));
	}
	for (auto v:lResult) 
		cout<<v<<"\n";
}

