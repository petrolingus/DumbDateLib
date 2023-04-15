#ifndef DUMBDATELIB_DUMB_DATE_H
#define DUMBDATELIB_DUMB_DATE_H

#include <string>

namespace dumbdate {

    const unsigned int OK = 0x00000001;
    const unsigned int NOT_DATE = 0x00000010;
    const unsigned int INCORRECT_FORMAT = 0x00000100;
    const unsigned int INCORRECT_DAY = 0x00001000;
    const unsigned int INCORRECT_MONTH = 0x00010000;
    const unsigned int INCORRECT_DELIMITER = 0x01000000;

    /**
     * Simple function that transforms a date into a text representation, adding three days to it.
     *
     * @param[in] date any date in the dd.mm format
     * @param[out] date_str adds three days to the `date` and returns a string representation of the new date
     * @return Execution error code.
     */
    int GetDatePlus3DaysStr(const std::string &date, std::string &date_str);
}

#endif //DUMBDATELIB_DUMB_DATE_H
