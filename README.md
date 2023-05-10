# Dumb Date Lib

A very simple and silly library consisting of a single function that transforms
a date into a text representation, adding three days to it.

## Function signature

```c++
int dumbdate::GetDatePlus3DaysStr(const std::string &date, std::string &date_str);
```

## Description of code errors

* `OK` - Everything was completed without errors
* `NOT_DATE` - The string passed is not a date
* `INCORRECT_DAY` - The given day does not exist
* `INCORRECT_MONTH` - The given month does not exist
* `INCORRECT_DELIMITER` - The specified separator does not match the format

## Types of Separator

You **cannot** enter a backslash (/), a dash (-), a period (.) or a B (or b), which indicates an empty space, for
a delimiter character. Only the comma (,) is supported.