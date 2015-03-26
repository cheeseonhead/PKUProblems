/*
Judge: PKU
PROG: 1737
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ONLINE_JUDGE
using namespace std;

int f(int n);
int g(int n);
int f_(int n);
int C(int top, int down);

int ary[50],r,N;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120313_1737.in","r",stdin);
	freopen("PKU_20120313_1737.out","w",stdout);
	#endif
	
	while(~scanf("%d",&N))
	{
		printf("%d\n",f(N));
	}
	
	return 0;
}

int g(int n)
{
	return 1<<(n*(n-1)/2);
}

int f(int n)
{
	if(ary[n])return ary[n];
	if(n<3)return 1;
	return ary[n] = g(n)-f_(n);
}

int f_(int n)
{
	int r=0;
	for(int k=1;k<n;k++)
	{
		r+=f(k)*C(n-1,k-1)*g(n-k);
	}
	return r;
}

int C(int top, int down)
{
	int top2 = top,down2 = down,x=1;
	while(top2)
	{
		x*=top2;top2--;
	}
	while(down2)
	{
		x/=down2;down2--;
	}
	while(top-down)
	{
		x/=top-down;top--;
	}
	return x;
}
