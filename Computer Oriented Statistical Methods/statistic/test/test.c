/*
    author: Christian Bender
    This file contains a CUnit test suit for the statistic-library
*/

#include <stdio.h>
#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"

#include "../src/statistic.h"

/* test for function average(...) */
void test_average(void)
{
    CU_ASSERT_DOUBLE_EQUAL(average(3,1.0,2.5,3.5),2.333,0.01);
}

/* test for function averageArray(...) */
void test_average_Array(void)
{
    double values[] = {1.0, 2.5, 3.5};
    CU_ASSERT_DOUBLE_EQUAL(average_Array(3, values), 2.333, 0.01);
}

/* test for function standard_deviation(...) */
void test_standard_deviation(void)
{
    CU_ASSERT_DOUBLE_EQUAL(standard_deviation(4, 15.0, 70.0, 25.0, 50.0), 24.8328, 0.01);
}

/* test for function standard_deviation_array() */
void test_standard_deviation_array(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(standard_deviation_array(4, values), 24.8328, 0.01);
}

/* test for function standard_deviation_N(...) */
void test_standard_deviation_N(void)
{
    CU_ASSERT_DOUBLE_EQUAL(standard_deviation_N(4, 15.0, 70.0, 25.0, 50.0), 21.5058, 0.01);
}

/* test for function standard_deviation_N_array() */
void test_standard_deviation_N_array(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(standard_deviation_N_array(4, values), 21.5058, 0.01);
}

/* test for the function variance(...) */
void test_variance(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(variance(4, values), 616.6667, 0.01);
}

/* test for the function variance(...) */
void test_variance_N(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(variance_N(4, values), 462.5, 0.01);
}

/* test for the max(...) function */
void test_max(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(max(4, values), 70.0, 0.01);
}

/* test for the min(...) function */
void test_min(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(min(4, values), 15.0, 0.01);
}

/* test for the median(...)-function */
void test_median(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(median(4, values), 37.5, 0.01);
}


/* test for the sum(...)-function */
void test_sum(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(sum(4, values), 160, 0.01);
}


/* test for the range(...)-function */
void test_range(void)
{
    double values[] = {15.0, 70.0, 25.0, 50.0};
    CU_ASSERT_DOUBLE_EQUAL(range(4, values), 55, 0.01);
}


/* test of frequency_of(...)-function */
void test_frequency_of(void)
{
    double values[] = {1.0,7.0,2.5,2.5,6.0};
    CU_ASSERT_DOUBLE_EQUAL(frequency_of(5, values,2.5), 0.4, 0.01);
    CU_ASSERT_DOUBLE_EQUAL(frequency_of(5, values,6.0), 0.2, 0.01);
}


/* test of quartile_I(...) and quartile_III(...)-function */
void test_quartile(void)
{
    double values[] = {3.0,4.0,5.0,7.0,7.0,7.0,8.0,9.0,11.0,13.0,13.0,13.0,15.0,16.0};
    double sample[] = {1600.0,2300.0,2300.0,2400.0,2900.0,3200,3500,4500,4600,5200,6500,12000};
    CU_ASSERT_DOUBLE_EQUAL(quartile_I(14, values), 7.0, 0.01);
    CU_ASSERT_DOUBLE_EQUAL(quartile_III(14, values), 13.0, 0.01);
    CU_ASSERT_DOUBLE_EQUAL(quartile_III(12, sample), 4900.0, 0.01);
}


/* test for quartile_distance(...)-function */
void test_quartile_distance(void)
{
    double values[] = {3.0,4.0,5.0,7.0,7.0,7.0,8.0,9.0,11.0,13.0,13.0,13.0,15.0,16.0};
    CU_ASSERT_DOUBLE_EQUAL(quartile_distance(14, values), 6.0, 0.01);
}

/* 
    init suite
*/
int init_suite1(void)
{
    return 0;
}

/*
    clean suite
*/
int clean_suite1(void)
{
    return 0;
}

/* test runner */
int main(void)
{
    CU_pSuite pSuite = NULL;

    /* initializes CUnit */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* adds the suit "Test for statistic" to the registry */
    pSuite = CU_add_suite("Test for statistic", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* registers the individual tests to the test-suite */
    if ((NULL == CU_add_test(pSuite, "test of average()", test_average)) 
    || (NULL == CU_add_test(pSuite, "test of average_Array()", test_average_Array)) 
    || (NULL == CU_add_test(pSuite, "test of standard_deviation()", test_standard_deviation)) 
    || (NULL == CU_add_test(pSuite, "test of standard_deviation_array()", test_standard_deviation_array)) 
    || (NULL == CU_add_test(pSuite, "test of standard_deviation_N_array()", test_standard_deviation_N_array)) 
    || (NULL == CU_add_test(pSuite, "test of standard_deviation_N()", test_standard_deviation_N)) 
    || (NULL == CU_add_test(pSuite, "test of variance()", test_variance)) 
    || (NULL == CU_add_test(pSuite, "test of variance_N()", test_variance_N)) 
    || (NULL == CU_add_test(pSuite, "test of max()", test_max)) 
    || (NULL == CU_add_test(pSuite, "test of min()", test_min))
    || (NULL == CU_add_test(pSuite, "test of median()", test_median))
    || (NULL == CU_add_test(pSuite, "test of sum()", test_sum))
    || (NULL == CU_add_test(pSuite, "test of range()", test_range))
    || (NULL == CU_add_test(pSuite, "test of frequency_of()", test_frequency_of))
    || (NULL == CU_add_test(pSuite, "test of quartile_I() and quartile_III()", test_quartile))
    || (NULL == CU_add_test(pSuite, "test of quartile_distance()", test_quartile_distance)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* runs tests */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}