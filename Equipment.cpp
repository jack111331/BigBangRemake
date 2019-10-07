//this,
// Created by edge on 2019-10-01.
//

#include "Equipment.h"

Equipment::Equipment() {

}

bool Equipment::addEquipmentCard(EquipmentCard *equipmentCard) {
    for (auto card : equipmentCardList) {
        if (card == equipmentCard) {
            return false;
        }
    }
    equipmentCardList.push_back(equipmentCard);
    return true;
}

void Equipment::removeEquipmentCard(EquipmentCard *equipmentCard) {
    for(auto card = equipmentCardList.begin();card != equipmentCardList.end();++card) {
        if(*card == equipmentCard) {
            equipmentCardList.erase(card);
            break;
        }
    }
}

bool Equipment::isEquipmentCardExist(const std::string & cardName) const{
    for (auto card : equipmentCardList) {
        if (cardName == card->getCardName()) {
            return true;
        }
    }
    return false;
}


WeaponCard *Equipment::getWeaponCard() const {
    return weaponCard;
}

void Equipment::setWeaponCard(WeaponCard *weaponCard) {
    Equipment::weaponCard = weaponCard;
}

Equipment::~Equipment() {

}
