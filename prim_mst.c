#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
void c_p_c()
{
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void solve_prims(int src_node,int n,int arr[n][n])
{


	bool visited[n];
	for(int i=0;i<n;i++)visited[i]=false;
	visited[src_node]=true;
	for(int i=0;i<n-1;i++)
	{
		int parent;
		int child;
		int min=INT_MAX;
		//this is the loop which will keep track of no of iters counter loop
		for (int j=0;j<n;j++)
		{
			//this loop is for visited array cntr
			if(visited[j]==true)
			{
				//now iterate over the adjacents and pick minimum
				for(int k=0;k<n;k++)
				{
					if(arr[j][k]<=min && arr[j][k]!=0 && arr[j][k]!=-1 && visited[k]==false)
					{
						min=arr[j][k];
						parent=j;
						child=k;
					}
				}
			}
		}
		// printf("parent %d chid %d weight %d\n",parent,child,min);
		arr[parent][child]=-1;
		arr[child][parent]=-1;
		visited[child]=true;
		visited[parent]=true;
	}


}
int main()
{

	c_p_c();
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int clone[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
			clone[i][j]=arr[i][j];
			if(i>j)
			{
				if (arr[i][j]!=arr[j][i])
				{
					printf("Weight of the edge %d - %d must be same as edge %d - %d",i+1,j+1,j+1,i+1);
					exit(0);
				}
			}
			else if(i==j&& arr[i][j]!=0)
			{
				printf("Weight of the edge %d - %d must be 0",i+1,i+1);
				exit(0);
			}
			else if(arr[i][j]<0)
			{
				printf("Weight of the edge %d - %d can not be negative",i+1,j+1);
				exit(0);
			}
		}
	}
	int src_node;
	scanf("%d",&src_node);
	solve_prims(src_node-1,n,arr);
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==-1 && i+1!=src_node && flag==false){
				arr[j][i]=0;
				printf("%d-%d\t%d\n",i+1,j+1,clone[i][j]);
				flag=true;	
			}
			
		}
	}
}
