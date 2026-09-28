#include <iostream>
#include <format>
#include <string>

void Problem01()
{
	int health{ 30 };
	int enemyCount{ 3 };

	if (health == 0) // Originally = so health was being set to 0
	{
		std::cout << "Status: dead\n";
	}
	else if (health < 25)
	{
		std::cout << "Status: critical\n";
	}
	else if (enemyCount > 2)
	{
		std::cout << "Status: outnumbered\n";
	}
	else
	{
		std::cout << "Status: ready\n";
	}
}

void Problem02()
{
    int mana{ 0 };
    int arrows{ 5 };
    bool hasStaff{ true };

    if (mana) //Int used as bool
    {
        std::cout << "A: mana\n";
    }

    if (arrows) //Int used as bool
    {
        std::cout << "B: arrows\n";
    }

    if (hasStaff == true) //Redundant check
    {
        std::cout << "C: staff\n";
    }

    if (mana == 10)
    {
        std::cout << "D: mana again\n";
    }

    std::cout << std::format("E: mana is {}\n", mana);

    if (arrows > 3)
        std::cout << "F: plenty of arrows\n";
    std::cout << "G: ready\n";

    if (mana > 5 && arrows > 10)
    {
        std::cout << "H: fully equipped\n";
    }
    else if (mana > 5 || arrows > 10)
    {
        std::cout << "I: partly equipped\n";
    }
}

void TryToCastSpell(bool knowsSpell, int mana, int manaCost, bool isSilenced)
{
    if (!knowsSpell)
    {
        std::cout << "   You do not know that spell.\n";
        return;
    }

    if (isSilenced)
    {
        std::cout << "   You cannot speak.\n";
        return;
    }

    if (mana < manaCost)
    {
        std::cout << "   Not enough mana.\n";
        return; 
    }

    std::cout << "   The spell goes off!\n";
}

enum class DamageType{ Pysical = 0, Fire = 1, Ice = 2, Poison = 3 };
enum class ArmourType{ None, Leather, Chain, Plate };

int ApplyResistance(int damage, DamageType type, ArmourType armour)
{
    int finalDamage{ 0 };
    switch (armour)
    {
        case ArmourType::None:
            finalDamage = damage;
            break;
        case ArmourType::Leather:
            if (type == DamageType::Poison)
            {
                finalDamage = damage / 2;
            }
            else
            {
                finalDamage = damage;
            }
            break;
        case ArmourType::Chain:
            if (type == DamageType::Pysical)
            {
                finalDamage = damage / 2;
            }
            else if (type == DamageType::Ice)
            {
                finalDamage = damage * 2;
            }
            else
            {
                finalDamage = damage;
            }
            break;
        case ArmourType::Plate:
            if (type == DamageType::Pysical)
            {
                finalDamage = damage / 2;
            }
            else if (type == DamageType::Fire || type == DamageType::Ice)
            {
                finalDamage = damage * 2;
            }
            else
            {
                finalDamage = damage;
            }
            break;
    }
    return finalDamage;
}

const char* NameOf(DamageType type)
{
    switch (type)
    {
        case DamageType::Pysical:
            return "pysical";
        case DamageType::Fire:
            return "fire";
        case DamageType::Ice:
            return "ice";
        case DamageType::Poison:
            return "poison";
    }
}

const char* NameOf(ArmourType type)
{
    switch (type)
    {
    case ArmourType::None:
        return "none";
    case ArmourType::Leather:
        return "leather";
    case ArmourType::Chain:
        return "chain";
    case ArmourType::Plate:
        return "plate";
    }
}

void Problem04()
{
    int damage{ 20 };
    DamageType damageType{ DamageType::Fire };
    ArmourType armourType{ ArmourType::Plate };

    int damageTaken{ ApplyResistance(damage, damageType, armourType) };
    std::cout << std::format("{} {} damage against {} becomes {}\n", damage, NameOf(damageType), NameOf(armourType), damageTaken);

    damageType = DamageType::Pysical;
    armourType = ArmourType::Chain;

    damageTaken = ApplyResistance(damage, damageType, armourType);
    std::cout << std::format("{} {} damage against {} becomes {}\n", damage, NameOf(damageType), NameOf(armourType), damageTaken);
}

enum class Command{ MoveNorth, MoveSouth, Attack, Wait, Quit};

void HandleCommand(Command command)
{
    switch (command)
    {
        case Command::MoveNorth:
            std::cout << "   You move north.\n";
            break;
        case Command::MoveSouth:
            std::cout << "   You move south.\n";
            break;
        case Command::Attack:
            std::cout << "   You attack!\n";
            break;
        case Command::Wait:
            std::cout << "   You wait.\n";
            break;
        case Command::Quit:
            std::cout << "   You Quit.\n";
            break;
    }
}

void Problem05()
{
    HandleCommand(Command::MoveNorth);
    HandleCommand(Command::Attack);
    HandleCommand(Command::Quit);
}

int main() 
{
	//Problem01();
	//Problem02();
    //TryToCastSpell(true, 5, 10, false);
    //Problem04();
    Problem05();
	return 0;
}