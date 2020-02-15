#pragma once

#include "../renderer2d.h"
#include "../renderable2d.h"

namespace engine { namespace graphics {

	class Layer
	{
	public:
		virtual ~Layer();
		virtual void add(Renderable2D * renderable);
		virtual void add(Renderable2D * renderable, math::vec3 location);
		virtual void remove(Renderable2D * renderable);
		virtual void removeAndReplace(Renderable2D * removedRenderable, Renderable2D * replacedRenderable);
		virtual void render();
		virtual void render(math::vec3 camera);
		Shader* getShader() { return m_Shader; }

		inline const std::vector<Renderable2D*> &getRenderables() const { return m_Renderables; }
		Layer(Renderer2D * renderer, Shader * shader, math::mat4 projectionMatrix);
		Renderer2D * m_Renderer;
	protected:

		std::vector<Renderable2D *> m_Renderables;
		Shader * m_Shader;
		math::mat4 m_ProjectionMatrix;
	};
	
}}
