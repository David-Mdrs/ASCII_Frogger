#include <iostream>
#include <string>

// #include "Game.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include "Movimentavel.hpp"
#include "Caminhao.hpp"
#include "Trem.hpp"

int main() {

	system("clear");

	SpriteBuffer screen(161, 40);

	ObjetoDeJogo parede("parede", Sprite("rsc/Fase1/Fase1_Parede.txt", COR::BRANCA), 0, 0);
	ObjetoDeJogo agua("agua", Sprite("rsc/Fase1/Fase1_Agua.txt", COR::CIANO), 20, 3);
	ObjetoDeJogo aguaMenor("aguaMenor", Sprite("rsc/Fase1/Fase1_Agua_Menor.txt", COR::CIANO), 10, 3);
	ObjetoDeJogo asfalto("rodovia", Sprite("rsc/Fase1/Fase1_Asfalto.txt", COR::CINZA), 24, 0);
	ObjetoDeJogo faixa("faixa", Sprite("rsc/Fase1/Fase1_Faixa.txt", COR::AMARELA), 24, 0);


	ObjetoDeJogo sapo("sapo", SpriteAnimado("rsc/Sapo.anm", 1, COR::VERDE), 31, 38);

	Movimentavel pocante(ObjetoDeJogo("pocante", SpriteAnimado("rsc/CarroDir.anm", 1, COR::VERMELHA), 31, 20), DIREITA);

	Caminhao caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoDir.anm", 1, COR::BORDO), 24, 2), DIREITA);

	// Game::run();

	std::string str;
	int posAgua{18};

	while(true) {
		getline(std::cin, str);

		screen.clear();
		system("clear");

		if(str == "w")
			sapo.moveUp();
		else if(str == "a")
			sapo.moveLeft(2);
		else if(str == "s")
			sapo.moveDown();
		else if(str == "d")
			sapo.moveRight(2);

		parede.update();		
		agua.update();
		aguaMenor.update();		
		asfalto.update();
		faixa.update();
		
		sapo.update();
		pocante.movimentar();
		caminhao.movimentar();

		parede.draw(screen, parede.getPosL(), parede.getPosC());
		asfalto.draw(screen, asfalto.getPosL(), asfalto.getPosC());
		faixa.draw(screen, faixa.getPosL(), faixa.getPosC());


		agua.draw(screen, agua.getPosL(), agua.getPosC());
		for(int i = 0; i < 6; i++) {
			aguaMenor.draw(screen, aguaMenor.getPosL(), aguaMenor.getPosC() + 29 * i);
		}

		sapo.draw(screen, sapo.getPosL(), sapo.getPosC());
		pocante.draw(screen, pocante.getPosL(), pocante.getPosC());
		caminhao.draw(screen, caminhao.getPosL(), caminhao.getPosC());

		std::cout << screen << std::endl;
	}
	
	return 0;
}
