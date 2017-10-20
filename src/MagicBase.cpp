#include "MagicBase.h"
#include "ofMain.h"


void MagicBase::setup(int _tone){
	switch (_tone) {
	case 0:
		fire.setup();
		break;
	case 1:
		wind.setup();
		break;
	}
}

void MagicBase::update(int _tone) {
	switch (_tone) {
	case 0:
		fire.update();
		break;
	case 1:
		wind.update();
		break;
	}
}

void MagicBase::draw(int _tone) {
	switch (_tone) {
	case 0:
		fire.draw();
		break;
	case 1:
		wind.draw();
		break;
	}
}


