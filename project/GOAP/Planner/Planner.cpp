#include"Planner.h"
#include"../Actions/Actions.h"
#include"../WorldStates/WorldStates.h"

Planner::Planner(std::vector<BaseWorldState*>* pWorldStates)
{


	m_Actions =
	{
		std::make_unique<


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
