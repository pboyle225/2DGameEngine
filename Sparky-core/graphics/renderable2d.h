#pragma once

#include "buffers\buffer.h"
#include "buffers\indexbuffer.h"
#include "buffers\vertexarray.h"

#include "renderer2d.h"

#include "../math/_math.h"
#include "shader.h"
#include "texture.h"

namespace engine {
	namespace graphics {

		struct VertexData
		{
			math::vec3 vertex;
			math::vec2 uv; //texture coord
			float tid; //texture id
			unsigned int color;
		};

		class Renderable2D
		{
		public:

			math::vec2 m_Size;
			math::vec3 m_Position;
			math::vec4 m_Color;
			std::vector<math::vec2> m_UV;
			Texture * m_Texture;
			math::mat4 rotation;
			int texID;

			Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color)
				: m_Size(size), m_Color(color)
			{
				m_Position = position;
				setUVDefaults();
				anchorPoint = math::vec3(0.0f, 0.0f, 0.0f);
				rotation = math::mat4::identity();
				m_Texture = NULL;
			}

			virtual ~Renderable2D()
			{
			}

			void setColor(const math::vec4 color)
			{
				//Store 4 1-Byte color components in single 4 byte unsigned integer.
				//~100 fps gain
				/*
				int r = color.x * 255.0f;
				int g = color.y * 255.0f;
				int b = color.z * 255.0f;
				int a = color.w * 255.0f;
				*/

				//m_Color = a << 24 | b << 16 | g << 8 | r;
				m_Color = color;
			}
			
			void setRotate(float angle, math::vec3 axis)
			{

				math::vec3 halfSprite(m_Position.x + anchorPoint.x ,m_Position.y + anchorPoint.y, 0);
				math::mat4 currMat = math::mat4::identity() * math::mat4::translation(-1 * halfSprite);
				math::mat4 rotMat = math::mat4::rotation(angle, axis) * currMat;
				
				rotMat = math::mat4::translation(halfSprite) * rotMat;

				rotation = rotMat;
			}

			void setAnchorPoint(math::vec3 newAnchorPoint)
			{
				anchorPoint = newAnchorPoint;
			}

			virtual void submit(Renderer2D* renderer) const
			{
				renderer->submit(this);
			}


			inline const math::vec3& getPosition() const { return m_Position; }
			inline const math::vec2& getSize() const { return m_Size; }
			inline const math::vec4& getColor() const { return m_Color; }
			inline const std::vector<math::vec2>& getUV() const { return m_UV; }
			inline const math::vec3& getAnchorPoint() const { return anchorPoint; }

			inline const GLuint getTID() const 
			{ 
				if (m_Texture == NULL)
				{
					return 0;
				}
				
				//return m_Texture->getID();
				return texID;
			}


		protected:
			Renderable2D() {
				setUVDefaults();
				anchorPoint = math::vec3(0, 0, 0);
				rotation = math::mat4::identity();
				m_Texture = NULL;
			}
			math::vec3 anchorPoint;
		private:

			void setUVDefaults()
			{
				m_UV.push_back(math::vec2(0, 0));
				m_UV.push_back(math::vec2(0, 1));
				m_UV.push_back(math::vec2(1, 1));
				m_UV.push_back(math::vec2(1, 0));
			}

		};
	}
}