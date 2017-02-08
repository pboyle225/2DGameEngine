#pragma once

#include "renderable2d.h"

namespace engine {
	namespace graphics {

		class Label : public Renderable2D
		{
		public:
			Label(std::string text, float x, float y, math::vec4 color);

			void submit(Renderer2D* renderer) const override;

			std::string text;
		};
	}
}
