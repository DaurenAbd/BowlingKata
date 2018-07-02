//
// Created by daurenabd on 18. 7. 2.
//

#include "Bowling.h"

Bowling::Bowling() {
    currentRoll = 0;
}

void Bowling::roll(int pins) {
    rolls[currentRoll++] = pins;
}

int Bowling::score() {
    int score = 0;
    int frameIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (isStrike(frameIndex)) {
            score += 10 + strikeBonus(frameIndex);
            frameIndex++;
        } else if (isSpare(frameIndex)) {
            score += 10 + spareBonus(frameIndex);
            frameIndex += 2;
        } else {
            score += frameScore(frameIndex);
            frameIndex += 2;
        }
    }

    return score;
}

int Bowling::frameScore(int frameIndex) {
    return rolls[frameIndex] + rolls[frameIndex + 1];
}

bool Bowling::isSpare(int frameIndex) {
    return frameScore(frameIndex) == 10 &&
           rolls[frameIndex] > 0 &&
           rolls[frameIndex + 1] > 0;
}

bool Bowling::isStrike(int frameIndex) {
    return rolls[frameIndex] == 10;
}

int Bowling::strikeBonus(int frameIndex) {
    return rolls[frameIndex + 1] + rolls[frameIndex + 2];
}

int Bowling::spareBonus(int frameIndex) {
    return rolls[frameIndex + 2];
}
