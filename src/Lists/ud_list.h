//
// Created by Aleskander on 18.06.2019.
//

#ifndef ALGORITHMS_LISTS_UD_LIST_H_
#define ALGORITHMS_LISTS_UD_LIST_H_

#include <string>

namespace Lists {

template<typename T>
struct UDNode;

template<typename T>
class UDList;

template<typename T>
struct UDNode {
  T value_;
  UDNode *next_;
 public:
  friend class UDList<T>;
  explicit UDNode() : value_(), next_(nullptr) {}
  explicit UDNode(T value) : value_(value), next_(nullptr) {}
  explicit UDNode(T value, UDNode<T> *next) : value_(value), next_(next) {}
};

template<typename T>
class UDList {
  UDNode<T> *top_;
  unsigned int count_nodes;
 public:
  explicit UDList();
  ~UDList();
  class UDListError {
   public:
    std::string message_;
    explicit UDListError() : message_("Unexpected error!") {}
    explicit UDListError(const char *m) : message_(m) {}
  };
  [[nodiscard]] unsigned int size() const;
  UDNode<T> *addAtBeginning(T value);
  UDNode<T> *addAtEnd(T value);
  UDNode<T> *insertAfter(UDNode<T> *after, T value);
  void deleteAfter(UDNode<T> *after);
  UDNode<T> *findNode(T target) const;
};

} // namespace Lists

#include "ud_list.hpp"

#endif // ALGORITHMS_LISTS_UD_LIST_H_
