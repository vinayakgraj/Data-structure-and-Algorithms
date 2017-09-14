#include <stdio.h>
#include <stdlib.h>
#include <math.h>


	void Merge(int *,int *,int,int *,int); 
	void MergeSort(int *,int);



void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {

	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = ceil(n/2);  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}

void main()
{
	int a[20]={0};
	int i ;
	//int numberOfElements ;
	int n	;
	n= sizeof(a)/sizeof(a[0]); 
	//printf("enter the array size");
	//scanf("%d",&n);
	printf("enter the array elements");
	for(i= 0; i < n ;i++)
	{
		scanf("%d",&a[i]);
	}
	
	MergeSort(a,n);
	
	for(i = 0;i < n;i++) 
		{
			printf("%d ",a[i]);
		}

}