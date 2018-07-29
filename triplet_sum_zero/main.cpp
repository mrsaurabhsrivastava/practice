#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>
#include<algorithm>

using namespace std;

vector<vector<int>> gGetTriplet(vector<int>& A) 
{
	vector<vector<int>> lTriplets;
	unordered_set<int> lKeySet;
	unordered_set<string> lSet;
	lKeySet.insert(A[0]);
	for (int i = 1; i < A.size()-1; i++) 
	{
		for (int j = i+1; j < A.size(); j++)
		{
			int lSum = -(A[i]+A[j]);
			if (lKeySet.find(lSum) != lKeySet.end()) 
			{
				vector<int> lTmp = {lSum, A[i], A[j]};
				std::sort(lTmp.begin(), lTmp.end());
				string lStr;
				for (auto v:lTmp) 
					lStr += to_string(v);
				if (lSet.find(lStr) == lSet.end()) 
				{
					lTriplets.push_back(lTmp);
					//cout<<lSum<<" "<<A[i]<<" "<<A[j]<<"\n";
					lSet.insert(lStr);
					break;
				}
			}
		}
		lKeySet.insert(A[i]);
	}
	return lTriplets; 
}

int main () 
{
	vector<int> lVec = {-1, 0, 1, 2, -1, -4};
	gGetTriplet(lVec);
}

