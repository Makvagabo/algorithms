//
// Created by Aleskander on 03.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/big_integer.h"

using namespace Numerical;

TEST(Numerical, BigInteger_test) {
  b_int bi1("9007199254740992");
  b_int bi2 = "4294967296";
  b_int bi3 = "18446744073709551616";
  b_int bi4 = 65536;
  b_int bi5(65536);
  b_int bi6(bi5);

  // relational
  b_int bi7 = "12301010102";
  b_int bi8 = "12401010102";
  EXPECT_EQ(bi4, bi6);
  EXPECT_NE(bi4, bi3);
  EXPECT_GT(bi8, bi7);
  EXPECT_LT(bi7, bi8);
  EXPECT_GE(bi4, bi5);
  EXPECT_LE(bi4, bi6);
  !bi8;
  EXPECT_GT(bi7, bi8);
  EXPECT_LT(bi8, bi7);
  !bi7;
  EXPECT_GT(bi7, bi8);
  EXPECT_LT(bi8, bi7);
  bi8 = bi7;
  EXPECT_EQ(bi8, bi7);

  // addition
  EXPECT_EQ((bi1 + bi2).toString(), "9007203549708288");
  !bi1;
  EXPECT_EQ((bi1 + bi2).toString(), "-9007194959773696");
  !bi2;
  EXPECT_EQ((bi1 + bi2).toString(), "-9007203549708288");
  !bi1;
  EXPECT_EQ((bi1 + bi2).toString(), "9007194959773696");
  bi1 += bi1;
  EXPECT_EQ(bi1.toString(), "18014398509481984");
  bi1 += bi2;
  EXPECT_EQ(bi1.toString(), "18014394214514688");
  !bi1;
  bi1 += bi2;
  EXPECT_EQ(bi1.toString(), "-18014398509481984");
  !bi2;
  bi1 += bi2;
  EXPECT_EQ(bi1.toString(), "-18014394214514688");

  // subtraction
  EXPECT_EQ((bi3 - bi2).toString(), "18446744069414584320");
  !bi2;
  EXPECT_EQ((bi3 - bi2).toString(), "18446744078004518912");
  !bi3;
  EXPECT_EQ((bi3 - bi2).toString(), "-18446744078004518912");
  !bi2;
  EXPECT_EQ((bi3 - bi2).toString(), "-18446744069414584320");
  bi3 -= bi2;
  EXPECT_EQ(bi3.toString(), "-18446744069414584320");
  !bi2;
  bi3 -= bi2;
  EXPECT_EQ(bi3.toString(), "-18446744073709551616");
  !bi3;
  bi3 -= bi2;
  EXPECT_EQ(bi3.toString(), "18446744078004518912");
  !bi2;
  bi3 -= bi2;
  EXPECT_EQ(bi3.toString(), "18446744073709551616");

  // multiplication
  EXPECT_EQ((bi4 * bi5).toString(), "4294967296");
  !bi4;
  EXPECT_EQ((bi4 * bi5).toString(), "-4294967296");
  !bi5;
  EXPECT_EQ((bi4 * bi5).toString(), "4294967296");
  !bi5;
  EXPECT_EQ((bi4 * bi5).toString(), "-4294967296");
  bi4 *= bi6;
  EXPECT_EQ(bi4.toString(), "-4294967296");
  !bi6;
  bi4 *= bi6;
  EXPECT_EQ(bi4.toString(), "281474976710656");
  bi4 *= bi6;
  EXPECT_EQ(bi4.toString(), "-18446744073709551616");
  !bi4;
  !bi6;
  bi4 *= bi6;
  EXPECT_EQ(bi4.toString(), "1208925819614629174706176");
}
