#include <iostream>
#include <format>

struct CarSetup
{
	int frontWing{ 0 };
	int rearWing{ 0 };
	int gearRatio{ 0 };
	int brakeBias{ 0 };
	int tyrePressure{ 0 };
	float rideHeight{ 0.0f };
};

int LapsRemaining(float fuel, float burnRate)
{
	return static_cast<int>(fuel / burnRate);
}

void BurnOneLap(float& fuel, float burnRate)
{
	fuel -= burnRate;
}

float& MakeFuel()
{
	float litres{ 60.0f };
	return litres;
}

void Problem01()
{
	float fuel{ 60.0f };
	float burnRate{ 2.4f };

	std::cout << std::format("laps: {}\n", LapsRemaining(fuel, burnRate));
	BurnOneLap(fuel, burnRate);
	std::cout << std::format("fuel now: {:.1f}\n", fuel);
}

void Adjust(int value) // Will change locally
{
	value += 100;
}

void AdjustRef(int& value) // Will change globally
{
	value += 100;
}

void Problem02()
{
	int downforce{ 10 };
	int& alias{ downforce };

	std::cout << std::format("A: {} {}\n", downforce, alias);

	alias = 25;
	std::cout << std::format("B: {} {}\n", downforce, alias);

	int other{ 99 };
	alias = other;
	std::cout << std::format("C: {} {} {}\n", downforce, alias, other);

	other = 7;
	std::cout << std::format("D: {} {} {}\n", downforce, alias, other);

	Adjust(downforce);
	std::cout << std::format("E: {}\n", downforce);

	AdjustRef(downforce);
	std::cout << std::format("F: {}\n", downforce);

	const int& view{ downforce };
	downforce = 3;
	std::cout << std::format("G: {}\n", view);
}

int TotalDownforce(CarSetup car)
{
	return car.frontWing + car.rearWing;
}

void SoftenSuspension(CarSetup& car, float raiseValue)
{
	car.rideHeight += raiseValue;
}

float FuelForLaps(int laps, float burnRate)
{
	return laps * burnRate;
}

void ApplyPitStop(CarSetup& car, float& fuelLevel, float fuelAdjust, int tyrePressure)
{
	fuelLevel += fuelAdjust;
	car.tyrePressure += tyrePressure;
}

void Problem03()
{
	CarSetup setup{ 12, 18, 4, 55, 22, 45.0f };
	float fuel{ 8.0f };

	std::cout << std::format("downforce: {}\n", TotalDownforce(setup));
	std::cout << std::format("fuel for 20 laps: {:.1f}\n", FuelForLaps(20, 2.4f));

	SoftenSuspension(setup, 5.0f);
	std::cout << std::format("ride height: {:.1f}\n", setup.rideHeight);

	ApplyPitStop(setup, fuel, 100.0f, 2);
	std::cout << std::format("fuel after stop: {:.1f}\n", fuel);
}

void Swap(int& first, int& second)
{
	int temporary{ first };
	first = second;
	second = temporary;
}

int& Fastest(int& lapA, int& lapB)
{
	if (lapA < lapB)
	{
		return lapA;
	}

	return lapB;
}

void Problem04()
{
	int driverOne{ 84 };
	int driverTwo{ 91 };

	Swap(driverOne, driverTwo);
	std::cout << std::format("after swap: {} {}\n", driverOne, driverTwo);

	int& best{ Fastest(driverOne, driverTwo) };
	std::cout << std::format("best lap: {}\n", best);
}

// Problem 5
//int TotalDownforce(const CarSetup& setup); // Originally Copied the entire struct
//void ResetSetup(CarSetup& setup); // Doesnt change anything due to lack of reference
//float AverageLapTime(float lapOne, float lapTwo); // const& slower
//void RecordLap(float& fastestSoFar, float thisLap); // cant update
//int GearFor(const CarSetup& setup, int speed); // Copies the setup
//bool IsLegal(const CarSetup& setup); // Shouldnt change anything

// Problem 6
// 1. Value
// 2. const&
// 3. &
// 4. &
// 5. value
// 6. value
// 7. value

void Stretch()
{
	for (CarSetup setup : { CarSetup{ 12, 18, 4, 55, 22, 45.0f },
							CarSetup{ 15, 22, 5, 52, 20, 40.0f } })
	{
		setup.frontWing += 1;
		std::cout << std::format("front wing: {}\n", setup.frontWing);
	}

	std::cout << std::format("sizeof(CarSetup) = {}\n", sizeof(CarSetup));
}

int main()
{
	//Problem01();
	//Problem02();
	//Problem03();
	//Problem04();
	Stretch();

	return 0;
}