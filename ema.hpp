#pragma once
#include "concepts.hpp"

template<typename result_t, typename multiplier_t = float, typename unit_t = multiplier_t>
requires Multipliable<result_t, multiplier_t> &&Subtractable<unit_t, result_t> struct EMA {
  const unit_t       unit = 1;
  result_t           prev = result_t();
  const multiplier_t mult;

  constexpr EMA(const multiplier_t &multiplier): mult(multiplier) {}
  constexpr EMA(const multiplier_t &multiplier, const result_t &initial):
      mult(multiplier), prev(initial) {}
  constexpr EMA(const multiplier_t &multiplier, const result_t &initial, const unit_t &unit):
      mult(multiplier), prev(initial), unit(unit) {}

  constexpr result_t update(const result_t &input) {
    return (prev = static_cast<result_t>(input * mult + prev * (unit - mult)));
  };
  constexpr result_t get() const { return prev; }
};
