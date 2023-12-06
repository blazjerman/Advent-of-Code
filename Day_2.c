#include <stdint-gcc.h>
#include <intrin.h>
#include <stdbool.h>
#include <stdio.h>


/////////////
/// Day 2 ///
/////////////


static uint32_t solution_2_1(const char *test, const uint32_t *occ){

    uint32_t ret = 0;
    uint32_t number = 0;

    uint32_t gameID = 1;

    bool error = false;

    for (uint32_t i = 0; i < strlen(test); ++i) {

        switch (test[i]) {
            case 'r':
                if(occ[0] < number)error = true;
                break;
            case 'g':
                if(occ[1] < number)error = true;
                break;
            case 'b':
                if(occ[2] < number)error = true;
                break;
            case '\n':
                if(error)error = false;
                else ret += gameID;

                ++gameID;
                continue;
            case ':':
                break;
            default:
                if ((uint32_t)(test[i] - '0') > 9)continue;
                number *= 10;
                number += (uint32_t)(test[i] - '0');
                continue;
        }

        number = 0;
    }

    return ret;
}


static uint32_t solution_2_2(const char *test){

    uint32_t ret = 0;
    uint32_t number = 0;

    uint32_t cubeOcc[3] = {0,0,0};

    for (int i = 0; i < strlen(test); i++) {

        switch (test[i]) {
            case 'r':
                if(number > cubeOcc[0])cubeOcc[0] = number;
                break;
            case 'g':
                if(number > cubeOcc[1])cubeOcc[1] = number;
                break;
            case 'b':
                if(number > cubeOcc[2])cubeOcc[2] = number;
                break;
            case '\n':
                ret += cubeOcc[0] * cubeOcc[1] * cubeOcc[2];
                cubeOcc[0] = cubeOcc[1] = cubeOcc[2] = 0;
                continue;
            case ':':
                break;
            default:
                if ((uint32_t)(test[i] - '0') > 9)continue;
                number *= 10;
                number += (uint32_t)(test[i] - '0');
                continue;
        }

        number = 0;
    }

    return ret;
}