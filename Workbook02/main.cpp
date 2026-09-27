#include <iostream>
#include <format>
#include <limits>
#include <cstdint>
constexpr int MaximumShields{ 120 };
constexpr int MaximumHull{ 200 };

void Problem01()
{
	int currentHull{ 150 };
	int currentShields{ 73 };

	float shieldPercent = static_cast<float>(currentShields) / MaximumShields * 100.0f;
	float hullPercent = static_cast<float>(currentHull) / MaximumHull * 100.0f;

	std::cout << std::format("Shields {:.1f}% Hull {:.1f}%\n", shieldPercent, hullPercent);
}

void Problem02()
{
	int shieldStrength{ 0 };
	float enginePower{ 2.5f };
	bool weaponsArmed{ true };
	int hullPlating{ 46 };
	char shipClass{ 'F' };
	std::cout << std::format("shields {}, engines {}, armed {}, plating {}, class {}\n", shieldStrength, enginePower, weaponsArmed, hullPlating, shipClass);
}

void Problem03()
{
	char callsign{ 'K' };
	int remainingTorpedoes{ 6 };
	double fuelRemaining{ 0.6237 };
	bool isAutopilot{ false };
	long long shipMass{ 4200000000 };

	std::cout << std::format("|{:>10}|{:>8}|\n", "Callsign", callsign);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Torpedoes", remainingTorpedoes);
	std::cout << std::format("|{:>10}|{:>8.2f}|\n", "Fuel", fuelRemaining*100.0f);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Autopilot", isAutopilot);
	std::cout << std::format("|{:>10}|{:>8}|\n", "Mass", shipMass);
}

void Problem04()
{
	std::cout << std::format("bool {} bytes, max {}\n",
		sizeof(bool), std::numeric_limits<bool>::max());
	std::cout << std::format("char {} bytes, max {}\n",
		sizeof(char), static_cast<int>(std::numeric_limits<char>::max()));
	std::cout << std::format("short {} bytes, max {}\n",
		sizeof(short), std::numeric_limits<short>::max());
	std::cout << std::format("int {} bytes, max {}\n",
		sizeof(int), std::numeric_limits<int>::max());
	std::cout << std::format("long long {} bytes, max {}\n",
		sizeof(long long), std::numeric_limits<long long>::max());
	std::cout << std::format("float {} bytes, max {}\n",
		sizeof(float), std::numeric_limits<float>::max());
	std::cout << std::format("uint8_t {} bytes, max {}\n",
		sizeof(std::uint8_t), std::numeric_limits<std::uint8_t>::max());
	std::cout << std::format("int32_t {} bytes, max {}\n",
		sizeof(std::int32_t), std::numeric_limits<std::int32_t>::max());
}

void Problem05()
{
	int currentShields{ 73 };
	int maximumShields{ 120 };

	float percentage = currentShields * 100.00f / maximumShields;

	std::cout << std::format("Shields at {:.1f}%\n", percentage);
}

constexpr int ARankScore{ 5000 };
constexpr int enemyDestroyScore{ 150 };
constexpr int wavesSurvivedScore{ 1000 };
constexpr int secondsRemainingScore{ 25 };

constexpr int maxScore{ (enemyDestroyScore * 40) + (wavesSurvivedScore * 5) + (secondsRemainingScore * 90) };

void Problem06()
{
	int enemiesDestroyed{ 14 };
	int wavesSurvived{ 3 };
	int secondsRemaining{ 47 };

	int score = (enemiesDestroyed * enemyDestroyScore) + (wavesSurvived * wavesSurvivedScore) + (secondsRemaining * secondsRemainingScore);

	if (score > ARankScore)
	{
		std::cout << std::format("Score {} - rank A\n", score);
	}
	else
	{
		std::cout << std::format("Score {} - rank B\n", score);
	}
}

char shipClass{ 'K' };
int hullPoints{ 250 };
int shieldRegenRate{ 2 };
bool isDocked{ false };
auto fuelburn{ 3 / 4 }; //Integer Division
uint8_t crewCount{ 12u };
float turnRadius{ 45.0f };
double missleYield{ 1.5 };

int main() 
{
	//Problem01();
	//Problem02();
	//Problem03();
	//Problem04();
	//Problem05();
	Problem06();
	return 0;
}