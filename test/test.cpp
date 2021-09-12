#include "../src/draw.h"
#include "../src/filework.h"
#include "../src/misstake.h"
#include "gtest/gtest.h"

int misse = 0;
int missm = 0;
int missh = 0;
int endg = 0;

TEST(FileworkTest, MissingFile)
{
    int result = file_check(
            "files/wrong.txt", "files/wrong.txt", "files/wrong.txt");
    int expected = -1;
    EXPECT_EQ(expected, result);
}

TEST(FileworkTest, EmptyFile)
{
    int result = file_check(
            "files/empty.txt", "files/word2.txt", "files/word3.txt");
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(FileworkTest, FileCheckPassed)
{
    int num = file_check(
            "files/word1.txt", "files/word2.txt", "files/word3.txt");
    int result = 0;
    if (num > 0) {
        result = 1;
    }
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, WrongDifficulty)
{
    char* buf;
    int result = 0;
    result = setdificulty(0, &buf);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, EasyDifficulty)
{
    char* buf;
    int result = 0;
    result = setdificulty(1, &buf);
    int expected = 10;
    EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, NormalDifficulty)
{
    char* buf;
    int result = 0;
    result = setdificulty(2, &buf);
    int expected = 5;
    EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, HardDifficulty)
{
    char* buf;
    int result = 0;
    result = setdificulty(3, &buf);
    int expected = 3;
    EXPECT_EQ(expected, result);
}

TEST(MisstakeTest, ExistLetter)
{
    char buf[5] = "test";
    char enter[5] = "t__t";
    int result = 0;
    result = misstake(buf, enter, 0, 5);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(MisstakeTest, NonExistLetter)
{
    char buf[5] = "test";
    char enter[5] = "____";
    int result = 0;
    result = misstake(buf, enter, 3, 4);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(MisstakeTest, EndGame)
{
    char buf[5] = "test";
    char enter[5] = "te_t";
    int result = 0;
    endg = 3;
    result = misstake(buf, enter, 2, 4);
    int expected = 2;
    EXPECT_EQ(expected, result);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
