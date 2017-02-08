#pragma once

#include <vector>
#include "GL\glew.h"
#include "../math/_math.h"


namespace engine {
	namespace graphics {
		
		class Renderable2D;

		class Renderer2D
		{
		public:
			virtual void begin() {}
			virtual void end() {}
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
			virtual void drawString(std::string text, const math::vec3& position, const math::vec4& color)
			{

			}

			void push(const math::mat4& matrix, bool override = false)
			{
				//When we want to push something not relative to another matrix
				if (override)
				{
					m_TransformationStack.push_back(matrix);
				}
				else
				{
					m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
				}

				m_TransformationBack = &m_TransformationStack.back();
			}

			void pop()
			{
				if (m_TransformationStack.size() > 1)
				{
					m_TransformationStack.pop_back();
				}

				m_TransformationBack = &m_TransformationStack.back();

				//TODO: should log this
			}

		protected:
			std::vector<math::mat4> m_TransformationStack;
			math::mat4* m_TransformationBack;
			
			Renderer2D()
			{
				m_TransformationStack.push_back(math::mat4::identity());
				m_TransformationBack = &m_TransformationStack.back();
			}

		};

	}
}
