Idea is 

n = 10 
Queries 

1-5 3
4-8 7
6-9 1

In array of 11 (10+1 , 0 index will not be used) initialize all element with 0 

with first query 
1-5 3 put arr[1] += 3 and arr[6] += -3 (end+1) 
4-8 7 put arr[4] += 7 and arr[9] += -7 
6-9 1 put arr[6] += 1 (Alraedy arr[6] has -3  so new value will be -2) arr[6] = -2
			and arr[10] = -1;

not array is 
arr[0] = 0;
arr[1] = 3;
arr[2] = 0;
arr[3] = 0;
arr[4] = 7;
arr[5] = 0;
arr[6] = -2;
arr[7] = 0;
arr[8] = 0;
arr[9] = 0 
arr[10] = -1;

now sum += arr[i] 
	if(sum > max) 
		max = sum;
