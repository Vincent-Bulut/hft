#include "hft/pricing.h"

#include <cmath>
#include <stdexcept>

namespace hft {

    namespace {

        // Fonction de répartition de la loi normale centrée réduite : N(x)
        double normal_cdf(double x) {
            return 0.5 * std::erfc(-x / std::sqrt(2.0));
        }

        // Vérifications minimales des paramètres
        void validate_inputs(double spot, double strike, double vol, double maturity) {
            if (spot <= 0.0) {
                throw std::invalid_argument("spot must be > 0");
            }
            if (strike <= 0.0) {
                throw std::invalid_argument("strike must be > 0");
            }
            if (vol <= 0.0) {
                throw std::invalid_argument("vol must be > 0");
            }
            if (maturity <= 0.0) {
                throw std::invalid_argument("maturity must be > 0");
            }
        }

        double compute_d1(double spot, double strike, double rate, double vol, double maturity) {
            return (std::log(spot / strike) + (rate + 0.5 * vol * vol) * maturity)
                   / (vol * std::sqrt(maturity));
        }

        double compute_d2(double d1, double vol, double maturity) {
            return d1 - vol * std::sqrt(maturity);
        }

    } // namespace

    double black_scholes_call(double spot, double strike, double rate, double vol, double maturity) {
        validate_inputs(spot, strike, vol, maturity);

        const double d1 = compute_d1(spot, strike, rate, vol, maturity);
        const double d2 = compute_d2(d1, vol, maturity);

        return spot * normal_cdf(d1)
               - strike * std::exp(-rate * maturity) * normal_cdf(d2);
    }

    double black_scholes_put(double spot, double strike, double rate, double vol, double maturity) {
        validate_inputs(spot, strike, vol, maturity);

        const double d1 = compute_d1(spot, strike, rate, vol, maturity);
        const double d2 = compute_d2(d1, vol, maturity);

        return strike * std::exp(-rate * maturity) * normal_cdf(-d2)
               - spot * normal_cdf(-d1);
    }

} // namespace hft