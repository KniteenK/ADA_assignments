#include <bits/stdc++.h>
using namespace std;

int Ring_or_Ding (int n , int *arr) {

    // 3d vector to store which word was called and how many times 
    vector <vector <vector <int>>> dp(n+1 , vector<vector<int>>(2 , vector <int>(4 , INT_MIN))) ; 

    dp[0][0][0] = 0 ;
    dp[0][1][0] = 0 ;

    for(int i = 1;i<=n;i++) {
        // if ring was called
        dp[i][0][1] = max ({dp[i-1][1][0] , dp[i-1][1][1] , dp[i-1][1][2] , dp[i-1][1][3]}) + arr[i-1] ;
        dp[i][0][2] = dp[i-1][0][1] == INT_MIN ? INT_MIN : dp[i-1][0][1] + arr[i-1] ;
        dp[i][0][3] = dp[i-1][0][2] == INT_MIN ? INT_MIN : dp[i-1][0][2] + arr[i-1] ;

        // if ding was called 
        dp[i][1][1] = max ({dp[i-1][0][0] ,dp[i-1][0][1] , dp[i-1][0][2] , dp[i-1][0][3]}) - arr[i-1] ;
        dp[i][1][2] = dp[i-1][1][1] == INT_MIN ? INT_MIN : dp[i-1][1][1] - arr[i-1] ;
        dp[i][1][3] = dp[i-1][1][2] == INT_MIN ? INT_MIN : dp[i-1][1][2] - arr[i-1] ;
        cout << dp[i][0][1] << " " <<  dp[i][0][2] << " " <<  dp[i][0][3] << " " << dp[i][1][1] << " " << dp[i][1][2] << " " << dp[i][1][3] << endl ;  
    }
    return max({dp[n][0][0] ,dp[n][0][1] , dp[n][0][2] , dp[n][0][3] ,dp[n][1][1] , dp[n][1][1] , dp[n][1][2] , dp[n][1][3]}) ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    cin >> t;
    while(t--){
        int n ; cin >> n ; 
        int arr[n] ;
        for(int i = 0;i<n;i++) {
            cin >> arr[i] ;
        }
        cout << Ring_or_Ding(n , arr) << endl ;
    }
    return 0;
}