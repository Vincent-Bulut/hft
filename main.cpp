
#include <iostream>
#include "derivatives.h"

int main() {
    Option callOption("2026-12-31", 100.0, true);
    Future futureContract("2027-06-30", 102.5);

    std::cout << "Option maturity: " << callOption.getMaturity() << "\n";
    std::cout << "Option strike: " << callOption.getStrike() << "\n";
    std::cout << "Option type: " << (callOption.getIsCall() ? "Call" : "Put") << "\n";

    std::cout << "Future maturity: " << futureContract.getMaturity() << "\n";
    std::cout << "Future delivery price: " << futureContract.getDeliveryPrice() << "\n";

    return 0;
}