#include "concepts.hpp"
#include "ema.hpp"
#include "vector2.hpp"
#include <cstdio>
#include <cstdlib>
#include <random>
#include <type_traits>

std::mt19937               generator(42);
std::binomial_distribution dist(50, .25);

struct Test {};

Vector2<int> generate_random_vector() {
  return Vector2(dist(generator), dist(generator));
}

constexpr auto max_val = 100;

int main() {
  // EMA<Test> t; //<-this errors we can't multiply test with floats
  //
  EMA ema(0.8, dist(generator));
  for(int i = 0; i < 100; i++) {
    const auto rval = dist(generator);
    std::printf("%i\t%i\n", rval, ema.update(rval));
  }

  std::printf("\n----------------------------\n");

  EMA<Vector2<int>, Vector2<float>> vectorEma(
    Vector2(0.3f, 0.3f), Vector2<int>(), Vector2(1.f, 1.f));
  for(int i = 0; i < 100; i++) {
    const auto rval = generate_random_vector();
    const auto nval = vectorEma.update(rval);
    std::printf("(%i,%i)\t(%i,%i)\n", rval.x, rval.y, nval.x, nval.y);
  }
}
