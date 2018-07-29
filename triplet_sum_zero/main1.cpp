#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>
#include<algorithm>

using namespace std;

vector<vector<int>> gGetTriplet(vector<int>& A) 
{
	vector<vector<int>> lTriplets;
	if (A.size() > 2) 

	sort(A.begin(), A.end());
	unordered_set<int> lSet;
	unordered_set<string> lUnique;
	lSet.insert(A[0]);
	for (int i = 1; i < A.size()-1; i++) 
	{

		for (int j = i+1; j < A.size(); j++) 
		{
			int lSum = -(A[i] + A[j]);
			if (lSet.find(lSum) != lSet.end()) 
			{
				string lTmp = to_string(lSum) + ","+to_string(A[i])+","+to_string(A[j]);
				if (lUnique.find(lTmp) == lUnique.end())
				{
					lTriplets.push_back({lSum, A[i], A[j]});
					cout<<lSum<<" "<<A[i]<<" "<<A[j]<<"\n";
					lUnique.insert(lTmp);
				}
			}		
		}
		lSet.insert(A[i]);
	}		

	return lTriplets; 
}

int main () 
{
	vector<int> lVec = { 1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3 };
	gGetTriplet(lVec);
}

