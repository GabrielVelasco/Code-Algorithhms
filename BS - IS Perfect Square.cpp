//https://www.spoj.com/problems/BSEARCH1/
//https://www.youtube.com/watch?v=GU7DpgHINWQ
#include <iostream>
#include <time.h>

using namespace std;

typedef long long ll;
ll n;

bool binSearch(){
	ll l = 0, r = n-1;
	ll m;
	while(l <= r){
		m = l + ((r-l)/2);
		if(m*m == n)
			return true;
		
		if(m*m < n)
			l = m + 1;
		else
			r = m - 1;
	}

	return false;
}

// verify if N is a perfect square
int main(){
	time_t t = clock();
	cin >> n;
	
	if(binSearch())
		cout << "yes\n";
	else
		cout << "no\n";

	t = clock() - t;
	printf("Time: %f\n", (float)t/CLOCKS_PER_SEC);

	return 0;
}