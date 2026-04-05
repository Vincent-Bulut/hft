#pragma once

namespace hft {

    double black_scholes_call(double spot, double strike, double rate, double vol, double maturity);
    double black_scholes_put(double spot, double strike, double rate, double vol, double maturity);

}