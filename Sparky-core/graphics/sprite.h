#pragma once

#include "renderable2d.h"

namespace engine {
	namespace graphics {

		class Sprite : public Renderable2D
		{
		public:
			math::vec3& position;

			Sprite(float x, float y, float width, float height, math::vec4& color);
			Sprite(float x, float y, float z, float width, float height, Texture * texture);
			Sprite(float x, float y, float width, float height, Texture * texture);

		private:

		};
	}
}