#include "StringUtils.h"

void StringUtils::strCpy(char* dest, const char* src)
{
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int StringUtils::strLen(const char* str)
{
    int counter = 0;
    while (*str)
    {
        counter++;
        str++;
    }
    return counter;
}

int StringUtils::strCmp(const char* text1, const char* text2)
{
    if (text1 == text2)
    {
        return 0;
    }

    if (!text1 || !text2)
    {
        return -1;
    }

    while (*text1 && *text1 == *text2)
    {
        text1++;
        text2++;
    }
    return *text1 - *text2;
}
