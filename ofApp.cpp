#include "ofApp.h"


void ofApp::setup(){
	//Intitial loading of variables
	baseMusic.load("baseMusic.mp3"); 
	baseMusic.play(); 

	effectMusic.load("effect.mp3");

	planet1Img.load("planet1.png");
	planet2Img.load("planet2.png");
	planet3Img.load("planet3.png");

	pointerImg.load("pointer.png");
	squareImg.load("square.png");

	//set initial positions relative to window (center it)
	planet1Pos.set(ofGetWindowWidth() / 2.0f, ofGetWindowHeight() / 2.0f);
	pointerPos.set(ofGetWindowWidth() / 2.0f, ofGetWindowHeight() / 2.0f);
	box1Pos.set(ofGetWindowWidth() / 2.0f, ofGetWindowHeight() / 2.0f);
	box2Pos.set(ofGetWindowWidth() / 2.0f, ofGetWindowHeight() / 2.0f);

	pointerTargetPos = pointerPos;

	//offset of planets from origin between random values (has multiple vars to ensure higher fluxuation in randomizability of values)  
	randomDist1x = ofRandom(50.0f, 550.0f); 
	randomDist1y = ofRandom(50.0f, 500.0f);
	randomDist2x = ofRandom(50.0f, 400.0f);
	randomDist2y = ofRandom(50.0f, 320.0f);

	planet2Pos.set(randomDist1x, randomDist1y);
	planet3Pos.set(randomDist2x, randomDist2y);
	planet4Pos.set(0, 40);

	//set anchor points for planets 
	planet1Img.setAnchorPoint(planet1Img.getWidth() / 2.0f, planet1Img.getHeight() / 2.0f);
	planet2Img.setAnchorPoint(planet2Img.getWidth() / 2.0f, planet2Img.getHeight() / 2.0f);
	planet3Img.setAnchorPoint(planet3Img.getWidth() / 2.0f, planet3Img.getHeight() / 2.0f);

	//setting planet angles  
	planet1Angle = 0.0f;
	planet2Angle = 0.0f;
	planet3Angle = 0.0f;
	planet4Angle = 0.0f;

	pointerAngle = 0.0f;
	boxAngle = 0.0f;
}


void ofApp::update(){
	//set click position per frame 
	clickPos.set((float)ofGetMouseX(), (float)ofGetMouseY());

	//movement function calling
	ofVec2f vecToClick = clickPos - pointerPos;
	pointerAngle = ofRadToDeg(atan2(vecToClick.y, vecToClick.x));
	pointerPos.x = lerp(pointerPos.x, pointerTargetPos.x, 0.1f);
	pointerPos.y = lerp(pointerPos.y, pointerTargetPos.y, 0.1f);

	ofVec2f vecToPointer = pointerPos - box1Pos;
	box1Pos.x = lerp(box1Pos.x, pointerPos.x, 0.1f);
	box1Pos.y = lerp(box1Pos.y, pointerPos.y, 0.1f);

	ofVec2f vecToPointer2 = box1Pos - box2Pos;
	box2Pos.x = lerp(box2Pos.x, box1Pos.x, 0.1f);
	box2Pos.y = lerp(box2Pos.y, box1Pos.y, 0.1f);

	//increment angles every frame (rotation movement of planets) 
	planet1Angle += 0.1f;
	planet2Angle += 0.8f;
	planet3Angle += 0.2f; 
	moonAngle += 0.2f;
}


void ofApp::draw(){
	//draw planets and set background color 
	ofSetBackgroundColor(0.0f, 0.0f, 0.0f);

	ofPushMatrix();
		ofTranslate(planet1Pos.x, planet1Pos.y);
		ofRotateDeg(planet1Angle);
		ofScale(0.1f, 0.1f);
		planet1Img.draw(0, 0);
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(planet1Pos.x , planet1Pos.y);

		//nexting matrices for planets with an orbiting moon 
		ofPushMatrix(); 
			ofRotateDeg(planet2Angle);
			ofTranslate(planet2Pos.x, planet2Pos.y);
			ofRotateDeg(planet2Angle * 3.0f);
			ofScale(0.1, 0.1);
			planet2Img.draw(0, 0);

				ofPushMatrix();
					ofRotateDeg(moonAngle);
					ofTranslate(planet3Pos.x + 100.0f, planet3Pos.y + 100.0f);
					ofRotateDeg(moonAngle);
					ofScale(0.3, 0.3);
					planet3Img.draw(0, 0);
				ofPopMatrix();
		ofPopMatrix();

		ofPushMatrix();
			ofRotateDeg(planet2Angle);
			ofTranslate(planet1Pos.x * 0.3f, planet1Pos.y * 0.12f);
			ofRotateDeg(planet2Angle * 10.0f);
			ofScale(0.07f, 0.07f);
			planet2Img.draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
			ofRotateDeg(planet3Angle);
			ofTranslate(planet3Pos.x, planet3Pos.y);
			ofRotateDeg(planet2Angle * 4.0f);
			ofScale(0.2, 0.2);
			planet3Img.draw(0, 0);

				ofPushMatrix();
					ofRotateDeg(moonAngle);
					ofTranslate(planet3Pos.x + 100.0f, planet3Pos.y + 100.0f);
					ofRotateDeg(moonAngle);
					ofScale(0.3, 0.3);
					planet3Img.draw(0, 0);
				ofPopMatrix();
		ofPopMatrix();

		ofPushMatrix();
			ofRotateDeg(planet2Angle * 0.5f);
			ofTranslate(planet2Pos.x * 1.0f, planet2Pos.y * 1.8f);
			ofRotateDeg(planet2Angle * 1.0f);
			ofScale(0.1, 0.1);
			planet2Img.draw(0, 0);

			ofPushMatrix();
				ofRotateDeg(moonAngle);
				ofTranslate(planet3Pos.x + 100.0f, planet3Pos.y + 100.0f);
				ofRotateDeg(moonAngle);
				ofScale(0.3, 0.3);
				planet3Img.draw(0, 0);
			ofPopMatrix();
		ofPopMatrix();

		ofPushMatrix();
			ofRotateDeg(planet1Angle * 5.0f);
			ofTranslate(planet2Pos.x * 1.0f, planet2Pos.y * 1.8f);
			ofRotateDeg(planet1Angle * 1.0f);
			ofScale(0.05, 0.05);
			planet1Img.draw(0, 0);
		ofPopMatrix();

		ofPushMatrix();
			ofRotateDeg(planet1Angle * 15.0f);
			ofTranslate(planet2Pos.x * 0.20f, planet2Pos.y * 1.0f);
			ofRotateDeg(planet1Angle * 2.0f);
			ofScale(0.04, 0.04);
			planet1Img.draw(0, 0);
		ofPopMatrix();

	ofPopMatrix();

	//draw pointer and following boxes 
	ofPushMatrix();
		ofTranslate(pointerPos.x, pointerPos.y);
		ofRotateDeg(pointerAngle);
		ofScale(0.2, 0.2);
		pointerImg.draw(0, 0);
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(box1Pos.x + 10.0f, box1Pos.y + 10.0f);
		ofRotateDeg(boxAngle);
		ofScale(0.2, 0.2);
		squareImg.draw(0, 0);
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(box2Pos.x + 10.0f, box2Pos.y + 10.0f);
		ofRotateDeg(boxAngle);
		ofScale(0.15, 0.15);
		squareImg.draw(0, 0);
	ofPopMatrix();
}

//movement lerp function 
float ofApp::lerp(float start, float end, float percent)
{
	return (start + percent * (end - start));
}

//setting mouse target points on different press types 
void ofApp::mousePressed(int x, int y, int button)
{
	pointerTargetPos.set((float)x, (float)y);
	effectMusic.play();
}


void ofApp::mouseDragged(int x, int y, int button) 
{
	pointerTargetPos.set((float)x, (float)y);
}
