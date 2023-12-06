#include <intrin.h>
#include <stdint-gcc.h>
#include <stdio.h>


/////////////
/// Day 4 ///
/////////////


static uint32_t solution4_1(const char *test){

    uint32_t ret = 0;
    uint32_t number = 0;
    uint32_t cmpNumber = 0;

    uint32_t point = 0;

    uint32_t start;
    uint32_t end;

    uint32_t size;

    for (uint32_t i = 0; i < strlen(test); ++i){

        switch (test[i]) {
            case '\n':size = i + 1;break;
            case '|':end = i;continue;
            case ':':start = i;continue;
            default:continue;
        }

        break;
    }


    for (uint32_t j = 0; j * size + size < strlen(test); ++j) {
        for (uint32_t i = start; i < end; ++i) {

            if((uint32_t)(test[j * size + i] - '0') > 9) {

                if (number == 0)continue;

                for (uint32_t k = end; k < size; ++k) {

                    if((uint32_t)(test[j * size + k] - '0') > 9){

                       if(number == cmpNumber){
                           if(point == 0)point = 1;
                           else point <<= 1;
                       }

                       cmpNumber = 0;
                       continue;
                    }

                    cmpNumber *= 10;
                    cmpNumber += (uint32_t)(test[j * size + k] - '0');
                }

                number = 0;
                continue;
            }

            number *= 10;
            number += (uint32_t)(test[j * size + i] - '0');
        }

        ret += point;
        point = 0;
    }

    return ret;
}




static uint32_t solution4_2(const char *test){

    uint32_t ret = 0;
    uint32_t number = 0;
    uint32_t cmpNumber = 0;

    uint32_t point = 0;

    uint32_t start;
    uint32_t end;
    uint32_t size;

    for (uint32_t i = 0; i < strlen(test); ++i){

        switch (test[i]) {
            case '\n':size = i + 1;break;
            case '|':end = i;continue;
            case ':':start = i;continue;
            default:continue;
        }

        break;

    }


    uint32_t matching = 0;
    uint32_t pointsOn[strlen(test) / size] = {};


    for (uint32_t j = 0; j < strlen(test) / size; ++j) {

        ++pointsOn[j];

        if (j > 0){
            for (int k = 0; k < pointsOn[j - 1]; ++k) {
                for (uint32_t l = j; l < j + matching; ++l) {
                    ++pointsOn[l];
                }
            }
        }

        ret += pointsOn[j];
        matching = 0;

        for (uint32_t i = start; i < size; ++i) {

            if(test[j * size + i] == '|')break;

            if((uint32_t)(test[j * size + i] - '0') > 9) {

                if (number != 0){

                    for (uint32_t k = end; k < size; ++k) {

                        if((uint32_t)(test[j * size + k] - '0') > 9){

                            if(number == cmpNumber){
                                ++matching;
                                if(point == 0)point = 1;
                                else point *= 2;
                            }

                            cmpNumber = 0;

                        } else{

                            cmpNumber *= 10;
                            cmpNumber += (uint32_t)(test[j * size + k] - '0');

                        }
                    }
                    number = 0;
                }

            } else{

                number *= 10;
                number += (uint32_t)(test[j * size + i] - '0');

            }
        }

        point = 0;
    }

    return ret;

}