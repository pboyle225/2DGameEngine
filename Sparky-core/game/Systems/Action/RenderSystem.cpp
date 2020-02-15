#include "RenderSystem.h"

void RenderSystem::update(std::vector<Entity*>& entities)
{
	for (Entity* ent : entities)
	{
		Render* render = static_cast<Render*>(ent->getComponent(ComponentIDEnum::RenderComp));
		Transform* transformComp = static_cast<Transform*>(ent->getComponent(ComponentIDEnum::TransformComp));

		if (render && transformComp)
		{
			render->GetRenderable()->m_Position = transformComp->location;
		}
	}
}