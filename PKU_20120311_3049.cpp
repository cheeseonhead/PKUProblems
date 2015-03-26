/*
Judge: PKU
PROG: 3049
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int pnt[20],L,n,c[27];

void print()
{
	for(int i=0;i<L;i++)
	{
		putchar(c[pnt[i]]);
	}
	puts("");
	return;
}

void mat(int x)
{
	if(x==L-1)print();
	int x2 = x;
	while(x2<=n-L+x)
	{
		mat(x+1);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120311_3049.in","r",stdin);
	freopen("PKU_20120311_3049.out","w",stdout);
	#endif
	
	while(~scanf("%d%d\n",&L,&n))
	{
		for(int i=0;i<n;i++)
		{
			pnt[i] = i;
			char ch = getchar();
			c[i] = ch;
			getchar();
		}
		mat(0);
	}
	
	return 0;
}
