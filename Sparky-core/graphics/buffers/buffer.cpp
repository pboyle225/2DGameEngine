#include "buffer.h"

namespace engine { namespace graphics {

	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
	{
		m_ComponentCount = componentCount;

		glGenBuffers(1, &m_BufferID);
		bind();
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		unbind();
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_BufferID);
	}

	void Buffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	}

	void Buffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

} }