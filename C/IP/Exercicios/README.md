# Exercícios de Introdução à Programação em C

Este repositório contém uma coleção de exercícios resolvidos em C, desenvolvidos durante o curso de Introdução à Programação. Cada arquivo corresponde a um problema específico da plataforma HackerRank, organizados em uma ordem lógica de aprendizado, desde conceitos fundamentais até estruturas de dados mais complexas.

## Ordem de Aprendizado e Descrição dos Exercícios

Abaixo, você encontrará uma descrição de cada exercício, seguindo uma trilha de aprendizado recomendada.

### Nível 1: Fundamentos

#### 1. `hello_world.c`
* **Descrição:** Um programa introdutório que imprime "Hello, World!" na tela, seguido por uma linha de texto inserida pelo usuário.
* **Conceitos Utilizados:** Estrutura básica de um programa em C, bibliotecas (`stdio.h`), função `main`, entrada e saída de dados (`printf`, `scanf`).

#### 2. `sum_diff_of_two_numbers.c`
* **Descrição:** Lê dois números inteiros e dois números de ponto flutuante, e então imprime a soma e a diferença de cada par.
* **Conceitos Utilizados:** Declaração de variáveis de diferentes tipos (`int`, `float`), operações aritméticas básicas (+, -), formatação de saída com `printf`.

#### 3. `conditional_statements.c`
* **Descrição:** Utiliza a estrutura `switch-case` para imprimir o nome de um número (de 1 a 9) que o usuário digita. Caso o número seja maior que 9, exibe "Greater than 9".
* **Conceitos Utilizados:** Controle de fluxo, declarações condicionais (`switch-case`).

### Nível 2: Laços e Funções

#### 4. `functions.c`
* **Descrição:** Define e utiliza uma função `max_of_four` que recebe quatro inteiros como parâmetros e retorna o maior entre eles.
* **Conceitos Utilizados:** Declaração, implementação e chamada de funções, passagem de parâmetros, valor de retorno, operador ternário.

#### 5. `for_loop.c`
* **Descrição:** Recebe dois números e itera entre eles. Para números de 1 a 9, imprime o nome por extenso. Para números maiores, identifica se são pares ("even") ou ímpares ("odd").
* **Conceitos Utilizados:** Laços de repetição (`for`), combinação de laços com condicionais (`if-else`, `switch-case`).

#### 6. `sum_of_digits.c`
* **Descrição:** Calcula a soma dos dígitos de um número de cinco dígitos inserido pelo usuário.
* **Conceitos Utilizados:** Laços (`for`), operadores aritméticos (`%` - módulo, `/` - divisão) para manipulação de dígitos.

### Nível 3: Tópicos Avançados

#### 7. `pointers.c`
* **Descrição:** Explora o conceito de ponteiros. A função `update` recebe dois ponteiros para inteiros e modifica os valores originais para conter a soma e a diferença absoluta entre eles.
* **Conceitos Utilizados:** Ponteiros, passagem de parâmetros por referência (endereço), desreferenciação de ponteiros.

#### 8. `student_marks_sum.c`
* **Descrição:** Uma função que recebe um array de notas, o número de estudantes e o gênero ('b' para meninos, 'g' para meninas) e retorna a soma das notas dos estudantes do gênero especificado.
* **Conceitos Utilizados:** Arrays, ponteiros como parâmetros de função, lógica condicional para filtragem de dados.

#### 9. `nth_term.c`
* **Descrição:** Aborda o conceito de recursão. A função `find_nth_term` calcula o n-ésimo termo de uma sequência definida pela soma dos três termos anteriores.
* **Conceitos Utilizados:** Recursão, casos base em funções recursivas.

### Nível 4: Manipulação de Memória e Estruturas de Dados

#### 10. `printing_tokens.c`
* **Descrição:** Recebe uma frase e a divide em "tokens" (palavras), imprimindo cada uma em uma nova linha.
* **Conceitos Utilizados:** Manipulação de strings (`strtok`), alocação dinâmica de memória (`malloc`, `realloc`), ponteiros para `char`.

#### 11. `boxes_tunnels.c`
* **Descrição:** Trabalha com o uso de `structs` para representar caixas com comprimento, largura e altura. Inclui funções para calcular o volume e verificar a altura.
* **Conceitos Utilizados:** Estruturas (`struct`), definição de tipos com `typedef`, funções que operam sobre `structs`.

#### 12. `insert_node_in_position.c`
* **Descrição:** Foca em listas ligadas. A função `insertNodeAtPosition` insere um novo nó com um determinado valor em uma posição específica de uma lista.
* **Conceitos Utilizados:** Estruturas de dados (listas ligadas), alocação dinâmica para nós, manipulação de ponteiros para construir e modificar a lista.
