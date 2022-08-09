#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAXS 500

char B[MAXS], A[MAXS];
int dp[MAXS][MAXS], ans, count = 0;

int lcs(int i, int j){

    if( A[i] == '\0' || B[j] == '\0' )
        return 0;

/*  if I already have the value for i and j stored on the matrix   */
    if(dp[i][j] != -1)
        return dp[i][j];

    if(A[i] == B[j]){
        dp[i][j] = 1 + lcs(i + 1, j + 1);
        return dp[i][j];

    }else{
        dp[i][j] = max( lcs(i + 1, j), lcs(i, j + 1) );
        return dp[i][j];

    }
    
}

int main(){

    scanf("%[^\n] %[^\n]", A, B);

    memset(dp, -1, sizeof(dp));

    printf("%d\n", lcs(0, 0));
    
    return 0;
}