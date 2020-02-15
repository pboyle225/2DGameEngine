#pragma once

#include "../../utils/rapidxml_utils.hpp"

struct LayerData
{
public:
	int width;
	int height;
	std::string name;
	std::string data;
};
struct FrameData
{
public:
	std::string tileID;
	std::string duration;
};

struct AnimationTileData
{
public:
	std::string tileID;
	std::vector<FrameData> frameData;
};

class TmxFile
{
public:

	TmxFile(std::string fileName)
	{
		xmlFile = new rapidxml::file<>(fileName.c_str());
		levelTest = new rapidxml::xml_document<>;
		levelTest->parse<0>(xmlFile->data());
	}

	~TmxFile()
	{

	}

	void loadTileLayersData()
	{
		rapidxml::xml_node<> * root_node = levelTest->first_node();
		rapidxml::xml_node<> * data_node;
		rapidxml::xml_node<> * animation_node;
		rapidxml::xml_node<> * animation2_node;

		animation_node = root_node->first_node("tileset");
		//Tile animation data
		

		for (rapidxml::xml_node<> * node = animation_node->first_node("tile"); node; node = node->next_sibling())
		{
			AnimationTileData anim;
			anim.tileID = node->first_attribute("id")->value();		
			animation2_node = node->first_node("animation");

			if (animation2_node)
			{
				for (rapidxml::xml_node<> * node2 = animation2_node->first_node("frame"); node2; node2 = node2->next_sibling())
				{
					FrameData frameData;
					frameData.tileID = node2->first_attribute("tileid")->value();
					frameData.duration = node2->first_attribute("duration")->value();

					anim.frameData.push_back(frameData);
				}
				animationsData.push_back(anim);
			}
		}
		
		std::string test = levelTest->first_node()->value();
		root_node = levelTest->first_node();

		//TileLayer data
		for (rapidxml::xml_node<> * node = root_node->first_node("layer"); node; node = node->next_sibling())
		{
			LayerData layerData;
			layerData.width = atoi(node->first_attribute("width")->value());
			layerData.height = atoi(node->first_attribute("height")->value());
			layerData.name = node->first_attribute("name")->value();
			data_node = node->first_node("data");
			layerData.data = data_node->value();

			layersData.push_back(layerData);
		}
	}

	std::vector<LayerData> getLayersData()
	{
		return layersData;
	}

	std::vector<AnimationTileData> getAnimationData()
	{
		return animationsData;
	}

private:

	rapidxml::xml_document<> * levelTest;
	rapidxml::file<> * xmlFile;
	std::vector<LayerData> layersData;
	std::vector<AnimationTileData> animationsData;

};