/*
Judge: PKU
PROG: 2393
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int val[10001];

long long int N,S,C,pnt;

struct PRD
{
	long long 
	int c,y;
	PRD(){}
	PRD(int a,int b){c=a;y=b;}
	int price(){return c*y;}
	int value(int i){return c+S*(N-i-1);}
}week[10001];

bool cmp(int a,int b)
{
	return week[a].value(a)<week[b].value(b);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120204_2193.in","r",stdin);
	freopen("PKU_20120204_2193.out","w",stdout);
	#endif
	scanf("%I64d%I64d",&N,&S);
	C=pnt=0;
	for(int i=0;i<N;i++)
		{scanf("%d%d",&week[i].c,&week[i].y);val[i]=i;}
	sort(val,val+N,cmp);
//	for(int i=0;i<N;i++)	printf("%d %d\n",val[i]+1,week[val[i]].value(val[i]));
	for(int i=N-1;i>-1;i--)
	{
		while(val[pnt]>i)pnt++;
		C+=week[i].y*(week[val[pnt]].c+S*(i-val[pnt]));
	}
	printf("%I64d\n",C);
	return 0;
}
