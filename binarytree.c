#include <stdio.h>
int main() {
	int n, i;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	int arr[n+1];
	printf("Enter the values at the nodes:\n");
	for ( i=0; i<n; i++ ) {
		scanf("%d", &arr[i]);
	}
	printf("The elements are:\n");
	for ( i=0; i<n; i++ ) {
		printf("%d ",arr[i]);
	}
	int k=0;
	while(k==0) {
		printf("\nEnter any node (1-%d, 0 to exit): ",n);
		int node;
		scanf("%d", &node);
		if (node==0) {
			printf("Exiting...\n");
			break;
		}
		if (node<1 || node>n) {
			printf("Invalid node! Enter any valid node (1-%d): ",n);
			continue;
		}
		if (node == 1) {
			printf("The node is root node\n");
		} else {
			printf("The parent node is %d\n",node/2);
			printf("The value of the parent node is %d\n",arr[(node/2)-1]);
			printf("The value of the node is %d\n",arr[node-1]);
			int leftChildIndex = 2*node;
			int rightChildIndex = (2*node)+1;
			if (leftChildIndex > n) {
				printf("This node has no left child\n");
			} else {
				printf("The left child of the node is %d and value at left child node is %d\n",leftChildIndex,arr[leftChildIndex-1]);
			}
			if (rightChildIndex > n) {
				printf("This node has no right child\n");
			} else {
				printf("The right child of the node is %d and value at right child node is %d\n",rightChildIndex,arr[rightChildIndex-1]);
			}
		}
	}
	return 0;
}
	
	
