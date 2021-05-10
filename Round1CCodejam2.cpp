#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;
int countDigit(ll n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}


int f(ll y){
    vector<int> v;
    while (y){
        v.push_back(y%10);
        y = y/10;
    }
    reverse(v.begin(), v.end());
    int sz = v.size()/2;
    for (int i = 1; i <=sz; ++i){
        ll num = 0;
        for (int j = 0;j<i;++j){
            num = 10*num+v[j];
        }
        int j = i;
        if ((countDigit(num+v.size()/i) == i) && (v.size()%i)) continue;
        while (j<v.size()){
            num++;
            y = num;int c = countDigit(num),c1=c;
            while (y){
                if (j+c-1 >= v.size() || v[j+c - 1] != (y%10)) goto sos;
                y = y/10;
                c--;
            }
            j += c1;
        }
        return 1;
        sos:{}
    }
    return 0;
}
int main() {
    int ans[1000001];
    ans[1000000] = 1234567;
    for (int i = 999999; i>=1; --i){
        if (f(i+1)) ans[i] = i+1;
        else ans[i] = ans[i+1];
    }
    int t;cin>>t;
    for (int i = 1; i<=t; ++i){
        int y;cin>>y;
        cout<<"Case #"<<i<<": "<<ans[y]<<"\n";
    }
}