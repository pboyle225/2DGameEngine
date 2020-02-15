#include "spritesheet.h"

namespace engine {
	namespace graphics {
		SpriteSheet::SpriteSheet(const std::string fileName, int numCols, unsigned int numRows, unsigned int numSprites, unsigned int spriteDimension)
			: m_Filename(fileName), m_NumCols(numCols), m_NumRows(numRows), m_NumSprites(numSprites)
		{
			BYTE* pixels = load_image(m_Filename.c_str(), &m_Width, &m_Height);

			int spriteWidth = m_Width / m_NumCols;
			int spriteHeight = m_Height / m_NumRows;
			int spriteSize = spriteWidth * spriteHeight * 4;

			std::deque<Texture *> queue;
			std::deque<Texture *> queue2;

			//Extract all sprites from sheet
			for (int row = 0; row < m_NumRows; row++)
			{
				for (int col = 0; col < m_NumCols; col++)
				{
					BYTE* temp = new BYTE[spriteSize];
					
					for (int y = 0; y < spriteHeight; y++)
					{
						for (int x = 0; x < spriteWidth; x++)
						{
							int i_sprite = (x + y * spriteHeight) * 4;
							
							//What a pain in the ass to find this. Maybe simplify this bad boy?
							int i_pixels = ((row * (spriteHeight * m_Width)) + (col * spriteWidth) + (y * m_Width) + x) * 4;
;
							temp[i_sprite] = pixels[i_pixels];			//b
							temp[i_sprite + 1] = pixels[i_pixels + 1];	//g
	 						temp[i_sprite + 2] = pixels[i_pixels + 2];	//r
							temp[i_sprite + 3] = pixels[i_pixels + 3];	//a
						}
					}

					Texture * tex = new Texture(temp, spriteWidth, spriteHeight);
					queue.push_back(tex);
				}

				while (!queue.empty())
				{
					queue2.push_back(queue.back());
					queue.pop_back();
				}
			}

			while (!queue2.empty())
			{
				textures.push_back(queue2.back());
				queue2.pop_back();
			}
		}

		SpriteSheet::~SpriteSheet()
		{
			for (int i = 0; i < textures.size(); i++)
			{
				delete textures[i];
			}
		}
	}
}