/**
 * @file
 * @brief Implementation of [Addition of two polynomials]
 * (https://en.wikipedia.org/wiki/Polynomial#Addition)
 * @author [Ankita Roy Chowdhury](https://github.com/Ankita19ms0010)
 * @details
 * This code takes two polynomials as input
 * and prints their sum using linked list.
 * The polynomials must be in increasing or decreasing order of degree.
 * Degree must be positive.
 */
#include <stdio.h>  // for io operations
#include <stdlib.h>

/**
 * @brief identifier for single-variable polynomial coefficients as a linked
 * list
 */
struct term
{
    int coef;          /**< coefficient value */
    int pow;           /**< power of the polynomial term */
    struct term *next; /**< pointer to the successive term */
};

/**
 * @brief Frees memory space
 * @param poly first term of polynomial
 * @returns void
 */
void free_poly(struct term *poly)
{
    while (poly)
    {
        struct term *next = poly->next;
        free(poly);
        poly = next;
    }
}

/**
 * The function will create a polynomial
 * @param poly stores the address of the polynomial being created
 * @param coef contains the coefficient of the node
 * @param pow contains the degree
 * @returns none
 */
void create_polynomial(struct term **poly, int coef, int pow)
{
    // Creating the polynomial using temporary linked lists
    struct term **temp1 = poly;

    while (*temp1)
    {
        temp1 = &(*temp1)->next;
    }

    // Now temp1 reaches to the end of the list
    *temp1 = (struct term *)malloc(
        sizeof(struct term));  // Create the term and linked as the tail
    (*temp1)->coef = coef;
    (*temp1)->pow = pow;
    (*temp1)->next = NULL;
}

/**
 * The function will add 2 polynomials
 * @param poly1 first polynomial of the addition
 * @param poly2 second polynomial of the addition
 * @param pol  the resultant polynomial
 */

void poly_add(struct term **pol, struct term *poly1, struct term *poly2)
{
    // Creating a temporary linked list to store the resultant polynomial
    struct term *temp = (struct term *)malloc(sizeof(struct term));
    temp->next = NULL;
    *pol =
        temp;  //*pol always points to the 1st node of the resultant polynomial

    // Comparing the powers of the nodes of both the polynomials
    // until one gets exhausted
    while (poly1 && poly2)
    {
        /* If the power of the first polynomial is greater than the power of the
       second one place the power and coefficient of that node of the first
       polynomial in temp and increase the pointer poly1
       */
        if (poly1->pow > poly2->pow)
        {
            temp->coef = poly1->coef;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
        }
        /* If the power of the second polynomial is greater than the power of
          the first one place the power and coefficient of that node of the
          second polynomial in temp and increase the pointer poly2
        */
        else if (poly1->pow < poly2->pow)
        {
            temp->coef = poly2->coef;
            temp->pow = poly2->pow;
            poly2 = poly2->next;
        }
        /* If both of them have same power then sum the coefficients
          place both the summed coefficient and the power in temp
          increase both the pointers poly1 and poly2
        */
        else
        {
            temp->coef = poly1->coef + poly2->coef;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        /* If none of the polynomials are exhausted
         dynamically create a node in temp
         */
        if (poly1 && poly2)
        {
            temp->next = (struct term *)malloc(
                sizeof(struct term));  // Dynamic node creation
            temp = temp->next;         // Increase the pointer temp
            temp->next = NULL;
        }
    }
    /* If one of the polynomials is exhausted
    place the rest of the other polynomial as it is in temp
    by creating nodes dynamically
    */
    while (poly1 || poly2)
    {
        temp->next = (struct term *)malloc(
            sizeof(struct term));  // Dynamic node creation
        temp = temp->next;         // Increasing the pointer
        temp->next = NULL;

        /* If poly1 is not exhausted
        place rest of that polynomial in temp
        */
        if (poly1)
        {
            temp->coef = poly1->coef;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
        }
        /* If poly2 is not exhausted
       place rest of that polynomial in temp
       */
        else if (poly2)
        {
            temp->coef = poly2->coef;
            temp->pow = poly2->pow;
            poly2 = poly2->next;
        }
    }
}

/**
 * The function will display the polynomial
 * @param poly first term of the polynomial to be displayed
 * @returns none
 */
void display_polynomial(struct term *poly)
{
    while (poly != NULL)
    {
        printf("%d x^%d", poly->coef, poly->pow);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
}

/**
 * @brief Test function 1
 *
 * @details
 * Polynomial 1 is 5 x^2 + 3 x^1 + 2 x^0
 * Polynomial 2 is 7 x^3 + 9 x^1 + 10 x^0
 * Resultant polynomial is 7 x^3 + 5 x^2 + 12 x^1 + 12 x^0
 * @returns void
 */
static void test1(struct term *poly1, struct term *poly2, struct term *poly3)
{
    printf("\n----Test 1----\n");
    printf("\nFirst Polynomial:\n");  // Defining the 1st polynomial
    create_polynomial(&poly1, 5, 2);
    create_polynomial(&poly1, 3, 1);
    create_polynomial(&poly1, 2, 0);
    display_polynomial(poly1);

    printf("\nSecond Polynomial:\n");  // Defining the 2nd polynomial
    create_polynomial(&poly2, 7, 3);
    create_polynomial(&poly2, 9, 1);
    create_polynomial(&poly2, 10, 0);
    display_polynomial(poly2);

    poly_add(&poly3, poly1, poly2);  // Adding the two polynomials
    printf("\nResultant polynomial:\n");
    display_polynomial(poly3);
    printf("\n");

    // Frees memory space
    free_poly(poly1);
    free_poly(poly2);
    free_poly(poly3);
}

/**
 * @brief Test function 2
 *
 * @details
 * Polynomial 1 is 3 x^5 + 1 x^4 + 2 x^3 + -2 x^1 + 5 x^0
 * Polynomial 2 is 2 x^5 + 3 x^3 + 7 x^1 + 2 x^0
 * Resultant polynomial is 5 x^5 + 1 x^4 + 5 x^3 + 5 x^1 + 7 x^0
 * @returns void
 */
static void test2(struct term *poly1, struct term *poly2, struct term *poly3)
{
    printf("\n----Test 2----\n");
    printf("\nFirst Polynomial:\n");  // Defining the 1st polynomial
    create_polynomial(&poly1, 3, 5);
    create_polynomial(&poly1, 1, 4);
    create_polynomial(&poly1, 2, 3);
    create_polynomial(&poly1, -2, 1);
    create_polynomial(&poly1, 5, 0);

    display_polynomial(poly1);

    printf("\nSecond Polynomial:\n");  // Defining the 2nd polynomial
    create_polynomial(&poly2, 2, 5);
    create_polynomial(&poly2, 3, 3);
    create_polynomial(&poly2, 7, 1);
    create_polynomial(&poly2, 2, 0);

    display_polynomial(poly2);

    poly_add(&poly3, poly1, poly2);  // Adding the two polynomials
    printf("\nResultant polynomial:\n");
    display_polynomial(poly3);
    printf("\n");

    // Frees memory space
    free_poly(poly1);
    free_poly(poly2);
    free_poly(poly3);
}

/**
 * @brief Test function 3
 *
 * @details
 * Polynomial 1 is -12 x^0 + 8 x^1 + 4 x^3
 * Polynomial 2 is 5 x^0 + -13 x^1 + 3 x^3
 * Resultant polynomial is -7 x^0 + -5 x^1 + 7 x^3
 * @returns void
 */
static void test3(struct term *poly1, struct term *poly2, struct term *poly3)
{
    printf("\n----Test 3----\n");
    printf("\nFirst Polynomial:\n");  // Defining the 1st polynomial
    create_polynomial(&poly1, -12, 0);
    create_polynomial(&poly1, 8, 1);
    create_polynomial(&poly1, 4, 3);

    display_polynomial(poly1);

    printf("\nSecond Polynomial:\n");  // Defining the 2nd polynomial
    create_polynomial(&poly2, 5, 0);
    create_polynomial(&poly2, -13, 1);
    create_polynomial(&poly2, 3, 3);

    display_polynomial(poly2);

    poly_add(&poly3, poly1, poly2);  // Adding the two polynomials
    printf("\nResultant polynomial:\n");
    display_polynomial(poly3);
    printf("\n");

    // Frees memory space
    free_poly(poly1);
    free_poly(poly2);
    free_poly(poly3);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void)
{
    struct term *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    test1(poly1, poly2, poly3);
    test2(poly1, poly2, poly3);
    test3(poly1, poly2, poly3);

    return 0;
}
