#include "testApp.h"

void testApp::setup()  
{  
    
    int bufferSize = 512;

    ofSoundStreamSetup(2,2,this, 44100, 512, 4);  
    leftAudio.assign(bufferSize, 0.0);
    rightAudio.assign(bufferSize, 0.0);  
}

void testApp::draw(){
//
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