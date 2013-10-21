/*
 * Copyright 2012-2013 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// C++ standard includes

// libfalltergeist includes
#include "../src/GcdFileType.h"
#include "../src/DatFileItem.h"

// Third party includes

namespace libfalltergeist
{

GcdFileType::GcdFileType(DatFileEntry * datFileEntry) : DatFileItem(datFileEntry)
{
}

GcdFileType::GcdFileType(std::ifstream * stream) : DatFileItem(stream)
{
}

GcdFileType::~GcdFileType()
{
}

void GcdFileType::_initialize()
{
    if (_initialized) return;
    DatFileItem::_initialize();
    DatFileItem::setPosition(0);

    // unknown 1
    *this >> _unknown1;

    // primary stats
    *this >> _strength >> _perception >> _endurance >> _charisma >> _intelligence >> _agility >> _luck;

    // secondary stats
    *this >> _hitPoints >> _actionPoints >> _armorClass;

    // unknown 2
    *this >> _unknown2;

    *this >> _meleeDamage >> _carryWeight >> _sequence >> _healingRate >> _criticalChance >> _criticalHitModifier
          >> _damageThresholdNormal >> _damageThresholdLaser >> _damageThresholdFire
          >> _damageThresholdPlasma >> _damageThresholdElectrical >> _damageThresholdEMP >> _damageThresholdExplosive
          >> _damageResistanceNormal >> _damageResistanceLaser >> _damageResistanceFire
          >> _damageResistancePlasma >> _damageResistanceElectrical >> _damageResistanceEMP >> _damageResistanceExplosive
          >> _radiationResistance >> _poisonResistance >> _age >> _gender;

    // bonuses to primary stats
    *this >> _strengthBonus >> _perceptionBonus >> _enduranceBonus >> _charismaBonus >> _intelligenceBonus
          >> _agilityBonus >> _luckBonus;

    // bonuses to secondary stats
    *this >> _hitPointsBonus >> _actionPointsBonus >> _armorClassBonus;

    // unknown 3
    *this >> _unknown3;

    *this >> _meleeDamageBonus >> _carryWeightBonus >> _sequenceBonus >> _healingRateBonus
          >> _criticalChanceBonus >> _criticalHitModifierBonus
          >> _damageThresholdNormalBonus >> _damageThresholdLaserBonus >> _damageThresholdFireBonus >> _damageThresholdPlasmaBonus
          >> _damageThresholdElectricalBonus >> _damageThresholdEMPBonus >> _damageThresholdExplosiveBonus
          >> _damageResistanceNormalBonus >> _damageResistanceLaserBonus >> _damageResistanceFireBonus >> _damageResistancePlasmaBonus
          >> _damageResistanceElectricalBonus >> _damageResistanceEMPBonus >> _damageResistanceExplosiveBonus
          >> _radiationResistanceBonus >> _poisonResistanceBonus >> _ageBonus >> _genderBonus;

    //skills
    *this >> _smallGunsSkill
          >> _bigGunsSkill
          >> _energyWeaponsSkill
          >> _unarmedSkill
          >> _meleeWeaponsSkill
          >> _throwingWeaponsSkill
          >> _firstAidSkill
          >> _doctorSkill
          >> _sneakSkill
          >> _lockpickSkill
          >> _stealSkill
          >> _trapsSkill
          >> _scienceSkill
          >> _repairSkill
          >> _speechSkill
          >> _barterSkill
          >> _gamblingSkill
          >> _outdoorsmanSkill;

    // unknown
    *this >> _unknown4 >> _unknown5 >> _unknown6 >> _unknown7;

    // name
    char * name = new char[32]();
    this->readBytes(name, 32);
    setName(name);
    delete [] name;

    *this >> _firstTaggedSkill
          >> _secondTaggedSkill
          >> _thirdTaggedSkill
          >> _fourthTaggedSkill
          >> _firstTrait
          >> _secondTrait
          >> _characterPoints;
}

void GcdFileType::setStrength(unsigned int strength)
{
    _strength = strength;
}

unsigned int GcdFileType::strength()
{
    _initialize();
    return _strength;
}

void GcdFileType::setPerception(unsigned int perception)
{
    _perception = perception;
}

unsigned int GcdFileType::perception()
{
    _initialize();
    return _perception;
}

void GcdFileType::setEndurance(unsigned int endurance)
{
    _endurance = endurance;
}

unsigned int GcdFileType::endurance()
{
    _initialize();
    return _endurance;
}

void GcdFileType::setCharisma(unsigned int charisma)
{
    _charisma = charisma;
}

unsigned int GcdFileType::charisma()
{
    _initialize();
    return _charisma;
}

void GcdFileType::setIntelligence(unsigned int intelligence)
{
    _intelligence = intelligence;
}

unsigned int GcdFileType::intelligence()
{
    _initialize();
    return _intelligence;
}

void GcdFileType::setAgility(unsigned int agility)
{
    _agility = agility;
}

unsigned int GcdFileType::agility()
{
    _initialize();
    return _agility;
}

void GcdFileType::setLuck(unsigned int luck)
{
    _luck = luck;
}

unsigned int GcdFileType::luck()
{
    _initialize();
    return _luck;
}

void GcdFileType::setHitPoints(unsigned int hitPoints)
{
    _hitPoints = hitPoints;
}

unsigned int GcdFileType::hitPoints()
{
    _initialize();
    return _hitPoints;
}

void GcdFileType::setActionPoints(unsigned int actionPoints)
{
    _actionPoints = actionPoints;
}

unsigned int GcdFileType::actionPoints()
{
    _initialize();
    return _actionPoints;
}

void GcdFileType::setArmorClass(unsigned int armorClass)
{
    _armorClass = armorClass;
}

unsigned int GcdFileType::armorClass()
{
    _initialize();
    return _armorClass;
}

void GcdFileType::setMeleeDamage(unsigned int meleeDamage)
{
    _meleeDamage = meleeDamage;
}

unsigned int GcdFileType::meleeDamage()
{
    _initialize();
    return _meleeDamage;
}

void GcdFileType::setCarryWeight(unsigned int carryWeight)
{
    _carryWeight = carryWeight;
}

unsigned int GcdFileType::carryWeight()
{
    _initialize();
    return _carryWeight;
}

void GcdFileType::setSequence(unsigned int sequence)
{
    _sequence = sequence;
}

unsigned int GcdFileType::sequence()
{
    _initialize();
    return _sequence;
}

void GcdFileType::setHealingRate(unsigned int healingRate)
{
    _healingRate = healingRate;
}

unsigned int GcdFileType::healingRate()
{
    _initialize();
    return _healingRate;
}

void GcdFileType::setCriticalChance(unsigned int criticalChance)
{
    _criticalChance = criticalChance;
}

unsigned int GcdFileType::criticalChance()
{
    _initialize();
    return _criticalChance;
}

void GcdFileType::setCriticalHitModifier(unsigned int criticalHitModifier)
{
    _criticalHitModifier = criticalHitModifier;
}

unsigned int GcdFileType::criticalHitModifier()
{
    _initialize();
    return _criticalHitModifier;
}

void GcdFileType::setDamageThresholdNormal(unsigned int damageThresholdNormal)
{
    _damageThresholdNormal = damageThresholdNormal;
}

unsigned int GcdFileType::damageThresholdNormal()
{
    _initialize();
    return _damageThresholdNormal;
}

void GcdFileType::setDamageThresholdLaser(unsigned int damageThresholdLaser)
{
    _damageThresholdLaser = damageThresholdLaser;
}

unsigned int GcdFileType::damageThresholdLaser()
{
    _initialize();
    return _damageThresholdLaser;
}

void GcdFileType::setDamageThresholdFire(unsigned int damageThresholdFire)
{
    _damageThresholdFire = damageThresholdFire;
}

unsigned int GcdFileType::damageThresholdFire()
{
    _initialize();
    return _damageThresholdFire;
}

void GcdFileType::setDamageThresholdPlasma(unsigned int damageThresholdPlasma)
{
    _damageThresholdPlasma = damageThresholdPlasma;
}

unsigned int GcdFileType::damageThresholdPlasma()
{
    _initialize();
    return _damageThresholdPlasma;
}

void GcdFileType::setDamageThresholdElectrical(unsigned int damageThresholdElectrical)
{
    _damageThresholdElectrical = damageThresholdElectrical;
}

unsigned int GcdFileType::damageThresholdElectrical()
{
    _initialize();
    return _damageThresholdElectrical;
}

void GcdFileType::setDamageThresholdEMP(unsigned int damageThresholdEMP)
{
    _damageThresholdEMP = damageThresholdEMP;
}

unsigned int GcdFileType::damageThresholdEMP()
{
    _initialize();
    return _damageThresholdEMP;
}

void GcdFileType::setDamageThresholdExplosive(unsigned int damageThresholdExplosive)
{
    _damageThresholdExplosive = damageThresholdExplosive;
}

unsigned int GcdFileType::damageThresholdExplosive()
{
    _initialize();
    return _damageThresholdExplosive;
}

void GcdFileType::setDamageResistanceNormal(unsigned int damageResistanceNormal)
{
    _damageResistanceNormal = damageResistanceNormal;
}

unsigned int GcdFileType::damageResistanceNormal()
{
    _initialize();
    return _damageResistanceNormal;
}

void GcdFileType::setDamageResistanceLaser(unsigned int damageResistanceLaser)
{
    _damageResistanceLaser = damageResistanceLaser;
}

unsigned int GcdFileType::damageResistanceLaser()
{
    _initialize();
    return _damageResistanceLaser;
}

void GcdFileType::setDamageResistanceFire(unsigned int damageResistanceFire)
{
    _damageResistanceFire = damageResistanceFire;
}

unsigned int GcdFileType::damageResistanceFire()
{
    _initialize();
    return _damageResistanceFire;
}

void GcdFileType::setDamageResistancePlasma(unsigned int damageResistancePlasma)
{
    _damageResistancePlasma = damageResistancePlasma;
}

unsigned int GcdFileType::damageResistancePlasma()
{
    _initialize();
    return _damageResistancePlasma;
}

void GcdFileType::setDamageResistanceElectrical(unsigned int damageResistanceElectrical)
{
    _damageResistanceElectrical = damageResistanceElectrical;
}

unsigned int GcdFileType::damageResistanceElectrical()
{
    _initialize();
    return _damageResistanceElectrical;
}

void GcdFileType::setDamageResistanceEMP(unsigned int damageResistanceEMP)
{
    _damageResistanceEMP = damageResistanceEMP;
}

unsigned int GcdFileType::damageResistanceEMP()
{
    _initialize();
    return _damageResistanceEMP;
}

void GcdFileType::setDamageResistanceExplosive(unsigned int damageResistanceExplosive)
{
    _damageResistanceExplosive = damageResistanceExplosive;
}

unsigned int GcdFileType::damageResistanceExplosive()
{
    _initialize();
    return _damageResistanceExplosive;
}

void GcdFileType::setRadiationResistance(unsigned int radiationResistance)
{
    _radiationResistance = radiationResistance;
}

unsigned int GcdFileType::radiationResistance()
{
    _initialize();
    return _radiationResistance;
}

void GcdFileType::setPoisonResistance(unsigned int poisonResistance)
{
    _poisonResistance = poisonResistance;
}

unsigned int GcdFileType::poisonResistance()
{
    _initialize();
    return _poisonResistance;
}

void GcdFileType::setAge(unsigned int age)
{
    _age = age;
}

unsigned int GcdFileType::age()
{
    _initialize();
    return _age;
}

void GcdFileType::setGender(unsigned int gender)
{
    _gender = gender;
}

unsigned int GcdFileType::gender()
{
    _initialize();
    return _gender;
}

void GcdFileType::setStrengthBonus(unsigned int strengthBonus)
{
    _strengthBonus = strengthBonus;
}

unsigned int GcdFileType::strengthBonus()
{
    _initialize();
    return _strengthBonus;
}

void GcdFileType::setPerceptionBonus(unsigned int perceptionBonus)
{
    _perceptionBonus = perceptionBonus;
}

unsigned int GcdFileType::perceptionBonus()
{
    _initialize();
    return _perceptionBonus;
}

void GcdFileType::setEnduranceBonus(unsigned int enduranceBonus)
{
    _enduranceBonus = enduranceBonus;
}

unsigned int GcdFileType::enduranceBonus()
{
    _initialize();
    return _enduranceBonus;
}

void GcdFileType::setCharismaBonus(unsigned int charismaBonus)
{
    _charismaBonus = charismaBonus;
}

unsigned int GcdFileType::charismaBonus()
{
    _initialize();
    return _charismaBonus;
}

void GcdFileType::setIntelligenceBonus(unsigned int intelligenceBonus)
{
    _intelligenceBonus = intelligenceBonus;
}

unsigned int GcdFileType::intelligenceBonus()
{
    _initialize();
    return _intelligenceBonus;
}

void GcdFileType::setAgilityBonus(unsigned int agilityBonus)
{
    _agilityBonus = agilityBonus;
}

unsigned int GcdFileType::agilityBonus()
{
    _initialize();
    return _agilityBonus;
}

void GcdFileType::setLuckBonus(unsigned int luckBonus)
{
    _luckBonus = luckBonus;
}

unsigned int GcdFileType::luckBonus()
{
    _initialize();
    return _luckBonus;
}

void GcdFileType::setHitPointsBonus(unsigned int hitPointsBonus)
{
    _hitPointsBonus = hitPointsBonus;
}

unsigned int GcdFileType::hitPointsBonus()
{
    _initialize();
    return _hitPointsBonus;
}

void GcdFileType::setActionPointsBonus(unsigned int actionPointsBonus)
{
    _actionPointsBonus = actionPointsBonus;
}

unsigned int GcdFileType::actionPointsBonus()
{
    _initialize();
    return _actionPointsBonus;
}

void GcdFileType::setArmorClassBonus(unsigned int armorClassBonus)
{
    _armorClassBonus = armorClassBonus;
}

unsigned int GcdFileType::armorClassBonus()
{
    _initialize();
    return _armorClassBonus;
}

void GcdFileType::setMeleeDamageBonus(unsigned int meleeDamageBonus)
{
    _meleeDamageBonus = meleeDamageBonus;
}

unsigned int GcdFileType::meleeDamageBonus()
{
    _initialize();
    return _meleeDamageBonus;
}

void GcdFileType::setCarryWeightBonus(unsigned int carryWeightBonus)
{
    _carryWeightBonus = carryWeightBonus;
}

unsigned int GcdFileType::carryWeightBonus()
{
    _initialize();
    return _carryWeightBonus;
}

void GcdFileType::setSequenceBonus(unsigned int sequenceBonus)
{
    _sequenceBonus = sequenceBonus;
}

unsigned int GcdFileType::sequenceBonus()
{
    _initialize();
    return _sequenceBonus;
}

void GcdFileType::setHealingRateBonus(unsigned int healingRateBonus)
{
    _healingRateBonus = healingRateBonus;
}

unsigned int GcdFileType::healingRateBonus()
{
    _initialize();
    return _healingRateBonus;
}

void GcdFileType::setCriticalChanceBonus(unsigned int criticalChanceBonus)
{
    _criticalChanceBonus = criticalChanceBonus;
}

unsigned int GcdFileType::criticalChanceBonus()
{
    _initialize();
    return _criticalChanceBonus;
}

void GcdFileType::setCriticalHitModifierBonus(unsigned int criticalHitModifierBonus)
{
    _criticalHitModifierBonus = criticalHitModifierBonus;
}

unsigned int GcdFileType::criticalHitModifierBonus()
{
    _initialize();
    return _criticalHitModifierBonus;
}

void GcdFileType::setDamageThresholdNormalBonus(unsigned int damageThresholdNormalBonus)
{
    _damageThresholdNormalBonus = damageThresholdNormalBonus;
}

unsigned int GcdFileType::damageThresholdNormalBonus()
{
    _initialize();
    return _damageThresholdNormalBonus;
}

void GcdFileType::setDamageThresholdLaserBonus(unsigned int damageThresholdLaserBonus)
{
    _damageThresholdLaserBonus = damageThresholdLaserBonus;
}

unsigned int GcdFileType::damageThresholdLaserBonus()
{
    _initialize();
    return _damageThresholdLaserBonus;
}

void GcdFileType::setDamageThresholdFireBonus(unsigned int damageThresholdFireBonus)
{
    _damageThresholdFireBonus = damageThresholdFireBonus;
}

unsigned int GcdFileType::damageThresholdFireBonus()
{
    _initialize();
    return _damageThresholdFireBonus;
}

void GcdFileType::setDamageThresholdPlasmaBonus(unsigned int damageThresholdPlasmaBonus)
{
    _damageThresholdPlasmaBonus = damageThresholdPlasmaBonus;
}

unsigned int GcdFileType::damageThresholdPlasmaBonus()
{
    _initialize();
    return _damageThresholdPlasmaBonus;
}

void GcdFileType::setDamageThresholdElectricalBonus(unsigned int damageThresholdElectricalBonus)
{
    _damageThresholdElectricalBonus = damageThresholdElectricalBonus;
}

unsigned int GcdFileType::damageThresholdElectricalBonus()
{
    _initialize();
    return _damageThresholdElectricalBonus;
}

void GcdFileType::setDamageThresholdEMPBonus(unsigned int damageThresholdEMPBonus)
{
    _damageThresholdEMPBonus = damageThresholdEMPBonus;
}

unsigned int GcdFileType::damageThresholdEMPBonus()
{
    _initialize();
    return _damageThresholdEMPBonus;
}

void GcdFileType::setDamageThresholdExplosiveBonus(unsigned int damageThresholdExplosiveBonus)
{
    _damageThresholdExplosiveBonus = damageThresholdExplosiveBonus;
}

unsigned int GcdFileType::damageThresholdExplosiveBonus()
{
    _initialize();
    return _damageThresholdExplosiveBonus;
}

void GcdFileType::setDamageResistanceNormalBonus(unsigned int damageResistanceNormalBonus)
{
    _damageResistanceNormalBonus = damageResistanceNormalBonus;
}

unsigned int GcdFileType::damageResistanceNormalBonus()
{
    _initialize();
    return _damageResistanceNormalBonus;
}

void GcdFileType::setDamageResistanceLaserBonus(unsigned int damageResistanceLaserBonus)
{
    _damageResistanceLaserBonus = damageResistanceLaserBonus;
}

unsigned int GcdFileType::damageResistanceLaserBonus()
{
    _initialize();
    return _damageResistanceLaserBonus;
}

void GcdFileType::setDamageResistanceFireBonus(unsigned int damageResistanceFireBonus)
{
    _damageResistanceFireBonus = damageResistanceFireBonus;
}

unsigned int GcdFileType::damageResistanceFireBonus()
{
    _initialize();
    return _damageResistanceFireBonus;
}

void GcdFileType::setDamageResistancePlasmaBonus(unsigned int damageResistancePlasmaBonus)
{
    _damageResistancePlasmaBonus = damageResistancePlasmaBonus;
}

unsigned int GcdFileType::damageResistancePlasmaBonus()
{
    _initialize();
    return _damageResistancePlasmaBonus;
}

void GcdFileType::setDamageResistanceElectricalBonus(unsigned int damageResistanceElectricalBonus)
{
    _damageResistanceElectricalBonus = damageResistanceElectricalBonus;
}

unsigned int GcdFileType::damageResistanceElectricalBonus()
{
    _initialize();
    return _damageResistanceElectricalBonus;
}

void GcdFileType::setDamageResistanceEMPBonus(unsigned int damageResistanceEMPBonus)
{
    _damageResistanceEMPBonus = damageResistanceEMPBonus;
}

unsigned int GcdFileType::damageResistanceEMPBonus()
{
    _initialize();
    return _damageResistanceEMPBonus;
}

void GcdFileType::setDamageResistanceExplosiveBonus(unsigned int damageResistanceExplosiveBonus)
{
    _damageResistanceExplosiveBonus = damageResistanceExplosiveBonus;
}

unsigned int GcdFileType::damageResistanceExplosiveBonus()
{
    _initialize();
    return _damageResistanceExplosiveBonus;
}

void GcdFileType::setRadiationResistanceBonus(unsigned int radiationResistanceBonus)
{
    _radiationResistanceBonus = radiationResistanceBonus;
}

unsigned int GcdFileType::radiationResistanceBonus()
{
    _initialize();
    return _radiationResistanceBonus;
}

void GcdFileType::setPoisonResistanceBonus(unsigned int poisonResistanceBonus)
{
    _poisonResistanceBonus = poisonResistanceBonus;
}

unsigned int GcdFileType::poisonResistanceBonus()
{
    _initialize();
    return _poisonResistanceBonus;
}

void GcdFileType::setAgeBonus(unsigned int ageBonus)
{
    _ageBonus = ageBonus;
}

unsigned int GcdFileType::ageBonus()
{
    _initialize();
    return _ageBonus;
}

void GcdFileType::setGenderBonus(unsigned int genderBonus)
{
    _genderBonus = genderBonus;
}

unsigned int GcdFileType::genderBonus()
{
    _initialize();
    return _genderBonus;
}

void GcdFileType::setSmallGunsSkill(unsigned int smallGunsSkill)
{
    _smallGunsSkill = smallGunsSkill;
}

unsigned int GcdFileType::smallGunsSkill()
{
    _initialize();
    return _smallGunsSkill;
}

void GcdFileType::setBigGunsSkill(unsigned int bigGunsSkill)
{
    _bigGunsSkill = bigGunsSkill;
}

unsigned int GcdFileType::bigGunsSkill()
{
    _initialize();
    return _bigGunsSkill;
}

void GcdFileType::setEnergyWeaponsSkill(unsigned int energyWeaponsSkill)
{
    _energyWeaponsSkill = energyWeaponsSkill;
}

unsigned int GcdFileType::energyWeaponsSkill()
{
    _initialize();
    return _energyWeaponsSkill;
}

void GcdFileType::setUnarmedSkill(unsigned int unarmedSkill)
{
    _unarmedSkill = unarmedSkill;
}

unsigned int GcdFileType::unarmedSkill()
{
    _initialize();
    return _unarmedSkill;
}

void GcdFileType::setMeleeWeaponsSkill(unsigned int meleeWeaponsSkill)
{
    _meleeWeaponsSkill = meleeWeaponsSkill;
}

unsigned int GcdFileType::meleeWeaponsSkill()
{
    _initialize();
    return _meleeWeaponsSkill;
}

void GcdFileType::setThrowingWeaponsSkill(unsigned int throwingWeaponsSkill)
{
    _throwingWeaponsSkill = throwingWeaponsSkill;
}

unsigned int GcdFileType::throwingWeaponsSkill()
{
    _initialize();
    return _throwingWeaponsSkill;
}

void GcdFileType::setFirstAidSkill(unsigned int firstAidSkill)
{
    _firstAidSkill = firstAidSkill;
}

unsigned int GcdFileType::firstAidSkill()
{
    _initialize();
    return _firstAidSkill;
}

void GcdFileType::setDoctorSkill(unsigned int doctorSkill)
{
    _doctorSkill = doctorSkill;
}

unsigned int GcdFileType::doctorSkill()
{
    _initialize();
    return _doctorSkill;
}

void GcdFileType::setSneakSkill(unsigned int sneakSkill)
{
    _sneakSkill = sneakSkill;
}

unsigned int GcdFileType::sneakSkill()
{
    _initialize();
    return _sneakSkill;
}

void GcdFileType::setLockpickSkill(unsigned int lockpickSkill)
{
    _lockpickSkill = lockpickSkill;
}

unsigned int GcdFileType::lockpickSkill()
{
    _initialize();
    return _lockpickSkill;
}

void GcdFileType::setStealSkill(unsigned int stealSkill)
{
    _stealSkill = stealSkill;
}

unsigned int GcdFileType::stealSkill()
{
    _initialize();
    return _stealSkill;
}

void GcdFileType::setTrapsSkill(unsigned int trapsSkill)
{
    _trapsSkill = trapsSkill;
}

unsigned int GcdFileType::trapsSkill()
{
    _initialize();
    return _trapsSkill;
}

void GcdFileType::setScienceSkill(unsigned int scienceSkill)
{
    _scienceSkill = scienceSkill;
}

unsigned int GcdFileType::scienceSkill()
{
    _initialize();
    return _scienceSkill;
}

void GcdFileType::setRepairSkill(unsigned int repairSkill)
{
    _repairSkill = repairSkill;
}

unsigned int GcdFileType::repairSkill()
{
    _initialize();
    return _repairSkill;
}

void GcdFileType::setSpeechSkill(unsigned int speechSkill)
{
    _speechSkill = speechSkill;
}

unsigned int GcdFileType::speechSkill()
{
    _initialize();
    return _speechSkill;
}

void GcdFileType::setBarterSkill(unsigned int barterSkill)
{
    _barterSkill = barterSkill;
}

unsigned int GcdFileType::barterSkill()
{
    _initialize();
    return _barterSkill;
}

void GcdFileType::setGamblingSkill(unsigned int gamblingSkill)
{
    _gamblingSkill = gamblingSkill;
}

unsigned int GcdFileType::gamblingSkill()
{
    _initialize();
    return _gamblingSkill;
}

void GcdFileType::setOutdoorsmanSkill(unsigned int outdoorsmanSkill)
{
    _outdoorsmanSkill = outdoorsmanSkill;
}

unsigned int GcdFileType::outdoorsmanSkill()
{
    _initialize();
    return _outdoorsmanSkill;
}

void GcdFileType::setName(std::string name)
{
    _name = name;
}

std::string GcdFileType::name()
{
    _initialize();
    return _name;
}

void GcdFileType::setFirstTaggedSkill(int firstTaggedSkill)
{
    _firstTaggedSkill = firstTaggedSkill;
}

int GcdFileType::firstTaggedSkill()
{
    _initialize();
    return _firstTaggedSkill;
}

void GcdFileType::setSecondTaggedSkill(int secondTaggedSkill)
{
    _secondTaggedSkill = secondTaggedSkill;
}

int GcdFileType::secondTaggedSkill()
{
    _initialize();
    return _secondTaggedSkill;
}

void GcdFileType::setThirdTaggedSkill(int thirdTaggedSkill)
{
    _thirdTaggedSkill = thirdTaggedSkill;
}

int GcdFileType::thirdTaggedSkill()
{
    _initialize();
    return _thirdTaggedSkill;
}

void GcdFileType::setFourthTaggedSkill(int fourthTaggedSkill)
{
    _fourthTaggedSkill = fourthTaggedSkill;
}

int GcdFileType::fourthTaggedSkill()
{
    _initialize();
    return _fourthTaggedSkill;
}

void GcdFileType::setFirstTrait(int firstTrait)
{
    _firstTrait = firstTrait;
}

int GcdFileType::firstTrait()
{
    _initialize();
    return _firstTrait;
}

void GcdFileType::setSecondTrait(int secondTrait)
{
    _secondTrait = secondTrait;
}

int GcdFileType::secondTrait()
{
    _initialize();
    return _secondTrait;
}

void GcdFileType::setCharacterPoints(unsigned int characterPoints)
{
     _characterPoints = characterPoints;
}

unsigned int GcdFileType::characterPoints()
{
    _initialize();
    return _characterPoints;
}
































}
