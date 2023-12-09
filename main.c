#include <stdio.h>
#include <intrin.h>

#include "Utility.c"

#include "Day_1.c"
#include "Day_2.c"
#include "Day_3.c"
#include "Day_4.c"
#include "Day_5.c"
#include "Day_6.c"
#include "Day_7.c"


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

        printf("Solution Day3_1: %d\n", solution3_1(buffer,141,140));
        printf("Solution Day3_2: %d\n", solution3_2(buffer,141,140));

        printf("\n");
        free(buffer);
    }

    {
        char *buffer = getStringFromFile("../inDay_4.txt");

        printf("Solution Day4_1: %d\n", solution4_1(buffer));
        printf("Solution Day4_2: %d\n", solution4_2(buffer));

        printf("\n");
        free(buffer);
    }

    {
        char *buffer = getStringFromFile("../inDay_5.txt");

        printf("Solution Day5_1: %lld\n", solution5_1(buffer));
        printf("Solution Day5_2: %lld\n", solution5_2(buffer));

        printf("\n");
        free(buffer);
    }


    {
        char *buffer = getStringFromFile("../inDay_6.txt");

        printf("Solution Day6_1: %lld\n", solution6_1(buffer));
        printf("Solution Day6_2: %lld\n", solution6_2(buffer));

        printf("\n");
        free(buffer);
    }

    {
        char *buffer = getStringFromFile("../inDay_7.txt");

        printf("Solution Day7_1: %lld\n", solution7_1(buffer));
        printf("Solution Day7_2: %u\n", solution7_2(buffer));

        printf("\n");
        free(buffer);
    }
}

