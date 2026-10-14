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
  int model_year{};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

int car_accidents() {
  int accidents{};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

double car_msrp() {
  double msrp{};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

bool car_has_premium_options() {

  std::string has_options_string{""};

  std::cout << "Does your car have premium options (yes/no)? ";

  std::cin >> has_options_string;

  if (has_options_string == "yes") {

    return true;
  } else {

    return false;
  }
}

void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(DIGITS)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

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
