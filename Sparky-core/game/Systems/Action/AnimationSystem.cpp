#include "AnimationSystem.h"

void AnimationSystem::update(std::vector<Entity*>& entities)
{
	for (Entity* ent : entities)
	{
		Input* input = static_cast<Input*>(ent->getComponent(ComponentIDEnum::InputComp));
		Animation* animation = static_cast<Animation*>(ent->getComponent(ComponentIDEnum::AnimComp));
		Render* render = static_cast<Render*>(ent->getComponent(ComponentIDEnum::RenderComp));
		
		if (input && animation && render)
		{
			if (input->isMainAttacking)
			{
				animation->GetAnimationManager()->changeAnimation(AnimationStates::Attacking);
			}
			switch (input->direction)
			{
				case Direction::STOPPED:
					animation->GetAnimationManager()->reset();
					break;
				case Direction::DOWN:
					animation->GetAnimationManager()->changeAnimation(AnimationStates::MoveDown);
					break;
				case Direction::UP:
					animation->GetAnimationManager()->changeAnimation(AnimationStates::MoveUp);
					break;
				case Direction::LEFT:
					animation->GetAnimationManager()->changeAnimation(AnimationStates::MoveLeft);
					break;
				case Direction::RIGHT:
					animation->GetAnimationManager()->changeAnimation(AnimationStates::MoveRight);
					break;
				default:
					animation->GetAnimationManager()->changeAnimation(AnimationStates::Default);
					break;
			}

			animation->GetAnimationManager()->update();
			render->GetRenderable()->texID = animation->GetAnimationManager()->getCurrentTexture()->getID();
		}
	}
}