/**
 * \file
 * \brief [Problem 19](https://projecteuler.net/problem=19) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdio.h>

/**
 * Function to get the number of days in a month.
 * \param month month identified by an integer -\n
 * > 0 = Jan and 11 = December
 * \returns number of days in given month
 * \note For February, adjust for leap year outside the function.
 */
char get_month_days(short month)
{
    if (month == 1) /* February has 28 days. Adjust leap year in the loop */
        return 28;
    else if (month <= 6) /* odd months till July have 30 days - Jan = 0 (even)*/
    {
        if (month & 0x01)
            return 30;
        else
            return 31;
    }

    // else if (month >= 7) /* odd months after July have 31 days*/

    if (month & 0x01)
        return 31;

    return 30;
}

/**
 * @brief Check if input year is a leap year.
 * \param year year to check
 * \return 1 if input year is a leap year
 * \return 0 if input year is not a leap year
 */
char is_leap_year(short year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;

    return 0;
}

#ifdef DEBUG
/** Function to convert integer month to string
 * \param day integer identifier of day (0 = Sunday and 7 = Saturday
 * \return pointer to string representation)
 */
const char *day_string(int day)
{
    switch (day)
    {
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    default:
        return "Shouldn't see this!";
    }
}
#endif

/** Main function */
int main(int argc, char **argv)
{
    int count_sundays = 0;
    const short start_year = 1901;
    const short end_year = 2000;

    /*
     * Let us identify days i.e., Sunday thru Saturday with integers - 0 thru 6
     * respectively Jan 1 1901 was a Tuesday
     */
    char start_day = 2;

    for (int year = start_year; year <= end_year; year++)
    {
        char is_leap = is_leap_year(year);
        for (char month = 0; month < 12; month++)
        {
            /*
             * These two for-loops count the start of day for the next month.
             * Hence, we have to skip the last December count
             */
            if (year == end_year && month == 11)
                continue;

            int days = get_month_days(month);

            if (is_leap && month == 1) /* for a leap year february, add a day */
                days++;

#ifdef DEBUG
            if (year == end_year)
            {
                printf("Year: %d\t Month: %d\t Days: %d\t First of day: %s\n",
                       year, month, days, day_string(start_day));
            }
#endif

            /* Main Algorithm:
             * every week has 7 days hence, the start of next day would be
             * modulo 7 add to this, the current start date and ensure the
             * result is still modulo 7!
             */
            start_day = ((days % 7) + start_day) % 7;

            /* If start-day is a Sunday, increment counter */
            if (start_day == 0)
                count_sundays++;
        }
    }

    printf(
        "Total number of Sundays that happened on the 1st of a month in the "
        "last century: %d\n",
        count_sundays);

    return 0;
}
