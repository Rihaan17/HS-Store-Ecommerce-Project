#include<iostream>
int main()
{
register long int i;
long int j = 1;
long int l[100001];
l[0] = 1;
for(i = 1;i<100001;i++)
{
j *=2;
j %=1000000007;
l[i] = j;
}
int t;
scanf("%d",&t);
while(t--)
{
long int n;
scanf("%ld",&n);
long int A[n+1];
for (i = 0;i < n+1;i++)
scanf("%ld",&A[i]);

long long int a=A[0];
long long int b = 0;
for(i = 1;i<n+1;i++)
{
b +=(((A[i]*a)%1000000007)*l[n-i+1])%1000000007;
a +=A[i]*l[i-1];
a %=1000000007;
}
b %=1000000007;
printf("%lld\n",b);
}
return 0;
}
