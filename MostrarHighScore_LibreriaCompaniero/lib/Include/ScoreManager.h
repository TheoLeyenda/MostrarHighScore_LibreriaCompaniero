#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <vector>
#include "Score.h"

using namespace std;


static struct PlayerComparer
{
	bool operator ()(Score i, Score j)
	{
		return (i.scoreValue > j.scoreValue);
	}
}comparer;

class ScoreManager{

private:
	Score HighScore;
	vector<Score> scoreList;

public:
	ScoreManager();
	~ScoreManager();
	void AddScore(Score score);
	void AddScore(string player, int value);
	Score getHighScore();
	vector<Score> getScoreBoard();
};

#endif