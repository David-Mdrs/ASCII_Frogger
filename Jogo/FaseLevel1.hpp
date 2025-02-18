#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "../ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Movimentavel.hpp"
#include "Caminhao.hpp"

class FaseLevel1 : public Fase {
public:
	FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel1() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
	bool colideComBloco() const;
	
private:
	ObjetoDeJogo *frogger;
	Movimentavel *carro1;
	Movimentavel *carro2;
	Caminhao *caminhao;
	
	// TextSprite *life;
	
	std::list<ObjetoDeJogo*> colisoes;
};

#endif // FASELEVEL1_HPP
