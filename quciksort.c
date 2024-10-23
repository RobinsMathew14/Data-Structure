#include <stdio.h>
int partition(int a[], int low, int high);
void quicksort(int a[], int low, int high);
void main() {
	int i, a[100], n;
	printf("Enter the array size: ");
	scanf("%d", &n);
	printf("Enter the array elements:\n");
	for ( i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, (n-1));
	printf("Sorted array is:\n");
	for ( i=0; i<n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
void quicksort(int a[], int low, int high) {
	if (low<high) {
		int j = partition(a, low, high);
		quicksort(a, low, (j-1));
		quicksort(a, (j+1), high);
	}
}
int partition(int a[], int low, int high) {
	int temp; 
	int i=low;
	int j=high;
	int pivot=a[low];
	
	while(i<j) {
		while((a[i] <= pivot) && (i<high)) {
			i++;
		}
		while( a[j]>pivot ) {
			j--;
		}
		if (i<j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;	
}
	
	
	

		
