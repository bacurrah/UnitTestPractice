/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, empty_string)
{
	Password password;
	int result = password.count_leading_characters("");
	ASSERT_EQ(0, result);
}

TEST(PasswordTest, single_letter)
{
	Password password;
	int result = password.count_leading_characters("a");
	ASSERT_EQ(1, result);
}

TEST(PasswordTest, single_letter_stop)
{
	Password password;
	int result = password.count_leading_characters("ab");
	ASSERT_EQ(1, result);
}

TEST(PasswordTest, double_letter)
{
	Password password;
	int result = password.count_leading_characters("aa");
	ASSERT_EQ(2, result);
}

TEST(PasswordTest, double_letter_stop)
{
	Password password;
	int result = password.count_leading_characters("aab");
	ASSERT_EQ(2, result);
}

TEST(PasswordTest, mixed_case)
{
	Password password;
	int result = password.count_leading_characters("aA");
	ASSERT_EQ(1, result);
}

TEST(PasswordTest, non_contiguous)
{
	Password password;
	int result = password.count_leading_characters("aba");
	ASSERT_EQ(1, result);
}

TEST(PasswordTest, escape_character)
{
	Password password;
	int result = password.count_leading_characters("\n\n");
	ASSERT_EQ(2, result);
}
