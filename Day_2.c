#include <stdint-gcc.h>
#include <intrin.h>
#include <stdbool.h>


/////////////
/// Day 2 ///
/////////////


static uint32_t findNumber(const char *test, const int32_t index){

    uint32_t ret = 0;

    for (int32_t i = index, j = 1; i >= 0; --i, j *= 10) {

        uint32_t number = (uint32_t)(test[i] - '0');

        if (number > 9)break;
        ret += j * number;

    }

    return ret;
}



static uint32_t solution_2_1(const char *test, const uint32_t *occ){

    uint32_t number = 0;

    uint32_t gameID = 1;
    uint32_t cubeOcc[3] = {0,0,0};;

    bool error = false;

    for (int i = 0; i < strlen(test); ++i) {

        switch (test[i]) {
            case '\n':
                if(!error)number += gameID;
                else error = false;
                ++gameID;
            case ';':
                cubeOcc[0] = cubeOcc[1] = cubeOcc[2] = 0;
                break;
            case 'r':
                if(occ[0] < findNumber(test, i - 2))error = true;
                break;
            case 'g':
                if(occ[1] < findNumber(test, i - 2))error = true;
                break;
            case 'b':
                if(occ[2] < findNumber(test, i - 2))error = true;
                break;
        }
    }

    return number;

}


static uint32_t solution_2_2(const char *test){

    uint32_t ret = 0;

    uint32_t number;

    uint32_t cubeOcc[3] = {0,0,0};

    for (int i = 0; i < strlen(test); i++) {

        switch (test[i]) {
            case 'r':
                number = findNumber(test, i - 2);
                if(number > cubeOcc[0])cubeOcc[0] = number;
                break;
            case 'g':
                number = findNumber(test, i - 2);
                if(number > cubeOcc[1])cubeOcc[1] = number;
                break;
            case 'b':
                number = findNumber(test, i - 2);
                if(number > cubeOcc[2])cubeOcc[2] = number;
                break;
            case 'G':
                ret += cubeOcc[0] * cubeOcc[1] * cubeOcc[2];
                cubeOcc[0] = cubeOcc[1] = cubeOcc[2] = 0;
                break;
            default:
                if(i == strlen(test) - 1){
                    ret += cubeOcc[0] * cubeOcc[1] * cubeOcc[2];
                    cubeOcc[0] = cubeOcc[1] = cubeOcc[2] = 0;
                }
        }

    }

    return ret;
}