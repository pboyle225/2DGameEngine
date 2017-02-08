#pragma once

#include <vector>
#include <GL\glew.h>

#include "buffer.h"

namespace engine {
	namespace graphics {

		class VertexArray
		{
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers; //will hold all buffers to send to shader
		};
	}
}