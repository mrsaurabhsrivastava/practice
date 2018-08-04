#include<iostream>
#include<vector>
#include<thread>
#include<future>

std::mutex mx;
static int i = 0;

using namespace std;

int gFindMissing(const vector<int> xVec, int n, promise<int>&& p)
{
	mx.lock();
	int lMissing = 0;
	int lSum = n*(n+1)/2; 
	
	for (auto el:xVec) 
	{
		lSum -= el;
	}
	p.set_value(lSum);
	//while(1);
	mx.unlock();
	return lSum;
}

int main () 
{
	int lNumTestcase = 2;
	cin>>lNumTestcase;
	vector<int> lResult;
	vector<vector<int>> lInput;
	lInput.resize(lNumTestcase);
	vector<thread> lThreads;
	vector<promise<int>> p;
	p.resize(lNumTestcase);
	vector<future<int>> f;
	f.resize(lNumTestcase);	
	for(int i = 0; i < lNumTestcase; i++)
	{
		int lNumElement;
		cin>>lNumElement;
		lInput[i].reserve(lNumElement-1);
		for(int j = 0; j < lNumElement-1; j++) 
		{
			int Element;
			cin>>Element;
			lInput[i].push_back(Element);
		}
		f[i] = p[i].get_future();
		lThreads.push_back(thread(gFindMissing, lInput[i],  lNumElement, std::move(p[i])));
	}
	
	for (int i = 0; i <lThreads.size(); i++)
	{
		lThreads[i].join();
		lResult.push_back(f[i].get());		
	}
	
	for (auto el:lResult) 
		cout<<el<<"\n";

	
}
