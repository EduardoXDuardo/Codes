# squareRootMethods

Este projeto demonstra e compara diferentes métodos para calcular a raiz quadrada de números em Java, implementando e testando os algoritmos de Newton-Raphson e Busca Binária.

## Motivação

A inspiração para este projeto surgiu durante uma aula de Cálculo, onde foi apresentado o **Teorema do Anulamento**. De forma simplificada, esse teorema afirma que, se uma função contínua assume valores de sinais opostos em dois pontos, então ela obrigatoriamente anula (ou seja, atinge o valor zero) em algum ponto entre eles. Esse conceito é fundamental para métodos numéricos de busca de raízes, como a busca binária.

Sempre tive curiosidade sobre como é implementada a função `sqrt` nas linguagens de programação. Aproveitei o conceito do Teorema do Anulamento para criar minha própria função de raiz quadrada utilizando busca binária (`BinarySearchSqrt`). Em seguida, pesquisei outras abordagens e implementei também o método de (`Newton-Raphson`). Por fim, desenvolvi uma função principal que compara os dois métodos em diversos casos de teste.

## Observação

O projeto foi desenvolvido em **Java** porque é a linguagem que estou estudando por fora e a que acho mais legal de usar, mesmo reconhecendo que talvez não seja a melhor escolha para este tipo de projeto.

## Descrição

O programa executa ambos os métodos para uma lista de valores de teste, apresentando o resultado e o tempo de execução de cada abordagem. O objetivo é ilustrar e comparar a precisão e eficiência dos métodos numéricos para encontrar raízes quadradas sem utilizar `Math.sqrt()`.

## Estrutura do Projeto

```
Java/squareRootMethods/
├── README.md
├── src/
│   ├── Main.java
│   └── math/
│       ├── SquareRoot.java
│       ├── NewtonRaphsonSqrt.java
│       └── BinarySearchSqrt.java
```

- **Main.java:** Classe principal. Executa os testes, compara métodos e exibe resultados.
- **math/SquareRoot.java:** Interface que define o contrato para métodos de cálculo de raiz quadrada.
- **math/NewtonRaphsonSqrt.java:** Implementação usando o método de Newton-Raphson.
- **math/BinarySearchSqrt.java:** Implementação usando busca binária.

## Exemplo de Saída

```
Method     Input      Result          Time (ns)
---------------------------------------------------------------
Newton     0.0001     0.01000000      3500
Binary     0.0001     0.01000000      2100

Newton     0.0100     0.10000000      1800
Binary     0.0100     0.10000000      1300

... (continua para outros valores)
```

## Sobre os Métodos

- **Newton-Raphson:** Algoritmo iterativo eficiente para aproximação de raízes.
- **Busca Binária:** Aproxima a raiz quadrada dividindo intervalos até atingir precisão desejada, fazendo uso do Teorema do Anulamento.

---

> Projeto criado por [EduardoXDuardo](https://github.com/EduardoXDuardo) para fins de estudo e comparação de algoritmos numéricos.