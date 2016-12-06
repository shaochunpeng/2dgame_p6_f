#ifndef MULTISPRITE__H
#define MULTISPRITE__H
#include <string>
#include <vector>
#include "drawable.h"

class ExplodingMultiSprite;
class MultiSprite : public Drawable {
public:
  MultiSprite(const std::string&);
  MultiSprite(const MultiSprite& s);
  MultiSprite& operator=(const MultiSprite&);

  virtual ~MultiSprite() { } 
  
  virtual void draw() const;
  virtual void update(Uint32 ticks);
  virtual const Frame* getFrame() const { 
    return m_frames[currentFrame]; 
  }
  void explode();

protected:
  ExplodingMultiSprite* explosion;
  const std::vector<Frame *> m_frames;
  int worldWidth;
  int worldHeight;

  unsigned currentFrame;
  unsigned numberOfFrames;
  unsigned frameInterval;
  float timeSinceLastFrame;
  int frameWidth;
  int frameHeight;

  void advanceFrame(Uint32 ticks);
};
#endif