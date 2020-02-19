#include "AttackSystem.h"

void AttackSystem::update(std::vector<Entity*>& entities, math::vec2 mousePos)
{
	for (int i = 0; i < entities.size(); i++)
	{
		Entity* ent = entities[i];
		Input* input = static_cast<Input*>(ent->getComponent(ComponentIDEnum::InputComp));
		Attack* attack = static_cast<Attack*>(ent->getComponent(ComponentIDEnum::AttackComp));

		if (input && input->isMainAttacking && attack && (attack->timer.elapsed() >= attack->cooldown))
		{
			attack->timer.reset();
			if (attack->attackID == AttackEnum::FireballID)
			{
				FireballAttack* fireballAttack = static_cast<FireballAttack*>(attack);
				Transform* transform = static_cast<Transform*>(ent->getComponent(ComponentIDEnum::TransformComp));
				printf("Player pos: %f, %f\n", transform->location.x, transform->location.y);
				printf("Cursor coords: %f, %f\n", mousePos.x, mousePos.y);
				Sprite * fireballSprite = new Sprite(transform->location.x, transform->location.y, 1.0f, 1.0f, math::vec4(1.0f, 0.0f, 0.0f, 1.0f));
				//math::vec2 direction = math::vec2(mousePos.x - transform->location.x, mousePos.y - transform->location.y);
				math::vec3 test = math::vec3(mousePos.x, mousePos.y, 0).normalize();
				float newx = mousePos.x < 0 ? -fireballAttack->speed : fireballAttack->speed;
				float newy = mousePos.y < 0 ? -fireballAttack->speed : fireballAttack->speed;
				newx *= test.x;
				newy *= test.y;
				Fireball* fireball = new Fireball();
				fireball->addComponent(new Input(fireballAttack->speed, InputType::AI, math::vec3(newx, newy, 0)));
				fireball->addComponent(new Transform(transform->location));
				fireball->addComponent(new Render(fireballSprite));
				fireball->addComponent(new RectangleCollider(fireballSprite->getSize().x, fireballSprite->getSize().y));
			}
		}
	}
}