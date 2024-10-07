#include <world/matlabfunctions.h>
#include <world/random_generator.hpp>

namespace wmi = world::modified::internal;

int main(int argc, char* argv[]) {
  randn_reseed();
  wmi::RandomGenerator i_rand;
  for (size_t i = 0; i < 100000; i++) {
    if (randn() != i_rand()) {
      return 1;
    }
  }
  return 0;
};
