/**
  \file      TD20200324.c
  \brief     txt file / dynamic alloc / workd processing
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200324.h"

uint32_t wc(char *s)
{

    bool inWord = false;
    uint32_t count = 0;
    uint32_t index = 0;

    while (s[index])
    {

        if (!inWord && !(s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {
            count++;
            inWord = true;
        }
        else if (inWord && (s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {
            inWord = false;
        }
        index++;
    }
    return count;
}

void ws(char *s)
{

    bool inWord = false;
    uint32_t wordIndex = 0;
    uint32_t index = 0;
    uint32_t k = 0;
    char **word = NULL;
    char **ptr = NULL; // result of realloc for word table
    char *start = NULL;
    char *stop = NULL;
    uint32_t length = 0;
    bool wordAlreadyExist = false;

    // 1. get number of word in s

    // 2. allocate the word table
    // each cell of word will contain a word
    // each cell of word will be a pointer on a string
    // word[0] <- "Ut"
    // word[1] <- "vulputate"
    // word[2] <- "mi"
    // word[3] <- "a"
    // ...
    // word[numWords-1] <- "suscipit"

    puts("*** Words in the dictionnary ***");
    word = NULL;

    while (s[index])
    {

        if (!inWord && !(s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {
            start = s + index;
            inWord = true;
        }
        else if (inWord && (s[index] == ' ' || s[index] == ',' || s[index] == '.' || s[index] == '\0'))
        {
            stop = s + index - 1;
            inWord = false;

            // display the chars from start to stop
#if 0
            putchar('[');
            for (p = start; p <= stop; p++)
            {
                putchar(*p);
            }
            putchar(']');
            puts("");
#endif
            // word length ("titi" => length=4)
            length = stop - start + 1;

            // detect if the new word already exits in word[]
            // must update : wordAlreadyExist

            // for loop on word[k] : [0..wordIndex[
            //  test if word[k]==new word => wordAlreadyExist=true

            wordAlreadyExist = false;

            *(stop + 1) = '\0'; // convert to a string

            for (k = 0; k < wordIndex; k++)
            {
                if (0 == strcmp(word[k], start))
                {
                    wordAlreadyExist = true;
                }
            }
            *(stop + 1) = ' '; // restore the char table

            // if not, add word to the table
            if (wordAlreadyExist == false)
            {
                ptr = (char **)realloc(word, (1 + wordIndex) * sizeof(char *)); // adjust the size of word
                if (ptr == NULL)
                {
                    puts("Error during realloc.");
                }
                else
                {
                    // use the new allocated area
                    word = ptr;

                    // allocate memory for the word in the table
                    word[wordIndex] = (char *)calloc(length + 1, sizeof(char)); // +1 for the '\0' to the end
                    // copy from string to word table (no need to add a \0', the calloc set the table to zero :)
                    memcpy(word[wordIndex], start, length);

                    // check the content of the table
                    printf("%s\n", word[wordIndex]);

                    wordIndex++;
                }
            }
        }
        index++;
    }
    printf("%u different word(s).\n", wordIndex);

    // free each word
    for (k = 0; k < wordIndex; k++)
    {
        if (word[k] != NULL)
        {
            free(word[k]);
            word[k] = NULL;
        }
    }

    // free of word table
    if (word != NULL)
    {
        free(word);
        word = NULL;
    }

    return;
}

int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;
    const char *filename = argv[1]; // may check argc...
    FILE *f = NULL;
    uint32_t fileSize = 0;
    char *text = NULL;
    uint32_t wordCount = 0;

    // open the file as a text file
    f = fopen(filename, "r");
    if (NULL == f)
    {
        returnCode = E_FILE_OPEN;
        printf("Error while opening %s\n", filename);
    }
    if (!returnCode)
    {
        fseek(f, 0, SEEK_END); // set the read pointer to the end
        fileSize = ftell(f);   // read the current position = size of the file
        printf("File size=%u bytes\n", fileSize);

        text = (char *)calloc((1 + fileSize), sizeof(char));
        if (text == NULL)
        {
            returnCode = E_MALLOC;
            printf("Error while allocating %u bytes\n", fileSize);
        }
    }
    if (!returnCode)
    {
        // transfert of the file content to the text area
        rewind(f);
        fgets(text, 1 + fileSize, f);

        // memory dump
        //for (k = 0; k < 1 + fileSize;k++) {
        //    printf("[%c]  %d\n", text[k], text[k]);
        //}

        printf("[%s]\n", text);
        printf("%lu\n", strlen(text)); //1336

        wordCount = wc(text);
        printf("%u word(s).\n", wordCount);

        ws(text);
    }

    if (!returnCode)
    {
        if (0 != fclose(f))
        {
            returnCode = E_FILE_CLOSE;
            printf("Error while closing %s\n", filename);
        }
    }

    if (text != NULL)
    {
        free(text);
        text = NULL;
    }
    return returnCode;
}
