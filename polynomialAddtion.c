#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coeff;
	int expo;
	struct Node* next;
};
struct Node* createNode(int coeff, int expo) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->coeff = coeff;
	newNode->expo = expo;
	newNode->next = NULL;
	return newNode;
}
void insertNode(struct Node** poly, int coeff, int expo) {
	struct Node* newNode = createNode(coeff, expo);
	if (*poly == NULL){ 
		*poly = newNode;
	} else {
		struct Node* temp = *poly;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
void displayPolynomial(struct Node* poly) {
	while(poly != NULL) {
		printf("%dx^%d",poly->coeff,poly->expo);
		if (poly->next != NULL && poly->next->coeff >= 0) {
			printf(" + ");
		}
		poly = poly->next;
	}
	printf("\n");
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
	struct Node* result = NULL;
	while (poly1 != NULL && poly2 != NULL) {
		if (poly1->expo > poly2->expo) {
			insertNode(&result, poly1->coeff, poly1->expo);
			poly1 = poly1->next;
		} else if (poly1->expo < poly2->expo) {
			insertNode(&result, poly2->coeff, poly2->expo);
			poly2 = poly2->next;
		} else {
			int sumCoeff = poly1->coeff + poly2->coeff;
			if (sumCoeff != 0) {
				insertNode(&result, sumCoeff, poly1->expo);
			}
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
	}
	while (poly1 != NULL) {
		insertNode(&result, poly1->coeff, poly1->expo);
		poly1 = poly1->next;
	}
	while (poly2 != NULL) {
		insertNode(&result, poly2->coeff, poly2->expo);
		poly2 = poly2->next;
	}
	return result;
}
int main() {
	struct Node* poly1 = NULL;
	struct Node* poly2 = NULL;
	struct Node* sum = NULL;
	int n, coeff, expo;
	printf("Enter the number of terms in the first polynomial: ");
	scanf("%d", &n);
	printf("Enter the terms in the first polynomial in the format (coefficient exponent):\n");
	for (int i=0; i<n; i++) {
		scanf("%d %d", &coeff, &expo);
		insertNode(&poly1, coeff, expo);
	}
	printf("Enter the number of terms in the second polynomial: ");
	scanf("%d", &n);
	printf("Enter the terms in the second polynomial in the format (coefficient exponent):\n");
	for (int i=0; i<n; i++) {
		scanf("%d %d", &coeff, &expo);
		insertNode(&poly2, coeff, expo);
	}
	printf("\nFirst polynomial: ");
	displayPolynomial(poly1);
	printf("\nSecond polynomial: ");
	displayPolynomial(poly2);
	sum = addPolynomials(poly1, poly2);
	printf("\nThe sum of the two polynomials: ");
	displayPolynomial(sum);
	return 0;
}
	
	
	
	
			
			
			
			
			
			
		
