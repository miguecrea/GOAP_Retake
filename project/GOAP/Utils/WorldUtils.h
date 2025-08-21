// WorldUtils.h
#pragma once
#include <IExamInterface.h>
#include <vector>

class WorldUtils
{
public:
    // Inventory helpers
    static bool InventoryContains(IExamInterface* iFace, eItemType type, int minValue = 0);
    static int CountItems(IExamInterface* iFace, eItemType type);
    static int CountItemsWithValue(IExamInterface* iFace, eItemType type, int minValue);
    static bool HasOpenSlot(IExamInterface* iFace);
    static bool IsInventoryFull(IExamInterface* iFace);

    // Agent helpers
    static bool HasLowHealth(IExamInterface* iFace, float threshold);
    static bool IsHungry(IExamInterface* iFace, float hungerThreshold);

    // Enemy helpers
    static bool EnemyInRange(IExamInterface* iFace, float range);
    static bool EnemiesAllOutOfRange(IExamInterface* iFace, float range);
};
