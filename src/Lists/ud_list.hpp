//
// Created by Aleskander on 18.06.2019.
//

namespace Lists {

template<typename T>
UDList<T>::UDList(): count_nodes(0) {
  top_ = new UDNode<T>();
}
template<typename T>
UDList<T>::~UDList() {
  auto current_node = top_->next_;
  UDNode<T> *next_node;

  while (current_node != nullptr) {
    next_node = current_node->next_;
    delete current_node;
    current_node = next_node;
  }

  delete top_;
  count_nodes = 0;
}
template<typename T>
UDNode<T> *UDList<T>::addAtBeginning(T value) {
  auto new_node = new UDNode<T>(value);
  new_node->next_ = top_->next_;
  top_->next_ = new_node;
  ++count_nodes;

  return new_node;
}
template<typename T>
UDNode<T> *UDList<T>::addAtEnd(T value) {
  auto last_node = top_;
  while (last_node->next_ != nullptr) {
    last_node = last_node->next_;
  }

  last_node->next_ = new UDNode<T>(value);
  ++count_nodes;

  return last_node->next_;
}
template<typename T>
UDNode<T> *UDList<T>::insertAfter(UDNode<T> *after, T value) {
  auto new_node = new UDNode<T>(value, after->next_);
  after->next_ = new_node;
  ++count_nodes;

  return new_node;
}
template<typename T>
void UDList<T>::deleteAfter(UDNode<T> *after) {
  if (count_nodes < 2) {
    throw UDListError("Count of nodes must be min 2");
  }

  auto del_node = after->next_;
  after->next_ = del_node->next_;
  delete del_node;
  --count_nodes;
}
template<typename T>
UDNode<T> *UDList<T>::findNode(T target) const {
  auto current_node = top_;

  while (current_node->next_ != nullptr) {
    if (current_node->next_->value_ == target) return current_node->next_;
    current_node = current_node->next_;
  }

  return nullptr;
}
template<typename T>
unsigned int UDList<T>::size() const {
  return count_nodes;
}

}
