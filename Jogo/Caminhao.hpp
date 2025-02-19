#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include "Movimentavel.hpp"

class Caminhao : public Movimentavel {
public:
    Caminhao(const ObjetoDeJogo &obj, const Direcao direcao, const int velocidade = 2) : Movimentavel{obj, direcao, velocidade} {}
    ~Caminhao() {}

    bool getAtivo() const { return m_ativo; }
    void setAtivo(const bool ativo) { m_ativo = ativo; }

    void update() override {
        ObjetoDeJogo::update();
        if(getDirecao() == ESQUERDA) {
            this->moveLeft(getVelocidade());
        } else {
            this->moveRight(getVelocidade());
        }

        if(getAtivo()) {
            setVelocidade(getVelocidade() + 6);
            if(getVelocidade() >= 16) { setAtivo(false); }
        } else {
            setVelocidade(getVelocidade() - 4);
            if(getVelocidade() <= 2) { setAtivo(true); }
        }
    }

private:
    bool m_ativo{true};
};

#endif
