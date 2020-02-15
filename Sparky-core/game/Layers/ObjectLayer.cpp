#include "ObjectLayer.h"

ObjectLayer::ObjectLayer(Shader* shader, SpriteSheet* spriteSheet, LayerData layerData)
	: TileLayer(shader, spriteSheet, layerData)
{
	for (Renderable2D* renderable : m_Renderables)
	{
		renderableMap[renderable] = true;
	}
}

ObjectLayer::~ObjectLayer()
{

}

void ObjectLayer::remove(Renderable2D* renderable)
{
	if (renderableMap.find(renderable) != renderableMap.end())
	{
		for (int i = 0; i < m_Renderables.size(); i++)
		{
			if (renderable == m_Renderables[i])
			{
				m_Renderables.erase(m_Renderables.begin() + i);
				return;
			}
		}
	}
}

void ObjectLayer::setRenderables(const std::vector<Renderable2D*>& renderables)
{
	// TODO: FIX MEMORY LEAK
	//std::vector<Renderable2D*> renderablesToDelete;
	//for (Renderable2D* renderable : renderables)
	//{
	//	if (renderableMap.find(renderable) == renderableMap.end())
	//	{
	//		renderablesToDelete.push_back(renderable);
	//	}
	//}

	//for (int i = 0; i < renderablesToDelete.size(); i++)
	//{
	//	delete renderablesToDelete[i];
	//}

	m_Renderables = renderables;
}