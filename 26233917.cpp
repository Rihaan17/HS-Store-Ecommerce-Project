#include <stdio.h>
short prime[]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1};
int hash[98765432]={0};
int power[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int t1,i,A[9],temp[9],queue[362880],rear,front,level,ptr;

void swap(int a,int b){
    
    int N=t1;
    int diff=temp[b]-temp[a];
    N= N+diff*power[8-a]-diff*power[8-b];
    if(hash[N/10]==0)
    {
    queue[rear++]=N;
	hash[N/10]=level;
	}
	
    }

int main(void) {
	t1=123456789;
	
    hash[t1/10]=1;
    
	rear=ptr=1;
    queue[0]=t1;
    front=1;
    level=2;
    
    do{	
    	
    	int N=t1;
 		for(i=8;i>=0;i--,N/=10){
			temp[i]=N%10;
		}
		if(prime[temp[0]+temp[1]])
 			{swap(0,1);}
 		if(prime[temp[1]+temp[2]])
 			{swap(1,2);}
 		if(prime[temp[3]+temp[4]])
 			{swap(3,4);}
 		if(prime[temp[4]+temp[5]])
 			{swap(4,5);}
 		if(prime[temp[6]+temp[7]])
 			{swap(6,7);}
 		if(prime[temp[7]+temp[8]])
 			{swap(7,8);}
 		if(prime[temp[0]+temp[3]])
 			{swap(0,3);}
 		if(prime[temp[1]+temp[4]])
 			{swap(1,4);}
 		if(prime[temp[2]+temp[5]])
 			{swap(2,5);}
 		if(prime[temp[3]+temp[6]])
 			{swap(3,6);}
 		if(prime[temp[4]+temp[7]])
 			{swap(4,7);}
 		if(prime[temp[5]+temp[8]])
 			{swap(5,8);}
 		
		if(front==0||front==ptr){
 			ptr=rear;
 			level++;
		}
		t1=queue[front++];
	}while(rear>=front);
		
		
	int t;
	scanf("%d",&t);
	int nn=0;
	for(int y =0;y<t;y++){
	    for(int j=0;j<9;j++){
	        scanf("%d",&A[j]);
	        nn=nn*10+A[j];
			
	    }
	    
	    
    
    if(!hash[nn/10])
	printf("%d\n",-1);
	else
	printf("%d\n",hash[nn/10]-1);
	nn=0;
}
	return 0;
}
