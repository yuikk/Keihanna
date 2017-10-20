#include "Sound.h"


void Sound::setInstrument(){
	for (int i = 0; i < 10; i++) {
		sprintf(soundTitle, "piano%d.png", i);
		sound_piano[i].load(soundTitle);
		sprintf(soundTitle, "xylophone%d.png", i);
		sound_xylophone[i].load(soundTitle);
		
	}
}

void Sound::manage(int _inst,int _tone){
	switch (_inst) {
	case 0:
		piano(_tone);
		break;
	case 1:
		xylophone(_tone);
		break;
	}
}

void Sound::piano(int _tone) {
	switch (_tone) {
	case 0:
		sound_piano[0].play();
		break;
	case 1:
		break;
	}
}
void Sound::xylophone(int _tone) {
	switch (_tone) {
	case 0:
		break;
	case 1:
		break;
	}
}

