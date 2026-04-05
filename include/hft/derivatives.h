#pragma once

namespace hft {

    // Payoff d'un call européen
    double call_payoff(double spot, double strike);

    // Payoff d'un put européen
    double put_payoff(double spot, double strike);

    // Valeur intrinsèque (call ou put)
    double intrinsic_value(bool is_call, double spot, double strike);

}