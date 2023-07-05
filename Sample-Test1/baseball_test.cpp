#include "pch.h"
#include "../baseball/baseball.cpp"

#include <string>
using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e)
		{

		}
	}
	
};

TEST_F(BaseballFixture, ThrowExpectionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}