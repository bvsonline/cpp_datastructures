//
//  Cprogramming_Practice.cpp
//  cpp_datastructures
//
//  Created by venkata bethamcharla on 4/17/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>

void CprogrammingPracticeExamples();
void Fahrenheit2Celcius();
void countLinesWordsChars();
void countDigitsWhiteSpacesandOthers();

void CprogrammingPracticeExamples()
{
    Fahrenheit2Celcius();
    //countLinesWordsChars();
    countDigitsWhiteSpacesandOthers();
    return;
}


void Fahrenheit2Celcius()
{
    
    float fahr, celcius;
    float step, lower, upper;
    
    lower = 0;
    upper = 300.0;
    step = 20.0;

    printf ("FAHR \t CELCIUS \n");
    fahr = lower;
    
    while (fahr <= upper)
    {
        celcius = 5 * (fahr-32) / 9;
        printf ("%0.2f \t %0.2f\n", fahr, celcius);
        fahr += step;
    }
    
    return;
}
#define OUT 0
#define IN  1

void countLinesWordsChars()
{
    int nl, nw, nc, c, state;
    nl = nw = nc = 0;
    
    while ((c = getchar()) != EOF)
    {
        ++nc;
        
        if (c == '\n')
        {
            ++nl;
        }
        
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    
    printf ("nl: %d, nc: %d, nw: %d \n", nl, nc, nw);
    
    return;
}

void countDigitsWhiteSpacesandOthers()
{
    int c, n_digits[10] = {0}, n_white_spaces = 0, n_other_characters = 0, i;
    
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ++n_digits[c-'0'];
        else if (c == ' '|| c == '\n' || c == '\t')
            ++n_white_spaces;
        else
            ++n_other_characters;
    }
    
    for (i = 0; i < 10; i++)
    {
        printf("n_digits[%d]: %d \n", i, n_digits[i]);
    }
    printf("n_white_spaces: %d, n_other_characters: %d \n", n_white_spaces, n_other_characters);
    
    return;
}
