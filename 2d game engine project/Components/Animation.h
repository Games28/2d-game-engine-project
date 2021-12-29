#ifndef ANIMATION_H
#define ANIMATION_H

class Animation
{
public:
	unsigned int Index;
	unsigned int numFrames;
	unsigned int animationSpeed;
	Animation();
	Animation(unsigned int index, unsigned int numframes, unsigned animationspeed);
};


#endif