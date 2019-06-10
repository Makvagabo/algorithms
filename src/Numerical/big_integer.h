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
  static void refresh(BigInteger &bi);
  static BigInteger division(const BigInteger &master_, const BigInteger &slave_, bool mod);
 public:
  BigInteger();
  explicit BigInteger(const std::string &number);
  BigInteger(const char *number);
  BigInteger(int number);
  BigInteger(const BigInteger &bi);
  explicit BigInteger(const BigInteger &bi, unsigned int start, unsigned int end);

  class BigIntegerError : public std::exception {
   public:
    std::string message_;
    std::string file_;
    int line_;
    explicit BigIntegerError(std::string message) : message_(std::move(message)) {}
    explicit BigIntegerError(std::string message, std::string file, int line)
        : message_(std::move(message)), file_(std::move(file)), line_(line) {}
  };

  std::string toString() const;

  BigInteger &operator+=(const BigInteger &second);
  BigInteger operator+(const BigInteger &second) const;
  friend BigInteger operator+(int left, const BigInteger &second);
  friend BigInteger operator+(const char *left, const BigInteger &second);

  BigInteger &operator-=(const BigInteger &second);
  BigInteger operator-(const BigInteger &second) const;
  friend BigInteger operator-(int left, const BigInteger &second);
  friend BigInteger operator-(const char *left, const BigInteger &second);

  BigInteger &operator*=(const BigInteger &second);
  BigInteger operator*(const BigInteger &second) const;
  friend BigInteger operator*(int left, const BigInteger &second);
  friend BigInteger operator*(const char *left, const BigInteger &second);

  BigInteger &operator/=(const BigInteger &second);
  BigInteger operator/(const BigInteger &second) const;
  friend BigInteger operator/(int left, const BigInteger &second);
  friend BigInteger operator/(const char *left, const BigInteger &second);

  BigInteger &operator%=(const BigInteger &second);
  BigInteger operator%(const BigInteger &second) const;
  friend BigInteger operator%(int left, const BigInteger &second);
  friend BigInteger operator%(const char *left, const BigInteger &second);

  BigInteger &operator++();
  BigInteger const operator++(int);
  BigInteger const operator!();

  friend std::ostream &operator<<(std::ostream &os, const BigInteger &bi);

  friend bool operator>(const BigInteger &left, const BigInteger &right);
  friend bool operator<(const BigInteger &left, const BigInteger &right);
  friend bool operator==(const BigInteger &left, const BigInteger &right);
  friend bool operator>=(const BigInteger &left, const BigInteger &right);
  friend bool operator<=(const BigInteger &left, const BigInteger &right);
  friend bool operator!=(const BigInteger &left, const BigInteger &right);
};

typedef BigInteger b_int;

} // namespace Numerical
#endif //ALGORITHMS_NUMERICAL_BIG_INTEGER_H_
