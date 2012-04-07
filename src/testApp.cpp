#include "testApp.h"

void testApp::setup()  
{  
    
    ofSetVerticalSync(true);
	ofBackground(54, 54, 54);	

    
    int bufferSize = 256;

    ofSoundStreamSetup(2,2,this, 44100, bufferSize, 4);  
    leftAudio.assign(bufferSize, 0.0);
    rightAudio.assign(bufferSize, 0.0);  
}

void testApp::draw(){
//
    
    ofSetColor(225);
	ofDrawBitmapString("AUDIO INPUT/OUTPUT", 32, 32);
	ofDrawBitmapString("press 's' to unpause the audio\n'e' to pause the audio", 31, 92);
	
	ofNoFill();
	
	// draw the left channel:
	ofPushStyle();
    ofPushMatrix();
    ofTranslate(32, 170, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Left Channel", 4, 18);
    
    ofSetLineWidth(1);	
    ofRect(0, 0, 512, 200);
    
    ofSetColor(245, 58, 135);
    ofSetLineWidth(3);
    
    ofBeginShape();
    for (int i = 0; i < leftAudio.size(); i++){
        ofVertex(i*2, 100 -leftAudio[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
	ofPopStyle();
    
	// draw the right channel:
	ofPushStyle();
    ofPushMatrix();
    ofTranslate(32, 370, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Right Channel", 4, 18);
    
    ofSetLineWidth(1);	
    ofRect(0, 0, 512, 200);
    
    ofSetColor(245, 58, 135);
    ofSetLineWidth(3);
    
    ofBeginShape();
    for (int i = 0; i < rightAudio.size(); i++){
        ofVertex(i*2, 100 -rightAudio[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
	ofPopStyle();

    
    
}

void testApp::update(){
//
}

void testApp::audioIn     (float * input, int bufferSize, int nChannels)  
{  
    for (int i = 0; i < bufferSize; i++)  
    {  
        leftAudio[i]  = input[i*2] ;  
        rightAudio[i] = input[(i*2)+1];  
    }  
}  


void testApp::audioOut    (float * output, int bufferSize, int nChannels)  
{  
    for (int i = 0; i < bufferSize; i++)  
    {  
        output[i*2]     = leftAudio[i] ;  
        output[(i*2)+1] = rightAudio[i];  
    }  
    
}  

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	if( key == 's' ){
		soundStream.start();
	}
	
	if( key == 'e' ){
		soundStream.stop();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}