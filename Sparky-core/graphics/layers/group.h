#pragma once

#include "../renderer2d.h"
#include "../renderable2d.h"

namespace engine {
	namespace graphics	{

	class Group : public Renderable2D
	{
	public:
		Group(const math::mat4 & transform);
		~Group();
		void submit(Renderer2D* renderer) const override;
		void add(Renderable2D* renderable);
	private:
		std::vector<Renderable2D*> m_Renderables;
		math::mat4 m_TransformationMatrix;
	};
} }