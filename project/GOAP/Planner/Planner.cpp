#include"Planner.h"

Planner::Planner(std::vector<BaseWorldState*>* pWorldStates)
{
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
