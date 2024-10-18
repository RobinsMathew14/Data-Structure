#include <stdio.h>
int main() {
	int arr[10], n, i, j, temp;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array:\n");
	for ( i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("The array before sorting:\n");
	for ( i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	i = 1;
	while (i<n) {
		temp = arr[i];
		j = i-1;
		while (j>=0 && temp<arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		i++;
	}
	printf("\nThe sorted array is: \n");
	for ( i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
		
	
