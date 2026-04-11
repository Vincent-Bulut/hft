import sys
from pathlib import Path

import hft

print(hft.black_scholes_put(100, 100, 0.05, 0.2, 1.0))

print(hft.black_scholes_call(100, 100, 0.05, 0.2, 1.0))

if __name__ == "__main__":
    pass
