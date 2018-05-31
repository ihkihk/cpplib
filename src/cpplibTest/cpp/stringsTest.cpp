
#include "gtest/gtest.h"
#include "strings.h"
#include <vector>
#include <string>

using namespace std;

TEST(TokenizeTest, EmptySource)
{
    using cpplib::tokenize;

    vector<string> vec;
    tokenize<vector<string> >(string(""), vec, string(":"));
    EXPECT_EQ(vec.size(), 0);
}

TEST(TokenizeTest, EmptyDelimiter)
{
    using cpplib::tokenize;

    vector<string> vec;
    tokenize<vector<string> >(string("abc:def"), vec, string(""));
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], "abc:def");
}

TEST(TokenizeTest, EmptySourceEmptyDelimiter)
{
    using cpplib::tokenize;

    vector<string> vec;
    tokenize<vector<string> >(string(""), vec, string(""));
    EXPECT_EQ(vec.size(), 0);
}

TEST(TokenizeTest, SingleRepeatingDelimiter)
{
    using cpplib::tokenize;

    vector<string> vec;
    tokenize<vector<string> >(string("a::i:::c:"), vec, string(":"), false, false);

    EXPECT_EQ(vec.size(), 6);
    EXPECT_EQ(vec[0], "a");
    EXPECT_EQ(vec[1], "");
    EXPECT_EQ(vec[2], "i");
    EXPECT_EQ(vec[3], "");
    EXPECT_EQ(vec[4], "");
    EXPECT_EQ(vec[5], "c");
}

TEST(TokenizeTest, SingleRepeatingDelimiterTrimEmpty)
{
    using cpplib::tokenize;

    vector<string> vec;
    tokenize<vector<string> >(string("a::i:::c:"), vec, string(":"), false, true);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], "a");
    EXPECT_EQ(vec[1], "i");
    EXPECT_EQ(vec[2], "c");
}

TEST(TokenizeTest, MultipleDelimiterTrimEmpty)
{
    using cpplib::tokenize;

    vector<string> vec;
    tokenize<vector<string> >(string("a::i:::c:d,e,f,"), vec, string(":,"), false, true);

    EXPECT_EQ(vec.size(), 6);
    EXPECT_EQ(vec[0], "a");
    EXPECT_EQ(vec[1], "i");
    EXPECT_EQ(vec[2], "c");
    EXPECT_EQ(vec[3], "d");
    EXPECT_EQ(vec[4], "e");
    EXPECT_EQ(vec[5], "f");
}

TEST(TokenizeTest, MultipleDelimiterTrimEmpty_NoDelimAtEnd)
{
    using cpplib::tokenize;

    vector<string> vec;
    tokenize<vector<string> >(string("a::i:::c:d,e,f"), vec, string(":,"), false, true);

    EXPECT_EQ(vec.size(), 6);
    EXPECT_EQ(vec[0], "a");
    EXPECT_EQ(vec[1], "i");
    EXPECT_EQ(vec[2], "c");
    EXPECT_EQ(vec[3], "d");
    EXPECT_EQ(vec[4], "e");
    EXPECT_EQ(vec[5], "f");
}

using namespace testing;

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}