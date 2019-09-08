#include <stdio.h>
#include <string.h> 

int main(void) {
	// your code goes here
	int t, score[4],against[4],points[4],a,b,count,i,j,k;
	char team[4][15],vs[5],home[15],away[15];
	scanf("%d",&t);
	while(t--) { 
	for(i=0;i<4;i++)
	{ score[i]=0;
	  against[i]=0;
	  points[i]=0;
	  team[i][0]='\0';
	}
	count = 0; 
	for(i=0;i<12;i++)
	{
	scanf("%s %d %s %d %s",home,&a,vs,&b,away);
    for(j=0;j<count;j++)
     if(strcmp(home,team[j])==0)
      break;
    if(j==count) {
    strcpy(team[count],home);
    count++; }
    for(k=0;k<count;k++)
     if(strcmp(team[k],away)==0)
       break;
    if(k==count) { 
	strcpy(team[count],away);
	count++; } 
	score[j] += a;
	score[k] += b;
	against[j] += b;
	against[k] += a;
	if(a>b) points[j]+=3;
	else if(a==b)
    { points[j]++; points[k]++; }
    else points[k] += 3; 
	}
	for(i=0;i<4;i++)
	 {
	     score[i]=score[i]-against[i];
	//    printf("%d--%s--%d\n",points[i],team[i],score[i]);
	 }
	if((points[0]>points[1])||(points[0]==points[1]&&score[0]>score[1]))
	 { i=0; j=1; }
	else
	 { i=1; j=0; }
	if((points[2]>points[i])||(points[2]==points[i]&&score[2]>score[i]))
	 { j = i; i = 2; }
	else if((points[2]>points[j])||(points[2]==points[j]&&score[2]>score[j]))
	 { j = 2; }
	if((points[3]>points[i])||(points[3]==points[i]&&score[3]>score[i]))
	 { j=i; i=3; }
	else if((points[3]>points[j])||(points[3]==points[j]&&score[3]>score[j]))
	 { j = 3; } 
	printf("%s %s\n",team[i],team[j]);
	}
	return 0;
}

