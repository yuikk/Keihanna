#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	//ofSetFullscreen(true);
	for (int i = 0; i < 10; i++) {
		magic[i].setup(i);
	}
	atelier.init("atelier.png");
	back.load("background.png");
	sound.setInstrument();
}

//--------------------------------------------------------------
void ofApp::update(){
	atelier.update();

	if (color_data == 1) {
		magic[hall_data].update(hall_data);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	back.draw(0, 0, ofGetWidth(), ofGetHeight());
	atelier.draw();

	if (color_data == 1) {
		magic[hall_data].draw(hall_data);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a') {
		hall_data = 0;
	}
	else {
		hall_data = 1;
	}


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


