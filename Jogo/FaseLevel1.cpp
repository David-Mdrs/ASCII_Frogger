#include "FaseLevel1.hpp"

#include "Movimentavel.hpp"
#include "Caminhao.hpp"

#include <iostream>

void FaseLevel1::init() {

	// Objetos de jogo apenas visuais
	objs.push_back(new ObjetoDeJogo("parede", Sprite("rsc/Fase1/Fase1_Background.txt", COR::VERDE), 0, 0));
	objs.push_back(new ObjetoDeJogo("agua", Sprite("rsc/Fase1/Fase1_Agua.txt", COR::CIANO), 20, 3));
	for(int i = 0; i < 6; i++) {
		objs.push_back(new ObjetoDeJogo("aguaMenor", Sprite("rsc/Fase1/Fase1_Agua_Menor.txt", COR::CIANO), 10, 3 + 29 * i));
	}
	objs.push_back(new ObjetoDeJogo("rodovia", Sprite("rsc/Fase1/Fase1_Asfalto.txt", COR::CINZA), 24, 0));
	objs.push_back(new ObjetoDeJogo("faixa", Sprite("rsc/Fase1/Fase1_Faixa.txt", COR::AMARELA), 24, 0));


	// Objetos de jogo funcionáveis
	// Caminhao caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoDir.anm", 1, COR::MAGENTA), 24, 2), DIREITA);

	frogger = new ObjetoDeJogo("frogger", SpriteAnimado("rsc/Frogger.anm", 1, COR::VERDE), 35, 77);
	objs.push_back(frogger);

	carro1 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 3, COR::MAGENTA), 24, -10), DIREITA);
	objs.push_back(carro1);
	carro2 = new Movimentavel(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 3, COR::MAGENTA), 24, 50), DIREITA);
	objs.push_back(carro2);

	objs.push_back(new ObjetoDeJogo("parede", Sprite("rsc/Fase1/Fase1_Parede.txt", COR::VERDE), 7, 0));
	objs.push_back(new ObjetoDeJogo("parede", Sprite("rsc/Fase1/Fase1_Parede.txt", COR::VERDE), 7, 158));

	// SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
	// life = dynamic_cast<TextSprite*> (tmp);
	
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

		carro1->movimentar();
		carro2->movimentar();

		// Lendo entrada
		getline(std::cin,ent);
		
		// Processando entradas
		int posL = frogger->getPosL(), posC = frogger->getPosC();
		
		// Colisão com bordas do mapa
		if (ent == "w" && frogger->getPosL() > 7)
			frogger->moveUp(1);
		else if (ent == "s" && frogger->getPosL() < screen.getAltura() - 5)
			frogger->moveDown(1);
		else if (ent == "a" && frogger->getPosC() > 3)
			frogger->moveLeft(2);
		else if (ent == "d" && frogger->getPosC() < screen.getLarguraMaxFit() - frogger->getSprite()->getLarguraMaxFit() - 5)
			frogger->moveRight(2);
		else if (ent == "q")
			return Fase::END_GAME;
			

		// if (colideComBloco())
		// 	frogger->moveTo(posL,posC);
		
		
		// //processando eventos
		// for (int g = 0 ; g < 2 ; g++)
		// 		if (hero->colideComBordas(*guardas[g])) {
		// 			hero->sofrerAtaque(guardas[g]->atacar());
					
		// 			if (!hero->isAlive())
		// 				return Fase::GAME_OVER;
					
		// 			life->setText(std::string(hero->getLife()/5,'#'));
		// 		}
		
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
		
		
		//padrão
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

