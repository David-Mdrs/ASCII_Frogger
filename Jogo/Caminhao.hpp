#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include "Movimentavel.hpp"

class Caminhao : public Movimentavel {
public:
    Caminhao(const ObjetoDeJogo &obj, const Direcao direcao) : Movimentavel{obj, direcao} {}
    ~Caminhao() {}

    int getVelocidade() const { return m_velocidade; }
    bool getAtivo() const { return m_ativo; }

    void setAtivo(const bool ativo) { m_ativo = ativo; }
    void setVelocidade(const int velocidade) { m_velocidade = velocidade; }

    void movimentar() override {
        if(getDirecao() == ESQUERDA) {
            this->moveLeft(getVelocidade());
        } else {
            this->moveRight(getVelocidade());
        }

        if(getAtivo()) {
            setVelocidade(getVelocidade() + 1);
            if(getVelocidade() == 8) { setAtivo(false); }
        } else {
            setVelocidade(getVelocidade() - 1);
            if(getVelocidade() == 0) { setAtivo(true); }
        }
    }

private:
    bool m_ativo{true};
    int m_velocidade{1};
};

#endif
