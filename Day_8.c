#include <stdint-gcc.h>
#include <intrin.h>
#include <stdbool.h>

#define LINE_SIZE 17

#define OFFSET_FOR_LEFT 7
#define OFFSET_FOR_RIGHT 12



static uint64_t solution8_1(const char *test){

    uint64_t mapperSize = 0;

    for (; mapperSize < strlen(test); ++mapperSize)if (test[mapperSize] == '\n')break;

    bool map[mapperSize] = {};
    for (int i = 0; i < mapperSize; ++i)map[i] = test[i] == 'R';

    char start[] = "AAA";
    char end[] = "ZZZ";

    uint32_t index = 0;

    while (true){

        for (uint32_t j = mapperSize + 2; j < strlen(test); j += LINE_SIZE) {

            if (test[j] == start[0] && test[j + 1] == start[1] && test[j + 2] == start[2]){

                uint32_t getOffset = OFFSET_FOR_LEFT + j;
                if (map[index % mapperSize])getOffset = OFFSET_FOR_RIGHT + j;

                start[0] = test[getOffset];
                start[1] = test[getOffset + 1];
                start[2] = test[getOffset + 2];

                if (end[0] == start[0] && end[1] == start[1] && end[2] == start[2])return ++index;
                break;
            }
        }
        ++index;
    }
    return index;
}







static uint32_t solution8_2(const char *test){

}