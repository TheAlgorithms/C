/**
 * @file simple_linear_regression.c
 * @brief Simple Linear Regression Algorithm implemented
 * @details
 * this file has Simple Linear Regression Algorithm implemented
 * it calculate intercept and slope for algorithm to predict 
 *
 * Note:
 * this is a simple linear regression or
 * single linear regression which is
 * this code only worked for 1D Arrays and only can be applied
 * for 1 Column of predictor variable (x)
 * 
 * @author [KeyzarRasya](https://github.com/KeyzarRasya)
 */

#include <assert.h>	/* assert */
#include <stdio.h>	/* printf, perror */
#include <stdlib.h>	/* exit, malloc */
#include <string.h>	/* memcpy */
#include <math.h>	/* fabs */

#define EPSILON 0.0001 /* limit of tolerance for testing prediction */

/*!
 * @enum data_type
 * an enum to storing information
 * about data type used for performing
 * calculation in simple_linear_regression
 */
enum data_types {
    TYPE_INT,
    TYPE_FLOAT
};


/*! @struct simple_linear_regression
 * a class to store predictor (x) and target (y)
 * variables and also for storing the result of
 * slope and intercept
 */
struct simple_linear_regression {
    void *predictor;	    	/**< used to predict the target variables */
    void *target;		        /**< known as (y) variables or the predicted values */
    int size;			        /**< the length of predictor and target variables */
    float intercept;	    	/**< storing the result of intercept */ 
    float slope;		        /**< storing the result of intercept */
    enum data_types data_type;	/**< the type data used for predictor variables */
};

/*!
 * Return the pointer of simple_linear_regression
 * struct with information passed in parameters
 *
 * @param predictor 	array of predictors variables (x)
 * @param target 	    array of target variables (y)
 * @param data_type  	data type of predictor variables
 * @param size		    size of given predictor variables
*/
struct simple_linear_regression *init_simple_linear_regression(
    void *predictor, void *target, enum data_types data_type, int size) {

	/* allocating memory for simple_linear_regression structi */
    	struct simple_linear_regression *regressor = 
            (struct simple_linear_regression*)
            malloc(sizeof(struct simple_linear_regression));
            
    	if (!regressor) {
        	perror("Failed to allocate memory");
        	return NULL;
    	} /* if memory failed to be allocated */

    	size_t element_size = (data_type == TYPE_INT) ? sizeof(int) : sizeof(float);

    	regressor->predictor = malloc(size * element_size);
    	regressor->target = malloc(size * element_size);
	
	if (!regressor->predictor || !regressor->target) {
        	perror("Failed to allocate memory");
        	return NULL;
    	}/* if memory at predictor and target failed to be allocated */

    	memcpy(regressor->predictor, predictor, size * element_size);
    	memcpy(regressor->target, target, size * element_size);

    	regressor->data_type = data_type;
    	regressor->size = size;
    	regressor->intercept = 0.0;
    	regressor->slope = 0.0;

    	return regressor;
}

/*!
 * Return sum of the array for
 * data typed arrays
 *
 * @param *arr	array to be summed
 * @param size	size of the given array 
 */
float sum_float(float *arr, int size) {
    float total = 0.0;
    
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    return total;
}

/*!
 * Returns array values that already squared
 *
 * @param *num	the array to be squarred
 * @param size the size of the given arrays 
 */
float *square_float(float *arr, int size) {
    float *result = malloc(size * sizeof(float));
    
    for (int i = 0; i < size; i++) {
        result[i] = arr[i] * arr[i];
    }

    return result;
}

/*!
 * Return the multiplication of predictor (x)
 * and target (y)	
 * 
 * @param *x 	predictor variables
 * @param *y 	target variables
 * @param size 	size of given arrays
 */
float *calculate_x_times_y_float(float *x, float *y, int size) {
    float *result = malloc(size * sizeof(float));
    
    for (int i = 0; i < size; i++) {
        result[i] = x[i] * y[i];
    }
    
    return result;
}

/*!
 * Return value of calculation scope
 *
 * @param n		        length of predictor and target variables
 * @param sum_x 	    result sum of x variables (predictor)
 * @param sum_xy	    the result of summed x_times_y
 * @param sum_y	        result sum of y variables (target)
 * @param sum_x_square	the result of summed x squared
 */
float calculate_slope(int n, float sum_x, float sum_xy,
                         float sum_y, float sum_x_square) {
    float top = (n * sum_xy) - (sum_x * sum_y);
    float bottom = (n * sum_x_square) - (sum_x * sum_x);
    
    if (bottom == 0) {
        printf("\nError: Division by zero in slope calculation!\n");
        return 0;
    }/* if bottom equals zero, in mathematics this return undefined */

    return top / bottom;
}

/*!
 * Return the calculation of intercept
 *
 * @param x_mean	mean of x variables (predictor)
 * @param y_mean	mean of y variables (target)
 * @param slope	    slope values 
 */
float calculate_intercept(float x_mean, float y_mean, float slope) {
    return y_mean - (slope * x_mean);
}

/*!
 * ---------Training-------------
 * 1. Checking the simple_linear_regression data types
 * 2. Calculating all the variables are needed
 * 3. Calculating slope and intercept
 * 4. store slope and intercept values to simple_linear_regression struct
 *
 * @param regressor	struct of simple_linear_regression
 */
void train(struct simple_linear_regression *regressor) {
    if (regressor->data_type == TYPE_INT) {
        int *x = (int *)regressor->predictor;
        int *y = (int *)regressor->target;

        int sum_x = sum_float((float *)x, regressor->size);
        int sum_y = sum_float((float *)y, regressor->size);
        float *x_square = square_float((float *)x, regressor->size);
        float *x_times_y = calculate_x_times_y_float((float *)x, 
                                                    (float *)y, regressor->size);
        float sum_x_square = sum_float(x_square, regressor->size);
        float sum_xy = sum_float(x_times_y, regressor->size);

        float x_mean = (float)sum_x / regressor->size;
        float y_mean = (float)sum_y / regressor->size;

        regressor->slope = calculate_slope(regressor->size, sum_x,
                                             sum_xy, sum_y, sum_x_square);
        regressor->intercept = calculate_intercept(x_mean, 
                                                    y_mean, regressor->slope);

        free(x_square);
        free(x_times_y);
    } /*if simple_linear_regression data type is integer */
    else {
        float *x = (float *)regressor->predictor;
        float *y = (float *)regressor->target;

        float sum_x = sum_float(x, regressor->size);
        float sum_y = sum_float(y, regressor->size);
        float *x_square = square_float(x, regressor->size);
        float *x_times_y = calculate_x_times_y_float(x, y, regressor->size);
        float sum_x_square = sum_float(x_square, regressor->size);
        float sum_xy = sum_float(x_times_y, regressor->size);

        float x_mean = sum_x / regressor->size;
        float y_mean = sum_y / regressor->size;

        regressor->slope = calculate_slope(regressor->size, sum_x, 
                                            sum_xy, sum_y, sum_x_square);
        regressor->intercept = calculate_intercept(x_mean, y_mean, 
                                                    regressor->slope);

        free(x_square);
        free(x_times_y);
    } /* if simple_linear_regression data_type is float */
}

/*!
 * Returning the result of simple_linear_regression prediction
 *
 * @param regressor	used simple_linear_regression struct
 * @param pred		value that want to be predicted
 */
float predict(struct simple_linear_regression *regressor,
             float pred) {
    return regressor->intercept + (regressor->slope * pred);
}

/*!
 * A function to test simple_linear_regression
 * prediction process
 * 
 * x variables is product price
 * y variables is amount of quality sold
 */
void test(){
	float x[] = {50000.0, 55000.0, 60000.0, 65000.0, 70000.0};
	float y[] = {20.0, 18.0, 15.0, 12.0, 10.0};

    	struct simple_linear_regression *regressor = 
            init_simple_linear_regression(x, y, TYPE_FLOAT, sizeof(x)/sizeof(float));

	train(regressor);

	float pred = 75000.0;
	float prediction = predict(regressor, pred);

	printf("\nPredicted value for product price %.2f is %f\n",
             pred, prediction);
	
	assert(fabs(prediction - 7.200008) < EPSILON);
	printf("Assertion Passed\n");
	free(regressor->predictor);
	free(regressor->target);
	free(regressor);
}

/*!
 * main function to call the
 * test functions
 */
int main() {
	test();
	return 0;
}
