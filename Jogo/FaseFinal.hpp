#ifndef FASEFINAL_HPP
#define FASEFINAL_HPP

#include "../ASCII_Engine/Fase.hpp"

class FaseFinal : public Fase {
public:
    FaseFinal(std::string name, const SpriteBuffer &bkg) : Fase(name, bkg) {}
	virtual ~FaseFinal() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
private:	
    ObjetoDeJogo *sapo1;
    ObjetoDeJogo *sapo2;
    ObjetoDeJogo *texto;
	enum {RIDING, PRACING, END};
};

#endif