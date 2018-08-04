#include<iostream>
#include<vector>
#include<array>

using namespace std;

array<int, 2> gGetIndexOfSubarraySum(int xArray[], int xSize, int xSum)
{
	array<int, 2> lResult;
	lResult[0] = -1;
	bool lFound = false;
	if (xSize > 0) 
	{
		int lStart = 0;
		int lCurrSum = 0;
		for (int i = 0; i < xSize; i++) 
		{
			lCurrSum += xArray[i];
			if (lCurrSum == xSum) 
			{
				lResult[0] = lStart+1;
				lResult[1] = i+1;
				lFound = true;
			}

			while (lStart >= 0 && lCurrSum > xSum) 
			{
				lCurrSum -= xArray[lStart];
				lStart++;
				if (lCurrSum == xSum) 
				{
					lResult[0] = lStart+1;
					lResult[1] = i+1;
					lFound = true;
					break;
				}
			}
			if (lFound) 
				break;
		}
	} 
	return lResult;
}

int main () 
{
	std::ios::sync_with_stdio(false);
	int lTestcase;
	cin>>lTestcase;
	vector<array<int, 2>> lResult;	
	for (int i = 0; i < lTestcase; i++)
	{
		int lSize, lSum;
		cin>>lSize>>lSum;
		int lArray[lSize];
		for (int j = 0; j < lSize; j++) 
		{
			cin>>lArray[j];
		}
		lResult.push_back(gGetIndexOfSubarraySum(lArray, lSize, lSum));
	}
	for (auto v:lResult) 
	{
		if (v[0] != -1) 	
		cout<<v[0]<<" "<<v[1]<<"\n";
		else 
		cout<<-1<<"\n";
	}
}
