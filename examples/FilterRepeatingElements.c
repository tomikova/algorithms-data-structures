#include <stdio.h>
#include <time.h>
#include <malloc.h>

int *filterElements(int *originalElements, int *counterArray, int number, int *m, int upperLimit, int lowerLimit) {
	int i, j;
	int *filteredElements;
	for (i=0; i<number; i++) {
		counterArray[originalElements[i]-lowerLimit]++;
	}
	for (i=0; i<(upperLimit-lowerLimit+1); i++) {
		if (counterArray[i]>1) {
			*m+=1;
		}
	}
	if (*m==0) {
		return NULL;
	}
	else {
		filteredElements = (int *)malloc(*m*sizeof(int));
		for (i=0, j=0; i<number; i++) {
			if(counterArray[originalElements[i]-lowerLimit]>1) {
				counterArray[originalElements[i]-lowerLimit]=0;
				filteredElements[j]=originalElements[i];
				j++;
			}
		}
	return filteredElements;
	}
}

int main () {
	int *originalElements, *counterArray, *filteredElements;
	int number, lowerLimit, upperLimit, i, m=0;
	printf ("Enter number of elements of 1-d array:\n");
	scanf ("%d", &number);
	originalElements = (int *)malloc(number*sizeof(int));
	printf ("The lower limit of the interval: ");
	scanf ("%d", &lowerLimit);
	printf ("The upper limit of the interval: ");
	scanf ("%d", &upperLimit);
	srand((unsigned) time(NULL));
	printf ("\nOriginal array\n\n");
	for (i=0; i<number; i++) {
		originalElements[i]=rand()%(upperLimit+1-lowerLimit)+lowerLimit;
		printf ("%d ", originalElements[i]);
	}
	printf ("\n");
	counterArray = (int *)malloc((upperLimit-lowerLimit+1)*sizeof(int));
	for (i=0; i<(upperLimit-lowerLimit+1); i++) {
		counterArray[i]=0;
	}
	filteredElements = filterElements(originalElements, counterArray, number, &m, upperLimit, lowerLimit);
	if (filteredElements==NULL) {
		printf ("\nThere are no repeating elements\n");
	}
	else {
		printf ("\nNumber of repeating elements: %d\n", m);
		printf ("\nNew array\n\n");
		for (i=0; i<m; i++) {
			printf ("%d ", filteredElements[i]);
		}
	}
	printf ("\n\n");
	free(originalElements);
	free(filteredElements);
	free(counterArray);
	return 0;
}
