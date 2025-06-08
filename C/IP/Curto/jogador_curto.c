#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador_17018992.h"

// Variáveis globais para armazenar o estado do jogador
static int id_jogador_global;
static int num_jogadores_global;
static Carta mao_global[6];
static int num_cartas_global;
static Valor manilha_atual_global;
static int quantidade_de_manilhas_minha_global;
static int cartas_jogadas[6] = {0}; // Controle de cartas jogadas

void atualiza_quantidade_de_manilhas() {
    quantidade_de_manilhas_minha_global = 0;
    for (int i = 0; i < num_cartas_global; i++) {
        // Só conta manilhas que não foram jogadas
        if (mao_global[i].valor == manilha_atual_global && cartas_jogadas[i] == 0)
            quantidade_de_manilhas_minha_global++;
    }
}

// Marca carta como usada
void joga_carta(int idx) {
    if (idx >= 0 && idx < num_cartas_global) {
        // Se for manilha atualiza o contador
        if (mao_global[idx].valor == manilha_atual_global && cartas_jogadas[idx] == 0) {
            if(quantidade_de_manilhas_minha_global > 0)
                quantidade_de_manilhas_minha_global--;
        }
        // Marca a carta como jogada
        cartas_jogadas[idx] = 1;
    }
}

const char* nome_jogador_17018992() {
    return "Luiz Eduardo";
}

void iniciar_17018992(int meu_id, int total_jogadores) {
    id_jogador_global = meu_id;
    num_jogadores_global = total_jogadores;
    // Reinicia o contador de cartas usadas
    for (int i = 0; i < 6; i++) {
        cartas_jogadas[i] = 0;
    }
}

void nova_rodada_17018992(int rodada, Carta carta_virada, int n_cartas, Carta* minha_mao) {
    num_cartas_global = n_cartas;

    // Seta a manilha atual
    manilha_atual_global = (carta_virada.valor == TRES) ? QUATRO : (Valor)(carta_virada.valor + 1);

    // Reinicia o contador de cartas usadas
    for (int i = 0; i < 6; i++) {
        cartas_jogadas[i] = 0;
    }

   // Seta a minha mao atual
    for (int i = 0; i < num_cartas_global; i++) {
        mao_global[i] = minha_mao[i];
    }

    atualiza_quantidade_de_manilhas();
}

// Aposta sempre a quantidade de manilha que tenho na rodada
int apostar_17018992(const int* apostas) {
    atualiza_quantidade_de_manilhas();
    return quantidade_de_manilhas_minha_global;
}

int manilha_mais_forte_da_mesa(const Carta* mesa, int num_na_mesa) {
    int idx = -1;
    for (int i = 0; i < num_na_mesa; i++) {
        if (mesa[i].valor == manilha_atual_global) {
            if (idx == -1 || mesa[i].naipe > mesa[idx].naipe) {
                idx = i;
            }
        }
    }
    return idx;
}

int nao_manilha_mais_forte_da_mesa(const Carta* mesa, int num_na_mesa) {
    int idx = -1;
    for (int i = 0; i < num_na_mesa; i++) {
        if (mesa[i].valor == manilha_atual_global) continue;
        if (idx == -1 || mesa[i].valor > mesa[idx].valor) {
            idx = i;
        }
    }
    return idx;
}

int maior_carta_sem_ser_manilha(Carta* mao_jogador, int num_cartas_jogador) {
    int idx = -1;
    for (int i = 0; i < num_cartas_jogador; i++) {
        if (cartas_jogadas[i]) continue;
        if (mao_jogador[i].valor == manilha_atual_global) continue;
        if (idx == -1 || mao_jogador[i].valor > mao_jogador[idx].valor) {
            idx = i;
        }
    }
    return idx;
}

int maior_carta_menor_igual_do_que_a_mesa(Carta* mao_jogador, int num_cartas_jogador, const Carta* mesa, int num_na_mesa) {
    int idx = -1;
    int mais_forte_na_mesa_idx = nao_manilha_mais_forte_da_mesa(mesa, num_na_mesa);
    if (mais_forte_na_mesa_idx == -1) {
        return -1;
    }
    Valor valor_limite = mesa[mais_forte_na_mesa_idx].valor;
    for (int i = 0; i < num_cartas_jogador; i++) {
        if (cartas_jogadas[i]) continue;
        if (mao_jogador[i].valor == manilha_atual_global) continue;
        if (mao_jogador[i].valor <= valor_limite) {
            if (idx == -1 || mao_jogador[i].valor > mao_jogador[idx].valor) {
                idx = i;
            }
        }
    }
    return idx;
}

int menor_carta_sem_ser_manilha(Carta* mao_jogador, int num_cartas_jogador) {
    int idx = -1;
    for (int i = 0; i < num_cartas_jogador; i++) {
        if (cartas_jogadas[i]) continue;
        if (mao_jogador[i].valor == manilha_atual_global) continue;

        if (idx == -1 || mao_jogador[i].valor < mao_jogador[idx].valor) {
            idx = i;
        }
    }
    return idx;
}

int jogar_17018992(const Carta* mesa, int num_na_mesa) {
    atualiza_quantidade_de_manilhas();

    int manilha_na_mesa_idx = manilha_mais_forte_da_mesa(mesa, num_na_mesa);
    int carta_a_jogar_idx = -1;

    // Se tem manilha na mesa
    if (manilha_na_mesa_idx >= 0) {

        // Tenta jogar uma manilha melhor que a da mesa
        int melhor_manilha_na_mao_idx = -1;
        for (int i = 0; i < num_cartas_global; i++) {
            if (mao_global[i].valor == manilha_atual_global && cartas_jogadas[i] == 0) {
                 if (mao_global[i].naipe > mesa[manilha_na_mesa_idx].naipe) {
                    if (melhor_manilha_na_mao_idx == -1 || mao_global[i].naipe > mao_global[melhor_manilha_na_mao_idx].naipe) {
                        melhor_manilha_na_mao_idx = i;
                    }
                }
            }
        }
        if (melhor_manilha_na_mao_idx != -1) {
            joga_carta(melhor_manilha_na_mao_idx);
            return melhor_manilha_na_mao_idx;
        }

        // Descarta a maior carta (sem ser manilha)
        carta_a_jogar_idx = maior_carta_sem_ser_manilha(mao_global, num_cartas_global);
        if (carta_a_jogar_idx != -1) {
            joga_carta(carta_a_jogar_idx);
            return carta_a_jogar_idx;
        }

        // Se só tenho manilhas na mao, e todas sao menores que a da mesa
        // Azar, aceita a derrota e joga a menor manilha
        int menor_manilha_na_mao_idx = -1;
        for (int i = 0; i < num_cartas_global; i++) {
            if (mao_global[i].valor == manilha_atual_global && cartas_jogadas[i] == 0) {
                if (menor_manilha_na_mao_idx == -1 || mao_global[i].naipe < mao_global[menor_manilha_na_mao_idx].naipe) {
                    menor_manilha_na_mao_idx = i;
                }
            }
        }
        if (menor_manilha_na_mao_idx != -1) {
            joga_carta(menor_manilha_na_mao_idx);
            return menor_manilha_na_mao_idx;
        }

    }

    // Não tem manilha na mesa

    // Tenta jogar a maior carta menor ou igual a maior da mesa
    carta_a_jogar_idx = maior_carta_menor_igual_do_que_a_mesa(mao_global, num_cartas_global, mesa, num_na_mesa);
    if (carta_a_jogar_idx != -1) {joga_carta(carta_a_jogar_idx);
        return carta_a_jogar_idx;
    }

    // Joga a menor manilha na mão, se tiver
    int menor_manilha_na_mao_idx = -1;
    for (int i = 0; i < num_cartas_global; i++) {
        if (mao_global[i].valor == manilha_atual_global && cartas_jogadas[i] == 0) {
            if (menor_manilha_na_mao_idx == -1 || mao_global[i].naipe < mao_global[menor_manilha_na_mao_idx].naipe) {
                menor_manilha_na_mao_idx = i;
            }
        }
    }
    if (menor_manilha_na_mao_idx != -1) {
        joga_carta(menor_manilha_na_mao_idx);
        return menor_manilha_na_mao_idx;
    }

    // Joga a menor carta
    carta_a_jogar_idx = menor_carta_sem_ser_manilha(mao_global, num_cartas_global);
    if (carta_a_jogar_idx != -1) {
        joga_carta(carta_a_jogar_idx);
        return carta_a_jogar_idx;
    }


    // Se der merda, joga qualquer carta possivel
    for (int i = 0; i < num_cartas_global; i++) {
        if (cartas_jogadas[i] == 0) {
            joga_carta(i);
            return i;
        }
    }

    // Erro
    return -1;
}