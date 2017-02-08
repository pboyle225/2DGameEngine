#pragma once

#include <string>
#include "GL\glew.h"
#include <FreeImage.h>
#include "../utils/imageLoad.h"

namespace engine {
	namespace graphics
	{
		class Texture
		{
		public:
			//Texture() {}
			Texture(const std::string& filename);
			Texture(BYTE* pixels, GLuint width, GLuint height);
			~Texture();
			void bind() const;
			void unbind() const;

			inline unsigned int getWidth() const { return m_Width;  }
			inline unsigned int getHeight() const { return m_Height; }
			inline unsigned int getID() const { return m_TID; }
		private:
			std::string m_FileName;
			GLuint m_TID; //texture id
			GLsizei m_Width, m_Height;

			GLuint load(BYTE* pixels);
		};
	}
}
