# 🚦Semáforo com Temporizador Periódico  

Este repositório contém um exemplo de código para a implementação de um **semáforo** utilizando temporizadores periódicos no **Raspberry Pi Pico W**, com simulação no **Wokwi**.  

## 🎯 Objetivo  

- Demonstrar o uso de **temporizadores periódicos (`add_repeating_timer_ms()`)** para controle de LEDs.  
- Simular o funcionamento de um **semáforo** com **3 segundos por estado**.  
- Implementar a **troca automática** entre os LEDs vermelho, amarelo e verde.  
- Exibir mensagens via **porta serial** a cada segundo.  

## 📹 Vídeo do Projeto  

- **[Ver Vídeo](https://drive.google.com/file/d/1fiJgC7fS5otYP2_xGBj1pBMj3zb1TFZK/view?usp=sharing)**

## 🛠️ Tecnologias Utilizadas  

- **Linguagem de Programação**: C.  
- **Placa Microcontroladora**: Raspberry Pi Pico W.  
- **Bibliotecas**:  
  - **Pico SDK** para manipulação de GPIO e temporizadores.  
- **Ferramentas**:  
  - **Wokwi** (Simulação).  
  - **VS Code** (Ambiente de Desenvolvimento).  

## 🗂️ Estrutura do Repositório  

- `timer-rpi-pico.c`: Código-fonte principal contendo a implementação do semáforo.  
- `README.md`: Documentação detalhada do projeto.  
- `diagram.json`: Configuração do circuito para simulação no **Wokwi**.  

## 🚀 Como Funciona  

O sistema **simula um semáforo**, alternando entre **três LEDs** com um intervalo fixo de **3 segundos**:  

1. **LED Vermelho (GP13) acende por 3 segundos** 🚦🔴  
2. **LED Amarelo (GP12) acende por 3 segundos** 🚦🟡  
3. **LED Verde (GP11) acende por 3 segundos** 🚦🟢  
4. **O ciclo se repete continuamente**.  

✅ **O temporizador periódico (`add_repeating_timer_ms()`) controla a alternância de LEDs**.  
✅ **Mensagens são exibidas na porta serial (`printf()`) a cada segundo**.  

## 🔌 Configuração do Hardware  

| Componente  | Pino do Pico W |  
|------------|---------------|  
| LED Verde  | GP11          |  
| LED Amarelo | GP12          |  
| LED Vermelho | GP13          |  


## 💡 Desenvolvido por  

- **Henrique Santos**  
- **[LinkedIn](https://www.linkedin.com/in/dev-henriqueo-santos/)**  
