#ifndef FASESTART_HPP
#define FASESTART_HPP

#include "../ASCII_Engine/Fase.hpp"

class FaseStart : public Fase {
public:
    FaseStart(std::string name, const SpriteBuffer &bkg) : Fase(name, bkg) {}
	virtual ~FaseStart() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
private:	
	enum {RIDING, PRACING, END};
};

#endif