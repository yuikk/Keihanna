#pragma once
#include"ofMain.h"


class Sound
{
public:
	void setInstrument();
	void manage(int _inst, int _tone);
	void piano(int _tone);
	void xylophone(int _tone);

	ofSoundPlayer sound_piano[10];
	ofSoundPlayer sound_xylophone[10];


	char soundTitle[20];
};

