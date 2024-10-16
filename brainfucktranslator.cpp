#include <fstream>
#include <iostream>

#define LOOP_COUNTER       10
#define ASCII_STEP_DIVISOR 10
#define MAX_CHARACTERS     1000

using namespace std;
ifstream fin("brainfucktranslator.in");
ofstream fout("brainfucktranslator.out");

int main()
{
    // Check if the input file was opened successfully
    if (!fin) 
    {
        fout << "Unable to open input file";
        return 1;
    }

    unsigned int numberCharactersText;
    char text[MAX_CHARACTERS];

    // Read characters from file up until the maximum character limit
    while(fin.get(text[numberCharactersText]) && (numberCharactersText < MAX_CHARACTERS))
    {
        numberCharactersText++;
    }

    // We use the first memory location as a counter for our loop. 
    for(int i = 0; i < LOOP_COUNTER; i++)
    {
        fout << '+';
    }
    fout << "\n";

    // Loop start
    fout << "[\n";

    for(int i = 0; i < numberCharactersText; i++)
    {
        // Go to the memory location of the current character
        fout << "  >";
        // Increments the current memory cell by adding + until its value equals the ASCII code of the
        // target character divided by ASCII_STEP_DIVISOR. Each + increases the memory cell by 1, so we
        // repeat the addition until the cell value reaches ASCII(character) / ASCII_STEP_DIVISOR
        for(int j = 0; j < (int)text[i] / ASCII_STEP_DIVISOR; j++)
        {
            fout << "+";
        }
        fout << "\n";
    }

    // Align the next code with the rest of the code in the loop
    fout << "  ";
    // Go to the memory location of the loop counter (the first position)
    for(int i = 0; i < numberCharactersText; i++)
    {
        fout << "<";
    }
    // Decrement the counter for the loop
    // In brainfuck the loop ends when the value located at the memory pointer reaches zero
    fout << "-\n";

    // Loop end
    fout << "]\n";

    for(int i = 0; i < numberCharactersText; i++)
    {
        // Go to the memory location of the current character
        fout << ">";
        // The current memory cell holds the value of ASCII(character) / ASCII_STEP_DIVISOR from the previous step.
        // Now, we need to add the remainder (ASCII(target) % ASCII_STEP_DIVISOR) to reach the exact ASCII code of
        // the desired character
        for(int j = 0; j < (int)text[i] % ASCII_STEP_DIVISOR; j++)
        {
            fout << "+";
        }
        // Write the character from the current memory location
        fout << ".\n";
    }
    
    fin.close();
    fout.close();
    return 0;
}