#include <iostream>
#include <vector>
#include <algorithm>

void BucketSort(long arr[], int n) 
{ 
	std::vector<long> b[n]; 
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

void quick_sort(int arr[], int left, int right)
{
	if(right <= left) return;
	
	int i = left - 1, j = right + 1, 
	center = arr[(left+right)/2]; //wybieramy punkt odniesienia
	while(1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci center
		while(center>arr[++i]);
		
		//szukam elementu mniejszego lub rownego center stojacego
		//po lewej stronie wartosci center
		while(center<arr[--j]);
		
		//jesli liczniki sie nie minely to zamień elementy ze soba
		//stojace po niewlasciwej stronie elementu center
		if( i <= j)
			//funkcja swap zamienia wartosciami arr[i] z arr[j]
			std::swap(arr[i],arr[j]);
		else
			break;
	}

	if(j > left)
	quick_sort(arr, left, j);
	if(i < right)
	quick_sort(arr, i, right);
}



