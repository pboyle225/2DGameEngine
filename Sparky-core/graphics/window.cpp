#include "window.h"

namespace engine {	namespace graphics {


	Window::Window(const char * name, int width, int height)
	{
		m_Title = name;
		m_Width = width;
		m_Height = height;
		if(!init())
		{
			glfwTerminate();
		}

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
			m_KeyState[i] = false;
			m_KeyTyped[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
			m_MouseState[i] = false;
			m_MouseClicked[i] = false;
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_KeyTyped[i] = m_Keys[i] && !m_KeyState[i];
		}
		
		for (int i = 0; i < MAX_BUTTONS; i++)
		{ 
			 m_MouseClicked[i] = m_MouseButtons[i] && !m_MouseState[i];
		}
		memcpy(m_KeyState, m_Keys, MAX_KEYS);
		memcpy(m_MouseState, m_MouseButtons, MAX_BUTTONS);


		GLenum error = glGetError();

		if (error != GL_NO_ERROR)
		{
			std::cout << " OPENGL ERROR: " << error << std::endl;
		}

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "GLFW Init failed!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		if (!m_Window)
		{
			std::cout << "Failed to create Window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetFramebufferSizeCallback(m_Window, windowResize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glfwSwapInterval(0);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not Init GLEW!" << std::endl;
			return false;
		}

		return true;
	}


	bool Window::isKeyTyped(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;
		return m_KeyTyped[keycode];
	}

	bool Window::isKeyPressed(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;
		return m_Keys[keycode];
	}

	void Window::getMousePosition(double &x, double &y) const
	{
		x = mx;
		y = my;
	}

	bool Window::isMouseButtonClicked(unsigned int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;
		return m_MouseClicked[button];
	}

	bool Window::isMouseButtonPressed(unsigned int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;
		return m_MouseButtons[button];
	}

	int Window::getStateOfKey(int key)
	{
		return glfwGetKey(m_Window, key);
	}
	bool Window::closed() const
	{
		if (!glfwWindowShouldClose(m_Window))
		{
			return false;
		}
		
		return true;
	}
	/*-----------------Friend functions (Used for GLFW Callbacks) ------------------------*/

	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
		Window * win = (Window *)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;

	}
	
	
	void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
	{
		Window * win = (Window*) glfwGetWindowUserPointer(window);

		if (action != GLFW_RELEASE)
		{
			win->m_Keys[key] = true;
		}
		else
		{
			//Key is released set to false;
			win->m_Keys[key] = false;
		}
	}

	void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
	{
		Window * win = (Window*)glfwGetWindowUserPointer(window);

		if (action != GLFW_RELEASE)
		{
			win->m_MouseButtons[button] = true;
		}
		else
		{
			win->m_MouseButtons[button] = false;
		}
	}

	void cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
	{
		Window * win = (Window*)glfwGetWindowUserPointer(window);

		win->mx = xpos;
		win->my = ypos;
	}
} }