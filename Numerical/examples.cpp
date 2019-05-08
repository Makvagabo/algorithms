//
// Created by Alexander on 09.05.2019.
//

#include <iostream>

#include "lcg.h"
#include "examples.h"

using namespace std;

namespace Numerical {

void lgc_example() {
  LCG gen;
  cout << "Example linear congruential generator: " <<
                gen.random(1) << ", " <<
                gen.random(2) << ", " <<
                gen.random(3) << ", " <<
                gen.random(4) << ", " <<
                gen.random(5) << ", " <<
                gen.random(6) << ", " <<
                gen.random(7) << ", " <<
                gen.random(8) << ", " <<
                gen.random(9) << ", " <<
                gen.random(10) << endl;
}

}
