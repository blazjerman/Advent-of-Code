#include <stdint-gcc.h>
#include <intrin.h>
#include <stdio.h>


struct BoatRace{

    uint64_t time;
    uint64_t distance;

};



static uint64_t solution6_1(const char *test){

    uint64_t ret = 1;

    uint64_t secondLine = 0;
    uint64_t racesCount = 0;

    for (; secondLine < strlen(test); ++secondLine){
        if (test[secondLine - 1] == ' ' && (uint64_t)(test[secondLine] - '0') <= 9)++racesCount;
        if(test[secondLine] == '\n')break;
    }

    struct BoatRace race[racesCount];

    for (uint64_t i = 0; i < racesCount; ++i) {
        race[i].time = 0;
        race[i].distance = 0;
    }

    int64_t index = -1;

    for (uint64_t i = 1; i < secondLine; ++i) {
        if ((uint64_t)(test[i] - '0') <= 9){
            if (test[i - 1] == ' ')++index;
            race[index].time *= 10;
            race[index].time += (uint64_t)(test[i] - '0');
        }
    }

    index = -1;

    for (uint64_t i = secondLine; i < strlen(test); ++i) {
        if ((uint64_t)(test[i] - '0') <= 9){
            if (test[i - 1] == ' ')++index;
            race[index].distance *= 10;
            race[index].distance += (uint64_t)(test[i] - '0');
        }
    }

    for (uint64_t i = 0; i < racesCount; ++i) {

        uint64_t occ = 0;

        for (int j = 1; j < race[i].time; ++j) {
            if (j * (race[i].time - j) > race[i].distance)++occ;
        }

        ret *= occ;

    }

    return ret;
}







static uint64_t solution6_2(const char *test){

    uint64_t ret = 0;

    uint64_t secondLine = 0;
    uint64_t racesCount = 0;

    for (; secondLine < strlen(test); ++secondLine){
        if (test[secondLine - 1] == ' ' && (uint64_t)(test[secondLine] - '0') <= 9)++racesCount;
        if(test[secondLine] == '\n')break;
    }

    struct BoatRace race = {0,0};

    for (uint64_t i = 1; i < secondLine; ++i) {
        if ((uint64_t)(test[i] - '0') <= 9){
            race.time *= 10;
            race.time += (uint64_t)(test[i] - '0');
        }
    }

    for (uint64_t i = secondLine; i < strlen(test); ++i) {
        if ((uint64_t)(test[i] - '0') <= 9){
            race.distance *= 10;
            race.distance += (uint64_t)(test[i] - '0');
        }
    }

    for (int j = 1; j < race.time; ++j) {
        if (j * (race.time - j) > race.distance)++ret;
    }

    return ret;
}