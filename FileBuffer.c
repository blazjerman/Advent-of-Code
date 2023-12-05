#include <stdio.h>
#include <intrin.h>


#define STRING_PADDING 10

static char *getStringFromFile(char *path){

    FILE *file;
    char *buffer;
    long file_size;

    file = fopen(path, "r");

    if (file == NULL) {
        perror("Error opening the file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);

    file_size = ftell(file);

    fseek(file, 0, SEEK_SET);

    buffer = malloc(sizeof(char) * (file_size + STRING_PADDING));

    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, file_size, file);

    buffer[file_size] = '\0';

    fclose(file);

    return buffer;

}