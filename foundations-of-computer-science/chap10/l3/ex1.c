/*
10.3.1 Write a C program to implement the algorithm of the deterministic automaton of Figure 10.9
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// dfa tells the number associated string end in which state
int dfa = 0;


bool usingStrLib(char *word)
{
    if (strstr(word, "man") != NULL) {
        return true;
    }
    return false;
}


void start(char c) 
{
    if (c == 'm') dfa = 1; 
    else dfa = 0;
}


void state1(char c)
{
    if (c == 'a') dfa = 2;
    else dfa = 0;
}


void state2(char c)
{
    if (c == 'n') dfa = 3;
    else dfa = 0;
}


bool isAccepted(char str[])
{
    int i = 0;
    while (i != strlen(str)) {
        if (dfa == 0)
            start(str[i]);
        else if (dfa == 1)
            state1(str[i]);
        else if (dfa == 2)
            state2(str[i]);
        ++i;
    }
    if (dfa == 3) {
        dfa = 0;
        return true;
    }
    else {
        dfa = 0;
        return false;
    }
}


int main()
{
    char *w1 = "maniac";
    char w2[] = "ombudsman";
    printf("%d\n", usingStrLib(w1));
    printf("%d\n", usingStrLib(w1));
    if (isAccepted(w1))
        printf("Accepted");
    else
        printf("Rejected");

    if (isAccepted(w2))
        printf("Accepted");
    else
        printf("Rejected");
    return 0;
}
