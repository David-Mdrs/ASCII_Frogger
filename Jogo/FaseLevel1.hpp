#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "../ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Movimentavel.hpp"
#include "Caminhao.hpp"
#include "Frogger.hpp"
#include "Plataforma.hpp"

class FaseLevel1 : public Fase {
public:
	FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel1() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
	bool colideComBloco() const;
	
private:
	Frogger *frogger;
	ObjetoDeJogo *centroFrogger;
	ObjetoDeJogo *froggerMorto;
	TextSprite *vida;
	ObjetoDeJogo *chegada;

	Movimentavel *carro1;
	Movimentavel *carro2;
	Movimentavel *carro3;

	Caminhao *caminhao1;
	Caminhao *caminhao2;

	Plataforma *troncoG1;
	Plataforma *troncoG2;
	Plataforma *troncoG3;

	Plataforma *troncoP1;
	Plataforma *troncoP2;

	ObjetoDeJogo *muro1;
	ObjetoDeJogo *muro2;
	ObjetoDeJogo *muro3;
	ObjetoDeJogo *muro4;
	ObjetoDeJogo *muro5;
	
	std::list<ObjetoDeJogo*> colisoes;
};

#endif // FASELEVEL1_HPP
