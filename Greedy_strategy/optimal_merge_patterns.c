/* This optimal merge patterns problems are abstraction
 of real world records merging . Here we will be given some files 
 and we have to merge them with minimum cost . The input is
 number of files in each record and the cost of merging these records
 is given as the sum of number of files present in both
 the records . The greedy paradigm is used here and the records with 
 minimum number of files are merged as first as possible to
 reduce the cost of merging */






#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int * find_two_minimum(int number_of_records, int * records){
	int * minimum_two = (int *)malloc(sizeof(int) * 2);
	minimum_two[0] = INT_MAX;
	minimum_two[1] = INT_MAX;
	int i;
	for (i = 0; i < number_of_records; i++){
		if(records[i] < minimum_two[0]){
			minimum_two[1] = minimum_two[0];
			minimum_two[0] = records[i];
		}
		else if(records[i] < minimum_two[1]){
			minimum_two[1] = records[i];
		}
	}
	
	return minimum_two;
}

int * replace_array_items(int number_of_records, int * smallest, int * records){
	int i;
	int min1_changed = 0;
	int min2_changed = 0;
	for (i = 0; i < number_of_records ; i++){
		if ((smallest[0] == records[i])&& (min1_changed == 0)){
			records[i] = smallest[0] + smallest[1];
			min1_changed = 1;
		}
		else if((smallest[1] == records[i]) && (min2_changed == 0)){
			records[i] = INT_MAX;
			min2_changed = 1;
		}
	}
	return records;
}



int min_cost_merge(int number_of_records,int * records){
	int cost = 0;
	int count;
	int * two_smallest_numbers = (int *)malloc(sizeof(int) * 2);
	int i;
	for (count = 1; count < number_of_records ; count ++){
		two_smallest_numbers = find_two_minimum(number_of_records, records);
		cost = two_smallest_numbers[0] + two_smallest_numbers[1];
		records = replace_array_items(number_of_records, two_smallest_numbers, records);
	}
	return cost;
}

		
int main(int argv, char * argc[]){
	int number_of_records = argv - 1;
	int * records = (int *) malloc(sizeof(int) * number_of_records);
	int i;
	for (i = 0 ; i < number_of_records; i ++){
		records[i] = atoi(argc[i + 1]);
	}
	printf("The minimum cost merging of records is %d", min_cost_merge(number_of_records, records));
	return 0;
}
