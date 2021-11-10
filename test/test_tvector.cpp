#include "utmatrix.h"

#include <gtest.h>

TEST(Vector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(Vector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(Vector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(Vector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(Vector<int> v(5, -2));
}

TEST(Vector, can_create_copied_vector)
{
	Vector<int> v(10);

	ASSERT_NO_THROW(Vector<int> v1(v));
}

TEST(Vector, copied_vector_is_equal_to_source_one)
{
	Vector<int> v(10);
	Vector<int> v1(v);
	bool f = v == v1;
	ASSERT_EQ(f, 1);
}

TEST(Vector, copied_vector_has_its_own_memory)
{
	Vector<int> v(10);
	Vector<int> v1(v);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i;
	}
	bool f = v == v1;
	EXPECT_NE(f, 1);
}

TEST(Vector, can_get_size)
{
	Vector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(Vector, can_get_start_index)
{
	Vector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(Vector, can_set_and_get_element)
{
	Vector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(Vector, throws_when_set_element_with_negative_index)
{
	Vector<int> v(4);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(Vector, throws_when_set_element_with_too_large_index)
{
	Vector<int> v(4);
	ASSERT_ANY_THROW(v[5]);
}

TEST(Vector, can_assign_vector_to_itself)
{
	Vector<int> v(4);
	ASSERT_NO_THROW(v = v);
}

TEST(Vector, can_assign_vectors_of_equal_size)
{
	Vector<int> v(4);
	Vector<int> v1(4);
	ASSERT_NO_THROW(v = v1);
}

TEST(Vector, assign_operator_change_vector_size)
{
	Vector<int> v(4);
	Vector<int> v1(5);
	v = v1;
	EXPECT_EQ(v.GetSize(), v1.GetSize());
}

TEST(Vector, can_assign_vectors_of_different_size)
{
	Vector<int> v(4);
	Vector<int> v1(5);
	ASSERT_NO_THROW(v = v1);
	bool f = v == v1;
	EXPECT_EQ(f, 1);
}

TEST(Vector, compare_equal_vectors_return_true)
{
	Vector<int> v(4);
	Vector<int> v1(5);
	v = v1;
	EXPECT_TRUE(v == v1);
}

TEST(Vector, compare_vector_with_itself_return_true)
{
	Vector<int> v(4);
	EXPECT_TRUE(v == v);
}


TEST(Vector, vectors_with_different_size_are_not_equal)
{
	Vector<int> v(4);
	Vector<int> v1(5);
	EXPECT_FALSE(v == v1);
}

/*TEST(Vector, can_add_scalar_to_vector)
{

}*/

/*TEST(Vector, can_subtract_scalar_from_vector)
{

}*/

TEST(Vector, can_multiply_scalar_by_vector)
{
	Vector<int> v(4);
	for (int i = 0; i < 4; i++)
	{
		v[i] = i;
	}
	ASSERT_NO_THROW(v * 3);
}

TEST(Vector, can_add_vectors_with_equal_size)
{
	Vector<int> v(4);
	Vector<int> v1(4);
	ASSERT_NO_THROW(v + v1);
}

TEST(Vector, cant_add_vectors_with_not_equal_size)
{
	Vector<int> v(4);
	Vector<int> v1(5);
	ASSERT_ANY_THROW(v + v1);
}

TEST(Vector, can_subtract_vectors_with_equal_size)
{
	Vector<int> v(4);
	Vector<int> v1(4);
	ASSERT_NO_THROW(v - v1);
}

TEST(Vector, cant_subtract_vectors_with_not_equal_size)
{
	Vector<int> v(4);
	Vector<int> v1(5);
	ASSERT_ANY_THROW(v - v1);
}

TEST(Vector, can_multiply_vectors_with_equal_size)
{
	Vector<int> v(4);
	Vector<int> v1(4);
	ASSERT_NO_THROW(v * v1);
}

TEST(Vector, cant_multiply_vectors_with_not_equal_size)
{
	Vector<int> v(4);
	Vector<int> v1(5);
	ASSERT_ANY_THROW(v * v1);
}//f,d
