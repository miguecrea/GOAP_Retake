#pragma once

#include"../../stdafx.h"
#include"BaseAction.h"

class ConsumeSavedFood final : public BaseAction
{
public:
	ConsumeSavedFood();
	bool Execute(float elapsedSec, SteeringPlugin_Output & steeringOutput, IExamInterface* iFace) override;

private:
	int m_MaxEnergy = 10;
};

class EvadeEnemy final : public BaseAction
{
public:

	EvadeEnemy();
	bool Execute(float elapsedSec, SteeringPlugin_Output& steeringOutput, IExamInterface* iFace) override;

private:
};