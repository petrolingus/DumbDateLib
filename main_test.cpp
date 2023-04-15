#include <gtest/gtest.h>
#include "dumb_date.h"

TEST(HelloTest, EmptyDate) {
    std::string date;
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, NotDate1) {
    std::string date = "aashdas";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, NotDate2) {
    std::string date = "asdas.asdsad";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, NotDate3) {
    std::string date = "aa.bb";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, NotDate4) {
    std::string date = "12.ff";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, NotDate5) {
    std::string date = "sa.21";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, NotDate6) {
    std::string date = "aacbb";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, ValidDate) {
    std::string date = "01.04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, "четвертое апреля");
    EXPECT_EQ(code, dumbdate::OK);
}

TEST(HelloTest, ValidDate2) {
    std::string date = "01.04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, u8"четвертое апреля") << date;
    EXPECT_EQ(code, dumbdate::OK);
}

TEST(HelloTest, IncorrectDay) {
    std::string date = "31.02";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_DAY);
}

TEST(HelloTest, IncorrectMonth) {
    std::string date = "13.14";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_MONTH);
}

TEST(HelloTest, IncorrectDayFormat) {
    std::string date = "1.04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_FORMAT);
}

TEST(HelloTest, IncorrectMonthFormat) {
    std::string date = "01.4";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_FORMAT);
}

TEST(HelloTest, Stress1) {
    std::string date = "-2.02";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, Stress2) {
    std::string date = "+2.02";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, Stress3) {
    std::string date = "*2.02";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, Stress4) {
    std::string date = "12.+2";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, Stress5) {
    std::string date = "12.-2";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(HelloTest, NextMonth) {
    std::string date = "29.02";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, "третье марта");
    EXPECT_EQ(code, dumbdate::OK);
}

TEST(HelloTest, LastDayAndMonth) {
    std::string date = "31.12";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, "третье января");
    EXPECT_EQ(code, dumbdate::OK);
}

TEST(HelloTest, IncorrectDelimiter) {
    std::string date = "01/04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_DELIMITER);
}