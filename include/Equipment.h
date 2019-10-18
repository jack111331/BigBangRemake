//
// Created by edge on 2019-10-01.
//

#ifndef BIGBANGREMAKE_EQUIPMENT_H
#define BIGBANGREMAKE_EQUIPMENT_H


#include "WeaponCard.h"

class Equipment {
public:
    Equipment();

    bool addEquipmentCard(EquipmentCard *equipmentCard);

    void removeEquipmentCard(EquipmentCard *equipmentCard);

    bool isEquipmentCardExist(const std::string & cardName) const;

    void setWeaponCard(WeaponCard *weaponCard);

    bool isHasMultiAttack() const;

    int getAttackRange() const;

    int getAddAttackRange() const;

    int getDefendAttackRange() const;

    ~Equipment();

private:
    std::vector<EquipmentCard *> equipmentCardList;
    WeaponCard *weaponCard;
};


#endif //BIGBANGREMAKE_EQUIPMENT_H
