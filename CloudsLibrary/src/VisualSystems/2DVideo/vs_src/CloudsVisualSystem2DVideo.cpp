//
//  CloudsVisualSystem2DVideo.cpp
//

#include "CloudsVisualSystem2DVideo.h"

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::selfSetupGui()
{

	playerGui = new ofxUISuperCanvas("VideoPlayer", gui);
	playerGui->copyCanvasStyle(gui);
	playerGui->copyCanvasProperties(gui);
	playerGui->setName("VideoPlayer");
	playerGui->setWidgetFontSize(OFX_UI_FONT_SMALL);
    playerGui->addLabel("VIDEOS");
    playerGui->addSpacer();
    playerGui->addRadio("MOVIE FILES",movieStrings);
    playerGui->addButton("IN TIME", false);
    playerGui->addButton("OUT TIME", false);
    
	ofAddListener(playerGui->newGUIEvent, this, &CloudsVisualSystem2DVideo::selfGuiEvent);
	guis.push_back(playerGui);
	guimap[playerGui->getName()] = playerGui;
    

    
}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::selfGuiEvent(ofxUIEventArgs &e)
{
    if (e.getKind() == OFX_UI_WIDGET_TOGGLE){

        ofxUIToggle* t = (ofxUIToggle*)e.widget;
        cout<<t->getName()<<endl;
        for(int i =0; i<movieStrings.size(); i++){
            if (movieStrings[i] == t->getName()) {
				cout << "Loading movie from GUI " << movieStrings[i] << endl;
                loadMovieAtIndex(i);
            }
        }
    }
    if (e.getKind() == OFX_UI_WIDGET_BUTTON){
        
        if(e.getName() == "IN TIME"){
            inTime = player.getCurrentTime();
        }
        else if (e.getName() == "OUT TIME"){
            outTime = player.getCurrentTime();
        }
    }

}

void CloudsVisualSystem2DVideo::loadMovieAtIndex(int index){
 
    if(player.isPlaying()){
        player.stop();
    }
                cout<<getVisualSystemDataPath(true)<< " : "<<movieStrings[index]<<endl;
    if(player.loadMovie(getVisualSystemDataPath(true)+movieStrings[index])){
        player.play();
        bFileLoaded = false;
    }
    else{
        cout<<"couldn't load the movie"<<endl;
    }
}

//Use system gui for global or logical settings, for exmpl
void CloudsVisualSystem2DVideo::selfSetupSystemGui(){

}

void CloudsVisualSystem2DVideo::guiSystemEvent(ofxUIEventArgs &e){
	
}
//use render gui for display settings, like changing colors
void CloudsVisualSystem2DVideo::selfSetupRenderGui(){

}

void CloudsVisualSystem2DVideo::guiRenderEvent(ofxUIEventArgs &e){
	
}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::selfSetup()
{
    screenRect = ofRectangle(0,0, ofGetWidth(), ofGetHeight());
    videoRect = ofRectangle(0,0, ofGetWidth(), ofGetHeight());
    movieIndex = 0;
    movieStrings.push_back("traffic_1.mov");
    movieStrings.push_back("unionsq_1 - Wi-Fi_Crop.mov");
    loadMovieAtIndex(movieIndex);

}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::restart()
{

}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::selfPresetLoaded(string presetPath)
{

}

// selfBegin is called when the system is ready to be shown
// this is a good time to prepare for transitions
// but try to keep it light weight as to not cause stuttering
void CloudsVisualSystem2DVideo::selfBegin(){
	player.play();
}

//do things like ofRotate/ofTranslate here
//any type of transformation that doesn't have to do with the camera
void CloudsVisualSystem2DVideo::selfSceneTransformation(){
	
}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::selfUpdate()
{
    if(! bFileLoaded){
        if(player.getWidth() >0){
            videoRect.x = 0;
            videoRect.y = 0;
            videoRect.width = player.getWidth();
            videoRect.height = player.getHeight();
            cout<<player.getWidth()<<","<<player.getHeight()<<endl;
            videoRect.scaleTo(screenRect);
            bFileLoaded = true;
        }
    }
    player.update();

    if(timeline->getDurationInSeconds() != (outTime - inTime)){
        timeline->setDurationInSeconds(outTime-inTime);
    }
}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::selfDraw()
{

}

// draw any debug stuff here
void CloudsVisualSystem2DVideo::selfDrawDebug(){

}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::selfDrawBackground()
{
    player.draw(videoRect.x, videoRect.y, videoRect.width, videoRect.height);
}

//--------------------------------------------------------------
void CloudsVisualSystem2DVideo::render()
{

}

// this is called when your system is no longer drawing.
// Right after this selfUpdate() and selfDraw() won't be called any more
void CloudsVisualSystem2DVideo::selfEnd(){

	
}
// this is called when you should clear all the memory and delet anything you made in setup
void CloudsVisualSystem2DVideo::selfExit(){
	
}

//events are called when the system is active
//Feel free to make things interactive for you, and for the user!
void CloudsVisualSystem2DVideo::selfKeyPressed(ofKeyEventArgs & args){
	
    if(args.key == 'i' ){
        cout<<player.getCurrentTime()<<endl;
    }
    else if (args.key == 'o'){
        cout<<player.getCurrentTime()<<endl;
    }
}
void CloudsVisualSystem2DVideo::selfKeyReleased(ofKeyEventArgs & args){
	
}

void CloudsVisualSystem2DVideo::selfMouseDragged(ofMouseEventArgs& data){
	
}

void CloudsVisualSystem2DVideo::selfMouseMoved(ofMouseEventArgs& data){
	
}

void CloudsVisualSystem2DVideo::selfMousePressed(ofMouseEventArgs& data){
	
}

void CloudsVisualSystem2DVideo::selfMouseReleased(ofMouseEventArgs& data){
	
}