#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectionSort (int *elements, int gen, int start, int sortOrder) {
	int i,tmp,beginning;
	tmp=start;
	if(start<gen) {
		for(i=(start+1);i<gen;i++) {		
			if ((sortOrder==1 && elements[i]<elements[tmp]) || (sortOrder==2 && elements[i]>elements[tmp])) {
				tmp=i;
			}
		}
		beginning=elements[start];
		elements[start]=elements[tmp];
		elements[tmp]=beginning;
		SelectionSort (&elements[0],gen,start+1,sortOrder);
	}	
	return;  
}

void BubbleSort (int *elements, int gen, int start, int sortOrder) {
	int i,beginning;
	if(start<gen-1) {
		for (i = 0; i < gen-1-start; i++) {		
			if ((sortOrder==1 && elements[i+1]<elements[i]) || (sortOrder==2 && elements[i+1]>elements[i]) {
				beginning=elements[i];
				elements[i]=elements[i+1];
				elements[i+1]=beginning;
			}
		}
		BubbleSort (&elements[0],gen,start+1,sortOrder);
	}
	return;
}

int main(int argc, char *argv[]) {
	
	int gen,i,start,sortOrder,sortChoice;
	int *elements;
	FILE *unsortedElStr;
	FILE *sortedElStr;
	  
	unsortedElStr=fopen("unsorted_elements.txt","w+");
	sortedElStr=fopen("sorted_elements.txt","w+");
	  
	srand((unsigned)time(NULL));
	gen=4000;
	elements=(int *)malloc(gen*sizeof(int));
	  
	printf("Unsorted elements:\n\n");
	for(i=0;i<gen;i++) {
		elements[i]=rand();
		fprintf(unsortedElStr,"%d\n",elements[i]);
		printf("%d ",elements[i]);
	}
	  
	printf("\n\nFor SelectionSort enter 1, for BubbleSort enter 2: ");
	scanf("%d",&sortChoice);
	printf("\n\nFor ascending sort enter 1, for descending sort enter 2: ");
	scanf("%d",&sortOrder);
	  
	start=0;
	  
	if (sortChoice==1 && (sortOrder==1 || sortOrder==2)) {
		SelectionSort (&elements[0],gen,start,sortOrder);
	}
	else if (sortChoice==2 && (sortOrder==1 || sortOrder==2))  {
		BubbleSort (&elements[0],gen,start,sortOrder);
	}
	else {
		printf("\n\nAvailable sort choices are 1 for SelectionSort or 2 for BubbleSort");
		printf("\nAvailable sort order choices are 1 for ascending or 2 for descending\n\n");
		fclose(unsortedElStr);
		fclose(sortedElStr);
		free(elements);
		return 0;
	}
	 
	printf("\n\nSorted elements:\n\n");
		 
	for(i=0;i<gen;i++) {
		fprintf(sortedElStr,"%d\n",elements[i]);
		printf("%d ",elements[i]);
	}
		  
	fclose(unsortedElStr);
	fclose(sortedElStr);
	free(elements);
	return 0; 
}
