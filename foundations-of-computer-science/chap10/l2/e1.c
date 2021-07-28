#include <stdio.h>
#include <stdbool.h>

bool findChar(char **pp, char c)
{
    while (**pp != c && **pp != '\0')
        ++(*pp);
    if (**pp == '\0')
        return false;
    else {
        ++(*pp);
        return true;
    }
}

bool testWord(char *p) 
{
    // state 0
    if (findChar(&p, 'a'))
        // state 1
        if (findChar(&p, 'e'))
            // state 2
            if (findChar(&p, 'i'))
                // state 3
                if (findChar(&p, 'o'))
                    // state 4
                    if (findChar(&p, 'u'))
                        // state 5
                        return true;
    return false;
}

int main()
{
    printf("%d\n", testWord("abstemious"));
}
