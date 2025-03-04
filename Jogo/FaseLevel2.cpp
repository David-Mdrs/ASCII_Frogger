#include "FaseLevel2.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"

#include <iostream>
#include <string>

void FaseLevel2::init() {

	// Objetos de jogo apenas visuais
	objs.push_back(new ObjetoDeJogo("fase1", Sprite("rsc/Fase.txt", COR::VERDE), 0, 0));

	objs.push_back(new ObjetoDeJogo("agua", Sprite("rsc/Agua.txt", COR::CIANO), 20, 3));

	for(int i = 0; i < 6; i++) { objs.push_back(new ObjetoDeJogo("aguaMenor", Sprite("rsc/Agua_Menor.txt", COR::CIANO), 10, 5 + 29 * i)); }

    objs.push_back(new ObjetoDeJogo("ferrovia", Sprite("rsc/Ferrovia.txt", COR::AMARELA), 21, 0));
	objs.push_back(new ObjetoDeJogo("trilho", Sprite("rsc/Trilho.txt", COR::CINZA), 22, 0));

	objs.push_back(new ObjetoDeJogo("rodovia", Sprite("rsc/Asfalto.txt", COR::CINZA), 28, 0));
	objs.push_back(new ObjetoDeJogo("rodovia", Sprite("rsc/Asfalto.txt", COR::CINZA), 31, 0));

	objs.push_back(new ObjetoDeJogo("faixa", Sprite("rsc/Faixa.txt", COR::AMARELA), 30, 0));
    objs.push_back(new ObjetoDeJogo("faixa", Sprite("rsc/Faixa.txt", COR::AMARELA), 33, 0));
	
	chegada = new ObjetoDeJogo("chegada", SpriteBuffer(155, 1), 7, 5);
	objs.push_back(chegada);

	// Primeira linha da água
	troncoP1 = new Plataforma(ObjetoDeJogo("troncoP", SpriteAnimado("rsc/TroncoPequenoEsq.anm", 3, COR::MARROM), 11, 30), ESQUERDA, 2);
	objs.push_back(troncoP1);
	troncoP2 = new Plataforma(ObjetoDeJogo("troncoP", SpriteAnimado("rsc/TroncoPequenoEsq.anm", 3, COR::MARROM), 11, 110), ESQUERDA, 2);
	objs.push_back(troncoP2);
	planta1 = new Planta(ObjetoDeJogo("planta", SpriteAnimado("rsc/Planta.anm", 3, COR::MAGENTA), 11, 80), ESQUERDA, 2);
	objs.push_back(planta1);
	planta2 = new Planta(ObjetoDeJogo("planta", SpriteAnimado("rsc/Planta.anm", 3, COR::MAGENTA), 11, 160), ESQUERDA, 2);
	objs.push_back(planta2);
	
	// Segunda linha da água
	troncoG1 = new Plataforma(ObjetoDeJogo("troncoG", SpriteAnimado("rsc/TroncoGrandeDir.anm", 3, COR::MARROM), 14, 0), DIREITA, 3);
	objs.push_back(troncoG1);
	troncoG2 = new Plataforma(ObjetoDeJogo("troncoG", SpriteAnimado("rsc/TroncoGrandeDir.anm", 3, COR::MARROM), 14, 110), DIREITA, 3);
	objs.push_back(troncoG2);

	// Terceira linha da água
	troncoP3 = new Plataforma(ObjetoDeJogo("troncoP", SpriteAnimado("rsc/TroncoPequenoEsq.anm", 3, COR::MARROM), 17, 70), ESQUERDA, 2);
	objs.push_back(troncoP3);
	troncoP4 = new Plataforma(ObjetoDeJogo("troncoP", SpriteAnimado("rsc/TroncoPequenoEsq.anm", 3, COR::MARROM), 17, 150), ESQUERDA, 2);
	objs.push_back(troncoP4);
	planta3 = new Planta(ObjetoDeJogo("planta", SpriteAnimado("rsc/Planta.anm", 3, COR::MAGENTA), 17, 35), ESQUERDA, 2);
	objs.push_back(planta3);
	planta4 = new Planta(ObjetoDeJogo("planta", SpriteAnimado("rsc/Planta.anm", 3, COR::MAGENTA), 17, 126), ESQUERDA, 2);
	objs.push_back(planta4);

	centroFrogger = new ObjetoDeJogo("centroFrogger", SpriteBuffer(2, 1), 20, 79);
	objs.push_back(centroFrogger);
	frogger = new Frogger(ObjetoDeJogo("frogger", SpriteAnimado("rsc/Frogger.anm", 2, COR::VERDE), 22, 77)); // 35, 77
	objs.push_back(frogger);

	carro1 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroEsq.anm", 5, COR::MAGENTA), 31, -10), ESQUERDA, 9);
	objs.push_back(carro1);
	carro2 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroEsq.anm", 5, COR::MAGENTA), 31, 70), ESQUERDA, 9);
	objs.push_back(carro2);

	caminhao1 = new Caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoDir.anm", 5, COR::LARANJA), 28, 80), DIREITA);
	objs.push_back(caminhao1);
	caminhao2 = new Caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoDir.anm", 5, COR::LARANJA), 28, 160), DIREITA, 14);
	objs.push_back(caminhao2);

    trem = new Trem(ObjetoDeJogo("trem", SpriteAnimado("rsc/Trem.anm", 4, COR::BRANCA), 20, -25), DIREITA);
	//objs.push_back(trem);

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

	objs.push_back(new ObjetoDeJogo("fase",TextSprite("02"), 3, 84));
	objs.push_back(new ObjetoDeJogo("vida",TextSprite("###"), 3, 41));
	SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
	vida = dynamic_cast<TextSprite*> (tmp);
}

unsigned FaseLevel2::run(SpriteBuffer &screen) {

	// Padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	Keyboard::setMode(Keyboard::NONBLOCKING);
	while (true) {
		if(carro1->getPosC() <= -5) { carro1->moveTo(31, 160); }
		if(carro2->getPosC() <= -5) { carro2->moveTo(31, 160); }

		if(caminhao1->getPosC() >= 160) { caminhao1->moveTo(28, 1); }
		if(caminhao2->getPosC() >= 160) { caminhao2->moveTo(28, 1); }
		
		if(trem->getPosC() >= 160) { trem->moveTo(20, -27); }
        // if(frogger->getPosL() == 20) { trem->setAtivo(true); }

		// Primeira linha da água
		if(troncoP1->getPosC() <= -15) { troncoP1->moveTo(11, 160); }
		if(troncoP2->getPosC() <= -15) { troncoP2->moveTo(11, 160); }
		if(planta1->getPosC() <= -15) { planta1->moveTo(planta1->getPosL(), 160); }
		if(planta2->getPosC() <= -15) { planta2->moveTo(planta2->getPosL(), 160); }

		// Segunda linha da água
		if(troncoG1->getPosC() >= 159) { troncoG1->moveTo(14, -49); }
		if(troncoG2->getPosC() >= 159) { troncoG2->moveTo(14, -49); }
		
		// Terceira linha da água
		if(troncoP3->getPosC() <= -15) { troncoP3->moveTo(17, 160); }
		if(troncoP4->getPosC() <= -15) { troncoP4->moveTo(17, 160); }
		if(planta3->getPosC() <= -15) { planta3->moveTo(planta3->getPosL(), 160); }
		if(planta4->getPosC() <= -15) { planta4->moveTo(planta4->getPosL(), 160); }

		if (planta1->getContador() == 15) { planta1->moveTo(45, 160); }
		if (planta2->getContador() == 15) { planta2->moveTo(45, 160); }
		if (planta3->getContador() == 15) { planta3->moveTo(45, 160); }
		if (planta4->getContador() == 15) { planta4->moveTo(45, 160); }

		// Lendo entrada
		char ent = Keyboard::read();

		// Colisão com bordas do mapa
		if (ent == 'w' && frogger->getPosL() > 7) {
			frogger->moveUp(1);
			if(frogger->colideCom(*muro1) || frogger->colideCom(*muro2) || frogger->colideCom(*muro3) || frogger->colideCom(*muro4) || frogger->colideCom(*muro5))
				frogger->moveDown(1);
		} else if (ent == 's' && frogger->getPosL() < screen.getAltura() - 6)
			frogger->moveDown(1);
		else if (ent == 'a' && frogger->getPosC() > 5) {
			frogger->moveLeft(2);
			if(frogger->colideCom(*muro1) || frogger->colideCom(*muro2) || frogger->colideCom(*muro3) || frogger->colideCom(*muro4) || frogger->colideCom(*muro5))
				frogger->moveRight(2);
		} else if (ent == 'd' && frogger->getPosC() < screen.getLarguraMaxFit() - frogger->getSprite()->getLarguraMaxFit() - 7) {
			frogger->moveRight(2);
			if(frogger->colideCom(*muro1) || frogger->colideCom(*muro2) || frogger->colideCom(*muro3) || frogger->colideCom(*muro4) || frogger->colideCom(*muro5))
				frogger->moveLeft(2);
		}
		else if (ent == 'q')
			return Fase::END_GAME;

		// Redefinindo centro do frogger
		centroFrogger->moveTo(frogger->getPosL()+1, frogger->getPosC()+2);
		
		// Colisão com carros, caminhões e trem
		if (frogger->colideComBordas(*carro1) || frogger->colideComBordas(*carro2) ||
			frogger->colideComBordas(*caminhao1) || frogger->colideComBordas(*caminhao2) ||
            frogger->colideComBordas(*trem)) {
				frogger->perderVida();
				frogger->moveTo(35, 77);
				vida->setText(std::string(frogger->getVida(), '#'));
		}
		// Colisão com água
		if (centroFrogger->getPosL() > 10 && centroFrogger->getPosL() < 20) {
			if (centroFrogger->colideCom(*troncoP1) || centroFrogger->colideCom(*troncoP2) ||
				centroFrogger->colideCom(*planta1) || centroFrogger->colideCom(*planta2)) {			
				if(frogger->colideCom(*muro1) || frogger->colideCom(*muro2) || frogger->colideCom(*muro3) || frogger->colideCom(*muro4) || frogger->colideCom(*muro5)) {
					frogger->moveRight(2);
				} else {
					frogger->moveLeft(2);
				}
			}

			if (centroFrogger->colideCom(*planta3) || centroFrogger->colideCom(*planta4))
				frogger->moveLeft(2);
	
			if (centroFrogger->colideCom(*planta1))
				planta1->setAtivo(true);
			else if (centroFrogger->colideCom(*planta2))
				planta2->setAtivo(true);
			else if (centroFrogger->colideCom(*planta3))
				planta3->setAtivo(true);
			else if (centroFrogger->colideCom(*planta4))
				planta4->setAtivo(true);

			else if (centroFrogger->colideCom(*troncoG1) || centroFrogger->colideCom(*troncoG2))
				frogger->moveRight(3);
			else if (centroFrogger->colideCom(*troncoP3) || centroFrogger->colideCom(*troncoP4))
				frogger->moveLeft(2);
			else {
				frogger->perderVida();
				frogger->moveTo(35, 77);
				vida->setText(std::string(frogger->getVida(), '#'));
			}

			if (frogger->getPosC() <= 5) {
				frogger->moveRight(3);
			} else if (frogger->getPosC() >= 156) {
				frogger->moveLeft(3);
			}
			centroFrogger->moveTo(frogger->getPosL()+1, frogger->getPosC()+2);
		}

		// Padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);
		system("sleep 0.125");

		if (!frogger->vivo())
			return Fase::GAME_OVER;

		if (frogger->colideComBordas(*chegada))
			return Fase::LEVEL_COMPLETE;
	}
	
	return Fase::END_GAME; // não necessário
}