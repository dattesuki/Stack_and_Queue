#include "stack_queue.h"
#include <gtest.h>
#include <vector>

TEST(Vector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(Vector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, can_get_size)
{
  Vector<int> v(4);

  EXPECT_EQ(0, v.size());
}

TEST(Vector, can_get_size2)
{
	Vector<int> v(4);
	v.push_back(5);
	EXPECT_EQ(1, v.size());
}

TEST(Vector, can_get_size3)
{
	Vector<int> v(16);
	for(size_t temp = 0; temp<10; ++temp) v.push_back(5);
	EXPECT_EQ(10, v.size());
}

TEST(Vector, can_get_size4)
{
	Vector<int> v(4);//проверка работоспособности перевыделения
	for (size_t temp = 0; temp < 10; ++temp) v.push_back(5);
	EXPECT_EQ(10, v.size());
}


TEST(Vector, throws_when_set_element_with_negative_index)
{
	Vector<int> v(10);
	ASSERT_ANY_THROW((v[-1] = 5));
}

TEST(Vector,check_index)
{
	Vector<int> v(10);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v[1] = 2;
    std::vector<int> v2; //= { 1,2,3 };
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
	EXPECT_EQ(v.GetVector(),v2);
}

TEST(Vector, check_push_back)
{
	Vector<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	EXPECT_EQ(v1.GetVector(), v2);
}

TEST(Vector, check_push_front)
{
	Vector<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push_front(2);
	v1.push_front(1);
	EXPECT_EQ(v1.GetVector(), v2);
}

TEST(Vector, check_pop)
{
	Vector<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.pop_back();
	v1.push_back(1);
	v1.pop_back();
	EXPECT_EQ(v1.GetVector(), v2);
}

TEST(Vector, check_throw1_pop)
{
	Vector<int> v;
	ASSERT_ANY_THROW(v.pop_back());
}

TEST(Vector, check_throw2_pop)
{
	Vector<int> v;
	ASSERT_ANY_THROW(v.pop_front());
}

TEST(Vector, check_throw1_get)
{
	Vector<int> v;
	ASSERT_ANY_THROW(v.front());
}

TEST(Vector, check_throw2_get)
{
	Vector<int> v;
	ASSERT_ANY_THROW(v.back());
}

TEST(Vector, check_get_front)
{
	Vector<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	EXPECT_EQ(v1.front(), v2.front());
}

TEST(Vector, check_get_back)
{
	Vector<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	EXPECT_EQ(v1.back(), v2.back());
}

TEST(Vector, check_insert)
{
	Vector<int> v1;
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v1.push_back(1);
	v1.push_back(3);
	v1.insert(2, 1);
	EXPECT_EQ(v1.GetVector(), v2);
}

TEST(Vector, check_throw_insert)
{
	Vector<int> v1;
	ASSERT_ANY_THROW(v1.insert(1, -1));
}
