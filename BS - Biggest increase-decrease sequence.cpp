//https://www.spoj.com/problems/BSEARCH1/
//https://www.youtube.com/watch?v=GU7DpgHINWQ

// in this case I want to find the FIRST element
// if arr[i] > arr[i-1] than arr[i] is true, i.e. a possible answer
// the answer will be the last true.
#include <iostream>
using namespace std;

// find the biggest element in a increasing and decreasing array
int n;
int arr[100];

int binSearch(){
	int l = 0, r = n-1, m;
	int ans;
	while(l <= r){
		m = l + ((r-l)/2);
		if(arr[m] > arr[m-1] || m == 0){ // possible ans or there is a better one to the right
			l = m + 1;
			ans = arr[m];
		}else{
			r = m - 1;
		}
	}

	return ans;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	printf("%d\n",binSearch());

	return 0;
}