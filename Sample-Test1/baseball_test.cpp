#include "pch.h"
#include "../baseball/baseball.cpp"

#include <string>
using namespace std;

TEST(BaseballGame, TryGameTest) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(BaseballGame, ThrowExpectionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExpectionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}