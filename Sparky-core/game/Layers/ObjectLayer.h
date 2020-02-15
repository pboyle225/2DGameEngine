#pragma once

#include "tilelayer.h"
#include <unordered_map>

class ObjectLayer : public TileLayer
{
public:
	ObjectLayer(Shader* shader, SpriteSheet* spriteSheet, LayerData layerData);
	~ObjectLayer();

	void remove(Renderable2D* renderable) override;
	void setRenderables(const std::vector<Renderable2D*>& renderables) override;
private:
	std::unordered_map<Renderable2D*, bool> renderableMap;

};