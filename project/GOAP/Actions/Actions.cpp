
#include"Actions.h"
#include"../WorldStates/WorldStates.h"
#include<vector>

ConsumeSavedFood::ConsumeSavedFood()
{

	SetName(typeid(this).name());
	AddPrecondition(std::make_unique<HasSavedUpFood>(true));
	AddEffect(std::make_unique<IsHungry>(false));
}

bool ConsumeSavedFood::Execute(float elapsedSec, SteeringPlugin_Output& steeringOutput, IExamInterface* iFace)
{
	return false;
}


/////////////