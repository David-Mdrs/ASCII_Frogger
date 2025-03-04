#ifndef FASELEVEL2_HPP
#define FASELEVEL2_HPP

#include "../ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Movimentavel.hpp"
#include "Caminhao.hpp"
#include "Trem.hpp"
#include "Frogger.hpp"
#include "Plataforma.hpp"
#include "Planta.hpp"

class FaseLevel2 : public Fase {
public:
	FaseLevel2(std::string name, const SpriteBuffer &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel2() {}
	
	
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

	Caminhao *caminhao1;
	Caminhao *caminhao2;

    Trem *trem;

	Planta *planta1;
	Planta *planta2;
	Planta *planta3;
	Planta *planta4;

	Plataforma *troncoG1;
	Plataforma *troncoG2;

	Plataforma *troncoP1;
	Plataforma *troncoP2;
	Plataforma *troncoP3;
	Plataforma *troncoP4;

	ObjetoDeJogo *muro1;
	ObjetoDeJogo *muro2;
	ObjetoDeJogo *muro3;
	ObjetoDeJogo *muro4;
	ObjetoDeJogo *muro5;
	
	std::list<ObjetoDeJogo*> colisoes;
};

#endif // FASELEVEL2_HPP
