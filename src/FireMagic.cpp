#include "FireMagic.h"
#include "ofxSPK.h"

ofxSPK::System sys_fire;
ofxSPK::Group group_fire;

ofImage sprite_fire;

ofxSPK::Modifier rot_fire;

//--------------------------------------------------------------
void FireMagic::setup() {
	// setup pointsprite texture
	// NOTES: the texture size must be Power of Two,
	// and turn off arb texture option while loading
	ofDisableArbTex();
	sprite_fire.loadImage("fire1.png");
	ofEnableArbTex();

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	sys_fire.setup();

	group_fire.setup(sys_fire);
	group_fire.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
		ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));

	group_fire.setLifeTime(0.5, 15);//—±q‚ª”­¶‚µ‚Ä‚¢‚éŠÔ‚Ì”ÍˆÍ(Å¬ŠÔ,Å‘åŠÔ)
	group_fire.setFriction(0.1);


	group_fire.setGravity(ofVec3f(0, -100, 0));
	group_fire.setMass(0.4, 0.6);

	group_fire.reserve(1000);//—±q‚Ì”­¶‚·‚é—Ê

	group_fire.setSize(0, ofxSPK::RangeF(50, 60));//—±q‚ÌÅ‘å‚Ì‘å‚«‚³

	rot_fire.setup(SPK::Vortex::create(SPK::Vector3D(ofGetWidth() / 2, ofGetHeight() / 2),
		SPK::Vector3D(0, 1, 0),
		200,
		10), group_fire);
}

//--------------------------------------------------------------
void FireMagic::update() {

	group_fire.emitRandom(10, ofVec3f(100 * sin(15 * ofGetElapsedTimef()) + ofGetWidth() / 2, ofGetHeight() / 4 * 3));

	sys_fire.update();

	
}

//--------------------------------------------------------------
void FireMagic::draw() {
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	// sys.debugDraw();

	// bind texture, enable point sprite while drawing particles
	sprite_fire.bind();
	ofEnablePointSprites();
	sys_fire.draw();
	ofDisablePointSprites();
	sprite_fire.unbind();
}

