#if 0

#include "graphics/window.h"
#include "math/_math.h"
#include "graphics/shader.h"
#include "utils\timer.h"

#include "graphics\buffers\buffer.h"
#include "graphics\buffers\indexbuffer.h"
#include "graphics\buffers\vertexarray.h"

#include "graphics\renderer2d.h"
#include "graphics\batchrenderer2d.h"

#include "graphics\sprite.h"

#include "graphics\layers\tilelayer.h"

#include "graphics\layers\group.h"
#include <time.h>

#include "graphics\texture.h"

int main()
{
	using namespace engine;
	using namespace graphics;
	using namespace math;

	srand(time(NULL));

	Window window("Game!", 960, 540);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* shader = new Shader("shaders/basic.vert", "shaders/basic.frag");

	TileLayer layer(shader);
	
	Texture * texture1 = new Texture("test2.png");
	Texture * texture3 = new Texture("test3.png");
	Texture * texture2 = new Texture("instalok.png");

	for (float y = -9.0f; y < 9.0f; y ++)
	{
		for (float x = -16.0f; x < 16.0f; x ++)
		{
			//layer.add(new Sprite(x, y, 0.9f, 0.9f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
			layer.add(new Sprite(x, y, 0.9f, 0.9f, rand() % 2 == 0 ? texture1 : texture2));
		}
	}
	
	//layer.add(new Sprite(0, 0, 9.0f, 9.0f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
	

	/*
	Group * group = new Group(mat4::translation(vec3(-15.0, 5.0f, 0.0f)));
	group->add(new Sprite(0, 0, 6, 3, math::vec4(1, 1, 1, 1)));
	Group * button = new Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));
	button->add(new Sprite(0.0f, 0.0f, 5.0f, 2.0f, math::vec4(1, 0, 1, 1)));
	button->add(new Sprite(0.5f, 0.5f, 3.0f, 1.0f, math::vec4(1, 0.3f, 0.8f, 1)));
	group->add(button);

	layer.add(group);
	TileLayer layer2(shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, math::vec4(1, 0, 1, 1)));
	*/

	//Allows for pixels in foreground with opacity to blend in with background pixels
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLint texIDs[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	shader->enable();
	shader->setUniformiv("textures", texIDs, 10);
	//shader->setUniform1i("tex", 0);
	//shader->setUniformMat4("pr_matrix", ortho);

	Timer time;
	float t = 0.0f;
	unsigned int frames = 0;
	double x, y;

	float angle = 0.0f;
	float scale = 0.0f;
	bool flag = false;

	while (!window.closed())
	{
		t += 0.001;
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;

		window.clear();
		window.getMousePosition(x, y);
		float newX = (float)(x * 32.0f / window.getWidth() - 16.0f);
		float newY = (float)(9.0f - y * 18.0f / window.getHeight());
		shader->enable();
		shader->setUniform2f("light_pos", vec2(newX, newY));


		const std::vector<Renderable2D *> & rs = layer.getRenderables();

		for (int i = 0; i < rs.size(); i++)
		{
			float c = sin(t) / 2.0 + 0.5;
			rs[i]->setColor(math::vec4(c, 0, 0, 1));
			//rs[i]->setColor(math::vec4(0, 1, 0, 1));
		}
		layer.render();

		window.update();

		frames++;
	
		if (time.elapsed() - t > 1000.0f)
		{
			t += 1000.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
		

	}


	return 0;
}
int main()
{
		const char * filename = "test.png";

		//image format
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		//pointer to the image, once loaded
		FIBITMAP *dib(0);
		//pointer to the image data
		BYTE* bits(0);
		//image width and height
		unsigned int width(0), height(0);
		//OpenGL's image ID to map to
		GLuint gl_texID;

		//check the file signature and deduce its format
		fif = FreeImage_GetFileType(filename, 0);
		//if still unknown, try to guess the file format from the file extension
		if (fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(filename);
		//if still unkown, return failure
		if (fif == FIF_UNKNOWN)
			return false;

		//check that the plugin has reading capabilities and load the file
		if (FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, filename);
		//if the image failed to load, return failure
		if (!dib)
			return false;


		//retrieve the image data
		bits = FreeImage_GetBits(dib);

		unsigned int bitsPerPixel = FreeImage_GetBPP(dib);

		//get the image width and height
		width = FreeImage_GetWidth(dib);
		height = FreeImage_GetHeight(dib);
		//if this somehow one of these failed (they shouldn't), return failure
		if ((bits == 0) || (width == 0) || (height == 0))
			return false;

		std::cout << width << ", " << height << std::endl;

		for (int i = 0; i < width * height * 3; i+=3)
		{
			printf("%d\n", bits[i]);
		}

		FreeImage_Unload(dib);

		system("PAUSE");

	return 0;
}
#endif