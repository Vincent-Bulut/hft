c++ -O3 -Wall -shared -std=c++17 -fPIC \
-I../include \
$(python3.12 -m pybind11 --includes) \
bindings.cpp pricing.cpp \
-o hft_pricing$(python3.12-config --extension-suffix)