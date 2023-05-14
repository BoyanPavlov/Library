#include "pch.h"
#include "../Library/MyString.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(MyStringTest, DefaultConstructorTest) {
	MyString str;
	EXPECT_TRUE(str.empty());
	EXPECT_EQ(str.size(), 0);
}

TEST(MyStringTest, CopyConstructorTest) {
	MyString str("hello world");
	MyString copy(str);
	EXPECT_EQ(copy, str);
}