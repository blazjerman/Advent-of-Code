#include <stdio.h>
#include <intrin.h>
#include <stdbool.h>
#include <stdint-gcc.h>



/////////////
/// Day 3 ///
/////////////


static uint32_t solution3_1(const char *test, const uint32_t width, const uint32_t height){

    uint32_t ret = 0;
    uint32_t number = 0;
    bool numberOk = false;

    for (uint32_t j = 0; j < height; ++j) {
        for (uint32_t i = 0; i < width; ++i) {

            if((uint32_t)(test[i + j * width] - '0') > 9){

                if(numberOk)ret += number;numberOk = false;
                number = 0;

            }else{

                number *= 10;
                number += (uint32_t)(test[i + j * width] - '0');

                for (int l = -1; l < 2; ++l) {
                    for (int k = -1; k < 2; ++k) {

                        uint32_t neighborX = i + k;
                        uint32_t neighborY = j + l;

                        if (neighborX >= width)continue;
                        if (neighborY >= height)continue;

                        switch (test[neighborX + neighborY * width]){
                            case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '.':case '\n':break;
                            default:numberOk = true;break;
                        }
                    }
                }
            }
        }
    }
    return ret;
}





static uint32_t findNumberAndDeleteIt3_2(char *test, const uint32_t index){

    uint32_t ret = 0;

    for (uint32_t i = index, j = 1; i < strlen(test); --i, j *= 10) {

        uint32_t number = (uint32_t)(test[i] - '0');

        if (number > 9)break;
        ret += j * number;
        test[i] = '.';

    }

    return ret;
}




static uint32_t solution3_2(char *test, const uint32_t width, const uint32_t height){

    uint32_t ret = 0;

    uint32_t countNumbersAroundGear = 0;
    uint32_t numbersAroundGear = 1;

    for (int32_t j = 0; j < height; ++j) {
        for (int32_t i = 0; i < width; ++i) {

            if (test[i + j * width] != '*')continue;

            for (int l = -1; l < 2; ++l) {
                for (int k = -1; k < 2; ++k) {

                    uint32_t neighborX = i + k;
                    uint32_t neighborY = j + l;

                    if (neighborX >= width)continue;
                    if (neighborY >= height)continue;

                    if((uint32_t)(test[neighborX + neighborY * width] - '0') > 9)continue;

                    countNumbersAroundGear++;

                    for (uint32_t n = neighborX; n < width; ++n) {

                        if ((uint32_t)(test[n + neighborY * width] - '0') <= 9)continue;
                        numbersAroundGear *= findNumberAndDeleteIt3_2(test, n + neighborY * width - 1);
                        break;

                    }
                }
            }

            if (countNumbersAroundGear == 2)ret += numbersAroundGear;
            numbersAroundGear = 1;
            countNumbersAroundGear = 0;

        }
    }

    return ret;
}