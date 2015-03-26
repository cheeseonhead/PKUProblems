/*
Judge: PKU
PROG: 1338
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,pnt,cons[] = {2,3,5},a;
unsigned long long int PRQ[100000],ans[1500];

void push(unsigned long long int* q,int point,long long int num)
{
//	printf("\t\tpush %d\n",num);
	q[point] = num;
//	printf("\t\t\tq[%d] = %d\n",point,q[point]);
	while(q[point]<q[point/2])
	{
		int temp = q[point];
		q[point] = q[point/2];
		q[point/2] = temp;
		point/=2;
	}
}

void pop(unsigned long long int* q,int point)
{
//	printf("\t\tpop q[0] = %d\n",q[0]);
	q[0] = q[--point];
	int tp = 0,min = tp;
	while(1)
	{
		if(tp*2+1<point && q[min]>q[tp*2+1])min = tp*2+1;
		if(tp*2+2<point && q[min]>q[tp*2+2])min = tp*2+2; 
		if(min == tp)break;
		int temp = q[tp];
		q[tp] = q[min];
		q[min] = temp;
		tp = min;
	}
}

void make_PRQ()
{
	push(PRQ,pnt++,1);
	while(a<1500)
	{
		int t = PRQ[0];
//		printf("PRQ[0] = %d\n",PRQ[0]);
//		printf("\tans[%d] = %d\n",a-1,ans[a-1]);
		pop(PRQ,pnt--);
		if(a>0 && t == ans[a-1])continue;
		ans[a++] = t;
//		printf("\tsigned ans[%d] = %d\n",a-1,ans[a-1]);
		//printf("\tpush ans[%d] = %d\n",a-1,ans[a-1]);
		for(int i=0;i<3;i++)push(PRQ,pnt++,t*cons[i]);
	}
}

int main()
{
	freopen("PKU_20111223_1338.in","r",stdin);
	freopen("PKU_20111223_1338.out","w",stdout);
	make_PRQ();
	while(~scanf("%d",&n) && n)
	{
		printf("%llu\n",ans[n-1]);
	}
	return 0;
}
