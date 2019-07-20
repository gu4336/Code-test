/*
There are N stairs, and a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, 
the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.*/

long long countWays(int m){
    // your code here
    long long dp[m + 1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= m; i++){
        dp[i] += dp[i - 1];
    }
    for(int i = 2; i <= m; i++){
        dp[i] += dp[i - 2];
    }
    return dp[m];
}
