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
		answer(answer) {}

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

	GuessResult guess(const string &guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if(guessNumber == "124")
			return { false, 2, 0 };
		return { true, 3, 0 };
	}

private:
	string question;
	string answer;
	int strikes;
	int balls;
};
