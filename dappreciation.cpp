#include <iomanip>
#include <iostream>
#include <string>

const int YEAR{2025}, AGE_LIMIT{11}, YOUNG_LIMIT{5}, MIDDLE_LIMIT{8};
const int MAX_ACCIDENTS{3}, ONE_ACCIDENT{1}, TWO_ACCIDENTS{2}, DIGITS{2};
const int SUCCESS{0};
const double YOUNG_RATE{0.85}, MIDDLE_RATE{0.63}, OLD_RATE{0.45};
const double ZERO{0.0}, ONE_PENALTY{0.02}, TWO_PENALTY{0.10};
const double THREE_PENALTY{0.20}, PREMIUM_BONUS{0.05};

int car_model_year() {
    std::cout << "What is the model year of the car?\n";
    int year{};
    std::cin >> year;
    return year;
}

int car_accidents() {
    std::cout << "How many accidents has the car been in?\n";
    int accidents{};
    std::cin >> accidents;
    return accidents;
}

/*
Prompts for yes or no and returns a bool:
true means the car has premium options; false means it does not.
*/
bool car_has_premium_options() {
    // Prompt for yes or no.
    std::cout << "Does the car have premium options? Enter yes or no.\n";
    // Store the answer as a string.
    std::string answer{};
    // Read the answer.
    std::cin >> answer;
    // Return true for yes and false for no.
    return answer == "yes";
}

double car_msrp() {
    std::cout << "What was the car's original MSRP?\n";
    double msrp{};
    std::cin >> msrp;
    return msrp;
}

void print_eligible_message(double price) {
    std::cout << "dappreciation will list your car for $"
              << std::fixed << std::setprecision(DIGITS) << price << ".\n";
}

void print_ineligible_message() {
    std::cout << "Unfortunately your car is ineligible for the "
                 "dappreciation platform.\n";
}

/*
Reads car information, checks eligibility, and prints the resale price
or an ineligible message.
*/
int main() {
    int year{car_model_year()};
    int accidents{car_accidents()};
    bool premium{car_has_premium_options()};
    double msrp{car_msrp()};
    int age{YEAR - year};

    if (age < AGE_LIMIT && accidents <= MAX_ACCIDENTS)
    {
        double baseline{};
        if (age < YOUNG_LIMIT)
        {
            baseline = YOUNG_RATE;
        }
        else if (age <= MIDDLE_LIMIT)
        {
            baseline = MIDDLE_RATE;
        }
        else
        {
            baseline = OLD_RATE;
        }

        double penalty{ZERO};
        if (accidents == ONE_ACCIDENT)
        {
            penalty = ONE_PENALTY;
        }
        else if (accidents == TWO_ACCIDENTS)
        {
            penalty = TWO_PENALTY;
        }
        else if (accidents == MAX_ACCIDENTS)
        {
            penalty = THREE_PENALTY;
        }

        double percentage{baseline - penalty};
        if (premium)
        {
            percentage = percentage + PREMIUM_BONUS;
        }
        print_eligible_message(msrp * percentage);
    }
    else
    {
        print_ineligible_message();
    }
    return SUCCESS;
}
