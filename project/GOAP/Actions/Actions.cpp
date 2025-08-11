
#include"Actions.h"
#include"../WorldStates/WorldStates.h"
#include<vector>
#include <IExamInterface.h>


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

EvadeEnemy::EvadeEnemy()
{
	SetName(typeid(this).name());

	AddPrecondition(std::make_unique<IsNearEnemy>(true));
	AddPrecondition(std::make_unique<IsLowOnAmmo>(true));

	AddEffect(std::make_unique<SafeFromEnemy>(true));

}

bool EvadeEnemy::Execute(float elapsedSec, SteeringPlugin_Output & steeringOutput, IExamInterface * iFace)
{
	
	if (!iFace) return false;

	const float grabRange = 10.0f; // Distance at which enemy can grab
	const float fleeSpeed = 5.0f;  // Movement speed while fleeing

	// Find closest enemy
	EnemyInfo closestEnemy{};
	bool enemyFound = false;
	float closestDistSq = FLT_MAX;

	auto enemies = iFace->GetEnemiesInFOV();
	for (auto& e : enemies)
	{
			float distSq = DistanceSquared(iFace->Agent_GetInfo().Position, e.Location);
			if (distSq < closestDistSq)
			{
				closestDistSq = distSq;
				closestEnemy = e;
				enemyFound = true;
			}
	}

	if (!enemyFound)
	{
		// No enemies found, stop moving
		steeringOutput.LinearVelocity = { 0.f, 0.f };
		return true;
	}

	// If already outside grab range, stop fleeing
	if (closestDistSq > grabRange * grabRange)
	{
		steeringOutput.LinearVelocity = { 0.f, 0.f };
		return true;
	}

	// Calculate flee direction
	Elite::Vector2 agentPos = iFace->Agent_GetInfo().Position;
	Elite::Vector2 enemyPos = closestEnemy.Location;
	Elite::Vector2 fleeDir = agentPos - enemyPos;

	if (fleeDir.MagnitudeSquared() > 0)
	{
		fleeDir.Normalize();
		steeringOutput.LinearVelocity = fleeDir * fleeSpeed;
	}
	else
	{
		steeringOutput.LinearVelocity = { 0.f, 0.f };
	}

	steeringOutput.AngularVelocity = 0.f;
	steeringOutput.AutoOrient = true;
	steeringOutput.RunMode = true; // Sprint if possible

	return true;
}
