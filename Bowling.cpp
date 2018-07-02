//
// Created by daurenabd on 18. 7. 2.
//

#include "Bowling.h"

Bowling::Bowling() {
    n = 0;
}

void Bowling::roll(int points) {
    scores[n++] = points;
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
    return scores[frameIndex] + scores[frameIndex + 1];
}

bool Bowling::isSpare(int frameIndex) {
    return frameScore(frameIndex) == 10 &&
           scores[frameIndex] > 0 &&
           scores[frameIndex + 1] > 0;
}

bool Bowling::isStrike(int frameIndex) {
    return scores[frameIndex] == 10;
}

int Bowling::strikeBonus(int frameIndex) {
    return scores[frameIndex + 1] + scores[frameIndex + 2];
}

int Bowling::spareBonus(int frameIndex) {
    return scores[frameIndex + 2];
}
