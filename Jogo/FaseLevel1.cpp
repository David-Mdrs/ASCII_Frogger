#include "FaseLevel1.hpp"

#include <iostream>
#include <string>

void FaseLevel1::init() {

	// Objetos de jogo apenas visuais
	objs.push_back(new ObjetoDeJogo("fase1", Sprite("rsc/Fase1.txt", COR::VERDE), 0, 0));

	objs.push_back(new ObjetoDeJogo("agua", Sprite("rsc/Agua.txt", COR::CIANO), 17, 3));

	for(int i = 0; i < 6; i++) { objs.push_back(new ObjetoDeJogo("aguaMenor", Sprite("rsc/Agua_Menor.txt", COR::CIANO), 10, 5 + 29 * i)); }

	objs.push_back(new ObjetoDeJogo("rodovia", Sprite("rsc/Asfalto.txt", COR::CINZA), 22, 0));
	objs.push_back(new ObjetoDeJogo("rodovia", Sprite("rsc/Asfalto.txt", COR::CINZA), 30, 0));

	objs.push_back(new ObjetoDeJogo("faixa", Sprite("rsc/Faixa.txt", COR::AMARELA), 24, 0));
	objs.push_back(new ObjetoDeJogo("faixa", Sprite("rsc/Faixa.txt", COR::AMARELA), 32, 0));
	
	chegada = new ObjetoDeJogo("chegada", SpriteBuffer(155, 1), 7, 5);
	objs.push_back(chegada);

	// Objetos de jogo funcionáveis
	troncoG1 = new Plataforma(ObjetoDeJogo("troncoG", SpriteAnimado("rsc/TroncoGrandeEsq.anm", 3, COR::MARROM), 14, 10), ESQUERDA);
	objs.push_back(troncoG1);
	troncoG2 = new Plataforma(ObjetoDeJogo("troncoG", SpriteAnimado("rsc/TroncoGrandeEsq.anm", 3, COR::MARROM), 14, 80), ESQUERDA);
	objs.push_back(troncoG2);
	troncoG3 = new Plataforma(ObjetoDeJogo("troncoG", SpriteAnimado("rsc/TroncoGrandeEsq.anm", 3, COR::MARROM), 14, 140), ESQUERDA);
	objs.push_back(troncoG3);

	troncoP1 = new Plataforma(ObjetoDeJogo("troncoP", SpriteAnimado("rsc/TroncoPequenoDir.anm", 3, COR::MARROM), 11, 30), DIREITA);
	objs.push_back(troncoP1);
	troncoP2 = new Plataforma(ObjetoDeJogo("troncoP", SpriteAnimado("rsc/TroncoPequenoDir.anm", 3, COR::MARROM), 11, 110), DIREITA);
	objs.push_back(troncoP2);

	frogger = new Frogger(ObjetoDeJogo("frogger", SpriteAnimado("rsc/Frogger.anm", 1, COR::VERDE), 35, 77));
	objs.push_back(frogger);

	carro1 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 5, COR::MAGENTA), 22, -10), DIREITA, 7);
	objs.push_back(carro1);
	carro2 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 5, COR::MAGENTA), 22, 50), DIREITA, 7);
	objs.push_back(carro2);
	carro3 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 5, COR::MAGENTA), 22, 100), DIREITA, 7);
	objs.push_back(carro3);

	caminhao1 = new Caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoEsq.anm", 5, COR::LARANJA), 30, 70), ESQUERDA);
	objs.push_back(caminhao1);
	caminhao2 = new Caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoEsq.anm", 5, COR::LARANJA), 30, 160), ESQUERDA, 14);
	objs.push_back(caminhao2);

	objs.push_back(new ObjetoDeJogo("parede", Sprite("rsc/Parede.txt", COR::VERDE), 7, 0));
	objs.push_back(new ObjetoDeJogo("parede", Sprite("rsc/Parede.txt", COR::VERDE), 7, 160));

	muro1 = new ObjetoDeJogo("muro", Sprite("rsc/Muro.txt", COR::VERDE), 7, 15);
	objs.push_back(muro1);
	muro2 = new ObjetoDeJogo("muro", Sprite("rsc/Muro.txt", COR::VERDE), 7, 44);
	objs.push_back(muro2);
	muro3 = new ObjetoDeJogo("muro", Sprite("rsc/Muro.txt", COR::VERDE), 7, 73);
	objs.push_back(muro3);
	muro4 = new ObjetoDeJogo("muro", Sprite("rsc/Muro.txt", COR::VERDE), 7, 102);
	objs.push_back(muro4);
	muro5 = new ObjetoDeJogo("muro", Sprite("rsc/Muro.txt", COR::VERDE), 7, 131);
	objs.push_back(muro5);

	objs.push_back(new ObjetoDeJogo("fase",TextSprite("01"), 3, 84));
	objs.push_back(new ObjetoDeJogo("vida",TextSprite("###"), 3, 41));
	SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
	vida = dynamic_cast<TextSprite*> (tmp);
}

unsigned FaseLevel1::run(SpriteBuffer &screen) {
	std::string ent;
	
	// Padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	while (true) {
		if(carro1->getPosC() >= 160) { carro1->moveTo(22, -5); }
		if(carro2->getPosC() >= 160) { carro2->moveTo(22, -5); }
		if(carro3->getPosC() >= 160) { carro3->moveTo(22, -5); }

		if(caminhao1->getPosC() <= 10) { caminhao1->moveTo(30, 160); }
		if(caminhao2->getPosC() <= 10) { caminhao2->moveTo(30, 160); }
		
		if(troncoG1->getPosC() <= -17) { troncoG1->moveTo(14, 160); }
		if(troncoG2->getPosC() <= -17) { troncoG2->moveTo(14, 160); }
		if(troncoG3->getPosC() <= -17) { troncoG3->moveTo(14, 160); }
		
		if(troncoP1->getPosC() >= 159) { troncoP1->moveTo(11, -8); }
		if(troncoP2->getPosC() >= 159) { troncoP2->moveTo(11, -8); }

		// Lendo entrada
		getline(std::cin,ent);
		
		// Processando entradas
		int posL = frogger->getPosL(), posC = frogger->getPosC();
		
		// Colisão com bordas do mapa
		if (ent == "w" && frogger->getPosL() > 7) {
			frogger->moveUp(1);
			if(frogger->colideCom(*muro1) || frogger->colideCom(*muro2) || frogger->colideCom(*muro3) || frogger->colideCom(*muro4) || frogger->colideCom(*muro5))
				frogger->moveDown(1);
		} else if (ent == "s" && frogger->getPosL() < screen.getAltura() - 6)
			frogger->moveDown(1);
		else if (ent == "a" && frogger->getPosC() > 5) {
			frogger->moveLeft(2);
			if(frogger->colideCom(*muro1) || frogger->colideCom(*muro2) || frogger->colideCom(*muro3) || frogger->colideCom(*muro4) || frogger->colideCom(*muro5))
				frogger->moveRight(2);
		} else if (ent == "d" && frogger->getPosC() < screen.getLarguraMaxFit() - frogger->getSprite()->getLarguraMaxFit() - 7) {
			frogger->moveRight(2);
			if(frogger->colideCom(*muro1) || frogger->colideCom(*muro2) || frogger->colideCom(*muro3) || frogger->colideCom(*muro4) || frogger->colideCom(*muro5))
				frogger->moveLeft(2);
		}
		else if (ent == "q")
			return Fase::END_GAME;
		
		
		// Processando eventos
		if (frogger->colideComBordas(*carro1) || frogger->colideComBordas(*carro2) || frogger->colideComBordas(*carro3) ||
			frogger->colideComBordas(*caminhao1) || frogger->colideComBordas(*caminhao2)) {
				frogger->perderVida();
				frogger->moveTo(35, 77);
				vida->setText(std::string(frogger->getVida(), '#'));
		}
			
		if (!frogger->vivo())
			return Fase::GAME_OVER;

		// Padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);

		if (frogger->colideComBordas(*chegada))
			return Fase::LEVEL_COMPLETE;
	}
	
	return Fase::END_GAME; // não necessário
}

// bool FaseLevel1::colideComBloco() const
// {
// 	for (auto it = colisoes.begin() ; it != colisoes.end() ; ++it)
// 		if (frogger->colideCom(**it)) {
// 			return true;
// 		}
	
// 	// if (frogger->colideCom(*porta) && !porta->isOpen() )
// 	// 	return true;
	
// 	return false;
// }

