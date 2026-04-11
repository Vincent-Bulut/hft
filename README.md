# hft — High-Frequency Trading Derivatives Pricing Library

A focused C++ library for pricing European options using the Black-Scholes model, with first-class Python bindings via pybind11.

---

## What it does

Given a set of market parameters, the library computes the fair value of European call and put options under the Black-Scholes framework:

```
C = S * N(d1) - K * e^(-rT) * N(d2)
P = K * e^(-rT) * N(-d2) - S * N(-d1)
```

where `d1 = [ln(S/K) + (r + σ²/2)T] / (σ√T)` and `d2 = d1 - σ√T`.

---

## Project structure

```
hft/
├── include/hft/
│   ├── pricing.h        # Black-Scholes call & put declarations
│   └── derivatives.h    # Payoff / intrinsic-value declarations
├── src/
│   ├── pricing.cpp      # Black-Scholes implementation
│   ├── derivatives.cpp  # Payoff implementations
│   ├── bindings.cpp     # pybind11 Python module (_core)
│   └── main.cpp         # CLI demo
├── python/hft/
│   ├── __init__.py
│   └── pricing.py       # Re-exports black_scholes_call / black_scholes_put
└── tests/
    └── test_pricing.cpp # Test stub (framework TBD)
```

Three build targets are produced:

| Target | Type | Purpose |
|---|---|---|
| `hft_lib` | Static library | Core pricing logic |
| `hft` | Executable | CLI demo |
| `hft_pricing` | Python extension | pybind11 bindings |

---

## Build

**Prerequisites**

```bash
brew install cmake
python3 -m pip install pybind11
```

**Configure and build**

```bash
# Get the pybind11 cmake directory
PYBIND11_DIR=$(python3 -m pybind11 --cmakedir)

mkdir -p cmake-build-debug && cd cmake-build-debug
cmake -DPYBIND11_FINDPYTHON=ON -Dpybind11_DIR=$PYBIND11_DIR ..
ninja
```

---

## Usage

### CLI

```bash
./cmake-build-debug/hft
```

```
Inputs:
  Spot     = 100.000000
  Strike   = 100.000000
  Rate     = 0.050000
  Vol      = 0.200000
  Maturity = 1.000000

Results:
  Black-Scholes Call = 10.450584
  Black-Scholes Put  = 5.573526
```

### Python

```python
import sys
sys.path.insert(0, 'cmake-build-debug')
import hft_pricing

call = hft_pricing.call(spot=100, strike=100, rate=0.05, vol=0.2, maturity=1.0)
put  = hft_pricing.put(spot=100, strike=100, rate=0.05, vol=0.2, maturity=1.0)

print(f"Call: {call:.6f}")  # 10.450584
print(f"Put:  {put:.6f}")   # 5.573526
```

---

## API reference

### `hft::black_scholes_call(spot, strike, rate, vol, maturity) -> double`

Computes the Black-Scholes price of a European **call** option.

### `hft::black_scholes_put(spot, strike, rate, vol, maturity) -> double`

Computes the Black-Scholes price of a European **put** option.

**Parameters** (all `double`, all must be strictly positive):

| Parameter | Description |
|---|---|
| `spot` | Current underlying price |
| `strike` | Option strike price |
| `rate` | Continuously compounded risk-free rate |
| `vol` | Annualised implied volatility |
| `maturity` | Time to expiry in years |

Throws `std::invalid_argument` if any parameter is `<= 0`.

### Payoff helpers (`hft::derivatives`)

- `call_payoff(spot, strike)` — `max(S - K, 0)`
- `put_payoff(spot, strike)` — `max(K - S, 0)`
- `intrinsic_value(is_call, spot, strike)` — dispatches to the above

---

## Design notes

- All public symbols live in the `hft::` namespace.
- Internal helpers (`normal_cdf`, `compute_d1`, `compute_d2`, `validate_inputs`) are in anonymous namespaces and are translation-unit private — no linkage leakage.
- Headers use `#pragma once`.
- The Python extension module is named `_core`; the `python/hft/pricing.py` wrapper re-exports the symbols under clean names.
