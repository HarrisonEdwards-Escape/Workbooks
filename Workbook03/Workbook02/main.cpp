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

void Problem02()
{
	std::cout << std::format("9 / 2: {}\n", (9 / 2));
	std::cout << std::format("9 % 2: {}\n", (9 % 2));
	std::cout << std::format("9.0 / 2: {}\n", (9.0 / 2));
	std::cout << std::format("9 / 2.0: {}\n", (9 / 2.0));
	std::cout << std::format("-9 / 2: {}\n", (-9 / 2));
	std::cout << std::format("-9 % 2: {}\n", (-9 % 2));
	std::cout << std::format("9 / 2 * 2: {}\n", (9 / 2 * 2));
	std::cout << std::format("9 * 2 / 2: {}\n", (9 * 2 / 2));
	std::cout << std::format("2 + 3 * 4 - 6 / 2: {}\n", (2 + 3 * 4 - 6 / 2));
	std::cout << std::format("7 > 3: {}\n", (7 > 3));
	std::cout << std::format("0.1 + 0.2 == 0.3: {}\n", (0.1 + 0.2 == 0.3));
}

void Problem03()
{
	unsigned int stock{ 3u };
	unsigned int purchased{ 5u };

	int remaining = stock - purchased; // Subtracting unsigned integers makes them wrap around if they get to < 0

	std::cout << std::format("Stock: {}\n", stock);
	std::cout << std::format("Purchased: {}\n", purchased);
	std::cout << std::format("Remaining: {}\n", remaining);
	std::cout << "Is stock less than purchased? " << (stock < purchased) << "\n";
}

constexpr int WeaponCount{ 4 };

void Problem04()
{
	int currentWeapon{ 3 };
	int nextWeapon{ (currentWeapon + 1) % WeaponCount };
	int previousWeapon{ (currentWeapon - 1) % WeaponCount };

	std::cout << std::format("from {}: next is {}, previous is {}\n", currentWeapon, nextWeapon, previousWeapon);
	currentWeapon = 0;
	nextWeapon = (currentWeapon + 1) % WeaponCount;
	previousWeapon = (currentWeapon + (WeaponCount-1)) % WeaponCount;
	std::cout << std::format("from {}: next is {}, previous is {}\n", currentWeapon, nextWeapon, previousWeapon);
}

int main()
{
	//Problem01();
	//Problem02();
	//Problem03();
	Problem04();
	return 0;
}