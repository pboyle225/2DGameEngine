#include "labelComponent.h"

LabelComponent::LabelComponent(Label * label)
{
	id = 17;
	name = "Label Component";
	bitmask = 0x1 << 17;

	this->label = label;
}