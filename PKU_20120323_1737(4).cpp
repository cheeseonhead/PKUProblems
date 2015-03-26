/*
Judge: PKU
PROG: 1737
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXD 700
#define MAXN 51
using namespace std;

int N;

struct BIGN{
	int d[MAXD];
	BIGN(){memset(d,0,sizeof(d));len = 1;}
	BIGN(int x)
	{
		memset(d,0,sizeof(d));
		for(int i=0;x>0;i++)
		{
			d[i] = x%10;
			x/=10;
		}
	}
	
	BIGN operator+ (BIGN B)
	{
		BIGN A = *this,C;
		int len;
		for(len=MAXD-1;!A.d[len]&&!B.d[i];len--)
		for(int i=0;i<=len;i++)
			C.d[i] = A.d[i]+B.d[i];
		
		for(int i=0;i<=len+1;i++)
		{
			C.d[i+1]+= C.d[i]/10;
			C.d[i]%=10;
		}
		return C;
	}
	
	BIGN operator* (BIGN B)
	{
		BIGN A = *this,C;
		for(int i=0;i<A.len;i++)
			for(int j=0;j<B.len;j++)
			{
				int temp = C.d[i+j];
				C.d[i+j]+=A.d[i]*B.d[j];
			}
		
		for(int i=0;i<=A.len+B.len;i++)
		{
			C.d[i+1]+=C.d[i]/10;
			C.d[i]%=10;
		}
		
		for(int i=MAXD-1;i>=0;i--)
			if(C.d[i]){C.len=i+1;break;}
		
		return C;
	}
	
	BIGN operator/ (BIGN B)
	{
		BIGN A=*this,C;
		bool op=0;
		C.len = A.len;
		for(int i=A.len-1;i>=0;i--)
		{
			for(int j=9;j>=0;j--)
			{
				C.d[i] = j;
				if(A>=B*C)
				{
					op=1;
					break;
				}
			}
			if(!C.d[i]&&!op){C.len--;op=1;}
		}
		return C;
	}
	
	bool operator>=(BIGN B)
	{
		if(this->len!=B.len)return this->len>B.len;
		for(int i=MAXD-1;i>=0;i--)
			if(this->d[i]!=B.d[i])return this->d[i]>B.d[i];
		return 1;
	}
	
	bool val()
	{
		for(int i=0;i<len;i++)
			if(d[i])return 1;
		return 0;
	}
	
	void print()
	{
		int i;
		for(i=len-1;i>=0;i--)
		{
			putchar(d[i]+'0');
		}
		puts("");
	}
	
}g[MAXN],ans,c[51][51];bool c_cal[51][51];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("PKU_20120323_1737.in","r",stdin);
	freopen("PKU_20120323_1737.out","w",stdout);
	#endif
	
	for(int i=1;i<=50;i++)
	{
		BIGN u(1);
		for(int j=1;j<=i;j++)
		{
			u = u*BIGN(i-j+1);
			u = u/BIGN(j);
			c[i][j] = u;
			c_cal[i][j] = true;
			printf("c(%d,%d)=",i,j);c[i][j].print();
		}
	}
	

/*	BIGN a(700000),u(2);
	a = a/u;
	a.print();
*/

/*	while(~scanf("%d",&N))
	{
	}
*/
	return 0;
}
