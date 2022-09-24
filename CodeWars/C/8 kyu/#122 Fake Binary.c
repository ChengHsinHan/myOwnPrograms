// Given a string of digits, you should replace any digit below 5 with '0' and
// any digit 5 and above with '1'. Return the resulting string.
//
// Note: input will never be an empty string

void fakeBin(const char* digits, char* buffer)
{
    // Please place result in the memory pointed to by
    // the buffer parameter. Buffer has enough memory to
    // accommodate the answer as well as the null-terminating
    // charcter.
    for ( ; *digits; ++digits, ++buffer)
        *buffer = (*digits < '5') ? '0' : '1';
    *buffer = '\0';
}
