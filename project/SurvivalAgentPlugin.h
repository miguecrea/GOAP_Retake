#pragma once
#include "IExamPlugin.h"
#include "Exam_HelperStructs.h"

class IBaseInterface;
class IExamInterface;
class Brain;
class WorldState;

class SurvivalAgentPlugin :public IExamPlugin
{
public:
	SurvivalAgentPlugin() {};
	virtual ~SurvivalAgentPlugin();

	void Initialize(IBaseInterface* pInterface, PluginInfo& info) override;
	void DllInit() override;
	void DllShutdown() override;

	void InitGameDebugParams(GameDebugParams& params) override;
	void Update_Debug(float dt) override;

	SteeringPlugin_Output UpdateSteering(float dt) override;
	void Render(float dt) const override;

private:
	IExamInterface *  m_pInterface = nullptr;

	Elite::Vector2 m_Target = {};
	bool m_CanRun = false; //Demo purpose
	bool m_GrabItem = false; //Demo purpose
	bool m_UseItem = false; //Demo purpose
	bool m_RemoveItem = false; //Demo purpose
	bool m_DestroyItemsInFOV = false;
	float m_AngSpeed = 0.f; //Demo purpose

	UINT m_InventorySlot = 0;


};

extern "C"
{
	__declspec (dllexport) IPluginBase* Register()
	{
		return new SurvivalAgentPlugin();
	}
}