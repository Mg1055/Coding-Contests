#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>      // std::setprecision
using namespace std;
typedef long long int ll;
int main() {
    int t;cin>>t;
    for (int i = 1; i <= t; ++i ){
        int n,k;cin>>n>>k;
        
        int p[n];for (int i = 0; i < n; ++i)cin>>p[i];
        
        if (n == 1){
            double ans1 = k - 1;
            cout << fixed << setprecision(7) << "Case #"<<i<<": "<<ans1/k<<"\n";;
            continue;
        }
        sort(p,p+n);
        int d[n-1];
        for (int i = 0 ; i < n-1; ++i)d[i]= p[i+1] - p[i];
        
        sort(d,d+n-1);
        
        double ans[4];for (int i = 0 ; i<4;++i)ans[i] = 0.0;
        
        if (n>=2)ans[0] = d[n-2]/2;if (n>=3)ans[1] = d[n-3]/2;
        ans[2] = p[0] - 1;ans[3] = k - p[n-1];
        
        sort(ans,ans+4);    
        
        double a1 = (ans[3]+ans[2])/k,a2 = (d[n-2]-1); a2 = a2/k;
        
        double a3 = max(a1,a2);
        
        
        
        
        
        cout << fixed << setprecision(7) <<"Case #"<<i<<": "<<a3<<"\n";;
        
        
    }
    
    
}