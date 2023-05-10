# Dumb Date Lib

A very simple and silly library consisting of a single function that transforms
a date into a text representation, adding three days to it.

> **_NOTE:_** February 29 is also accepted!

## Function signature

```c++
/**
 * Simple function that transforms a date into a text representation, adding three days to it.
 *
 * @param[in] date any date in the dd.mm format
 * @param[out] date_str adds three days to the `date` and returns a string representation of the new date
 * @return Execution error code.
 */
int dumbdate::GetDatePlus3DaysStr(const std::string &date, std::string &date_str);
```

> **_NOTE:_** The returned date text is in Russian in UTF-8 encoding.

## Description of code errors

* `OK` - Everything was completed without errors
* `NOT_DATE` - The specified string does not match the date format
* `INCORRECT_DAY` - The given day does not exist
* `INCORRECT_MONTH` - The given month does not exist
* `INCORRECT_DELIMITER` - The specified separator does not match the format

## Types of Separator

You **cannot** enter a backslash (/), a dash (-), a period (.) or a B (or b), which indicates an empty space, for
a delimiter character. Only the comma (,) is supported.