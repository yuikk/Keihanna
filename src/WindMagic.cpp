#include "WindMagic.h"
#include "ofxSPK.h"
#include "stdio.h"

ofxSPK::System sys;
ofxSPK::Group group;

ofImage sprite;

ofxSPK::Modifier rot;

//--------------------------------------------------------------
void WindMagic::setup() {
	// setup pointsprite texture
	// NOTES: the texture size must be Power of Two,
	// and turn off arb texture option while loading
	
	ofDisableArbTex();
	sprite.loadImage("wind1.png");
	ofEnableArbTex();

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	sys.setup();

	group.setup(sys);
	group.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
		ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));

	group.setLifeTime(0.5, 5);//ó±éqÇ™î≠ê∂ÇµÇƒÇ¢ÇÈéûä‘ÇÃîÕàÕ(ç≈è¨éûä‘,ç≈ëÂéûä‘)
	group.setFriction(0.1);


	group.setGravity(ofVec3f(0, -50, 0));
	group.setMass(0.1, 0.1);

	rot.setup(SPK::Vortex::create(SPK::Vector3D(ofGetWidth() / 2, ofGetHeight() / 2),
		SPK::Vector3D(0, 1, 0),
		200,
		10), group);

	group.reserve(1000);//ó±éqÇÃî≠ê∂Ç∑ÇÈó 
}

//--------------------------------------------------------------
void WindMagic::update() {
	group.setSize(0, ofxSPK::RangeF(30, 50));//ó±éqÇÃç≈ëÂÇÃëÂÇ´Ç≥
	group.emitRandom(10, ofVec3f(150 * sin(15 * ofGetElapsedTimef()) + ofGetWidth() / 3, ofGetHeight() / 4 * 3));
	group.emitRandom(10, ofVec3f(150 * sin(15 * ofGetElapsedTimef()) + ofGetWidth() / 3 * 2, ofGetHeight() / 4 * 3));

	sys.update();

	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void WindMagic::draw() {
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	// sys.debugDraw();

	// bind texture, enable point sprite while drawing particles
	sprite.bind();
	ofEnablePointSprites();
	sys.draw();
	ofDisablePointSprites();
	sprite.unbind();
}



