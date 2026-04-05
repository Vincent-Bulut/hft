#include <iostream>
#include <iomanip>
#include <exception>

#include "hft/pricing.h"

int main() {
    const double spot = 100.0;
    const double strike = 100.0;
    const double rate = 0.05;
    const double vol = 0.20;
    const double maturity = 1.0;

    try {
        const double call_price = hft::black_scholes_call(spot, strike, rate, vol, maturity);
        const double put_price = hft::black_scholes_put(spot, strike, rate, vol, maturity);

        std::cout << std::fixed << std::setprecision(6);
        std::cout << "Inputs:\n";
        std::cout << "  Spot     = " << spot << '\n';
        std::cout << "  Strike   = " << strike << '\n';
        std::cout << "  Rate     = " << rate << '\n';
        std::cout << "  Vol      = " << vol << '\n';
        std::cout << "  Maturity = " << maturity << '\n';

        std::cout << "\nResults:\n";
        std::cout << "  Black-Scholes Call = " << call_price << '\n';
        std::cout << "  Black-Scholes Put  = " << put_price << '\n';
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}