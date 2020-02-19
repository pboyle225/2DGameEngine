#include "CursorSystem.h"

void CursorSystem::update(std::vector<Entity*>& entities, math::vec2 cursorLoc, math::vec2 windowDim)
{
	for (Entity* ent : entities)
	{
		Transform* transform = static_cast<Transform*>(ent->getComponent(ComponentIDEnum::TransformComp));
		CursorC* cursorComp = static_cast<CursorC*>(ent->getComponent(ComponentIDEnum::CursorComp));

		if (transform && cursorComp)
		{
			float newx = (float)(cursorLoc.x * 32.0f / windowDim.x - 16.0f);
			float newy = (float)(9.0f - cursorLoc.y * 18.0f / windowDim.y);

			transform->location.x = newx;
			transform->location.y = newy;

			//printf("cursor Pos: %f, %f\n", newx, newy);
		}
	}
}