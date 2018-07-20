#include<bits/stdc++.h>

using namespace std;

struct elementInfo 
{
    int lValue;
    int lCurrPos;
    int lExpectedPos;
    bool lVisited;
};
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int>& arr) {
    map<elementInfo> lArr;
    vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());
    for (int i = 0; i < arr.size(); i++)
   {
        elementInfo lEl;
        lEl.lValue = arr[i];
        lEl.lCurrPos = i;
        lEl.lExpectedPos = 0;
        lEl.lVisited = false;
	lEl.lExpectedPos = std::distance(sortedArr.begin(), std::find(sortedArr.begin(), sortedArr.end(), lEl.lValue));
        lArr.push_back(lEl);
   }
    
    int lSwapNeeded = 0;
    for (int i = 0; i < lArr.size(); i++)
    {
	elementInfo* lEl = &lArr[i];
        if (!lEl->lVisited)
        {
            int lOrig = lEl->lValue;
            while (lEl->lCurrPos != lEl->lExpectedPos && 
                   lEl->lVisited == false)
            {
                lEl->lVisited = true;
                lSwapNeeded++;
                lEl = &lArr[lEl->lExpectedPos];
                if (lEl->lValue == lOrig)
                {
		    lSwapNeeded--;
                    lEl->lVisited = true;
                    break;
                }
                    
            }
        }
    }
    
    return lSwapNeeded;

}

int main ( ) 
{
	vector<int> a = {1,3,5,2,4,6,8};
	cout<<minimumSwaps(a)<<endl;
	return 0;
}
