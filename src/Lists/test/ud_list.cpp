//
// Created by Alexander on 21.07.2019.
//

#include <gtest/gtest.h>

#include "Lists/ud_list.h"

using Lists::UDList;

class UDListFixture : public ::testing::Test {
 public:
  ~UDListFixture() override = default;

 protected:
  UDList<int> *udl_0;
  UDList<int> *udl_1;
  UDList<int> *udl_2;
  UDList<int> *udl_3;
  UDList<int> *udl_4;

  void TearDown() override {
    delete udl_0;
    delete udl_1;
    delete udl_2;
    delete udl_3;
    delete udl_4;
  }

  void SetUp() override {
    udl_0 = new UDList<int>();
    udl_1 = new UDList<int>();
    udl_2 = new UDList<int>();
    udl_3 = new UDList<int>();
    udl_4 = new UDList<int>();
  }
};

TEST_F(UDListFixture, size) {
  EXPECT_EQ(0, udl_0->size());
  udl_0->addAtBeginning(5);
  EXPECT_EQ(1, udl_0->size());
}

TEST_F(UDListFixture, addAtBeginning) {
  auto n0 = udl_1->addAtBeginning(5);
  auto n1 = udl_1->addAtBeginning(10);
  auto n2 = udl_1->addAtBeginning(15);

  EXPECT_EQ(15, n2->value_);
  EXPECT_EQ(n1, n2->next_);

  EXPECT_EQ(10, n1->value_);
  EXPECT_EQ(n0, n1->next_);

  EXPECT_EQ(5, n0->value_);
}

TEST_F(UDListFixture, deleteAfter) {
  udl_2->addAtBeginning(5);
  auto n1 = udl_2->addAtBeginning(10);

  udl_2->deleteAfter(n1);
  EXPECT_EQ(1, udl_2->size());
  EXPECT_THROW(udl_2->deleteAfter(n1), UDList<int>::UDListError);
}

TEST_F(UDListFixture, addAtEnd) {
  auto n0 = udl_3->addAtEnd(5);
  auto n1 = udl_3->addAtEnd(10);
  auto n2 = udl_3->addAtEnd(15);

  EXPECT_EQ(5, n0->value_);
  EXPECT_EQ(n1, n0->next_);

  EXPECT_EQ(10, n1->value_);
  EXPECT_EQ(n2, n1->next_);

  EXPECT_EQ(15, n2->value_);
}

TEST_F(UDListFixture, insertBefore) {
  auto n0 = udl_4->addAtEnd(5);
  auto n1 = udl_4->insertAfter(n0, 10);

  EXPECT_EQ(2, udl_4->size());
  EXPECT_EQ(n1, n0->next_);
}

TEST_F(UDListFixture, findNode) {
  auto n0 = udl_4->addAtEnd(15);

  EXPECT_EQ(n0, udl_4->findNode(15));
}
