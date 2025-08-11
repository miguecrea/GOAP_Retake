
#include"WorldStates.h" 
#include "../../stdafx.h"
#include <IExamInterface.h>


void HasSavedUpFood::Update(float elapsedSec, IExamInterface* iFace)
{
	int currentMedKitCount{ 0 };
	ItemInfo currentItem{};

	m_Predicate = false;

	for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
	{
		if (iFace->Inventory_GetItem(i, currentItem) && currentItem.Type == eItemType::FOOD)
		{
			m_Predicate = true;
			return;
		}
	}
}


void HasSavedUpMedKits::Update(float elapsedSec, IExamInterface* iFace)
{
	int currentMedKitCount{ 0 };
	ItemInfo currentItem{};

	m_Predicate = false;

	for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
	{
		if (iFace->Inventory_GetItem(i, currentItem) && currentItem.Type == eItemType::MEDKIT)
		{
			m_Predicate = true;
			return;
		}
	}
}



void IsLoadedWithMedKits::Update(float elapsedSec, IExamInterface* iFace)
{
	int currentMedKitCount{ 0 };
	ItemInfo currentItem{};

	m_Predicate = false;

	for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
	{
		if (iFace->Inventory_GetItem(i, currentItem) && currentItem.Type == eItemType::MEDKIT)
		{
			++currentMedKitCount;

			if (currentMedKitCount >= m_AcceptableAmountOfMedKits)
			{
				m_Predicate = true;
				return;
			}
		}
	}
}


/////////////
void HasSavedWeaponsWithAcceptableAmmo::Update(float elapsedSec, IExamInterface* iFace)
{

	ItemInfo item;
	int numOfAcceptableWeapons = 0;
	m_Predicate = false;
	for (size_t i = 0; i < iFace->Inventory_GetCapacity(); i++)
	{
		if (iFace->Inventory_GetItem(i, item) &&
			(item.Type == eItemType::PISTOL ||
				item.Type == eItemType::SHOTGUN) && item.Value >= m_AcceptableAmmo)
		{
			++numOfAcceptableWeapons;

			if (numOfAcceptableWeapons >= m_NumberOfAcceptableWeapons)
			{
				m_Predicate = true;
				return;
			}
		}
	}
}


void HasWeaponState::Update(float elapsedSec, IExamInterface* iFace)
{

	ItemInfo item;

	m_Predicate = false;
	for (size_t i = 0; i < iFace->Inventory_GetCapacity(); i++)
	{
		if (iFace->Inventory_GetItem(i, item) &&
			(item.Type == eItemType::PISTOL ||
				item.Type == eItemType::SHOTGUN))
		{
			m_Predicate = true;
			return;
		}
	}
}


void IsHungry::Update(float elapsedSec, IExamInterface* iFace)
{
	float totalEnergyValueInInventory{ 0 };
	ItemInfo currentItem{};
	bool foodInInventory{ false };

	for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
	{
		if (iFace->Inventory_GetItem(i, currentItem) && currentItem.Type == eItemType::FOOD)
		{
			foodInInventory = true;
			totalEnergyValueInInventory += currentItem.Value;
		}
	}

	float actualHungerThreshold =
		!foodInInventory ? m_HungerThresholdIfNoFoodInInventory :
		totalEnergyValueInInventory >= m_MaxEnergyCapacity ? m_LowestHungerThreshold :
		m_MaxEnergyCapacity - totalEnergyValueInInventory;


	m_Predicate = iFace->Agent_GetInfo().Energy <= actualHungerThreshold;
}

void IsHurtState::Update(float elapsedSec, IExamInterface* iFace)
{
	m_Predicate = iFace->Agent_GetInfo().Health < m_HealthThreshold;
}

void IsInHouseState::Update(float elapsedSec, IExamInterface* iFace)
{
	m_Predicate = iFace->Agent_GetInfo().IsInHouse;
}




void NextToFood::Update(float elapsedSec, IExamInterface* iFace)
{

	std::vector<ItemInfo> itemInfo = iFace->GetItemsInFOV();

	m_Predicate = false;
	for (const auto& info : itemInfo)
	{
		if (info.Type == eItemType::MEDKIT)
		{
			if ((info.Location - iFace->Agent_GetInfo().Position).Magnitude() < iFace->Agent_GetInfo().GrabRange)
			{
				m_Predicate = true;
				break;
			}
		}

	}
}

void NextToWeapon::Update(float elapsedSec, IExamInterface* iFace)
{

	std::vector<ItemInfo> itemInfo = iFace->GetItemsInFOV();

	m_Predicate = false;
	for (const auto& info : itemInfo)
	{
		if (info.Type == eItemType::SHOTGUN ||
			info.Type == eItemType::PISTOL)
		{
			if ((info.Location - iFace->Agent_GetInfo().Position).Magnitude() < iFace->Agent_GetInfo().GrabRange)
			{
				m_Predicate = true;
				break;
			}
		}

	}
}

void ZombieInViewState::Update(float elapsedSec, IExamInterface* iFace)
{

	m_Predicate = iFace->FOV_GetStats().NumEnemies > 0;
}

void RecentlyBittenState::Update(float elapsedSec, IExamInterface* iFace)
{

	if (iFace->Agent_GetInfo().WasBitten)
		m_GracePeriod = m_DefaultGracePeriod;

	if (m_GracePeriod > 0)
	{
		m_GracePeriod -= elapsedSec;

		m_Predicate = true;
	}
	else
	{
		m_Predicate = false;
	}
}
