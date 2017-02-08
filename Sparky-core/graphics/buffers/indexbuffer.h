#pragma once

#pragma once

#include "GL\glew.h"

namespace engine {
	namespace graphics {

		class IndexBuffer
		{
		public:
			IndexBuffer(GLushort* data, GLsizei count);
			~IndexBuffer();
			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_Count; }
		private:
			GLuint m_BufferID;
			GLuint m_Count; //used to tell what dimension vectors we are using
		};

	}
}
