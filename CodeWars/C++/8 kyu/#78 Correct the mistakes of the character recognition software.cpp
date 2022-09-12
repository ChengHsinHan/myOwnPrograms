// Character recognition software is widely used to digitise printed texts. Thus
// the texts can be edited, searched and stored on a computer.
//
// When documents (especially pretty old ones written with a typewriter), are
// digitised character recognition softwares often make mistakes.
//
// Your task is correct the errors in the digitised text. You only have to
// handle the following mistakes:
//
// S is misinterpreted as 5
// O is misinterpreted as 0
// I is misinterpreted as 1
// The test cases contain numbers only by mistake.

#include <string>

std::string correct(std::string str)
{
    for (unsigned int index = 0; index < str.length(); ++index)
    {
        switch (str[index])
        {
        case '5':
            str[index] = 'S';
            break;
        case '0':
            str[index] = 'O';
            break;
        case '1':
            str[index] = 'I';
            break;
        }
    }
    return str;
}
