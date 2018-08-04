#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main () 
{
	std::ios::sync_with_stdio(false);
	int lTestcase;
	vector<int> lResult;
	cin>>lTestcase;
	for (int i =0; i < lTestcase; i++) 
	{
		int lArraySize;
		cin>>lArraySize;
		int lArray[lArraySize];
		for (int j = 0; j < lArraySize; j++) 
		{
			cin>> lArray[j];
		}
		sort(lArray, lArray+lArraySize);
		if (lArraySize % 2 == 0) 
		{
			lResult.push_back((lArray[lArraySize/2] + lArray[lArraySize/2-1])/2);
		}
		else 
		{
			lResult.push_back(lArray[lArraySize/2]);
		}
	}
	for (auto v:lResult) 
		cout<<v<<"\n";
}
