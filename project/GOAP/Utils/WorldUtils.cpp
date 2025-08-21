//// WorldUtils.cpp
//#include "WorldUtils.h"

////#include "../../stdafx.h"
////#include "../Memory/Memory.h"
//
//
//
//bool WorldUtils::InventoryContains(IExamInterface * iFace, eItemType type, int minValue)
//{
//    ItemInfo item{};
//    for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
//    {
//        if (iFace->Inventory_GetItem(i, item) && item.Type == type && item.Value >= minValue)
//            return true;
//    }
//    return false;
//}
//
//int WorldUtils::CountItems(IExamInterface * iFace, eItemType type)
//{
//    int count = 0;
//    /*ItemInfo item{};
//    for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
//    {
//        if (iFace->Inventory_GetItem(i, item) && item.Type == type)
//            ++count;
//    }*/
//    return count;
//}
//
//int WorldUtils::CountItemsWithValue(IExamInterface* iFace, eItemType type, int minValue)
//{
//    int count = 0;
//    ItemInfo item{};
//
//   /* for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
//    {
//        if (iFace->Inventory_GetItem(i, item) && item.Type == type && item.Value >= minValue)
//            ++count;
//    }*/
//    return count;
//}
//
//bool WorldUtils::HasOpenSlot(IExamInterface* iFace)
//{
//    ItemInfo item{};
//  /*  for (UINT i = 0; i < iFace->Inventory_GetCapacity(); i++)
//    {
//        if (!iFace->Inventory_GetItem(i, item))
//            return true;
//    }*/
//    return false;
//}
//
//bool WorldUtils::IsInventoryFull(IExamInterface* iFace)
//{
//    return !HasOpenSlot(iFace);
//}
//
//bool WorldUtils::HasLowHealth(IExamInterface* iFace, float threshold)
//{
//    return iFace->Agent_GetInfo().Health < threshold;
//}
//
//bool WorldUtils::IsHungry(IExamInterface* iFace, float hungerThreshold)
//{
//    return iFace->Agent_GetInfo().Energy <= hungerThreshold;
//}
//
//bool WorldUtils::EnemyInRange(IExamInterface* iFace, float range)
//{
//   /* auto enemies = iFace->GetEnemiesInFOV();
//    Elite::Vector2 agentPos = iFace->Agent_GetInfo().Position;
//
//    for (const auto& e : enemies)
//        if ((e.Location - agentPos).Magnitude() < range)
//            return true;*/
//    return false;
//}
//
//bool WorldUtils::EnemiesAllOutOfRange(IExamInterface* iFace, float range)
//{
//   /* auto enemies = iFace->GetEnemiesInFOV();
//    Elite::Vector2 agentPos = iFace->Agent_GetInfo().Position;
//
//    for (const auto& e : enemies)
//        if ((e.Location - agentPos).Magnitude() <= range)
//            return false;*/
//    return true;
//}
