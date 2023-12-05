#include <stdio.h>
#include <intrin.h>

#include "FileBuffer.c"

#include "Day_1.c"
#include "Day_2.c"
#include "Day_3.c"



int main() {


    {
        char *buffer = getStringFromFile("../inDay_1.txt");

        printf("Solution Day1_1: %d\n", solution_1_1(buffer));
        printf("Solution Day1_2: %d\n", solution_1_2(buffer));

        printf("\n");
        free(buffer);
    }

    {
        char *buffer = getStringFromFile("../inDay_2.txt");

        uint32_t in[] = {12,13,14};

        printf("Solution Day2_1: %d\n", solution_2_1(buffer, in));
        printf("Solution Day2_2: %d\n", solution_2_2(buffer));

        printf("\n");
        free(buffer);
    }

    {
        char *buffer = getStringFromFile("../inDay_3.txt");

        printf("Solution Day3_1: %d\n", solution3_1(buffer));
        //printf("Solution Day3_1: %d\n", solution3_2(buffer));

        printf("\n");
        free(buffer);
    }

}

