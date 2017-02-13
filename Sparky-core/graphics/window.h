#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW\glfw3.h>

namespace engine {	namespace graphics {

#define MAX_KEYS	1024
#define MAX_BUTTONS 32

	class Window
	{
	public:
		Window(const char * name, int width, int height);
		~Window();
		

		void init2(const char * name, int width, int height);

		void update();
		bool closed() const;
		void clear() const;

		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int button) const;
		void getMousePosition(double &x, double &y) const;
		int getStateOfKey(int key);
		int getWidth() const { return m_Width; }
		int getHeight() const { return m_Height; }
		bool isKeyTyped(unsigned int keycode) const;
		bool isMouseButtonClicked(unsigned int button) const;

		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];
		bool m_KeyState[MAX_KEYS];
		bool m_KeyTyped[MAX_KEYS];
		bool m_MouseState[MAX_BUTTONS];
		bool m_MouseClicked[MAX_BUTTONS];

		double mx, my; //mouse x mouse y position

	private:
		int m_Width, m_Height;
		const char* m_Title;
		GLFWwindow * m_Window;
		bool m_Closed;

		bool init();
		friend void windowResize(GLFWwindow *window, int width, int height);
		friend void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
		friend void cursor_position_callback(GLFWwindow * window, double xpos, double ypos);
	};

} }
