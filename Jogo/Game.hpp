#ifndef GAME_HPP
#define GAME_HPP

#include "FaseStart.hpp"
#include "FaseLevel1.hpp"
#include "FaseLevel2.hpp"
#include "FaseFinal.hpp"
#include "FaseGameOver.hpp"

#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Cores.hpp"

class Game {
public:
	Game() {}
	~Game() {}
	
	static void run() {

		Sound musica("rsc/Sons/musica_fundo.mp3");
		musica.playloop();

		SpriteBuffer screen(165, 41);
	
		FaseStart start("FaseStart", screen);
		FaseLevel1 fase1("Fase1", screen);
		FaseLevel2 fase2("Fase2", screen);
		FaseFinal faseFinal("FaseFinal", screen);
		FaseGameOver gameOver("FaseFinal", screen);
		
		start.init();
		start.run(screen);

		screen.clear();
		fase1.init();
		int resultado = fase1.run(screen);
		if (resultado == Fase::LEVEL_COMPLETE) {
			screen.clear();
			fase2.init();

			int resultado = fase2.run(screen);
			if (resultado == Fase::LEVEL_COMPLETE) {
				screen.clear();
				faseFinal.init();
				faseFinal.run(screen);
			}
		}
		if (resultado != Fase::LEVEL_COMPLETE) {
			screen.clear();
			gameOver.init();
			gameOver.run(screen);
		}
	}
};

#endif // GAME_HPP
