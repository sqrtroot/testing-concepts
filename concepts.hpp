#pragma once

template<typename T1, typename T2>
concept Addable = requires(T1 t1, T2 t2) {
  t1 + t2;
};
template<typename T1, typename T2>
concept Subtractable = requires(T1 t1, T2 t2) {
  t1 - t2;
};
template<typename T1, typename T2>
concept Devidable = requires(T1 t1, T2 t2) {
  t1 / t2;
};
template<typename T1, typename T2>
concept Multipliable = requires(T1 t1, T2 t2) {
  t1 *t2;
};
