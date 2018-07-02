//
// Created by daurenabd on 18. 7. 2.
//

#ifndef BOWLING_BOWLING_H
#define BOWLING_BOWLING_H

class Bowling {
private:
    int scores[21];
    int n;
public:
    Bowling ();
    void roll(int points);
    int score();
    int frameScore(int frameIndex);
    bool isSpare(int frameIndex);
    bool isStrike(int frameIndex);
    int strikeBonus(int frameIndex);
    int spareBonus(int frameIndex);


};

#endif //BOWLING_BOWLING_H
