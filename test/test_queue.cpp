#include "stack_queue.h"
#include <gtest.h>
#include <vector>
#include <queue>

TEST(Queue, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> v(5));
}

TEST(Queue, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> v(-5));
}

TEST(Queue, can_get_size)
{
	Queue<int> v(4);

	EXPECT_EQ(0, v.size());
}

TEST(Queue, can_get_size2)
{
	Queue<int> v(4);
	v.push_back(5);
	EXPECT_EQ(1, v.size());
}

TEST(Queue, can_get_size3)
{
	Queue<int> v(16);
	for (size_t temp = 0; temp < 10; ++temp) v.push_back(5);
	EXPECT_EQ(10, v.size());
}


TEST(Queue, check_push)
{
	Queue<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	EXPECT_EQ(v1.GetVector(), v2);
}


TEST(Queue, check_pop)
{
	Queue<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.pop_back();
	v2.push_back(2);
	v1.push_back(2);
	v1.pop_front();
	v1.push_back(1);
	EXPECT_EQ(v1.GetVector(), v2);
}

TEST(Queue, check_throw1_pop)
{
	Queue<int> v;
	ASSERT_ANY_THROW(v.pop_front());
}


TEST(Queue, check_throw2_get)
{
	Queue<int> v;
	ASSERT_ANY_THROW(v.get());
}


TEST(Queue, check_get_front)
{
	Queue<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	EXPECT_EQ(v1.get(), v2.front());
}

TEST(Queue, soft_test) {
	Queue<float> s1(10);
	std::queue<float> s2;
	for (int i = 0; i < 9; ++i) {
		s1.push_back(i * 2.5);
		s2.push(i * 2.5);
	}
	//start = 0
	//end = 9
	bool flag = 1;
	for (int i = 0; i < 5; ++i) {
		s1.pop_front();
		s2.pop();
	}
	//start = 5
	//end = 9;
	for (int i = 0; i < 3; ++i) {
		s1.push_back(i * 2.5);
		s2.push(i * 2.5);
	}
	//start = 5
	//end = 2
	for (size_t i = 0; i < s2.size(); ++i) {
		flag &= (s1.get() == s2.front());
		s1.pop_front();
		s2.pop();
	}
	flag &= (s1.IsEmpty() == s2.empty());
	EXPECT_EQ(flag, 1);
}

TEST(Queue, hard_test) {
	Queue<float> s1(10000);
	std::queue<float> s2;
	for (size_t i = 0; i < 1000; ++i) {
		s1.push_back(float(i) / 10);
		s2.push(float(i) / 10);
	}
	for (size_t i = 0; i < 100; ++i) {
		s1.pop_front();
		s2.pop();
	}
	for (size_t i = 0; i < 2000; ++i) {
		s1.push_back(float(i) / 10);
		s2.push(float(i) / 10);
	}
	bool flag = 1;
	for (size_t i = 0; i < s2.size(); ++i) {
		flag &= (s1.get() == s2.front());
		//std::cout << s1.get() << " " << s2.front() << std::endl;
		s1.pop_front();
		s2.pop();
	}
	flag &= (s1.IsEmpty() == s2.empty());
	EXPECT_EQ(flag, 1);
}
