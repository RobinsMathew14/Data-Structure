#include <stdio.h>
void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
void main() {
	int i, a[100], n;
	printf("Enter the array size: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");
	for ( i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	mergesort(a, 0, (n-1));
	printf("Sorted array:\n");
	for ( i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void mergesort(int a[], int low, int high) {
	if (low<high) {
		int mid = (low+high)/2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}
void merge(int a[], int low, int mid, int high) {
	int i = low;
	int j = (mid+1);
	int k=0;
	int temp[100];
	while( (i<=mid) && (j<=high)) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}
	while (i<=mid) {
		temp[k++] = a[i++];
	}
	while (j<=high) {
		temp[k++] = a[j++];
	}
	for ( i=low,k=0; i<=high; i++,k++) {
		a[i] = temp[k];
	}
}
	

	
	
	
	
	
	
	
	
	
	
	
	
