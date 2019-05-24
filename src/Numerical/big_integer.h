//
// Created by Alexander on 24.05.2019.
//

#ifndef ALGORITHMS_NUMERICAL_BIG_INTEGER_H_
#define ALGORITHMS_NUMERICAL_BIG_INTEGER_H_

#include <vector>
#include <string>

namespace Numerical {

class BigInteger {
  std::vector<int> number_;
  bool positive;
  enum {
    BASE = 10
  };
 public:
  BigInteger();
  explicit BigInteger(const std::string &number);
  BigInteger(const BigInteger &bi);
  BigInteger operator+(const BigInteger &second) const;
  BigInteger &operator+=(const BigInteger &second);
  BigInteger operator-(const BigInteger &second) const;
  BigInteger operator-=(const BigInteger &second);
  BigInteger operator*(const BigInteger &second) const;
  BigInteger &operator*=(const BigInteger &second);
  friend bool operator>(const BigInteger &left, const BigInteger &right);
  friend bool operator<(const BigInteger &left, const BigInteger &right);
  friend bool operator==(const BigInteger &left, const BigInteger &right);
  friend std::ostream &operator<<(std::ostream &os, const BigInteger &bi);
};

typedef BigInteger b_int;

} // namespace Numerical
#endif //ALGORITHMS_NUMERICAL_BIG_INTEGER_H_
