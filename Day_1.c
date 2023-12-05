#include <stdint-gcc.h>
#include <intrin.h>


/////////////
/// Day 1 ///
/////////////


static uint32_t solution_1_1(const char *test){

    uint32_t ret = 0;
    uint32_t lastValue , firstValue = 0;

    for (int i = 0; i < strlen(test); ++i) {

        uintptr_t number = (uint32_t)(test[i] - '0');

        if(number <= 9){

            lastValue = number;
            if (firstValue == 0)firstValue = (uint32_t)(test[i] - '0');

        } else if(test[i] == '\n'){

            ret += firstValue * 10 + lastValue;
            firstValue = 0;

        }

    }
    return ret;
}

//This disaster is for optimization
static uint32_t getIntFromCharArray1_2(const char *test, uint32_t index){

    switch(test[index]) {
        case 'o':
            if (test[++index] == 'n' && test[++index] == 'e')return 1;
            return 0;

        case 't':
            switch(test[++index]){
                case 'w':if (test[++index] == 'o')return 2;return 0;
                case 'h':if (test[++index] == 'r' && test[++index] == 'e' && test[++index] == 'e')return 3;return 0;
            }
            return 0;

        case 'f':
            switch(test[++index]){
                case 'o':if (test[++index] == 'u' && test[++index] == 'r')return 4;return 0;
                case 'i':if (test[++index] == 'v' && test[++index] == 'e')return 5;return 0;
            }
            return 0;

        case 's':
            switch(test[++index]){
                case 'i':if (test[++index] == 'x')return 6;return 0;
                case 'e':if (test[++index] == 'v' && test[++index] == 'e' && test[++index] == 'n')return 7;return 0;
            }
            return 0;

        case 'e':
            if (test[++index] == 'i' && test[++index] == 'g' && test[++index] == 'h' && test[++index] == 't')return 8;
            return 0;

        case 'n':
            if (test[++index] == 'i' && test[++index] == 'n' && test[++index] == 'e')return 9;
            return 0;

        case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            return (int32_t)(test[index] - '0');

        default:
            return 0;
    }
}


static uint32_t solution_1_2(const char *test){

    uint32_t number = 0;

    uint32_t lastValue = 0, firstValue = 0;


    for (int i = 0; i < strlen(test); ++i) {

        if (firstValue == 0)firstValue = getIntFromCharArray1_2(test, i);
        else if(test[i] == '\n'){

            for (int j = i - 1; j >= 0; --j) {
                if (lastValue == 0)lastValue = getIntFromCharArray1_2(test, j);
                else break;
            }

            number += firstValue * 10 + lastValue;
            firstValue = lastValue = 0;

        }

    }
    return number;

}
