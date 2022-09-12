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

char* correct(char* string)
{
    /* Please modify the string in-place and return it.
    */
    for (unsigned int index = 0; string[index]; ++index)
    {
        switch (string[index])
        {
        case '5':
            string[index] = 'S';
            break;
        case '0':
            string[index] = 'O';
            break;
        case '1':
            string[index] = 'I';
            break;
        }
    }
    return string;
}
