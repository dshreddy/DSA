#include<bits/stdc++.h>
#define int long long int

using namespace std;

// Brute Force
int bruteForce(int n) {
    if (n <= 1) {
        return n;
    }
    return bruteForce(n - 1) + bruteForce(n - 2);
}

// Memoization
int memoization(int n, unordered_map<int, int> *cache) 
{
    if (n <= 1) return n;
    if (cache->count(n)) return (*cache)[n];
    return memoization(n - 1, cache) + memoization(n - 2, cache);
}

// Dynamic Programming
int dp(int n) 
{
    if (n < 2) return n;

    int dp[] = {0, 1};
    int i = 2;

    while (i <= n) 
    {
        int tmp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = tmp;
        i++;
    }
    return dp[1];
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
   /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/climbing-stairs/
    https://leetcode.com/problems/house-robber/
    */
}

