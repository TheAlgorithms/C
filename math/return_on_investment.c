/**
 * @file
 * @brief Calculate [Return on Investment (ROI)](https://www.investopedia.com/terms/r/returnoninvestment.asp)
 * @details
 * Return on Investment (ROI) measures the profitability of an investment
 * relative to its cost, expressed as a percentage.
 *
 * Formula: ROI = (Gain - Cost) / Cost * 100
 *
 * @author [InukaWijerathna](https://github.com/InukaWijerathna)
 */

#include <assert.h>  /// for assert()
#include <stdio.h>   /// for IO operations

/**
 * @brief Calculate return on investment as a percentage
 * @param gain_from_investment total value gained from the investment
 * @param cost_of_investment total cost of the investment (must be > 0)
 * @return ROI as a percentage, or -999.0 on invalid input
 */
double return_on_investment(double gain_from_investment,
                            double cost_of_investment) {
    if (cost_of_investment <= 0) {
        fprintf(stderr, "Error: cost_of_investment must be > 0\n");
        return -999.0;
    }
    return (gain_from_investment - cost_of_investment) / cost_of_investment *
           100.0;
}

/**
 * @brief Self-test implementations
 */
static void tests(void) {
    assert(return_on_investment(1000.0, 500.0) == 100.0);
    assert(return_on_investment(500.0, 500.0) == 0.0);
    assert(return_on_investment(200.0, 500.0) == -60.0);
    assert(return_on_investment(0.0, 500.0) == -100.0);
    assert(return_on_investment(1000.0, 0.0) == -999.0);
    printf("All tests passed!\n");
}

/**
 * @brief Main function
 */
int main(void) {
    tests();
    return 0;
}
