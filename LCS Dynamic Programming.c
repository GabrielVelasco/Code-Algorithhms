#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXS 500
#define max(a, b) (((a) > (b)) ? (a) : (b))

int dp[MAXS][MAXS];
char A[MAXS], B[MAXS], C[MAXS];

int lcs(int lenA, int lenB){
	int i, j;
	for(i = 1; i <= lenA; i++){
		for(j = 1; j <= lenB; j++){

			if(A[i-1] == B[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max( dp[i-1][j], dp[i][j-1] );

		}
	}

	return dp[lenA][lenB];
}

int main(){
	scanf("%[^\n] %[^\n]", A, B); getchar();
	int ans, lenA = strlen(A), lenB = strlen(B);

	ans = lcs(lenA, lenB);
	printf("%d\n", ans);

	return 0;
}