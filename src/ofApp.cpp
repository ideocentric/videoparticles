#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cp.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    cp.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cp.draw();
    ofSetColor(255);
    ofDrawBitmapString(ofToString( ofGetFrameRate() ), 10,15);
    ofDrawBitmapString(ofToString( cp.particles.size() ), 10,30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
