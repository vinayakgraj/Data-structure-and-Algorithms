#include <stdio.h>
#include <stdlib.h>
void QuickSort(int *,int, int);
int partition(int *,int,int);
void swap(int *,int *);

void main()
{
	int a[20]={0};
	int i ;
	int n	;
	n= sizeof(a)/sizeof(a[0]); 
	printf("enter the array elements");
	for(i= 0; i < n ;i++)
	{
		scanf("%d",&a[i]);
	}
	
	QuickSort(a,0,n);
	
	for(i = 0;i < n;i++) 
		{
			printf("%d ",a[i]);
		}

}

void QuickSort(int *A,int n, int m)
{
	if(n<m)
	{
		int pindex = partition(A ,n ,m );
		QuickSort(A ,n ,pindex-1 );
		QuickSort(A ,pindex+1 ,m );
	}	

}

int partition(int *A,int n,int m)
{
	int Pindex= n;
	int pivot = A[m];
	for(int i=n;i<m;i++)
	{
		if(A[i]<=pivot)
		{
			swap(&A[i],&A[Pindex]);
			Pindex++;
		}

	}
	swap(&A[Pindex],&A[m]);
	return Pindex;
}

void swap(int *a,int *b)
   {
   int temp = *a;
   *a = *b;
   *b = temp;
   } 