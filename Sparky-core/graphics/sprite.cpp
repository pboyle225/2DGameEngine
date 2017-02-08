#include "sprite.h"

namespace engine {
	namespace graphics {

		Sprite::Sprite(float x, float y, float width, float height, math::vec4& color)
			: Renderable2D(math::vec3(x, y, 0), math::vec2(width, height), color), position(m_Position)
		{
			rotation = math::mat4::identity();
		}

		Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
			: Renderable2D(math::vec3(x, y, 0), math::vec2(width, height), math::vec4(1, 1, 1, 1)), position(m_Position)
		{
			m_Color = math::vec4(1, 1, 1, 1);
			m_Texture = texture;
			rotation = math::mat4::identity();
		}
	
		Sprite::Sprite(float x, float y, float z, float width, float height, Texture* texture)
			: Renderable2D(math::vec3(x, y, z), math::vec2(width, height), math::vec4(1, 1, 1, 1)), position(m_Position)
		{
			position = math::vec3(x, y, z);
			m_Color = math::vec4(1, 1, 1, 1);
			m_Texture = texture;
			rotation = math::mat4::identity();
		}
}}