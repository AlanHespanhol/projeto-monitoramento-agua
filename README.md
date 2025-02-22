# Matriz de LEDs - Contador com Botões e Joystick Embarcatech

Este projeto implementa um contador exibido em uma **matriz de LEDs**, onde o valor exibido pode ser incrementado ou decrementado utilizando os botões A e B. O número é exibido na matriz de LEDs e, quando o valor for decrementado até o **-1**, todos os LEDs serão apagados. O modo de gravação (bootsel) é ativado ao pressionar o **joystick (GPIO22)**.

## Funcionalidades

- Exibição de um **contador numérico** na matriz de LEDs.
- O **botão A** incrementa o número exibido.
- O **botão B** decrementa o número exibido.
- Quando o número for decrementado até **-1**, todos os LEDs serão apagados.
- **Modo de gravação**: Ao pressionar o **joystick (conectado ao GPIO22)**, o sistema entra no modo de gravação.
  
## Vídeo de apresentação
https://www.youtube.com/watch?v=3v5Q67LJ-lM

## Tecnologias Utilizadas

- **Microcontrolador**: Raspberry Pi Pico 2040.
- **Kit BitDogLab**
- **Linguagem de Programação**: C (usando o **Pico SDK**).
- **Ambiente de Desenvolvimento**: Visual Studio Code (VSCode) com Pico SDK.

## Instalação

### Requisitos

- **Visual Studio Code** (VSCode) instalado.
- **Pico SDK** configurado no seu ambiente de desenvolvimento.
- **CMake** instalado.

### Passos para Configuração

1. **Instale o Visual Studio Code**:
   - Baixe o VSCode em: [https://code.visualstudio.com/](https://code.visualstudio.com/).
   
2. **Instale o Pico SDK**:
   - Siga o guia de instalação do Pico SDK em: [https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf).

3. **Clone o repositório**:
   - Abra o terminal e execute:
     ```bash
     git clone https://github.com/pedropalmarella/MatrizLeds-0a9-IRQ-Embarcatech.git
     ```

4. **Abra o projeto no VSCode**:
   - Abra a pasta do projeto no VSCode.

5. **Configure o ambiente de desenvolvimento**:
   - Instale as dependências e ferramentas recomendadas, como o **CMake**.

6. **Compilando o código**:
   - Abra o terminal integrado do VSCode e execute:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

7. **Carregue o código no Raspberry Pi Pico**:
   - Conecte o Raspberry Pi Pico ao computador.
   - Coloque o Pico no modo de bootloader e copie o arquivo compilado `.uf2` para o dispositivo.

## Como Usar

1. Compile o projeto utilizando o VSCode.
2. Carregue o código no Raspberry Pi Pico ou use o simulador Wokwi para testar.
3. Ao iniciar o sistema, o **número 0** será exibido na matriz de LEDs.
4. O **botão A** incrementa o número exibido na matriz de LEDs.
5. O **botão B** decrementa o número exibido na matriz de LEDs.
6. Quando o número for decrementado até **-1**, **todos os LEDs serão apagados**.
7. **Modo de gravação**: Ao pressionar o **joystick (GPIO22)**, o sistema entra no **modo de gravação**, permitindo a modificação de configurações ou o controle adicional do sistema.
