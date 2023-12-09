#include <stdint-gcc.h>
#include <intrin.h>
#include <stdio.h>
#include <stdbool.h>


#define VALUE_SIZE 5
#define CARD_LABELS 13

struct Card{

    char value[VALUE_SIZE];
    uint32_t number;

};

static uint32_t getCharValue(char c){

    switch (c) {
        case 'A':return 0;
        case 'K':return 1;
        case 'Q':return 2;
        case 'J':return 3;
        case 'T':return 4;
        case '9':return 5;
        case '8':return 6;
        case '7':return 7;
        case '6':return 8;
        case '5':return 9;
        case '4':return 10;
        case '3':return 11;
        case '2':return 12;
    }

}

static uint32_t *getOcc(struct Card a){
    
    uint32_t *occ = malloc(CARD_LABELS * sizeof(uint32_t));

    for (int i = 0; i < CARD_LABELS; ++i)occ[i] = 0;
    for (int i = 0; i < VALUE_SIZE; ++i)++occ[getCharValue(a.value[i])];


    for (int i = 0; i < CARD_LABELS; ++i) {
        int j = i;

        while(j > 0 && (occ[j] > occ[j - 1])){

            uint32_t tmp = occ[j];
            occ[j] = occ[j - 1];
            occ[j - 1] = tmp;

            j--;
        }
    }

    return occ;
}

static bool cmpCards(struct Card a, struct Card b){

    uint32_t *occA = getOcc(a);
    uint32_t *occB = getOcc(b);


    for (int i = 0; i < VALUE_SIZE; ++i){
        if (occA[i] < occB[i])return true;
        if (occA[i] > occB[i])return false;
    }

    for (int i = 0; i < VALUE_SIZE; ++i){
        if (getCharValue(a.value[i]) > getCharValue(b.value[i]))return true;
        if (getCharValue(a.value[i]) < getCharValue(b.value[i]))return false;
    }
    
    free(occA);
    free(occB);

    return false;
}

static uint64_t solution7_1(const char *test){

    uint32_t cardsCount = 0;

    for (int i = 0; i < strlen(test); ++i)if (test[i] == '\n')++cardsCount;

    struct Card cards[cardsCount];

    uint32_t index = 0;

    for (int i = 0; i < strlen(test); ++i) {

        if (i == 0)for (int j = 0; j < VALUE_SIZE; ++j)cards[index].value[j] = test[i + j];
        else if (test[i - 1] == '\n')for (int j = 0; j < VALUE_SIZE; ++j)cards[index].value[j] = test[i + j];

        else if (test[i - 1] == ' '){

            if ((uint32_t)(test[i] - '0') > 9)continue;
            cards[index].number = 0;

            for (int j = i; j < strlen(test); ++j) {
                if ((uint32_t)(test[j] - '0') > 9)break;
                cards[index].number *= 10;
                cards[index].number += (uint32_t)(test[j] - '0');
            }

            ++index;
        }
    }

    for (int i = 0; i < cardsCount; ++i) {
        int j = i;
        while(j > 0 && cmpCards(cards[j], cards[j - 1])){

            struct Card tmp = cards[j];
            cards[j] = cards[j - 1];
            cards[j - 1] = tmp;

            j--;
        }
    }

    uint64_t ret = 0;
    for (int i = 0; i < cardsCount; ++i) {
        ret += (i + 1) * cards[i].number;
    }


    return ret;

}





static uint32_t getCharValueJoker(char c){

    switch (c) {
        case 'A':return 0;
        case 'K':return 1;
        case 'Q':return 2;
        case 'T':return 3;
        case '9':return 4;
        case '8':return 5;
        case '7':return 6;
        case '6':return 7;
        case '5':return 8;
        case '4':return 9;
        case '3':return 10;
        case '2':return 11;
        case 'J':return 12;
    }

}

static uint32_t *getOccJoker(struct Card a){

    uint32_t *occ = malloc(CARD_LABELS * sizeof(uint32_t));

    for (int i = 0; i < CARD_LABELS; ++i)occ[i] = 0;

    uint32_t jokers = 0;

    for (int i = 0; i < VALUE_SIZE; ++i){
        uint32_t value = getCharValueJoker(a.value[i]);
        if (value == CARD_LABELS - 1)++jokers;
        else ++occ[value];
    }


    for (int i = 0; i < CARD_LABELS; ++i) {
        int j = i;

        while(j > 0 && (occ[j] > occ[j - 1])){

            uint32_t tmp = occ[j];
            occ[j] = occ[j - 1];
            occ[j - 1] = tmp;

            j--;
        }
    }

    occ[0] += jokers;

    return occ;
}


static bool cmpCardsJoker(struct Card a, struct Card b){

    uint32_t *occA = getOccJoker(a);
    uint32_t *occB = getOccJoker(b);


    for (int i = 0; i < VALUE_SIZE; ++i){
        if (occA[i] < occB[i])return true;
        if (occA[i] > occB[i])return false;
    }

    for (int i = 0; i < VALUE_SIZE; ++i){
        if (getCharValueJoker(a.value[i]) > getCharValueJoker(b.value[i]))return true;
        if (getCharValueJoker(a.value[i]) < getCharValueJoker(b.value[i]))return false;
    }

    free(occA);
    free(occB);

    return false;
}

static uint32_t solution7_2(const char *test){

    uint32_t cardsCount = 0;

    for (int i = 0; i < strlen(test); ++i)if (test[i] == '\n')++cardsCount;

    struct Card cards[cardsCount];

    uint32_t index = 0;

    for (int i = 0; i < strlen(test); ++i) {

        if (i == 0)for (int j = 0; j < VALUE_SIZE; ++j)cards[index].value[j] = test[i + j];
        else if (test[i - 1] == '\n')for (int j = 0; j < VALUE_SIZE; ++j)cards[index].value[j] = test[i + j];

        else if (test[i - 1] == ' '){

            if ((uint32_t)(test[i] - '0') > 9)continue;
            cards[index].number = 0;

            for (int j = i; j < strlen(test); ++j) {
                if ((uint32_t)(test[j] - '0') > 9)break;
                cards[index].number *= 10;
                cards[index].number += (uint32_t)(test[j] - '0');
            }

            ++index;
        }
    }

    for (int i = 0; i < cardsCount; ++i) {
        int j = i;
        while(j > 0 && cmpCardsJoker(cards[j], cards[j - 1])){

            struct Card tmp = cards[j];
            cards[j] = cards[j - 1];
            cards[j - 1] = tmp;

            j--;
        }
    }

    uint64_t ret = 0;
    for (int i = 0; i < cardsCount; ++i) {
        ret += (i + 1) * cards[i].number;
    }


    return ret;

}