/**
  \file      TD20200324.c
  \brief     txt file / dynamic alloc / workd processing
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200324.h"

#if 0

uint32_t wc(char *s) {
    bool inWord = false;
    uint32_t count = 0;
    uint32_t index = 0;

    while(s[index]) {
        if(!inWord && s[index]!=' ') {
            count++;
            inWord = true;
        }
        else if(inWord && (s[index]==' ' || s[index]==',' || s[index]=='.'  || s[index]=='\0') ){
            inWord = false;
        }
        index++;
    }
    return count;
}

void wstat(char *s) {
    bool inWord = false;
    uint32_t count = 0;
    uint32_t index = 0;
    char *start=NULL;
    char *end=NULL;
    bool knownWord = true;
    uint32_t wordCount = wc(s);
    char **word=NULL;
    uint32_t *histo = (uint32_t*)malloc(wordCount * sizeof(uint32_t));
    word = (char **)malloc(wordCount * sizeof(char *));
    uint32_t wordLength = 0;
    uint32_t k = 0;

    while(s[index])
    {
        if(!inWord && s[index]!=' ') {
            start = s + index;
            inWord = true;
        }
        else if(inWord && (s[index]==' ' || s[index]==',' || s[index]=='.' || s[index]=='\0' )) {
            end = s + index - 1;
            wordLength = end - start + 1;

            *(end+1) = 0;

            knownWord = false;
            //printf("Word: %s\n", start);

            for (k = 0; k < count; k++)
            {
                if(0==strcmp(word[k],start)) {
                    knownWord = true;
                    //printf("word [%s] already seen at position %u\n",start,k);
                    break;
                }

            }
           // knownWord = false;
           if (knownWord)
            {

                histo[k]++;
            }
            else
            { // one more word
                histo = realloc(histo, (count + 1) * sizeof(uint32_t));
                histo[count] = 1;
                word[count] = (char *)malloc((wordLength + 1) * sizeof(char));
                memcpy(word[count], start, wordLength);
                word[count][wordLength] = 0;
                //printf("[%s]\n", word[count]);
             count++;
           }
            
            *(end + 1) = ' ';

            inWord = false;
        }
        index++;
    } 
    printf("Number  word(s)=%u\n", wordCount);
    printf("Number of different word(s)=%u\n", count);
    for (k = 0; k < count; k++)
    {
        printf("%-20s %u\n", word[k], histo[k]);
}

for (index = 0; index < wordCount; index++)
{
    free(word[index]);
    word[index] = NULL;
    }
    free(word);
    word = NULL;

    return;
}
    
int main2(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;
    //char text[] = "   les sanglots longs des violons  ";
    char text[] = 
    "Ut vulputate mi a odio porta, a vestibulum sem mollis. Fusce vulputate lacus faucibus purus sagittis, finibus sagittis velit"
    " lobortis. Curabitur pretium dapibus mi, id condimentum mauris gravida vitae. Vivamus nec massa et leo posuere blandit vel vitae elit. Morbi "
    "ac massa ultrices, varius nunc nec, pharetra nunc. Phasellus malesuada nunc et sapien condimentum fringilla. Nullam lobortis et est ac auctor."
    " Suspendisse quis felis dictum risus varius placerat. Nunc ornare, sem in ornare consequat, nisi felis lacinia arcu, vitae cursus lorem augue "
    "quis sem. Nunc nisi massa, dapibus eu dolor sit amet, finibus efficitur nunc. Sed efficitur non nisi elementum auctor. Mauris sollicitudin purus "
    "ut ante placerat hendrerit. Proin neque diam, vestibulum eu bibendum id, feugiat sit amet ex. Mauris consequat blandit ex, vitae gravida nunc"
    " rutrum sed. Quisque ut pellentesque mauris. Nunc porttitor felis lacinia laoreet suscipit. Donec consequat, nunc sed viverra eleifend, ante ante "
    "lobortis lacus, nec malesuada diam est vel ligula. Suspendisse nec dolor arcu. Aenean venenatis ultrices justo vel porta. Sed sit amet tellus id "
    "risus hendrerit varius. Fusce hendrerit mollis lacinia. Nunc lobortis vulputate euismod. Duis quis dolor tortor. Etiam vel augue quis augue temp"
    "us lacinia ac ut nisi. Donec condimentum turpis et ipsum suscipit.";
    //char text[] = "un lapin un chat un canard chat.";
    uint32_t wordCount = 0;
    wordCount = wc(text);

    wstat(text);
    puts("");
    puts(text);
    return returnCode;
}









int main1(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;
    const char *filename = "text.txt";
    FILE *f = NULL;
    uint32_t fileSize=0;

    // open the file as a text file
    f = fopen(filename, "r");
    if(NULL==f) {
        returnCode = E_FILE_OPEN;
        printf("Error while opening %s\n", filename);
    }
    if(!returnCode) {
        fseek(f, 0, SEEK_END); // set the read pointer to the end
        fileSize = ftell(f);   // read the current position = size of the file
        printf("File size=%u bytes\n", fileSize);
    }
    if(!returnCode) {
        if(0!=fclose(f)){
            returnCode = E_FILE_CLOSE;
            printf("Error while closing %s\n", filename);
        }
    }
    return returnCode;
}


uint32_t wc(char *s) {

    bool inWord = false;
    uint32_t count = 0;
    uint32_t index = 0;

    while(s[index]) {

        if(!inWord && !(s[index]==' ' || s[index]==',' || s[index]=='.'  || s[index]=='\0') ) {
            count++;
            inWord = true;
        }
        else if(inWord && (s[index]==' ' || s[index]==',' || s[index]=='.'  || s[index]=='\0') ){
            inWord = false;
        }
        index++;
    }
    return count;
}


int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;
    const char *filename = "text.txt";
    FILE *f = NULL;
    uint32_t fileSize=0;
    char *text = NULL;
    uint32_t wordCount = 0;

    // open the file as a text file
    f = fopen(filename, "r");
    if(NULL==f) {
        returnCode = E_FILE_OPEN;
        printf("Error while opening %s\n", filename);
    }
    if(!returnCode) {
        fseek(f, 0, SEEK_END); // set the read pointer to the end
        fileSize = ftell(f);   // read the current position = size of the file
        printf("File size=%u bytes\n", fileSize);

        text = (char *)calloc( (1 + fileSize), sizeof(char) );
        if(text==NULL) {
            returnCode = E_MALLOC;
            printf("Error while allocating %u bytes\n", fileSize);
        }
    }
    if(!returnCode) {
        // transfert of the file content to the text area
        rewind(f);
        fgets(text, 1 + fileSize, f);
        printf("[%s]\n", text);
        printf("%lu\n", strlen(text)); //1336

        wordCount=wc(text);
        printf("%u word(s).\n", wordCount);

    }

    if(!returnCode) {
        if(0!=fclose(f)){
            returnCode = E_FILE_CLOSE;
            printf("Error while closing %s\n", filename);
        }
    }

    if(text!=NULL) {
        free(text);
        text = NULL;
    }
    return returnCode;
}









    /*if(!returnCode) {
        rewind(f);
        fgets(text, 1+fileSize, f);
        printf("[%s]\n",text);
        printf("length=%lu\n", strlen(text));
    }*/
#endif
