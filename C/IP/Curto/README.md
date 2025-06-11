# Bot Jogador para Curto (Fodinha)

Este projeto contém uma implementação de jogador automatizado (bot) para o jogo **Curto** (também conhecido como **Fodinha**), compatível com a simulação de jogo [`@marciomoretto/curto`](https://github.com/marciomoretto/curto).

---

## Regras do Jogo

- **Objetivo:**  
  Terminar com a menor penalidade possível, apostando corretamente e jogando cartas estrategicamente.

- **Manilha:**  
  A cada rodada, uma carta é virada para definir a manilha. A manilha é a carta imediatamente superior à carta virada, seguindo a ordem dos valores.

- **Rodadas:**
    - Cada jogador recebe um conjunto de cartas no início da rodada.
    - Os jogadores fazem suas apostas, indicando quantas rodadas acreditam que podem vencer.
    - Os jogadores jogam uma carta por vez, seguindo a ordem da mesa.
    - A carta mais forte, considerando o valor e a manilha, vence a rodada.

- **Pontuação:**
    - Um jogador recebe penalidades se vencer mais ou menos rodadas do que apostou.
    - Se vencer exatamente o número de rodadas apostadas, o jogador não recebe penalidades.

- **Fim do Jogo:**  
  O jogo termina após um número pré-determinado de rodadas. O jogador com a menor penalidade total é declarado vencedor.

Para mais detalhes, consulte a documentação oficial da simulação de jogo [`@marciomoretto/curto`](https://github.com/marciomoretto/curto).

---

## Funções do Arquivo

### Funções Auxiliares

Estas funções dão suporte à lógica principal do bot, realizando operações sobre o estado das cartas e ajudando na decisão das jogadas:

- **`void joga_carta(int idx)`**  
  Marca uma carta como jogada e atualiza o contador de manilhas se necessário.

- **`void atualiza_quantidade_de_manilhas()`**  
  Conta quantas manilhas ainda restam na mão do jogador (desconsiderando as já jogadas).

- **`int manilha_mais_forte_da_mesa(const Carta* mesa, int num_na_mesa)`**  
  Retorna o índice da manilha mais forte já jogada na mesa, ou -1 se não houver manilha.

- **`int nao_manilha_mais_forte_da_mesa(const Carta* mesa, int num_na_mesa)`**  
  Retorna o índice da carta mais forte (que não seja manilha) na mesa, ou -1 se não houver.

- **`int maior_carta_menor_igual_do_que_a_mesa(Carta* mao_jogador, int num_cartas_jogador, const Carta* mesa, int num_na_mesa)`**  
  Retorna o índice da maior carta (não manilha) na mão do jogador que seja menor ou igual à maior carta da mesa.

- **`int maior_carta_sem_ser_manilha(Carta* mao_jogador, int num_cartas_jogador)`**  
  Retorna o índice da maior carta (não manilha) na mão do jogador.

- **`int menor_carta_sem_ser_manilha(Carta* mao_jogador, int num_cartas_jogador)`**  
  Retorna o índice da menor carta (não manilha) na mão do jogador.

---

### Funções Principais do Jogador

Estas funções constituem a interface principal do bot e são chamadas diretamente pela simulação durante o jogo:

- **`const char* nome_jogador_17018992()`**  
  Retorna o nome do jogador/bot.

- **`void iniciar_17018992(int meu_id, int total_jogadores)`**  
  Inicializa variáveis globais e prepara o jogador para o início da partida.

- **`void nova_rodada_17018992(int rodada, Carta carta_virada, int n_cartas, Carta* minha_mao)`**  
  Prepara o estado do jogador para uma nova rodada, atualizando as cartas da mão, a manilha e reseta cartas jogadas.

- **`int apostar_17018992(const int* apostas)`**  
  Decide quantas rodadas o bot pretende ganhar na rodada atual, de acordo com a estratégia abaixo

- **`int jogar_17018992(const Carta* mesa, int num_na_mesa)`**  
  Decide qual carta jogar na rodada, de acordo com a estratégia abaixo.

---

## Estratégia do Bot

A lógica do bot é baseada em aproveitar ao máximo as manilhas, tentando vencer apenas quando tem manilhas e descartando cartas fracas em outras situações:

1. **Aposta:**  
   O bot aposta sempre a quantidade de manilhas que possui na mão, pois são as cartas com maior probabilidade de vitória.

2. **Jogada:**
   - Se houver manilha na mesa:
     - Tenta jogar uma manilha ainda mais forte para tentar vencer.
     - Se não for possível, descarta a maior carta comum.
     - Se só restarem manilhas (todas mais fracas), joga a mais fraca e aceita perder.
   - Se não houver manilha na mesa:
     - Tenta jogar a maior carta (não manilha) que seja menor ou igual à carta mais forte da mesa.
     - Se não for possível, joga a menor manilha que possui.
     - Se não houver manilha, descarta a menor carta comum.
   - Se não houver opção melhor, joga qualquer carta disponível.

---

## Licença

Este projeto é livre para fins acadêmicos e de estudo.  
Consulte a simulação de jogo principal para detalhes de licença e uso.

---
