#include "RenderSystem.h"

void RenderSystem::update(std::vector<Entity*>& entities, Layer* layer)
{
	std::vector<Renderable2D*> renderables;

	for (Entity* ent : entities)
	{
		Render* render = static_cast<Render*>(ent->getComponent(ComponentIDEnum::RenderComp));
		Transform* transformComp = static_cast<Transform*>(ent->getComponent(ComponentIDEnum::TransformComp));

		if (render && transformComp)
		{
			render->GetRenderable()->m_Position = transformComp->location;

			if (render->isShown)
			{
				renderables.push_back(render->GetRenderable());
			}
		}
	}

	layer->setRenderables(renderables);
}