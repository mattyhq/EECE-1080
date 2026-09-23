#include <iostream>

int main ()
{

const double charityChargesPerPatient = 1375.61;

int firstYear = 0;
int firstYearPatients = 0;
int secondYear = 0;
int secondYearPatients = 0;

double firstYearCharityCharges = 0.0;
double secondYearCharityCharges = 0.0;
double patientIncreasePercent = 0.0;

std::cout << "Enter the first year:";
std::cin >> firstYear;

std::cout << "Enter the number of patients we saw that year: ";
std::cin >> firstYearPatients;

std::cout << "Enter the second year: ";
std::cin >> secondYear;

std::cout << "Enter the number of patients we saw that year: ";
std::cin >> secondYearPatients;

firstYearCharityCharges =
  firstYearPatients * charityChargesPerPatient;

secondYearCharityCharges = 
  secondYearPatients * charityChargesPerPatient;

patientIncreasePercent = 
(static_cast<double>(secondYearPatients - firstYearPatients) 
/ firstYearPatients) * 100;

std::cout << "In year " << firstYear
              << ", our hospital issued "
              << firstYearCharityCharges
              << " dollars of charity charges.\n";

std::cout << "In year " << secondYear
              << ", our hospital issued "
              << secondYearCharityCharges
              << " dollars of charity charges.\n";

std::cout << "Between " << firstYear
              << " and " << secondYear
              << ", there was a "
              << patientIncreasePercent
              << "% increase in patients seen at our hospital.\n";

return 0;
}
