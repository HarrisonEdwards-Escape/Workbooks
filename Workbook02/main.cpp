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

int main() 
{
	//Problem01();
	//Problem02();
	Problem03();
	return 0;
}