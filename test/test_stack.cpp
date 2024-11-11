#include "stack_queue.h"
#include <gtest.h>
#include <vector>
#include <stack>

TEST(Stack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(Stack<int> v(5));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(Stack<int> v(-5));
}

TEST(Stack, can_get_size)
{
  Stack<int> v(4);

  EXPECT_EQ(0, v.size());
}

TEST(Stack, can_get_size2)
{
	Stack<int> v(4);
	v.push_back(5);
	EXPECT_EQ(1, v.size());
}

TEST(Stack, can_get_size3)
{
	Stack<int> v(16);
	for(size_t temp = 0; temp<10; ++temp) v.push_back(5);
	EXPECT_EQ(10, v.size());
}

TEST(Stack, can_get_size4)
{
	Stack<int> v(4);//проверка работоспособности перевыделения
	for (size_t temp = 0; temp < 10; ++temp) v.push_back(5);
	EXPECT_EQ(10, v.size());
}


TEST(Stack, check_push)
{
	Stack<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push(1);
	v1.push(2);
	EXPECT_EQ(v1.GetVector(), v2);
}


TEST(Stack, check_pop)
{
	Stack<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.pop_back();
	v2.push_back(2);
	v1.push(1);
	v1.pop();
	v1.push(2);
	EXPECT_EQ(v1.GetVector(), v2);
}

TEST(Stack, check_throw1_pop)
{
	Stack<int> v;
	ASSERT_ANY_THROW(v.pop_back());
}


TEST(Stack, check_throw2_get)
{
	Stack<int> v;
	ASSERT_ANY_THROW(v.back());
}


TEST(Stack, check_get_back)
{
	Stack<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	EXPECT_EQ(v1.get(), v2.back());
}

TEST(Stack, hard_test) {
	Stack<float> s1;
	std::stack<float> s2;
	for (size_t i = 0; i < 1000; ++i) {
		s1.push(float(i) / 10);
		s2.push(float(i) / 10);
	}
	for (size_t i = 0; i < 100; ++i) {
		s1.pop();
		s2.pop();
	}
	for (size_t i = 0; i < 2000; ++i) {
		s1.push(float(i) / 10);
		s2.push(float(i) / 10);
	}
	bool flag = 1;
	for (size_t i = 0; i < s2.size(); ++i) {
		flag &= (s1.back() == s2.top());
		s1.pop();
		s2.pop();
	}
	flag &= (s1.IsEmpty() == s2.empty());
	EXPECT_EQ(flag, 1);
}