#include <stdexcept>
#include <string>

using namespace std;
struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string&question, const string& answer)
		: question(question),
		answer(answer),
	result{false, 0, 0}
	{
	}

	bool isDuplicateNumber(const string& guessNumber)
	{
		return (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]);
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch :guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicateNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number");
		}
	}

	void checkStrikes(const string& guessNumber)
	{
		if (guessNumber[0] == answer[0])
			result.strikes++;
		if (guessNumber[1] == answer[1])
			result.strikes++;
		if (guessNumber[2] == answer[2])
			result.strikes++;
	}

	int getStrikes(void)
	{
		return result.strikes;
	}

	GuessResult guess(const string &guessNumber)
	{
		assertIllegalArgument(guessNumber);
		checkStrikes(guessNumber);

		if (result.strikes == 3)
			result.solved = true;

		return result;
	}

private:
	string question;
	string answer;
	GuessResult result;
};
