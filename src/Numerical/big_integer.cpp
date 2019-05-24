//
// Created by Alexander on 24.05.2019.
//

#include "big_integer.h"

#include <stdlib.h>
#include <iostream>
#include <algorithm>

namespace Numerical {

using std::cout;

BigInteger::BigInteger() : positive(true) {}
BigInteger::BigInteger(const std::string &number) : positive(true) {
  int i = 0;
  auto it = number.begin();

  if (*it == '-') {
    positive = false;
    it++;
  }

  while (it != number.end()) {
    auto ch = *it;
    number_.push_back(strtol(&ch, nullptr, 10));
    it++;
    i++;
  }
}
BigInteger::BigInteger(const b_int &bi) {
  positive = bi.positive;
  number_ = bi.number_;
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
b_int BigInteger::operator*(const b_int &second) const {
  b_int result(*this);

  result *= second;

  return result;
}
b_int &BigInteger::operator*=(const b_int &second) {
  b_int result;

  if (number_.empty() && !second.number_.empty()) {
    *this = second;
    return *this;
  } else if (!number_.empty() && second.number_.empty()) {
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

  // нельзя сделать тут отрицательным так как нет операции вычитания
  // result.positive = positive && second.positive;
  master.positive = true;
  slave.positive = true;

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

  *this = result;

  return *this;
}
b_int BigInteger::operator+(const b_int &second) const {
  b_int result(*this);

  result += second;

  return result;
}
b_int &BigInteger::operator+=(const b_int &second) {
  b_int result;
  auto general_size = number_.size() < second.number_.size() ? second.number_.size() : number_.size();

  b_int second_temp = second;
  std::reverse(number_.begin(), number_.end());
  std::reverse(second_temp.number_.begin(), second_temp.number_.end());

  auto main_it = number_.begin();
  auto main_end = number_.end();
  auto second_it = second_temp.number_.begin();
  auto second_end = second_temp.number_.end();

  if (!(positive ^ second.positive)) {
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
      second_temp.positive = true;
      result = *this - second_temp;
      *this = result;
    }
  }

  if (!positive && !second.positive) this->positive = false;

  return *this;
}
b_int BigInteger::operator-(const b_int &second) const {
  b_int result;

  result += *this;
  result -= second;

  return result;
}
b_int BigInteger::operator-=(const b_int &second) {
  b_int result;
  if (number_.empty() && second.number_.empty()) {
    return result;
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

  if (*this > second) {
    if (!master.positive && slave.positive) {
      master.positive = true;
      result = master + slave;
      result.positive = false;
      *this = result;
      return* this;
    }
  } else if (*this < second) {
    result.positive = false;
    master = second;
    slave = *this;
  } else {
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

  auto it = result.number_.begin();
  while (*it == 0) {
    result.number_.erase(it++);
  }

  *this = result;
  return *this;
}
bool operator>(const b_int &left, const b_int &right) {
  if (left.positive && !right.positive) {
    return true;
  }
  if (!left.positive && right.positive) {
    return false;
  }

  if (left.number_.empty() && right.number_.empty()) {
    std::cerr << "Operands is empty";
    exit(1);
  }

  auto left_size = left.number_.size();
  auto right_size = right.number_.size();
  if (left_size > right_size) {
    return true;
  }
  if (left_size < right_size) {
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
    return *left_it > *right_it;
  }

  return true;
}
bool operator<(const b_int &left, const b_int &right) {
  if (!left.positive && right.positive) {
    return true;
  }
  if (left.positive && !right.positive) {
    return false;
  }

  if (left.number_.empty() && right.number_.empty()) {
    std::cerr << "Operands is empty";
    exit(1);
  }

  auto left_size = left.number_.size();
  auto right_size = right.number_.size();
  if (left_size < right_size) {
    return true;
  }
  if (left_size > right_size) {
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
    return *left_it < *right_it;
  }

  return true;
}
bool operator==(const b_int &left, const b_int &right) {
  if ((!left.positive && right.positive) || (left.positive && !right.positive)) {
    return false;
  }

  if (left.number_.empty() && right.number_.empty()) {
    std::cerr << "Operands is empty";
    exit(1);
  }

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

} // namespace Numerical
