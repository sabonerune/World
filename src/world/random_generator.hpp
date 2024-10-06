/*
SPDX-FileCopyrightText: (c) 2024, sabonerune
SPDX-License-Identifier: 0BSD
*/

#ifndef WORLD_MODIFIED_RANDOM_INTERNAL_GENERATOR_HPP_
#define WORLD_MODIFIED_RANDOM_INTERNAL_GENERATOR_HPP_
#include <cstdint>
namespace world {
namespace modified {
namespace internal {
class RandomGenerator {
 private:
  std::uint32_t g_randn_x;
  std::uint32_t g_randn_y;
  std::uint32_t g_randn_z;
  std::uint32_t g_randn_w;

 public:
  RandomGenerator();
  ~RandomGenerator();
  double operator()();
};
}  // namespace internal
}  // namespace  modified
}  // namespace world
#endif
