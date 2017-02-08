#pragma once

#include "../utils/fileutils.h"
#include "GL\glew.h"
#include <vector>
#include <iostream>
#include "../math/_math.h"

namespace engine { namespace graphics {
	
	class Shader
	{
	public:

		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void enable() const;
		void disable() const;
		

		void setUniform1f(const GLchar * name, float value);
		void setUniformfv(const GLchar * name, float * value, int count);
		void setUniform1i(const GLchar * name, int value);
		void setUniformiv(const GLchar * name, int * value, int count);
		void setUniform2f(const GLchar * name, const math::vec2& vector);
		void setUniform3f(const GLchar * name, const math::vec3& vector);
		void setUniform4f(const GLchar * name, const math::vec4& vector);
		void setUniformMat4(const GLchar * name, const math::mat4& matrix);
	
	private:
		GLuint m_ShaderID; //unique id for certain shader
		const char* m_VertPath;
		const char* m_FragPath;

		GLint getUniformLocation(const GLchar * name);
		GLuint load();

	};
}}
