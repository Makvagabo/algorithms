//
// Created by Aleskander on 03.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/big_integer.h"

using Numerical::b_int;

TEST(Numerical, BigInteger_Common_Test) {
  std::string si1 = "12g45";
  EXPECT_THROW(new b_int(si1), b_int::BigIntegerError);
  EXPECT_THROW(new b_int("12g45"), b_int::BigIntegerError);

  b_int bi1 = "00144";
  std::string si2 = "01245";
  b_int bi2(si2);
  EXPECT_EQ(bi1, 144);
  EXPECT_EQ(bi2, 1245);
}
TEST(Numerical, BigInteger_Relational_Test) {
  b_int bi1, bi2;
  b_int bi3 = "18446744073709551616";
  b_int bi4 = 65536;
  b_int bi5(65536);
  b_int bi6 = bi5;
  b_int bi7 = "12301010102";
  b_int bi8 = "12401010102";

  EXPECT_EQ(bi4, bi6);
  EXPECT_NE(bi4, bi3);
  EXPECT_EQ(bi1, bi2);
  EXPECT_EQ(bi1, 0);
  EXPECT_EQ(0, bi1);
  bi1 = 1;
  EXPECT_NE(bi1, 0);
  EXPECT_NE(0, bi1);
  EXPECT_NE(bi1, bi2);
  EXPECT_GT(bi1, bi2);
  EXPECT_LT(bi2, bi1);
  EXPECT_GT(bi8, bi7);
  EXPECT_LT(bi7, bi8);
  EXPECT_GE(bi4, bi5);
  EXPECT_LE(bi4, bi6);
  EXPECT_GT(bi7, !bi8);
  EXPECT_LT(!bi8, bi7);
  EXPECT_GT(!bi7, !bi8);
  EXPECT_LT(!bi8, !bi7);
  bi8 = bi7;
  EXPECT_EQ(bi8, bi7);
}
TEST(Numerical, BigInteger_Addition_Test) {
  b_int bi1("9007199254740992");
  b_int bi2 = "4294967296";

  EXPECT_EQ((bi1 + !bi1), 0);
  EXPECT_EQ((!bi1 + bi1), 0);
  EXPECT_EQ((bi1 + bi2), "9007203549708288");
  EXPECT_EQ((!bi1 + bi2), "-9007194959773696");
  EXPECT_EQ((!bi1 + !bi2), "-9007203549708288");
  EXPECT_EQ((bi1 + !bi2), "9007194959773696");
  bi1 += bi1;
  EXPECT_EQ(bi1, "18014398509481984");
  bi1 += !bi2;
  EXPECT_EQ(bi1, "18014394214514688");
  bi1 = !bi1;
  bi1 += bi2;
  EXPECT_EQ(bi1, "-18014389919547392");
  bi2 = !bi2;
  bi1 += bi2;
  EXPECT_EQ(bi1, "-18014394214514688");
  EXPECT_EQ((bi1 + 0), "-18014394214514688");
  EXPECT_EQ(("0" + bi1), "-18014394214514688");
}
TEST(Numerical, BigInteger_Subtraction_Test) {
  b_int bi1 = "4294967296";
  b_int bi2 = "18446744073709551616";

  EXPECT_EQ((bi2 - bi1), "18446744069414584320");
  EXPECT_EQ((bi2 - !bi1), "18446744078004518912");
  EXPECT_EQ((!bi2 - !bi1), "-18446744078004518912");
  EXPECT_EQ((!bi2 - bi1), "-18446744069414584320");
  bi2 -= bi1;
  EXPECT_EQ(bi2, "18446744069414584320");
  bi1 = !bi1;
  bi2 -= bi1;
  EXPECT_EQ(bi2, "18446744073709551616");
  bi2 = !bi2;
  bi2 -= bi1;
  EXPECT_EQ(bi2, "-18446744078004518912");
  bi1 = !bi1;
  bi2 -= bi1;
  EXPECT_EQ(bi2, "-18446744073709551616");
  EXPECT_EQ((bi2 - bi2), 0);
  EXPECT_EQ((!bi2 - !bi2), 0);
  EXPECT_EQ((bi2 - 0), "-18446744073709551616");
  EXPECT_EQ((0 - bi2), "-18446744073709551616");
  EXPECT_EQ(("0" - bi2), "-18446744073709551616");
}
TEST(Numerical, BigInteger_Multiplication_Test) {
  b_int bi1;
  b_int bi2(65536);

  EXPECT_THROW((bi1 * bi2), b_int::BigIntegerError);
  EXPECT_THROW((bi2 * bi1), b_int::BigIntegerError);

  bi1 = 65536;
  b_int bi3(bi2);

  EXPECT_EQ((bi1 * bi2), "4294967296");
  EXPECT_EQ((!bi1 * bi2), "-4294967296");
  EXPECT_EQ((!bi1 * !bi2), "4294967296");
  EXPECT_EQ((!bi1 * bi2), "-4294967296");
  bi1 *= bi3;
  EXPECT_EQ(bi1, "4294967296");
  bi3 = !bi3;
  bi1 *= bi3;
  EXPECT_EQ(bi1, "-281474976710656");
  bi1 *= bi3;
  EXPECT_EQ(bi1, "18446744073709551616");
  bi3 *= bi1;
  EXPECT_EQ(bi3, "-1208925819614629174706176");
  EXPECT_EQ((bi1 * 0), 0);
  EXPECT_EQ((0 * bi1), 0);
  EXPECT_EQ(("0" * bi3), 0);
  bi3 = 0;
  EXPECT_EQ((bi3 * 65536), 0);
  EXPECT_EQ((65536 * bi3), 0);
  EXPECT_EQ(("-65536" * bi3), 0);
}
TEST(Numerical, BigInteger_Division_Test) {
  b_int bi1 = 65536;
  b_int bi2 = "1208911819114";
  EXPECT_EQ((bi2 / bi1), "18446530");
  EXPECT_EQ((bi2 % bi1), "29034");

  b_int bi3 = "1208925819614629174706176";
  b_int bi4 = "184465";
  EXPECT_EQ((bi3 / bi4), "6553686713547985659");
  EXPECT_EQ((!bi3 / bi4), "-6553686713547985659");
  EXPECT_EQ((bi3 / !bi4), "-6553686713547985659");
  EXPECT_EQ((!bi3 / !bi4), "6553686713547985659");
  EXPECT_EQ((bi4 / bi3), 0);
  EXPECT_EQ((0 / bi3), 0);
  EXPECT_EQ((!bi3 % bi4), "118741");
  EXPECT_EQ((bi4 % !bi3), "184465");
  EXPECT_EQ((0 % bi3), 0);

  EXPECT_THROW((bi4 / 0), b_int::BigIntegerError);
  EXPECT_THROW((bi4 % 0), b_int::BigIntegerError);
}
