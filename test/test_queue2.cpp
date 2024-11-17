#include "stack_queue.h"
#include <gtest.h>
#include <vector>
#include <queue>

TEST(Queue2, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Queue2<int> v(5));
}

TEST(Queue2, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Queue2<int> v(-5));
}

TEST(Queue2, can_get_size)
{
	Queue2<int> v(4);

	EXPECT_EQ(0, v.size());
}

TEST(Queue2, can_get_size2)
{
	Queue2<int> v(4);
	v.push_back(5);
	EXPECT_EQ(1, v.size());
}

TEST(Queue2, can_get_size3)
{
	Queue2<int> v(16);
	for (size_t temp = 0; temp < 10; ++temp) v.push_back(5);
	EXPECT_EQ(10, v.size());
}


TEST(Queue2, check_push)
{
	Queue2<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.enqueue(1);
	v1.enqueue(2);

	std::vector<int> temp;
	size_t size = v1.size();
	for (size_t i = 0; i < size; ++i) {
		temp.push_back(v1.get());
		v1.dequeue();
	}

	EXPECT_EQ(temp, v2);
}


TEST(Queue2, check_pop) {
	Queue2<int> v1;
	v1.enqueue(1);
	v1.enqueue(2);
	v1.dequeue();  
	v1.enqueue(3);
    std::vector<int> v2; //= {2,3 };
    v2.push_back(2);
    v2.push_back(3);

	std::vector<int> temp;
	size_t size = v1.size();
	for (size_t i = 0; i < size; ++i) {
		temp.push_back(v1.get());
		v1.dequeue();
	}

	EXPECT_EQ(temp, v2);  
}

TEST(Queue2, check_throw1_pop)
{
	Queue2<int> v;
	ASSERT_ANY_THROW(v.dequeue());
}


TEST(Queue2, check_throw2_get)
{
	Queue2<int> v;
	ASSERT_ANY_THROW(v.get());
}


TEST(Queue2, check_get_front)
{
	Queue2<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.enqueue(1);
	v1.enqueue(2);
	EXPECT_EQ(v1.get(), v2.front());
}

TEST(Queue2, soft_test) {
	Queue2<float> s1(10);
	std::queue<float> s2;
	for (int i = 0; i < 9; ++i) {
		s1.enqueue(i * 2.5);
		s2.push(i * 2.5);
	}
	bool flag = 1;
	for (int i = 0; i < 5; ++i) {
		s1.dequeue();
		s2.pop();
	}
	for (int i = 0; i < 3; ++i) {
		s1.enqueue(i * 2.5);
		s2.push(i * 2.5);
	}
	for (size_t i = 0; i < s2.size(); ++i) {
		flag &= (s1.get() == s2.front());
		s1.dequeue();
		s2.pop();
	}
	flag &= (s1.IsEmpty() == s2.empty());
	EXPECT_EQ(flag, 1);
}

TEST(Queue2, hard_test) {
	Queue2<float> s1(10000);
	std::queue<float> s2;
	for (size_t i = 0; i < 1000; ++i) {
		s1.enqueue(float(i) / 10);
		s2.push(float(i) / 10);
	}
	for (size_t i = 0; i < 100; ++i) {
		s1.dequeue();
		s2.pop();
	}
	for (size_t i = 0; i < 2000; ++i) {
		s1.enqueue(float(i) / 10);
		s2.push(float(i) / 10);
	}
	bool flag = 1;
	for (size_t i = 0; i < s2.size(); ++i) {
		flag &= (s1.get() == s2.front());
		//std::cout << s1.get() << " " << s2.front() << std::endl;
		s1.dequeue();
		s2.pop();
	}
	flag &= (s1.IsEmpty() == s2.empty());
	EXPECT_EQ(flag, 1);
}
