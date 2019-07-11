/* In fractional Knapsack we wil be given a knapsack
 of certain capacity and items with their respective
 profits and weights . The aim here is to maximize 
 the profit by filling the items into knapsssack .
 We can even add fractions of items into knapsack 
 from which its name comes . So, The greedy strategy
 followed here is to consider maximum profits/weights
 ratio element as first as possible to get mximum profit*/




#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMBER_OF_ELEMENTS 3
#define KNAPSACK_CAPACITY 20



typedef struct pairs{
	float value;
	float reference_value;
}pair;



pair * sort_pair(pair * values){
	int i;
	int j;
	pair tmp;
	for (i = 0; i <NUMBER_OF_ELEMENTS - 1; i ++){
		for (j = 0; j < NUMBER_OF_ELEMENTS - i - 1; j ++){
			if (values[j].reference_value < values[j + 1].reference_value) {
				tmp       = values[j];
        			values[j]   = values[j + 1];
        			values[j + 1] = tmp;
			}
		}
	}
	return values;
}



float * sort_using_other_array(float * array,float * reference_array){
	int i ;
	pair * tmp = (pair *)malloc(sizeof(pair) * NUMBER_OF_ELEMENTS);
	for ( i = 0; i < NUMBER_OF_ELEMENTS; i ++){
		tmp[i].value = array[i] ;
		tmp[i].reference_value =  reference_array[i] ; 
	}
	
	tmp = sort_pair(tmp);
	for ( i = 0; i < NUMBER_OF_ELEMENTS; i ++){
               array[i] = tmp[i].value;
        }
	return array;

}




float compute_profit(float * fraction_included, float * profits_in_sorted_order_of_profits_by_weights_ratio){

	int i = 0;
	float max_profit = 0;
	for ( i = 0; i < NUMBER_OF_ELEMENTS; i ++){
		max_profit += (fraction_included[i] * profits_in_sorted_order_of_profits_by_weights_ratio[i] );
	}
	return max_profit;
}




float * add_items_to_knapsack(float * weights){

	float * fraction_included = (float *)calloc(sizeof(float), NUMBER_OF_ELEMENTS);
	float remaining_capacity = KNAPSACK_CAPACITY;
	int i ;
	for ( i = 0; i < NUMBER_OF_ELEMENTS; i ++){
		if (weights[i] > remaining_capacity){
			break;
		}
		fraction_included[i] = 1;
		remaining_capacity -= weights[i] ;
	}
	if ( i < NUMBER_OF_ELEMENTS){
		fraction_included[i] = remaining_capacity / weights[i] ;
	}

	return fraction_included;
}





float find_maximum_profit(float * weights, float * profits){
	
	
	float max_profit = 0;
	float * fraction_included = (float *)calloc(sizeof(float), NUMBER_OF_ELEMENTS);
	float * weights_in_sorted_order_of_profits_by_weights_ratio = (float *)malloc(sizeof(float) * NUMBER_OF_ELEMENTS);
	float * profits_in_sorted_order_of_profits_by_weights_ratio = (float *)malloc(sizeof(float) * NUMBER_OF_ELEMENTS);
	float * profits_by_weights_ratio = (float *)calloc(sizeof(float), NUMBER_OF_ELEMENTS);
	int i;


	for ( i = 0; i < NUMBER_OF_ELEMENTS; i ++){
		
		profits_by_weights_ratio[i] = profits[i] / weights[i];
	}


	weights_in_sorted_order_of_profits_by_weights_ratio = sort_using_other_array(weights, profits_by_weights_ratio);
	profits_in_sorted_order_of_profits_by_weights_ratio = sort_using_other_array(profits, profits_by_weights_ratio);
	printf("After the elements are sorted in increasing order of their profit/weight ratio\n");
	
	
	
	for (i = 0; i < NUMBER_OF_ELEMENTS; i ++ ){
		printf("%f     %f\n" , weights_in_sorted_order_of_profits_by_weights_ratio[i] , profits_in_sorted_order_of_profits_by_weights_ratio[i]);
	
	}


	fraction_included = add_items_to_knapsack(weights_in_sorted_order_of_profits_by_weights_ratio);


	max_profit = compute_profit(fraction_included, profits_in_sorted_order_of_profits_by_weights_ratio);
	

	return max_profit;
}





int main(int argv, char* argc[]){

	float * weights = (float *)malloc(sizeof(float) * NUMBER_OF_ELEMENTS);
	float * profits = (float *)malloc(sizeof(float) * NUMBER_OF_ELEMENTS);
	int i;
	
	srand((unsigned int)time(NULL));

	for (i = 0; i < NUMBER_OF_ELEMENTS; i ++ ){

		weights[i] =  ((float) rand() / (float) (RAND_MAX)) * KNAPSACK_CAPACITY;
		profits[i] =  ((float) rand() / (float) (RAND_MAX)) * KNAPSACK_CAPACITY;

	}


        printf("weights  |   profits\n");
        for ( i = 0; i < NUMBER_OF_ELEMENTS; i ++){
                printf("%f       %f\n", weights[i] , profits[i]);
        }

	printf("The maximum profit that can be obtained is : %f " , find_maximum_profit(weights, profits));
	return 0;
}
	


