#include "ofMain.h"
#include "ofxOMXPlayer.h"


class ofRPIVideoPlayer: public ofBaseVideoPlayer
{
public:
    ofRPIVideoPlayer();
    bool load(string name);
    void loadAsync(string name);
    void play();
    void stop();
    ofTexture* getTexturePtr();
    float getWidth() const;
    float getHeight() const;
    bool isPaused() const;
    bool isLoaded() const;
    bool isPlaying() const;
    bool isInitialized() const;
    const ofPixels& getPixels() const;
    ofPixels& getPixels();
    void update();
    bool isFrameNew() const;
    void close();
    bool setPixelFormat(ofPixelFormat pixelFormat);
    ofPixelFormat getPixelFormat() const;
    
    ofxOMXPlayer omxPlayer;
	void draw(float x, float y, float w, float h);
    void draw(float x, float y);
protected:
    ofPixels pixels;
    ofPixelFormat pixelFormat;
    float videoWidth;
    float videoHeight;
    bool pauseState;
    bool openState;
    bool isPlayingState;
    bool hasNewFrame;
};
