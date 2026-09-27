#include <iostream>
#include <format>
#include <cmath>
#include <limits>

constexpr int MaximumArmour{ 50 };

void Problem01()
{
	int currentArmour{ 40 };
	int rawDamage{ 7 };
	float reduction = static_cast<float>(currentArmour) / MaximumArmour;
	float finalDamage = rawDamage * (1.0f - reduction);
	std::cout << std::format("Damage taken: {:.2f}\n", finalDamage);
	std::cout << std::format("Reduction: {:.2f}\n", reduction);
}

int main()
{
	Problem01();
	return 0;
}