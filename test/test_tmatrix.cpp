#include "utmatrix.h"

#include <gtest.h>

//f,d
TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> s(5);
	TMatrix<int> a(s);
	EXPECT_EQ(a, s);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> s(5);
	TMatrix<int> a(s);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			a[i][j] = i * 10 + j;
		}

	bool f = a != s;

	EXPECT_EQ(f, 1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> s(5);
	EXPECT_EQ(s.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> a(5);
	a[0][0] = 1;
	EXPECT_EQ(1, a[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> a(5);
	a[0][0] = 1;
	EXPECT_ANY_THROW(a[-1][-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(5);
	EXPECT_ANY_THROW(a[6][6] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> a(5);
	ASSERT_NO_THROW(a = a);

}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> s(5);
	TMatrix<int> a(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			a[i][j] = i * 10 + j;
		}
	ASSERT_NO_THROW(s = a);
	EXPECT_EQ(a, s);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> s(4);
	TMatrix<int> a(5);
	s = a;
	EXPECT_EQ(a, s);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> s(5);
	TMatrix<int> a(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			a[i][j] = i * 10 + j;
		}
	s = a;
	EXPECT_EQ(a, s);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> s(5);
	TMatrix<int> a(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			a[i][j] = i * 10 + j;
		}
	s = a;
	EXPECT_TRUE(a == s);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			a[i][j] = i * 10 + j;
		}
	EXPECT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> a(3), s(4);
	EXPECT_TRUE(a != s);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> s(5);
	TMatrix<int> res(5);
	TMatrix<int> a(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			a[i][j] = i * 10 + j;
			s[i][j] = i * 10 + j + 1;
			res[i][j] = a[i][j] + s[i][j];
		}
	EXPECT_EQ(res, a + s);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a(5);
	TMatrix<int> s(4);
	EXPECT_ANY_THROW(a + s);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a(5);
	TMatrix<int> s(5);
	TMatrix<int> res(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			a[i][j] = i * 10 + j;
			s[i][j] = i * 10 + j + 1;
			res[i][j] = a[i][j] - s[i][j];
		}
	EXPECT_EQ(res, a - s);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(5);
	TMatrix<int> s(4);
	EXPECT_ANY_THROW(a - s);
}
TEST(TMatrix, can_create_matrix)
{
	ASSERT_NO_THROW(TMatrix<int> a);
}
TEST(TMatrix, can_use_constructor_preobrazovaniya_tipa)
{
	TMatrix<int> s(5);
	Vector<Vector<int>> a;
	ASSERT_NO_THROW(a = s);
}

