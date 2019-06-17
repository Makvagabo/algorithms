//
// Created by Alexander on 16.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/is_carmichael.h"

TEST(Numerical, IsCarmichael_Test) {
  // comments test are pass for 100 tryings
  EXPECT_TRUE(Numerical::IsCarmichael(561, 10));
  // EXPECT_TRUE(Numerical::IsCarmichael(1105, 100));
  // EXPECT_TRUE(Numerical::IsCarmichael(1729, 100));
  // EXPECT_TRUE(Numerical::IsCarmichael(2465, 100));
}
