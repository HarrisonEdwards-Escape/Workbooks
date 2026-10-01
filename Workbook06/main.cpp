#include <iostream>
#include <format>

void PrintReport(int total)
{
	std::cout << std::format("Total: {}\n", total);
}

int TotalDamage(int hits, int perHit)
{
	return hits * perHit;
}

void Mystery()
{
	int counter{ 0 };
	static int tally{ 0 };

	++counter;
	++tally;

	std::cout << std::format("counter {}, tally {}\n", counter, tally);
}

void Problem02()
{
	int value{ 5 };
	std::cout << std::format("A: {}\n", value);

	{
		int value{ 50 };
		std::cout << std::format("B: {}\n", value);
		value += 5;
		std::cout << std::format("C: {}\n", value);
	}

	std::cout << std::format("D: {}\n", value);

	Mystery();
	Mystery();
	Mystery();
}

void DrinkPotion(int &health)
{
	health += 25;
	std::cout << std::format("   You feel better. Health is now {}\n", health);
}

void Problem03()
{
	int playerHealth{ 40 };

	std::cout << std::format("Health: {}\n", playerHealth);
	DrinkPotion(playerHealth);
	std::cout << std::format("Health: {}\n", playerHealth);
}

float PercentageOf(int part, int whole)
{
	return static_cast<float>(part) / whole;
}

void PrintStat(const char* label, int value)
{
	std::cout << std::format("{:>11}:{:>5}\n", label, value);
}

void PrintStat(const char* label, float value)
{
	std::cout << std::format("{:>11}:{:>5.1f}\n", label, value);
}

void PrintSeparator(int width, char symbol = '-')
{
	std::cout << std::format("{:-<20}", symbol) << "\n";
}

void Problem04()
{
	int health{ 40 };
	int maxHealth{ 60 };

	PrintSeparator(10);
	PrintStat("Health", health);
	PrintStat("Max Health", maxHealth);
	PrintStat("Health", static_cast<float>(health) / maxHealth);
}

int main()
{
	//int hitCount{ 3 };
	//int damagePerHit{ 7 };

	//int total = TotalDamage(hitCount, damagePerHit);
	//PrintReport(total);

	//Problem02();
	//Problem03();
	Problem04();

	return 0;
}