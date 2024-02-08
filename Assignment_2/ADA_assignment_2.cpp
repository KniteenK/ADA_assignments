#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n ; cin >> n;
    int arr[n] ;
    for(int i = 0;i<n;i++) {
        cin >> arr[i] ;
    }

    vector <vector <int>> dp(n+1 , vector<int>(2 , INT_MIN)) ;
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<=i;j++) {
            
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    cin >> t;
    while(t--){
        solve() ;
    }
    return 0;
}