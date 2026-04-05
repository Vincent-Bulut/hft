#include "derivatives.h"

Derivative::Derivative(std::string maturity)
    : maturity(std::move(maturity)) {
}

const std::string& Derivative::getMaturity() const {
    return maturity;
}

Option::Option(std::string maturity, double strike, bool isCall)
    : Derivative(std::move(maturity)), strike(strike), isCall(isCall) {
}

double Option::getStrike() const {
    return strike;
}

bool Option::getIsCall() const {
    return isCall;
}

Future::Future(std::string maturity, double deliveryPrice)
    : Derivative(std::move(maturity)), deliveryPrice(deliveryPrice) {
}

double Future::getDeliveryPrice() const {
    return deliveryPrice;
}