#include <stdint-gcc.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>


static uint64_t solution5_1(const char *test){



    uint32_t seedStart = 0;
    uint32_t seedEnd = 0;
    uint32_t seedsCount = 0;

    for (; seedEnd < strlen(test); ++seedEnd){
        if(test[seedEnd] == ' '){
            if(seedStart == 0)seedStart = seedEnd;
            ++seedsCount;
        }
        else if(test[seedEnd] == '\n')break;
    }

    uint64_t seeds[seedsCount] = {};
    bool seedsMappingDone = false;

    uint32_t index = 0;

    for (uint32_t i = seedStart + 1; i < seedEnd; ++i){

        if((uint32_t)(test[i] - '0') > 9){
            index++;
            continue;
        }

        seeds[index] *= 10;
        seeds[index] += (uint32_t)(test[i] - '0');
    }

    uint64_t map[3] = {};

    index = 0;
    uint64_t ret = UINT64_MAX;

    for (int n = 0; n < seedsCount; ++n) {

        uint64_t seedNew = seeds[n];

        for (uint32_t i = seedEnd + 1; i < strlen(test); ++i) {

            if(test[i] == ':')seedsMappingDone = false;

            if((uint32_t)(test[i] - '0') > 9){
                if (index < 2)++index;
                continue;
            }

            if (test[i - 1] == '\n'){
                map[0] = map[1] = map[2] = 0;
                index = 0;
            }

            map[index] *= 10;
            map[index] += (uint64_t)(test[i] - '0');

            if (test[i + 1] == '\n'){

                if (seedsMappingDone)continue;

                if (seedNew >= map[1] && seedNew < map[1] + map[2]){
                    seedNew = map[0] + seedNew - map[1];
                    seedsMappingDone = true;
                }
            }
        }

        ++index;
        if (ret > seedNew)ret = seedNew;
    }


    return ret;
}


static uint64_t get5_2(const char *test, uint64_t start, uint64_t value, uint64_t range){

    if (range == 0)return UINT64_MAX;

    uint64_t map[3] = {};
    uint64_t index = 0;
    bool startMapping = false;

    for (uint64_t i = start; i < strlen(test); ++i){

        if(test[i] == 'm' && startMapping)return get5_2(test, i, value, range);
        if(test[i] == ':')startMapping = true;

        if (!startMapping)continue;

        if((uint64_t)(test[i] - '0') > 9){
            if (index < 2)++index;
            continue;
        }

        if (test[i - 1] == '\n'){
            map[0] = map[1] = map[2] = 0;
            index = 0;
        }

        map[index] *= 10;
        map[index] += (uint64_t)(test[i] - '0');

        if (test[i + 1] == '\n'){

            uint64_t startSeed = value;
            uint64_t endSeed = value + range;

            uint64_t startMap = map[1];
            uint64_t endMap = map[1] + map[2];

            uint64_t min = UINT64_MAX;

            if(startMap <= startSeed && endSeed - 1 <= endMap) {

                return get5_2(test, i, map[0] + startSeed - map[1], endSeed - startSeed);

            }else if(startSeed <= startMap && endMap <= endSeed - 1) {

                uint64_t up = get5_2(test, start, startSeed, startMap - startSeed);
                uint64_t middle = get5_2(test, i, map[0] + startMap - map[1], endMap - startMap);
                uint64_t down = get5_2(test, start, endMap + 1, endSeed - endMap);

                if (min > up)min = up;
                if (min > middle)min = middle;
                if (min > down)min = down;

                return min;

            }else if (startMap <= startSeed && startSeed < endMap && endMap <= endSeed - 1) {

                uint64_t middle = get5_2(test, i, map[0] + startSeed - map[1], endMap - startSeed);
                uint64_t down = get5_2(test, start, endMap + 1, endSeed - endMap);

                if (min > middle)min = middle;
                if (min > down)min = down;

                return min;

            }else if (startSeed <= startMap && startMap < endSeed - 1 && endSeed - 1 <= endMap) {

                uint64_t up = get5_2(test, start, startSeed, startMap - startSeed);
                uint64_t middle = get5_2(test, i, map[0] + startMap - map[1], endSeed - startMap);

                if (min > up)min = up;
                if (min > middle)min = middle;

                return min;

            }
        }
    }
    return value;
}


static uint64_t solution5_2(const char *test){

    uint64_t seedStart = 0;
    uint64_t seedEnd = 0;
    uint64_t seedsCount = 0;

    for (; seedEnd < strlen(test); ++seedEnd){
        if(test[seedEnd] == ' '){
            if(seedStart == 0)seedStart = seedEnd;
            ++seedsCount;
        }
        else if(test[seedEnd] == '\n')break;
    }

    uint64_t seeds[seedsCount] = {};

    uint64_t index = 0;

    for (uint64_t i = seedStart + 1; i < seedEnd; ++i){

        if((uint64_t)(test[i] - '0') > 9){
            index++;
            continue;
        }

        seeds[index] *= 10;
        seeds[index] += (uint64_t)(test[i] - '0');
    }

    uint64_t ret = UINT64_MAX;

    for (int n = 0; n < seedsCount / 2; ++n) {
        uint64_t seedNew = get5_2(test, seedEnd, seeds[n * 2], seeds[n * 2 + 1]);
        if (ret > seedNew)ret = seedNew;
    }

    return ret;
}