#include "Animation.h"

Animation::Animation()
{

}

Animation::Animation(unsigned int index, unsigned int numframes, unsigned animationspeed)
{
	this->Index = index;
	this->numFrames = numframes;
	this->animationSpeed = animationspeed;
}