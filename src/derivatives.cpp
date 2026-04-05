#include "hft/derivatives.h"

namespace hft {

    double call_payoff(double spot, double strike) {
        return (spot > strike) ? (spot - strike) : 0.0;
    }

    double put_payoff(double spot, double strike) {
        return (spot < strike) ? (strike - spot) : 0.0;
    }

    double intrinsic_value(bool is_call, double spot, double strike) {
        return is_call ? call_payoff(spot, strike)
                       : put_payoff(spot, strike);
    }

}