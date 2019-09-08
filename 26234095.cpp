#include<iostream>
#define ll long long
using namespace std;
int main()
{
    ll n,k,t,a;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
            a = n/k;
            if(a%k == 0)
            {
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
    }
}
