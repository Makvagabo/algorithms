//
// Created by Alexander on 24.05.2019.
//

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>

#include "Numerical/big_integer.h"

namespace Numerical {

using std::cout, std::vector;

b_int::BigInteger() : positive(true) {}
b_int::BigInteger(const std::string &number) : positive(true) {
  number_.clear();

  auto it = number.begin();

  if (*it == '-') {
    positive = false;
    it++;
  }

  while (it != number.end()) {
    auto temp = (int) *it - (int) 48;

    if (temp > 9 || temp < 0) {
      std::string message = "Error convert. Unexpected char: ";
      message.append(std::to_string(temp));
      throw BigIntegerError(message, __FILE__, __LINE__);
    }

    number_.push_back(temp);
    it++;
  }

  refresh(*this);
}
b_int::BigInteger(const char *number) : positive(true) {
  number_.clear();

  if (*number == '-') {
    positive = false;
  }

  int i = !positive;
  while (*(number + i) != '\0') {
    auto temp = (int) *(number + i) - (int) 48;

    if (temp > 9 || temp < 0) {
      std::string message = "Error convert. Unexpected char: ";
      message.append(std::to_string(temp));
      throw BigIntegerError(message, __FILE__, __LINE__);
    }

    number_.push_back(temp);
    i++;
  }

  refresh(*this);
}
b_int::BigInteger(int number) : positive(true) {
  number_.clear();

  auto number_str = std::to_string(number);
  auto it = number_str.begin();

  if (*it == '-') {
    positive = false;
    it++;
  }

  while (it != number_str.end()) {
    auto temp = (int) *it - (int) 48;

    if (temp > 9 || temp < 0) {
      std::string message = "Error convert. Unexpected char: ";
      message.append(std::to_string(temp));
      throw BigIntegerError(message, __FILE__, __LINE__);
    }

    number_.push_back(temp);
    it++;
  }
}
b_int::BigInteger(const b_int &bi) {
  positive = bi.positive;
  number_ = bi.number_;
}
b_int::BigInteger(const b_int &bi, unsigned int start, unsigned int end) {
  if (start >= bi.number_.size() || end >= bi.number_.size() || start > end) {
    throw BigIntegerError("Incorrect range slice", __FILE__, __LINE__);
  }

  positive = bi.positive;
  for (auto it = bi.number_.begin() + start; it != bi.number_.begin() + end; ++it) {
    number_.push_back(*it);
  }
}

std::string b_int::toString() const {
  std::string temp;

  if (!positive) {
    temp.append("-");
  }

  for (auto ch : number_) {
    temp.append(std::to_string(ch));
  }

  return temp;
}
void b_int::refresh(b_int &bi) {
  auto it = bi.number_.begin();
  while (*it == 0 && it != bi.number_.end()) {
    // !!! past bug was because iterator was incrementing
    bi.number_.erase(it);
  }
}
b_int b_int::division(const b_int &master, const b_int &slave, bool mod = false) {
  // на ноль делить нельзя и на пустоту
  if (slave.number_.empty() || slave == 0) {
    throw BigIntegerError("Divider can not be empty or zero.", __FILE__, __LINE__);
  }

  b_int result;
  if (master.number_.empty() || master == 0) {
    result = 0;
    return result;
  }

  // делить только большее или равное по размеру и величине с делителем число
  auto dividend_size = master.number_.size();
  auto divider_size = slave.number_.size();
  if (dividend_size <= divider_size) {
    if (mod) {
      result = master;
      result.positive = true;
      return result;
    }
    if (((master.positive && slave.positive) && (master < slave)) ||
        ((!master.positive && !slave.positive) && (master > slave))
        ) {
      result = 0;
      return result;
    }
  }

  b_int master_(master); master_.positive = true;
  b_int slave_(slave); slave_.positive = true;

  // минимальная разделяемая часть по количеству знаков будет как делитель
  auto dividend_part = b_int(master_, 0, divider_size);
  auto dividend_it = master_.number_.begin() + divider_size;
  // повторяем пока итератор не равен конечному итератору
  while (dividend_it != master_.number_.end()) {
    // если делимая часть меньше чем делитель и следующий знак есть, добираем
    bool add_zero = false;
    while (dividend_part < slave_) {
      // если увеличиваем размер делимой части больше чем на одну цифру
      if (add_zero && !mod) result.number_.push_back(0);

      if (dividend_it != master_.number_.end()) {
        dividend_part.number_.push_back(*dividend_it);
        // смещаем указатель итератор на количество делимых знаков
        dividend_it++;
        add_zero = true;
        refresh(dividend_part);
      } else {
        break;
      }
    }
    if (dividend_part < slave_) {
      break;
    }
    // производим деление
    // находим максимальный множитель, произведение которого с делителем не превышало делимую часть
    int max_multiplier = 1;
    while (slave_ * (max_multiplier + 1) < dividend_part) {
      max_multiplier++;
    }
    // записываем множитель в результат
    if (!mod) result.number_.push_back(max_multiplier);
    // находим остаток
    dividend_part -= slave_ * max_multiplier;
  }
  // возвращаем результат
  refresh(dividend_part);
  result.positive = !(master.positive ^ slave.positive);
  return mod ? dividend_part : result;
}

std::ostream &operator<<(std::ostream &os, const b_int &bi) {
  if (bi.number_.empty()) {
    cout << '0';
  } else {
    if (!bi.positive) cout << '-';
    for (auto digit : bi.number_) {
      cout << digit;
    }
  }
  return os;
}

b_int &b_int::operator*=(const b_int &second) {
  if (this->number_.empty() || second.number_.empty()) {
    throw BigIntegerError("Error operation multiplication. One or more operands is empty.", __FILE__, __LINE__);
  }

  b_int result;

  if (*this == 0 || second == 0) {
    *this = result;
    return *this;
  }

  b_int master, slave;
  if (number_.size() < second.number_.size()) {
    master = *this;
    slave = second;
  } else {
    master = second;
    slave = *this;
  }

  std::reverse(master.number_.begin(), master.number_.end());
  std::reverse(slave.number_.begin(), slave.number_.end());

  int i = 0;
  for (int &master_it : master.number_) {
    b_int addend;
    int count_base = 0;
    for (int &slave_it : slave.number_) {
      int interim = master_it * slave_it + count_base;

      if (interim >= BASE) {
        int remainder = interim % BASE;
        count_base = (interim - remainder) / BASE;
        interim = remainder;
      } else if (count_base) {
        count_base = 0;
      }

      addend.number_.push_back(interim);
    }

    if (count_base) addend.number_.push_back(count_base);

    std::reverse(addend.number_.begin(), addend.number_.end());

    for (int j = 0; j < i; ++j) {
      addend.number_.push_back(0);
    }

    result += addend;
    i++;
  }

  result.positive = !(positive ^ second.positive);
  *this = result;

  return *this;
}
b_int b_int::operator*(const b_int &second) const {
  if (this->number_.empty() || second.number_.empty()) {
    throw BigIntegerError("Error operation multiplication. One or more operands is empty.", __FILE__, __LINE__);
  }

  b_int result;
  if (*this == 0 || second == 0) {
    return result;
  }

  result = *this;
  result *= second;

  return result;
}
b_int operator*(int left, const BigInteger &second) {
  b_int result = left;
  result *= second;

  return result;
}
b_int operator*(const char *left, const BigInteger &second) {
  b_int result = left;
  result *= second;

  return result;
}

b_int &b_int::operator+=(const b_int &second) {
  if (*this == 0) {
    *this = second;
    return *this;
  }

  if (second == 0) {
    return *this;
  }

  b_int result;
  auto general_size = number_.size() < second.number_.size() ? second.number_.size() : number_.size();

  if (!(positive ^ second.positive)) {
    b_int second_temp = second;

    std::reverse(number_.begin(), number_.end());
    std::reverse(second_temp.number_.begin(), second_temp.number_.end());

    auto main_it = number_.begin();
    auto main_end = number_.end();
    auto second_it = second_temp.number_.begin();
    auto second_end = second_temp.number_.end();

    bool add_base = false;
    for (int i = 0; i < general_size; i++) {
      int interim = add_base;

      if (main_it != main_end) {
        interim += *main_it;
        main_it++;
      }

      if (second_it != second_end) {
        interim += *second_it;
        second_it++;
      }

      if (interim >= BASE) {
        interim -= BASE;
        add_base = true;
      } else if (add_base) {
        add_base = false;
      }

      if (number_.size() > i) {
        number_[i] = interim;
      } else {
        number_.push_back(interim);
      }
    }

    if (add_base) number_.push_back(add_base);

    std::reverse(number_.begin(), number_.end());

    return *this;
  } else {
    if (positive) {
      b_int second_temp = second;
      second_temp.positive = true;

      result = *this - second_temp;
    } else {
      b_int second_temp = *this;
      second_temp.positive = true;

      result = second_temp - second;
      result.positive = false;
    }
    *this = result;
  }

  if (!positive && !second.positive) positive = false;

  return *this;
}
b_int b_int::operator+(const b_int &second) const {
  b_int result;

  if (*this == 0) {
    result = second;
    return result;
  }

  if (second == 0) {
    result = *this;
    return result;
  }

  result = *this;
  result += second;

  return result;
}
b_int operator+(int left, const BigInteger &second) {
  b_int result = left;
  result += second;

  return result;
}
b_int operator+(const char *left, const BigInteger &second) {
  b_int result = left;
  result += second;

  return result;
}

b_int &b_int::operator-=(const b_int &second) {
  if (*this == 0) {
    *this = second;
    return *this;
  }

  if (second == 0) {
    return *this;
  }

  b_int result;
  if (number_.empty() && second.number_.empty()) {
    return *this;
  }

  if (*this == second) {
    *this = result;
    return *this;
  }

  b_int master, slave;
  int general_size;

  if (number_.size() < second.number_.size()) {
    general_size = second.number_.size();
    master = second;
    slave = *this;
  } else {
    general_size = number_.size();
    master = *this;
    slave = second;
  }

  if (master.positive && !slave.positive) {
    slave = !slave;
    result = master + slave;
    *this = result;
    return *this;
  }

  if (!master.positive && !slave.positive) {
    master = !master;
    slave = !slave;
    result = master + slave;
    result = !result;
    *this = result;
    return *this;
  }

  std::reverse(master.number_.begin(), master.number_.end());
  std::reverse(slave.number_.begin(), slave.number_.end());

  auto master_it = master.number_.begin();
  auto master_end = master.number_.end();
  auto slave_it = slave.number_.begin();
  auto slave_end = slave.number_.end();

  bool sub_base = false;
  for (int i = 0; i < general_size; i++) {
    int interim = -sub_base;

    if (master_it != master_end) {
      interim += *master_it;
      master_it++;
    }

    if (slave_it != slave_end) {
      interim -= *slave_it;
      slave_it++;
    }

    if (interim < 0) {
      interim += BASE;
      sub_base = true;
    } else if (sub_base) {
      sub_base = false;
    }

    result.number_.push_back(interim);
  }

  std::reverse(result.number_.begin(), result.number_.end());

  refresh(result);

  if (!master.positive) {
    result = !result;
  }

  *this = result;
  return *this;
}
b_int b_int::operator-(const b_int &second) const {
  b_int result;

  if (*this == 0) {
    result = second;
    return result;
  }

  if (second == 0) {
    result = *this;
    return result;
  }

  result = *this;
  result -= second;

  return result;
}
b_int operator-(int left, const BigInteger &second) {
  b_int result = left;
  result -= second;

  return result;
}
b_int operator-(const char *left, const BigInteger &second) {
  b_int result = left;
  result -= second;

  return result;
}

b_int &b_int::operator/=(const b_int &second) {
  *this = division(*this, second);
  return *this;
}
b_int b_int::operator/(const b_int &second) const {
  return division(*this, second);
}
b_int operator/(int left, const BigInteger &second) {
  b_int result = left;
  result /= second;

  return result;
}
b_int operator/(const char *left, const BigInteger &second) {
  b_int result = left;
  result /= second;

  return result;
}

b_int &b_int::operator%=(const b_int &second) {
  *this = division(*this, second, true);
  return *this;
}
b_int b_int::operator%(const b_int &second) const {
  return division(*this, second, true);
}
b_int operator%(int left, const BigInteger &second) {
  b_int temp = left;

  return BigInteger::division(temp, second, true);
}
b_int operator%(const char *left, const BigInteger &second) {
  b_int temp = left;

  return BigInteger::division(temp, second, true);
}

bool operator>(const b_int &left, const b_int &right) {
  if ((left.number_.empty() && right.number_.empty()) ||
      (left.number_.empty() && !right.number_.empty()) ||
      (!left.positive && right.positive)
      ) {
    return false;
  }
  if ((!left.number_.empty() && right.number_.empty()) || (left.positive && !right.positive)) {
    return true;
  }

  bool result = true;

  auto left_size = left.number_.size();
  auto right_size = right.number_.size();
  if (left_size > right_size) {
    result = true;
  } else if (left_size < right_size) {
    result = false;
  } else {
    auto left_it = left.number_.begin();
    auto left_end = left.number_.end();
    auto right_it = right.number_.begin();
    while (left_it != left_end) {
      if (*left_it == *right_it) {
        left_it++;
        right_it++;
        continue;
      }
      result = *left_it > *right_it;
      break;
    }
  }

  return (!left.positive && !right.positive) == !result;
}
bool operator<(const b_int &left, const b_int &right) {
  return !(left > right) || left == right;
}
bool operator==(const b_int &left, const b_int &right) {
  if (left.number_.empty() && !right.number_.empty()) {
    b_int temp = 0;
    return temp == right;
  }

  if (!left.number_.empty() && right.number_.empty()) {
    b_int temp = 0;
    return left == temp;
  }

  if ((left.positive ^ right.positive)) {
    return false;
  }

  if (left.number_.empty() && right.number_.empty()) return true;

  if (left.number_.size() != right.number_.size()) {
    return false;
  }

  auto left_it = left.number_.begin();
  auto left_end = left.number_.end();
  auto right_it = right.number_.begin();
  while (left_it != left_end) {
    if (*left_it == *right_it) {
      left_it++;
      right_it++;
      continue;
    }
    return false;
  }

  return true;
}
bool operator>=(const b_int &left, const b_int &right) {
  return left > right && left == right;
}
bool operator<=(const b_int &left, const b_int &right) {
  return left < right && left == right;
}
bool operator!=(const b_int &left, const b_int &right) {
  return !(left == right);
}

b_int const b_int::operator!() {
  b_int temp(*this);
  temp.positive = !positive;
  return temp;
}
b_int &b_int::operator++() {
  *this += 1;
  return *this;
}
b_int const b_int::operator++(int) {
  b_int temp(*this);
  operator++();
  return temp;
}
} // namespace Numerical
