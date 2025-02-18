#include "FaseLevel1.hpp"

#include <iostream>
#include <string>

void FaseLevel1::init() {

	// Objetos de jogo apenas visuais
	objs.push_back(new ObjetoDeJogo("fase1", Sprite("rsc/Fase1.txt", COR::VERDE), 0, 0));
	for(int i = 0; i < 5; i++) {
		objs.push_back(new ObjetoDeJogo("cabine", Sprite("rsc/Cabine.txt", COR::VERDE), 7, 15 + 29 * i));
	}
	objs.push_back(new ObjetoDeJogo("agua", Sprite("rsc/Agua.txt", COR::CIANO), 20, 3));
	for(int i = 0; i < 6; i++) {
		objs.push_back(new ObjetoDeJogo("aguaMenor", Sprite("rsc/Agua_Menor.txt", COR::CIANO), 10, 5 + 29 * i));
	}
	objs.push_back(new ObjetoDeJogo("rodovia", Sprite("rsc/Asfalto.txt", COR::CINZA), 24, 0));
	objs.push_back(new ObjetoDeJogo("rodovia", Sprite("rsc/Asfalto.txt", COR::CINZA), 31, 0));

	objs.push_back(new ObjetoDeJogo("faixa", Sprite("rsc/Faixa.txt", COR::AMARELA), 26, 0));
	objs.push_back(new ObjetoDeJogo("faixa", Sprite("rsc/Faixa.txt", COR::AMARELA), 33, 0));

	// Objetos de jogo funcionáveis
	frogger = new Frogger(ObjetoDeJogo("frogger", SpriteAnimado("rsc/Frogger.anm", 1, COR::VERDE), 35, 77));
	objs.push_back(frogger);

	carro1 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 5, COR::MAGENTA), 24, -10), DIREITA), 4;
	objs.push_back(carro1);
	carro2 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 5, COR::MAGENTA), 24, 50), DIREITA, 4);
	objs.push_back(carro2);
	carro3 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 5, COR::MAGENTA), 24, 100), DIREITA, 4);
	objs.push_back(carro3);

	caminhao1 = new Caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoEsq.anm", 5, COR::MAGENTA), 31, 70), ESQUERDA);
	objs.push_back(caminhao1);
	caminhao2 = new Caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoEsq.anm", 5, COR::MAGENTA), 31, 160), ESQUERDA, 5);
	objs.push_back(caminhao2);

	objs.push_back(new ObjetoDeJogo("parede", Sprite("rsc/Parede.txt", COR::VERDE), 7, 0));
	objs.push_back(new ObjetoDeJogo("parede", Sprite("rsc/Parede.txt", COR::VERDE), 7, 160));

	objs.push_back(new ObjetoDeJogo("vida",TextSprite("###"), 3, 39));
	SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
	vida = dynamic_cast<TextSprite*> (tmp);
	
	// Blocos
	// objs.push_back(new ObjetoDeJogo("B1",Sprite("rsc/castleBlock1.img",COR::VERMELHA),18,38));
	// colisoes.push_back(objs.back());
	
}

unsigned FaseLevel1::run(SpriteBuffer &screen) {
	std::string ent;
	
	// Padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	while (true) {
		if(carro1->getPosC() >= 160) { carro1->moveTo(24, -15); }
		if(carro2->getPosC() >= 160) { carro2->moveTo(24, -15); }
		if(carro3->getPosC() >= 160) { carro3->moveTo(24, -15); }
		if(caminhao1->getPosC() <= 10) { caminhao1->moveTo(31, 160); }
		if(caminhao2->getPosC() <= 10) { caminhao2->moveTo(31, 160); }

		// Lendo entrada
		getline(std::cin,ent);
		
		// Processando entradas
		int posL = frogger->getPosL(), posC = frogger->getPosC();
		
		// Colisão com bordas do mapa
		if (ent == "w" && frogger->getPosL() > 7)
			frogger->moveUp(1);
		else if (ent == "s" && frogger->getPosL() < screen.getAltura() - 6)
			frogger->moveDown(1);
		else if (ent == "a" && frogger->getPosC() > 5)
			frogger->moveLeft(2);
		else if (ent == "d" && frogger->getPosC() < screen.getLarguraMaxFit() - frogger->getSprite()->getLarguraMaxFit() - 7)
			frogger->moveRight(2);
		else if (ent == "q")
			return Fase::END_GAME;
		

		// if (colideComBloco())
		// 	frogger->moveTo(posL,posC);
		
		
		// Processando eventos
		if (frogger->colideComBordas(*carro1) || frogger->colideComBordas(*carro2) || frogger->colideComBordas(*carro3) ||
			frogger->colideComBordas(*caminhao1) || frogger->colideComBordas(*caminhao2)) {
				frogger->perderVida();
				frogger->moveTo(35, 77);
				vida->setText(std::string(frogger->getVida(), '#'));
		}
			
		if (!frogger->vivo())
			return Fase::GAME_OVER;
			
			// life->setText(std::string(hero->getLife()/5,'#'));
		
		// if (hero->colideComBordas(*chave))
		// {
		// 	chave->desativarObj();
		// 	miniChave->ativarObj();
		// 	hero->pegarChave();
		// }
		// else if (hero->colideComBordas(*tapetePorta) && hero->possuiChave())
		// {
		// 	porta->openTheDoor();
		// }
		// else if (hero->colideComBordas(*princesa))
		// {
		// 	princesa->desativarObj();
		// 	hero->salvarPrincesa();
		// }
		// else if (hero->colideComBordas(*portao) && hero->salvouPrincesa())
		// {
		// 	return Fase::LEVEL_COMPLETE;
		// }
		
		// Padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);
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

