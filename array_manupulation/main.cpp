//https://www.hackerrank.com/challenges/crush/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
	vector<int> lVec(n+1,0);
	
	for (int i = 0; i < queries.size(); i++) 
	{
		
		// Put sum at start of query range 
		// and -sum at end+1 of query range
		lVec[queries[i][0]] += queries[i][2];
		if (queries[i][1] + 1 <= n) 
			lVec[queries[i][1] +1] -= queries[i][2];
		
	}
	long lMax = LONG_MIN;
	long lSum = 0;
	for (int i = 0; i < lVec.size(); i++) 
	{
		lSum += lVec[i];
		if (lSum > lMax) 
			lMax = lSum;
	}
	return lMax;
}

int main () 
{
	//vector<vector<int>> queries = {{1, 2, 100},
//				       {2,5,100},
//					{3,4,100}};
	vector<vector<int>> queries = {{2, 3, 603},
				       {1,1,286},
					{4,4,882}};
	int n = 4;
	cout<<arrayManipulation(n, queries)<<endl;
	return 0;

}
