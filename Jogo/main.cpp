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

	SpriteBuffer screen(160, 40);

	ObjetoDeJogo background("background", Sprite("rsc/Fase1.txt"), 0, 0);

	ObjetoDeJogo sapo("sapo", SpriteAnimado("rsc/Sapo.anm", 1, COR::VERDE), 34, 38);

	Movimentavel pocante(ObjetoDeJogo("pocante", SpriteAnimado("rsc/CarroDir.anm", 1, COR::VERDE), 30, 20), DIREITA);

	Caminhao caminhao(ObjetoDeJogo("caminhao", SpriteAnimado("rsc/CaminhaoDir.anm", 1, COR::MAGENTA), 10, 0), DIREITA);

	Trem trem(ObjetoDeJogo("trem", SpriteAnimado("rsc/Trem.anm", 1, COR::CIANO), 15, 0), DIREITA);

	// SpriteAnimado trem("rsc/Trem.anm", 1, COR::CIANO);
	// Game::run();

	std::string str;

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

		pocante.movimentar();
		caminhao.movimentar();
		trem.movimentar();

		background.update();		
		sapo.update();

		background.draw(screen, background.getPosL(), background.getPosC());
		sapo.draw(screen, sapo.getPosL(), sapo.getPosC());
		pocante.draw(screen, pocante.getPosL(), pocante.getPosC());
		caminhao.draw(screen, caminhao.getPosL(), caminhao.getPosC());
		trem.draw(screen, trem.getPosL(), trem.getPosC());

		std::cout << screen << std::endl;
	}
	
	return 0;
}
