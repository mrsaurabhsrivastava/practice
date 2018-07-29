//https://www.hackerrank.com/challenges/mark-and-toys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting

#include<iostream>
#include<vector>

using namespace std;


void gQuickSort(vector<int>& xArray, int xStart, int xEnd) 
{
	if (xStart >= xEnd) 
		return;

    	//int lPivot = xStart + (rand() % (xEnd-xStart));
	//swap(xArray[lPivot], xArray[xEnd]);
	int lPivot = xEnd;
  	int lLastLargeIndex = xStart;
    	for (int i = xStart; i < xEnd; i++)
    	{
    		if (xArray[i] < xArray[lPivot]) 
		{
			swap(xArray[i], xArray[lLastLargeIndex]);
			lLastLargeIndex++;
		}
   	}
	swap(xArray[lLastLargeIndex], xArray[lPivot]);
	gQuickSort(xArray, xStart, lLastLargeIndex-1);
	gQuickSort(xArray, lLastLargeIndex+1, xEnd);
	return;
}

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
	
	gQuickSort(prices, 0, prices.size()-1);
	int lCurrSum = 0;
	int lNumToys = 0;
	for (int i = 0; i < prices.size(); i++) 
	{
		lCurrSum+= prices[i];
		if (lCurrSum <= k) 
			lNumToys++;
		else 
			break; 
	}
	return lNumToys;
}

int main ( )
{
	vector<int> lArr = {1, 12, 5, 111, 200, 1000, 10};
	int k = 50;
	cout<<maximumToys(lArr, k)<<endl;;
}
