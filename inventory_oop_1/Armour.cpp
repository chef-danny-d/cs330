#include "Armour.h"

//------------------------------------------------------------------------------
Armour::Armour()
    :Item("Armour", false), // There should be something simliar in Consumable.cpp
     material(),
     modifier()
{
    this->durability    = 0;
    this->defense       = 0;
    this->modifierLevel = 1;
}

//------------------------------------------------------------------------------
void Armour::display(std::ostream& outs) const
{
    // Implement this function
    Item::display(outs);
    outs << "Nme" << ": " << getName() << "\n"
         << "Dur" << ": " << getDurability() << "\n"
         << "Def" << ": " << getDefense() << "\n"
         << "Mtl" << ": " << getMaterial() << "\n"
         << "Mdr" << ": " << getModifier() << "\n"
         << "Emt" << ": " << getElement()
         << "\n";
}

//------------------------------------------------------------------------------
void Armour::read(std::istream& ins)
{
    // Implement this function
}

//------------------------------------------------------------------------------
Item* Armour::clone() const
{
    // Implement this function
    return nullptr; // remove this line
}

