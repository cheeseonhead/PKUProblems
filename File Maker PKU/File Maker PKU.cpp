#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char sec[100],name[100],date[100],fn[100],oj[100],dup[10];
	int cnt=0;
	/*puts("Welcome to file maker");
	puts("Please enter the Online Judge");
	gets(oj);*/
	sprintf(oj,"PKU");
	puts("Please enter the problem number");
	gets(name);
	puts("If it's a duplicate, enter duplicate number.\nElse enter '/'");
	gets(dup);
	puts("Please enter the date as 20110101");
	gets(date);
	sprintf(fn,"%s_%s_%s.in",oj,date,name);
	fclose(fopen(fn,"a"));
	if(dup[0]=='/'){sprintf(fn,"%s_%s_%s.cpp",oj,date,name);}
	else {sprintf(fn,"%s_%s_%s(%s).cpp",oj,date,name,dup);}
	fclose(fopen(fn,"a"));
	freopen("file maker PKU.txt","r",stdin);
	freopen(fn,"w",stdout);
	while(gets(sec))
	{
		if(strchr(sec,'%')!=NULL)
		{
			if(cnt==0)sprintf(fn,sec,oj);
			if(cnt==1)sprintf(fn,sec,name);
			if(cnt==2){sprintf(fn,sec,oj,date,name);cnt--;}
			cnt++;
		}
		else sprintf(fn,sec);
		puts(fn);
	}
} 
