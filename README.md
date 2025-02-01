# 🚦 Atividade 1: Semáforo com Temporizador Periódico  

Este repositório contém um exemplo de código para a implementação de um **semáforo** utilizando temporizadores periódicos no **Raspberry Pi Pico W**, com simulação no **Wokwi**.  

## 🎯 Objetivo  

- Demonstrar o uso de **temporizadores periódicos (`add_repeating_timer_ms()`)** para controle de LEDs.  
- Simular o funcionamento de um **semáforo** com **3 segundos por estado**.  
- Implementar a **troca automática** entre os LEDs vermelho, amarelo e verde.  
- Exibir mensagens via **porta serial** a cada segundo.  

## 📹 Vídeo do Projeto  

- **[Ver Vídeo](#)**

## 🛠️ Tecnologias Utilizadas  

- **Linguagem de Programação**: C.  
- **Placa Microcontroladora**: Raspberry Pi Pico W.  
- **Bibliotecas**:  
  - **Pico SDK** para manipulação de GPIO e temporizadores.  
- **Ferramentas**:  
  - **Wokwi** (Simulação).  
  - **VS Code** (Ambiente de Desenvolvimento).  

## 🗂️ Estrutura do Repositório  

- `main.c`: Código-fonte principal contendo a implementação do semáforo.  
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

## 📜 Código Simplificado  

```c
bool repeating_timer_callback(struct repeating_timer *t) {
    if (counter == 1) setLEDs(0, 0, 1);  // Vermelho  
    else if (counter == 2) setLEDs(0, 1, 0);  // Amarelo  
    else setLEDs(1, 0, 0);  // Verde  

    counter = (counter % 3) + 1; // Alterna os estados  
    return true;
}

int main() {
    initLEDs();
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Ola, Embarcatech!\n");
        sleep_ms(1000);
    }
}
