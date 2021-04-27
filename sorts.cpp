#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(float arr[], int n) 
{ 
	
	std::vector<float> b[n]; 
    // Put array elements in different buckets 
	for (int i = 0; i < n; i++) { 
		int bi = n * arr[i]; // Index in bucket 
		b[bi].push_back(arr[i]);    
	} 
    // sorting the buckets 
	for (int i = 0; i < n; i++) 
		sort(b[i].begin(), b[i].end()); 
    // add all the buckets into arr.
	int index = 0; 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < b[i].size(); j++) 
			arr[index++] = b[i][j]; 
} 

