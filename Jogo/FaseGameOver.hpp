#ifndef FASEGAMEOVER_HPP
#define FASEGAMEOVER_HPP

#include "../ASCII_Engine/Fase.hpp"

class FaseGameOver : public Fase {
public:
    FaseGameOver(std::string name, const SpriteBuffer &bkg) : Fase(name, bkg) {}
	virtual ~FaseGameOver() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
private:	
    ObjetoDeJogo *sapo1;
    ObjetoDeJogo *sapo2;
    ObjetoDeJogo *gameOver;
	enum {RIDING, PRACING, END};
};

#endif