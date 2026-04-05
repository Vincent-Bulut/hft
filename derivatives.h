//
// Created by Vincent Bulut on 05/04/2026.
//

#ifndef HFT_DERIVATIVES_H
#define HFT_DERIVATIVES_H

#include <string>

class Derivative {
protected:
    std::string maturity;

public:
    explicit Derivative(std::string maturity);
    virtual ~Derivative() = default;

    const std::string& getMaturity() const;
};

class Option : public Derivative {
private:
    double strike;
    bool isCall;

public:
    Option(std::string maturity, double strike, bool isCall);

    double getStrike() const;
    bool getIsCall() const;
};

class Future : public Derivative {
private:
    double deliveryPrice;

public:
    Future(std::string maturity, double deliveryPrice);

    double getDeliveryPrice() const;
};

#endif // HFT_DERIVATIVES_H
