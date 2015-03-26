/*
Judge: PKU
PROG: 3050
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int cheb[5][5];

struct Seq
{
	int s[6];
	bool operator <(const Seq &B)const{return memcmp(this,&B,sizeof(s))==1;}
	void print(){for(int i=0;i<5;i++)printf("%d ",s[i]);puts("");}
}use;

set <Seq> S;
set <Seq> ::iterator it;
const int dir[4][2]={0,1,1,0,-1,0,0,-1};

void print_board(int n,int x,int y)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<=n;j++)printf("\t");
		for(int j=0;j<5;j++)
			if(i==x&&j==y)printf("* ");
			else printf("%d ",cheb[i][j]);
		puts("");
	}
}

void dfs(int n,int x,int y)
{
	if(n==5){S.insert(use);return;}
	for(int i=0;i<4;i++)
	{
		int u,v;
		u = x+dir[i][0];
		v = y+dir[i][1];
		if(u<0||v<0||u>=5||v>=5)continue;
		//for(int j=0;j<=n;j++)printf("\t");
		//printf("u %d v %d\n",u,v);
		//print_board(n,u,v);
		use.s[n+1]=cheb[u][v];
		dfs(n+1,u,v);
	}
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120202_3050.in","r",stdin);
	freopen("PKU_20120202_3050.out","w",stdout);
	#endif
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)scanf("%d",cheb[i]+j);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			use.s[0] = cheb[i][j];
			//printf("u %d v %d\n",i,j);
			//print_board(-1,i,j);
			dfs(0,i,j);
		}
	for(it=S.end(),it--;;it--)
	{
		for(int i=0;i<6;i++)
			printf("[%d]",it->s[i]);
		puts("");
		//printf("%d%d%d%d%d%d\n",*it);
		if(it==S.begin())break;
	}
	printf("%d\n",S.size());
	return 0;
}
