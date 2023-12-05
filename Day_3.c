#include <stdio.h>
#include <intrin.h>
#include <stdbool.h>
#include <stdint-gcc.h>


/////////////
/// Day 3 ///
/////////////


static uint32_t solution3_1(const char *test){

    uint32_t height = 0;
    uint32_t width = 0;

    for (; width < strlen(test); ++width)if (test[width]=='\n')break;
    for (int i = 0; i < strlen(test); ++i)if (test[i]=='\n')++height;
    width++;

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









static uint32_t solution3_2(char *test, const int32_t height, const int32_t width){

    uint32_t ret = 0;


    for (int32_t j = 0; j < height; ++j) {
        for (int32_t i = 0; i < width; ++i) {

            switch (test[i + j * width]){
                case '*':break;
                default:continue;
            }

            for (int l = -1; l < 2; ++l) {
                for (int k = -1; k < 2; ++k) {

                    uint32_t neighborX = i + k;
                    uint32_t neighborY = j + l;

                    if (neighborX >= width)continue;
                    if (neighborY >= height)continue;

                    uint32_t number = (uint32_t)(test[neighborX + neighborY * width] - '0');

                    if(number <= 9){

                        for (uint32_t m = neighborX; m < width; ++m) {

                            number = (uint32_t)(test[m + neighborY * width] - '0');



                            if (number > 9) {


                                printf("%d\n", test[m + neighborY * width - 1] - '0');

                                for (uint32_t n = m, e = 1; n < width; --n, e *= 10) {

                                    number = (uint32_t)(test[i] - '0');

                                    if (number > 9)break;
                                    ret += e * number;

                                }

                                break;

                            }

                        }

                    }

                    //printf("%c\n", test[neighborX + neighborY * width]);

                }
            }
        }
    }

    printf("%s\n", test);
    return ret;
}