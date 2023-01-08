#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n;
void dfs(int v)    //which node to visit
{
	int i;
    reach[v]=1;
	for(i=1;i<n;i++)
	{
		if(a[v][i]==1 && !reach[i])
		{
			printf("\n %d->%d",v,i);
			dfs(i);
		}
	}
	
}
int main()
{	
	int i,j,count;
	printf("\n Enter no of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		reach[i]=0;
		for(j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	printf("enter the adjancancy matrix:\t");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d ",&a[i][j]);
		}
	}
	dfs(1);
	
	for(i=1;i<=n;i++)
	{
		if(reach[i])
		{
			count++;
		}
	}
	if(count==n)
	{
		printf("\ngraph is connected");
	}
	else{
		printf("\ngraph is not connected");
	}
}
