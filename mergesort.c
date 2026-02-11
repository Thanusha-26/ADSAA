#include<stdio.h>
void merge(int[],int,int,int);
void merge_sort(int[],int,int);
void merge(int a[],int left,int mid,int right)
{
	int temp[right-left+1];
	int i,j,k=0;
	i=left;
	j=mid+1;
	while(i<=mid && j<=right)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;
		}
		else
		{
			temp[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		i++;k++;
	}
	while (j<=right)
	{
		temp[k]=a[j];
		j++;k++;
	}
	for(i=left,k=0;i<=right;i++,k++)
	{
		a[i]=temp[k];
	}
}
void merge_sort(int a[],int left,int right)
{
	int mid;
	if(left<right)
	{
    	mid=(left+right)/2;
    	merge_sort(a,left,mid);
    	merge_sort(a,mid+1,right);
    	merge(a,left,mid,right);
	}
}
int main()
{
	int arr[25],n,i;
	printf("Enter the n value:");
	scanf("%d",&n);
	printf("Enter the %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	printf("The sorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
