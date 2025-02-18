#ifndef FROGGER_HPP
#define FROGGER_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Frogger : public ObjetoDeJogo {
public:
	Frogger(const ObjetoDeJogo &obj, int vida = 3) : ObjetoDeJogo{obj}, m_vida{vida} {}
    virtual ~Frogger() {}

	bool vivo() const { return m_vida != 0; }
	int getVida() const { return m_vida; }
	
	void perderVida() { m_vida = ((m_vida - 1 >= 0) ? m_vida - 1 : 0); }

private:
    int m_vida;
};

#endif