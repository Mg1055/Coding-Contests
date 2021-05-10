#include<vector>
#include<algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int n;
vector<int>v;

void solve(){
    int x;
    int j;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n-1; i++) 
    {
        auto min = min_element(v.begin()+i, v.end());
        j = min - v.begin();
        reverse(v.begin()+i, min+1);
        ans = ans + j - i + 1 ;
    }
    cout << ans << endl;
    v.clear();
}


int main ()
{
    int t;
    cin >> t;
    int i = 1;
    while(t--){
        cout << "Case #" <<  i << ": ";
        solve();
        ++i;
    }
    return 0;
}