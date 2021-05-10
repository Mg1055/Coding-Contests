#include<vector>
#include<algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;


int n,c;
vector<int>v;
int checkcost(vector<int>v, int n)
{
    int j, cost = 0;
    for(int i = 0; i < n-1; i++) 
    {
        auto min = min_element(v.begin()+i, v.end());
        j = min - v.begin();
        reverse(v.begin()+i, min+1);
        cost = cost + j - i + 1 ;
    }
    return cost;
}

void printvec(vector<int>v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

void solve(){
    cin >> n >> c;
    int counter = 1;
    for(int i = n; i > 0; i--){
        v.push_back(i);
    }
    do {
        if(checkcost(v,n) == c){
            counter = counter*0;
            break;
        }
    } while (std::prev_permutation(v.begin(), v.end()));
    if(counter == 1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        printvec(v);
    }
    v.clear();
    cout << endl;
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