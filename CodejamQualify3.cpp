#include <stdio.h>
#include <iostream>
using namespace std;
#include<string>
int x , y;
string s;

int calc(string s, int x, int y){
    int a = 0;
    int n = s.length();
    int xc = 0;
    int yc = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == 'C')
        {
            if(s[i+1] == 'J')
                xc++;
        }
        if(s[i] == 'J'){
            if(s[i+1] == 'C')
                yc++;
        }
    }
    a = (xc*x) + (yc*y);
    return a;
}


void solve(){
    cin >> x >> y;
    cin >> s;
    int n = s.length();
    for(int i = 0;i < n; i++){
        if(s[i] == '?')
        {
            if(i == 0)
            {
                if(s[1] == 'C' || s[1] == 'J')
                    s[0] = s[1];
                else if(s[1] == '?')
                {
                    int k = 1;
                    int c = 1;
                    while(c > 0)
                    {
                        k++;
                        if(s[k] == 'C' || s[k] == 'J'){
                            c = c*0;
                            s[0] = s[k];
                        }
                        if(c>0 && k == n-1){
                            c = c*0;
                            s[0] == 'C';
                        }
                    }
                }
            }
            else if(i == n-1)
            {
                s[i] = s[i-1];
            }
            else
            {
                s[i] = s[i-1];
            }
        }
    }
    int ans = calc(s,x,y);
    cout << ans << endl;
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