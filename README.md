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
* `INCORRECT_FORMAT` - Incorrect date format (i.e. the format dd.mm is not followed)
* `INCORRECT_DAY` - The given day does not exist
* `INCORRECT_MONTH` - The given month does not exist
* `INCORRECT_DELIMITER` - The specified separator does not match the format