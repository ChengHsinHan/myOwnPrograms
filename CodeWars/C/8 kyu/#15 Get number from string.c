// Write a function which removes from string all non-digit characters and parse
// the remaining to number. E.g: "hell5o wor6ld" -> 56
//
// Function:
//
// getNumberFromString(s)

int get_number_from_string(const char* src)
{
    int number = 0;
    for (const char* charPtr = src; *charPtr; ++charPtr)
        if ((*charPtr >= '0') && (*charPtr <= '9'))
            number = number * 10 + (*charPtr - '0');
    return number;
}
