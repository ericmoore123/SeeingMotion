#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofImage planet1Img; 
		ofImage planet2Img;
		ofImage planet3Img;
		ofImage pointerImg; 

		ofImage squareImg;

		ofVec2f clickPos;
		ofVec2f pointerPos;

		ofVec2f box1Pos; 
		ofVec2f box2Pos;

		ofVec2f planet1Pos;
		ofVec2f planet2Pos; 
		ofVec2f planet3Pos; 
		ofVec2f planet4Pos; 

		float randomDist1x, randomDist1y, randomDist2x, randomDist2y; 

		ofVec2f pointerTargetPos;


		ofVec3f planet2Pos2;

		float planet1Angle; 
		float planet2Angle;
		float planet3Angle;
		float planet4Angle;
		float moonAngle;

		float pointerAngle; 
		float boxAngle; 

		ofSoundPlayer baseMusic; 
		ofSoundPlayer effectMusic;

		float lerp(float start, float end, float percent);

		void mousePressed(int x, int y, int button);

		void mouseDragged(int x, int y, int button);
};


