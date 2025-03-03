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
    ObjetoDeJogo *sapo1;
    ObjetoDeJogo *sapo2;
    ObjetoDeJogo *texto;
	enum {RIDING, PRACING, END};
};

#endif