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
    for (auto card = equipmentCardList.begin(); card != equipmentCardList.end(); ++card) {
        if (*card == equipmentCard) {
            equipmentCardList.erase(card);
            break;
        }
    }
}

bool Equipment::isEquipmentCardExist(const std::string &cardName) const {
    for (auto card : equipmentCardList) {
        if (cardName == card->getCardName()) {
            return true;
        }
    }
    return false;
}

void Equipment::setWeaponCard(WeaponCard *weaponCard) {
    this->weaponCard = weaponCard;
}

bool Equipment::isHasMultiAttack() const {
    if(weaponCard) {
        return weaponCard->isMultiAttack();
    }
    return false;
}

int Equipment::getAttackRange() const {
    if(weaponCard) {
        return weaponCard->getAttackRange();
    }
    return 1;
}

int Equipment::getAddAttackRange() const {
    if(weaponCard) {
        return weaponCard->getAddAttackRange();
    }
    return 0;
}

int Equipment::getDefendAttackRange() const {
    if(weaponCard) {
        return weaponCard->getDefendRange();
    }
    return false;
}

Equipment::~Equipment() {

}
