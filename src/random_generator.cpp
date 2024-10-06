/*
SPDX-FileCopyrightText: (c) 2024, sabonerune
SPDX-License-Identifier: 0BSD
*/

#include "world/random_generator.hpp"
#include <cstdint>

using namespace world::modified::internal;

RandomGenerator::RandomGenerator() {
  //-----------------------------------------------------------------------------
  // Copyright 2012 Masanori Morise
  // Author: mmorise [at] meiji.ac.jp (Masanori Morise)
  //-----------------------------------------------------------------------------
  // this code copy from ../matlabfunctions.cpp
  g_randn_x = 123456789;
  g_randn_y = 362436069;
  g_randn_z = 521288629;
  g_randn_w = 88675123;
  //-----------------------------------------------------------------------------
};
RandomGenerator::~RandomGenerator() {};
double RandomGenerator::operator()() {
  //-----------------------------------------------------------------------------
  // Copyright 2012 Masanori Morise
  // Author: mmorise [at] meiji.ac.jp (Masanori Morise)
  //-----------------------------------------------------------------------------
  // this code copy from ./matlabfunctions.cpp
  std::uint32_t t;
  t = g_randn_x ^ (g_randn_x << 11);
  g_randn_x = g_randn_y;
  g_randn_y = g_randn_z;
  g_randn_z = g_randn_w;
  g_randn_w = (g_randn_w ^ (g_randn_w >> 19)) ^ (t ^ (t >> 8));

  std::uint32_t tmp = g_randn_w >> 4;
  for (int i = 0; i < 11; ++i) {
    t = g_randn_x ^ (g_randn_x << 11);
    g_randn_x = g_randn_y;
    g_randn_y = g_randn_z;
    g_randn_z = g_randn_w;
    g_randn_w = (g_randn_w ^ (g_randn_w >> 19)) ^ (t ^ (t >> 8));
    tmp += g_randn_w >> 4;
  }
  return tmp / 268435456.0 - 6.0;
  //-----------------------------------------------------------------------------
};
