#include <iostream>
#include <string>

using namespace std;

// Provided function declarations from the skeleton
int get_int();
string format_money(double amount);
string quarter_to_ordinal(int quarter);
double calculate_per_capita_gdp_estimate(int quarters);

const int QUARTERS_PER_YEAR = 4;
const int EPOCH_YEAR = 1977;
const int EPOCH_QUARTER = 1;

/*
 * This program calculates the projected contribution to GDP
 * per working-age person for a specified quarter and year.
 */
int main()
{
    int year;
    int quarter;

    cout << "Please enter the year for the calculation: ";
    year = get_int();

    cout << "Please enter the quarter for the calculation: ";
    quarter = get_int();

    int userDateQuarters;
    int epochQuarters;
    int quartersBetween;

    userDateQuarters = (year * QUARTERS_PER_YEAR) + quarter;

    epochQuarters = (EPOCH_YEAR * QUARTERS_PER_YEAR) + EPOCH_QUARTER;

    quartersBetween = userDateQuarters - epochQuarters;

    double gdpEstimate;
    gdpEstimate = calculate_per_capita_gdp_estimate(quartersBetween);

    string quarterOrdinal;
    quarterOrdinal = quarter_to_ordinal(quarter);

    string formattedGdp;
    formattedGdp = format_money(gdpEstimate);

    cout << "In the " << quarterOrdinal << " quarter of "
         << year << ", the projected contribution to GDP per "
         << "working-age person is $" << formattedGdp << "." << endl;

    return 0;
}
