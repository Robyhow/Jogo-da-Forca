# Jogo da Forca em C

Este repositório contém a implementação do clássico jogo da forca em linguagem C.

## Como Jogar

1. Clone este repositório para o seu computador.
2. Compile o programa usando um compilador C, como o GCC: `gcc jogo_da_forca.c -o jogo_da_forca`.
3. Execute o programa: `./jogo_da_forca`.
4. Siga as instruções exibidas no console para tentar adivinhar a palavra secreta.

## Funcionalidades

- O jogo escolhe aleatoriamente uma palavra secreta a partir de um conjunto de palavras predefinidas.
- O jogador tem um número limitado de tentativas para adivinhar a palavra.
- O jogador pode tentar adivinhar uma letra por vez ou tentar adivinhar a palavra completa.
- Após cada tentativa, o jogador é informado sobre quais letras foram usadas e quantas tentativas restam.
- Ao final do jogo, o jogador recebe uma mensagem indicando se ganhou ou perdeu.

## Personalização

Você pode personalizar o jogo adicionando mais palavras ao array `palavras` no código-fonte. Basta editar o arquivo `jogo_da_forca.c` e adicionar suas próprias palavras ao array.

## Contribuições

Contribuições são bem-vindas! Se você tiver alguma ideia de melhoria ou quiser corrigir algum problema, sinta-se à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).
