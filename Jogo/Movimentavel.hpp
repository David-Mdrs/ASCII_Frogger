#ifndef MOVIMENTAVEL_HPP
#define MOVIMENTAVEL_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include <string>

enum Direcao { ESQUERDA, DIREITA };

class Movimentavel : public ObjetoDeJogo {
public:
    Movimentavel(const ObjetoDeJogo &obj, const Direcao direcao, const int velocidade = 2) : ObjetoDeJogo{obj}, m_direcao{direcao} {}
    virtual ~Movimentavel() {}

    Direcao getDirecao() const { return m_direcao; }

    virtual void update() {
        ObjetoDeJogo::update();
        if(getDirecao() == ESQUERDA) {
            this->moveLeft(2);
        } else {
            this->moveRight(2);
        }
    }

private:
    Direcao m_direcao;
};

#endif
