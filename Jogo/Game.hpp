#ifndef GAME_HPP
#define GAME_HPP

#include "FaseLevel1.hpp"
#include "FaseStart.hpp"
// #include "FaseFinal.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Cores.hpp"

class Game {
public:
	Game() {}
	~Game() {}
	
	static void run() {
		SpriteBuffer screen(165, 41);

	
		FaseStart start("FaseStart", screen);
		FaseLevel1 fase1("Fase1",Sprite("rsc/Fase1.txt",COR::VERMELHA));
		// FaseFinal faseFinal("Fase1",Sprite("rsc/title1Gothic.img"));
		
		start.init();
		start.run(screen);
		
		screen.clear();
		fase1.init();
		int ret1 = fase1.run(screen);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME) {
			screen.clear();
			std::cout << "Fim de jogo..." << std::endl;
			// faseFinal.init();
			// faseFinal.run(screen);
		} else {
			std::cout << "GAME OVER" << std::endl;
		}
		std::cout << "Saindo..." << std::endl;
	}
};

#endif // GAME_HPP
