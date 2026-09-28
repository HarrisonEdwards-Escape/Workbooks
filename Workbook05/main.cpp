#include <iostream>
#include <format>

void Problem01()
{
	for (int i = 3; i > 0; --i)
	{
		std::cout << std::format("{}...\n", i);
	}
	std::cout << "Liftoff!\n";
}

void Broken1()
{
    for (int i = 1; i < 6; ++i)
    {
        std::cout << std::format("{} ", i);
    }
    std::cout << "\n";
}

void Broken2()
{
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << std::format("{} ", i);
    }
    std::cout << "\n";
}

void Broken3()
{
    int i{ 1 };
    while (i <= 5)
    {
        std::cout << std::format("{} ", i);
        ++i;
    }
    std::cout << "\n";
}

void Broken4()
{
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << std::format("{} ", i);
    }
    std::cout << "\n";
}

void Problem03()
{
    Broken1();
    Broken2();
    Broken3();
    Broken4();
}

int main()
{
	//Problem01();
    //Problem03();
	return 0;
}