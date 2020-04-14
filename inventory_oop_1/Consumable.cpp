#include "Consumable.h"

//------------------------------------------------------------------------------
Consumable::Consumable()
    :Item("Consumable", true),
     effect()
{
    this->uses    = 0;
}

//------------------------------------------------------------------------------
void Consumable::display(std::ostream& outs) const
{
    Item:display(outs);
    outs << "Nme" << ": " << getName() << "\n"
         << "Eft" << ": " << getEffect() << "\n"
         << "Use" << ": " << getNumberOfUses() << "\n"
         << "Qty" << ": " << getNumberOfUses()
         << "\n";
}
//

void Consumable::read(std::istream& ins){
}
Item* Consumable::clone() const{
    return nullptr;
}