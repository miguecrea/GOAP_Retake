#include"Planner.h"
#include"../Actions/Actions.h"
#include"../WorldStates/WorldStates.h"

Planner::Planner(std::vector<BaseWorldState*>* pWorldStates)
{


	//m_Actions =
	//{
	//	std::make_unique<


	//};



	m_Goals =
	{
		std::make_unique<IsInPurgeZoneState>(false),
		std::make_unique<RecentlyBittenState>(false),
		std::make_unique<ZombieInViewState>(false),
		std::make_unique<HasWeaponState>(true),
		std::make_unique<IsHungry>(false),
		std::make_unique<HasSavedUpItem>(true,eItemType::FOOD),
		std::make_unique<IsLoadedWithMedKits>(true),
		std::make_unique<HasVisitedAllSeenHouses>(true),
		std::make_unique<HasSavedWeaponsWithAcceptableAmmo>(true),
	};



}

Planner::~Planner()
{
}

bool Planner::CalculateAction(float elapsedSec, SteeringPlugin_Output& steeringOutput, IExamInterface* iFace)
{
	return false;
}

void Planner::MakeGraph(BaseWorldState* stateToAchieve)
{
}
