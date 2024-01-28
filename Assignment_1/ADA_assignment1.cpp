#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long

pair <int,int> CountSmallerAndEqualNumbers(int *arr , int n , int key) {

    // This function simply just returns the number of elements smaller than key , also if there are duplicate elements it will return their range

    int l = lower_bound(arr , arr + n , key) - arr ;
    int r = upper_bound(arr , arr + n , key) - arr ;

    return {l,r} ;
}

int BinarySearchForAnswer (int *a , int *b , int *c , int k , int n) {

    // This function tries to find a element which has k-1 smaller elements than itself .

    int i = 0 , j = n-1 ;
    while (i <= j) {
        int mid = i + (j-i) / 2 ;
        auto range_a = CountSmallerAndEqualNumbers(a , n , a[mid]) , range_b = CountSmallerAndEqualNumbers(b , n , a[mid]) , range_c = CountSmallerAndEqualNumbers(c , n , a[mid]) ;
        int count1 = range_a.first + range_b.first + range_c.first ;
        int count2 = range_a.second + range_b.second + range_c.second ;
        if (count1 < k && k <= count2) {
            return a[mid] ;
        }
        else if (count1 >= k) {
            j = mid-1 ;
        }
        else i = mid+1 ;
    }
    return -1 ;
}

int Answer (int n , int k , int *a , int *b , int *c) {

    // I'm checking for the answer in each array one by one , if the kth element is not present in one array , move to the next
    int ans = BinarySearchForAnswer(a , b , c , k , n) ;
    if (ans != -1) return ans ;
    else {
        ans = BinarySearchForAnswer(b , a , c , k , n) ;
        if (ans != -1) return ans ;
        else {
            ans = BinarySearchForAnswer(c , b , a , k , n) ; 
            return ans ;
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , k ; cin >> n >> k ;
    int a[n] , b[n] , c[n];
    // take input array a , b and c
    for(int i = 0;i<n;i++) {
        cin >> a[i] ;
    }
    for(int i = 0;i<n;i++) {
        cin >> b[i] ;
    }
    for(int i = 0;i<n;i++) {
        cin >> c[i] ;
    }
    cout << Answer (n , k , a , b , c) << endl ;
    return 0;
}