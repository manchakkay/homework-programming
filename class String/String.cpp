#include <iostream>
#include "String.h"

using namespace std;

String String::leftpart(int band)
{
    if (band > length || band < 0)
    {
        cerr << "incorrect band in::leftpart()";
        exit(-1);
        return NULL;
    }

    char *new_array = new char[band + 1];

    for (int i = 0; i < band; i++)
    {
        new_array[i] = array[i];
    }
    new_array[band] = '\0';

    String result = new_array;

    return result;
}

String String::rightpart(int band)
{
    if (band > length || band < 0)
    {
        cerr << "incorrect band in::rightpart()";
        exit(-3);
        return NULL;
    }

    char *new_array = new char[band + 1];

    for (int i = length - band; i < length; i++)
    {
        new_array[i - length + band] = array[i];
    }
    new_array[band] = '\0';

    String result = new_array;

    return result;
}

String String::middle(int start, int band)
{
    if (start >= length || start < 0 || band + start - 1 >= length || band < 0)
    {
        cerr << "incorrect band in::middle()";
        exit(-2);
        return NULL;
    }

    char *new_array = new char[band + 1];

    for (int i = start; i < start + band; i++)
    {
        new_array[i - start] = array[i];
    }
    new_array[band] = '\0';

    String result = new_array;

    return result;
}

String String::concatenation(String input)
{

    int len2 = get_len(input.to_char());
    char *new_array = new char[length + len2 + 1];

    for (int i = 0; i < length; i++)
    {
        new_array[i] = array[i];
    }
    for (int i = 0; i < len2; i++)
    {
        new_array[i + length] = input.to_char()[i];
    }

    free(array);

    length = length + len2;
    array = new_array;

    return *(this);
}

String::String()
{
    length = 0;
    array = new char[length + 1];

    eol();
}

String::String(const char *input)
{
    length = get_len(input);
    array = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        array[i] = input[i];
    }

    eol();
}

int String::len()
{
    return length;
}

char *String::to_char()
{
    return array;
}

void String::eol()
{
    array[length] = '\0';
}

int String::get_len(const char *input)
{
    int i = 0;
    while (input[i] != '\0')
    {
        i++;
    }

    return i;
}
