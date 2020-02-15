#pragma once

#include "graphics/window.h"
#include "math\_math.h"
#include "utils/timer.h"
#include "graphics\renderer2d.h"
#include "graphics\batchrenderer2d.h"
#include "Layers/tilelayer.h"
#include "graphics\spritesheet.h"
#include "graphics\label.h"
#include "graphics\layers\group.h"
#include "soundEngine\soundEngine.h"


namespace engine
{
	class Engine
	{
	public:
		
		Timer deltaTime;
		
		void start()
		{
			init();
			run();
		}

	protected:
		Engine()
		{
			m_FramesPerSecond = 0;
			m_UpdatesPerSecond = 0;
		}

		virtual ~Engine()
		{
			delete m_Window;
		}

		Window * createWindow(const char * name, int width, int height)
		{
			m_Window = new graphics::Window(name, width, height);
			return m_Window;
		}


		//Run once per initialization
		virtual void init() = 0;

		//Runs once per second
		virtual void tick() { }

		//Run 60 times per second if able
		virtual void update() { }

		//Runs as fast as CPU can (unless VSYNC is enabled)
		virtual void render() = 0;

		const unsigned int getFPS() const { return m_FramesPerSecond; }
		const unsigned int getUPS() const { return m_UpdatesPerSecond; }
	protected:

		Timer* m_Timer; //main timer for window
	private:
		graphics::Window * m_Window; //main window of game
		int m_FramesPerSecond, m_UpdatesPerSecond;

		void run()
		{
			float timer = 0.0f;
			float updateTimer = 0.0f;
			float updateTick = 1.0f / 60.0f;
			m_Timer = new Timer();
			unsigned int frames = 0;
			unsigned int updates = 0;
			deltaTime.reset();

			while (!m_Window->closed())
			{
				render();
				m_Window->update();
				m_Window->clear();

				//limit to 60 updates a frame
				if ((m_Timer->elapsed() - updateTimer) > updateTick)
				{
					updates++;
					update();
					updateTimer += updateTick;
					deltaTime.reset();
				}

				if (m_Timer->elapsed() - timer > 1.0f)
				{
					timer += 1.0f;
					m_FramesPerSecond = frames;
					m_UpdatesPerSecond = updates;
					frames = 0;
					updates = 0;
					tick();
				}
				frames++;
			}
		}
	};
}
