#include<iostream> 
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int i=0, n = s.length();
    int ans = 0;
    while(i < n)
    {
        int c = 0;
        char e = s[i];
        while(i<n && s[i] == e) c++,i++;
        ans = max(ans,c);
    }
    cout << ans << endl;
return 0;
}