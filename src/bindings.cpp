#include <pybind11/pybind11.h>
#include "hft/pricing.h"

namespace py = pybind11;

#include <pybind11/pybind11.h>
#include "hft/pricing.h"

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.doc() = "Black-Scholes pricing module";

    m.def("black_scholes_call", &hft::black_scholes_call,
          "Black-Scholes Call Price",
          py::arg("spot"),
          py::arg("strike"),
          py::arg("rate"),
          py::arg("vol"),
          py::arg("maturity"));

    m.def("black_scholes_put", &hft::black_scholes_put,
          "Black-Scholes Put Price",
          py::arg("spot"),
          py::arg("strike"),
          py::arg("rate"),
          py::arg("vol"),
          py::arg("maturity"));
}

