#pragma once
#include <vector>
#include <string>
#include "sprite.h"
#include "../utils/imageLoad.h"
#include <deque>

namespace engine{
	namespace graphics
	{
		class SpriteSheet
		{
		public:
			SpriteSheet(std::string fileName, int numCols, unsigned int numRows, unsigned int numSprites, unsigned int spriteSize);
			~SpriteSheet();
			std::vector<Texture *> textures;
		private:
			unsigned int m_NumCols;
			unsigned int m_NumRows;
			unsigned int m_NumSprites;
			GLsizei m_Width;
			GLsizei m_Height;

			std::string m_Filename;
		};
	}
}