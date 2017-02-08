#pragma once

#include <cstddef>
#include "renderer2d.h"
#include "renderable2d.h"
#include "buffers\indexbuffer.h"

#include "../../Dependencies/FreeType-gl/freetype-gl.h"

namespace engine {
	namespace graphics {

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6
#define RENDERER_MAX_TEXTURES   32

#define SHADER_VERTEX_INDEX 0
#define SHADER_UV_INDEX 1
#define SHADER_TID_INDEX 2
#define SHADER_COLOR_INDEX 3

		class BatchRenderer2D : public Renderer2D
		{
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void submit(const Renderable2D* renderable) override;
			void drawString(std::string text, const math::vec3& position, const math::vec4& color) override;
			void flush() override;
			void begin() override;
			void end() override;
		private:
			VertexData* m_Buffer;
			GLuint m_VAO;
			GLuint m_VBO;
			IndexBuffer* m_IBO;
			GLsizei m_IndexCount;
			std::vector<GLuint> m_TextureSlots;

			ftgl::texture_atlas_t * m_FTAtlas;
			ftgl::texture_font_t * m_FTFont;

			void init();

		};
	}
}
