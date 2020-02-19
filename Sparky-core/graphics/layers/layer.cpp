#include "layer.h"

namespace engine {
	namespace graphics {

		Layer::Layer(Renderer2D * renderer, Shader * shader, math::mat4 projectionMatrix)
			: m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
		{
			m_Shader->enable();
			m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
			
			GLint texIDs[] =
			{
				0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
				10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
				20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
				30, 31
			};

			m_Shader->setUniformiv("textures", texIDs, 32);
			m_Shader->disable();
		}

		Layer::~Layer()
		{
			delete m_Shader;
			delete m_Renderer;

			for (int i = 0; i < m_Renderables.size(); i++)
			{
				delete m_Renderables[i];
			}
		}

		void Layer::add(Renderable2D * renderable)
		{
			m_Renderables.push_back(renderable);
		}

		void Layer::add(Renderable2D * renderable, math::vec3 location)
		{
			renderable->m_Position = location;
			m_Renderables.push_back(renderable);
		}

		void Layer::setRenderables(const std::vector<Renderable2D*>& renderables)
		{
			m_Renderables = renderables;
		}

		void Layer::remove(Renderable2D * renderable)
		{
			for (int i = 0; i < m_Renderables.size(); i++)
			{
				if (renderable == m_Renderables[i])
				{
					m_Renderables.erase(m_Renderables.begin() + i);
					break;
				}
			}
		}

		void Layer::removeAndReplace(Renderable2D * removedRenderable, Renderable2D * replacedRenderable)
		{
			if (removedRenderable == replacedRenderable)
			{
				return;
			}

			for (int i = 0; i < m_Renderables.size(); i++)
			{
				if (removedRenderable == m_Renderables[i])
				{
					m_Renderables[i] = replacedRenderable;
				}
			}
		}

		void Layer::render()
		{
			m_Shader->enable();

			m_Renderer->begin();

			for (const Renderable2D * renderable : m_Renderables)
			{
				renderable->submit(m_Renderer);
			}
			m_Renderer->end();

			m_Renderer->flush();
		}

		void Layer::render(math::vec3 camera)
		{
			m_Shader->enable();

			m_Renderer->begin();

			for (const Renderable2D * renderable : m_Renderables)
			{			
				//Only render sprites on screen and slightly off
				float diffLeft = camera.x - 20;
				float diffRight = camera.x + 20;
				float diffUp = camera.y + 20;
				float diffDown = camera.y - 20;

				if ((renderable->m_Position.x < diffRight && renderable->m_Position.x > diffLeft)
					&& (renderable->m_Position.y < diffUp && renderable->m_Position.y > diffDown))
				{
					renderable->submit(m_Renderer);
				}
			}
			m_Renderer->end();

			m_Renderer->flush();
		}
	}

}