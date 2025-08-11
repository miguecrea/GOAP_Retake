#include "../../stdafx.h"
#include"BaseAction.h"
#include"../WorldStates/BaseWorldState.h"

BaseAction::~BaseAction()
{
}

float BaseAction::GetWeight() const
{
	return m_Weight;
}

int BaseAction::GetGraphNodeIndex() const
{
	return m_GraphNodeIdx;
}

const std::string & BaseAction::GetName() const
{
	return m_Name;
}

const std::vector<std::unique_ptr<BaseWorldState>>& BaseAction::GetPreconditions() const
{
	return m_Preconditions;
}

const std::vector<std::unique_ptr<BaseWorldState>>& BaseAction::GetEffects() const
{
	return m_Effects;
}

void BaseAction::SetWeight(float weight)
{
	m_Weight = weight;
}

void BaseAction::SetName(const std::string& name)
{
	m_Name = name;
}

void BaseAction::SetGraphNodeIndex(int idx)
{
	m_GraphNodeIdx = idx;
}

void BaseAction::AddPrecondition(std::unique_ptr<BaseWorldState>state)
{
	m_Preconditions.push_back(std::move(state));

}
void BaseAction::AddEffect(std::unique_ptr<BaseWorldState> state)
{
	m_Effects.push_back(std::move(state));
}
