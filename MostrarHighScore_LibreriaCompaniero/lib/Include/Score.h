#ifndef SCORE_H
#define SCORE_H

#include <iostream>
using namespace std;

class Score
{
public:
	int scoreValue;
	string scorePlayer;

	Score(string player, int value);
	Score();
	~Score();
	void setPlayer(string player);
	void setScore(int score);
};

#endif