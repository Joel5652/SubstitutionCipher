#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

//functions

bool checkNonAlpha(string key);
bool checkRepitition(string key);

//main

int main(int argc, string argv[])
{
    //command line argument check

    if (argc < 2 || argc > 2) //too many or too little command line arguments
    {
        printf("Command line argument error, please enter a valid key.\n");
        return 1;
    }
    else //key check
    {
        int n = strlen(argv[1]);
        string array = argv[1];

        for (int i = 0; i < 26; i++)
        {
            array[i] = toupper(array[i]);
        }


        //check correct number of chars, valid charachters and repeated charachters
        if (n == 26 && checkNonAlpha(array) == false && (checkRepitition(array) == false))
        {
            printf("key: %s\n",  array);
        }
        else //if key invalid
        {
            printf("Command line argument error, please enter a valid key.\n");
            return 1;
        }
    }

    // Cipher substitution

    string key = argv[1];

    //converts key to capitals

    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(key[i]);
    }

    //2d array to hold key and alphabet index

    char mapping[3][26];

    // loops key characters into array

    for (int i = 0; i < 26; i++)
    {
        mapping[2][i] = key[i];
    }

    //Dictionary for alphabet

    //lowercase

    mapping[0][0] = 'a';
    mapping[0][1] = 'b';
    mapping[0][2] = 'c';
    mapping[0][3] = 'd';
    mapping[0][4] = 'e';
    mapping[0][5] = 'f';
    mapping[0][6] = 'g';
    mapping[0][7] = 'h';
    mapping[0][8] = 'i';
    mapping[0][9] = 'j';
    mapping[0][10] = 'k';
    mapping[0][11] = 'l';
    mapping[0][12] = 'm';
    mapping[0][13] = 'n';
    mapping[0][14] = 'o';
    mapping[0][15] = 'p';
    mapping[0][16] = 'q';
    mapping[0][17] = 'r';
    mapping[0][18] = 's';
    mapping[0][19] = 't';
    mapping[0][20] = 'u';
    mapping[0][21] = 'v';
    mapping[0][22] = 'w';
    mapping[0][23] = 'x';
    mapping[0][24] = 'y';
    mapping[0][25] = 'z';

    //uppercase

    mapping[1][0] = 'A';
    mapping[1][4] = 'E';
    mapping[1][8] = 'I';
    mapping[1][12] = 'M';
    mapping[1][16] = 'Q';
    mapping[1][20] = 'U';
    mapping[1][24] = 'Y';
    mapping[1][1] = 'B';
    mapping[1][5] = 'F';
    mapping[1][9] = 'J';
    mapping[1][13] = 'N';
    mapping[1][17] = 'R';
    mapping[1][21] = 'V';
    mapping[1][25] = 'Z';
    mapping[1][2] = 'C';
    mapping[1][6] = 'G';
    mapping[1][10] = 'K';
    mapping[1][14] = 'O';
    mapping[1][18] = 'S';
    mapping[1][22] = 'W';
    mapping[1][3] = 'D';
    mapping[1][7] = 'H';
    mapping[1][11] = 'L';
    mapping[1][15] = 'P';
    mapping[1][19] = 'T';
    mapping[1][23] = 'X';

    string input = get_string("plaintext: ");

    int length = strlen(input);

    int num;

    //ciphertext

    printf("ciphertext: ");

    //loop starts here

    for (int front = 0; front < length; front++)
    {
        for (int back = 0; back < 26; back++)
        {
            if (input[front] == mapping[1][back]) //checks uppercase index
            {
                num = (int)mapping[2][back];
                num = toupper(num);
            }
            else if (input[front] == mapping[0][back]) //checks lowercase index
            {
                num = (int)mapping[2][back];
                num = tolower(num);
            }
            else if (input[front] == 32) //checks for space
            {
                num = 32;
            }
            else if (input[front] < 65) //checks for non alphabetical character under 65
            {
                num = input[front];
            }
            else if (input[front] < 97 && input[front] > 90) //checks for non alphabetical character between 90 and 97
            {
                num = input[front];
            }
            else if (input[front] > 122) //checks for non alphabetical character over 122
            {
                num = input[front];
            }

        }

        printf("%c", num); //print cipher
    }
    printf("\n");
}


//Functions

bool checkRepitition(string key) //check for repeated characters
{
    int sum = 0;

    int front;

    int back;

    for (front = 0; front < 26; front++) //checks repeated letters
    {
        for (back = front; back < 26 ; back++)
        {
            if (back == front)
            {
            }
            else if (key[back] == key[front])
            {
                sum++;
            }
            else
            {
            }
        }
    }
    if (sum == 0) //outputs
    {
        return false;
    }
    else
    {
        return true;
    }
}


bool checkNonAlpha(string key) //Check if there is any non-alphabetical characters
{
    int check = 0;

    for (int i = 0; i < 26; i++) //checks nonalpha
    {
        if ((int)toupper(key[i]) >= 65 && (int)toupper(key[i]) <= 90)
        {
            check++;
        }
    }
    if (check == 26) //output
    {
        return false;
    }
    else
    {
        return true;
    }
}