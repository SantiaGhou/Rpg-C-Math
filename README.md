# Rpg C Math - RPG em C

O **Rpg C ** é um jogo de RPG desenvolvido em C, onde o jogador enfrenta inimigos, gerencia seu personagem e avança na história por meio de batalhas estratégicas.
O Math no nome é em referencia a meu grande amigo matheus que me desafiou a enfrentar desafios e aprender esta linguagem!
## 📌 Recursos

- Sistema de batalha por turnos ⚔️
- Diferentes tipos de inimigos 🏹
- Gerenciamento de atributos do personagem 🧙
- Código modular e expansível 💡

## 🚀 Tecnologias Utilizadas

- **Linguagem C**
- **Bibliotecas padrão do C (stdio.h, stdlib.h, time.h, etc.)**

## 📂 Estrutura do Projeto

```
Rpg-C-Math/
│-- enemy.c       # Lógica dos inimigos
│-- enemy.h       # Definições dos inimigos
│-- game.c        # Controle do jogo
│-- game.h        # Definições gerais do jogo
│-- main.c        # Arquivo principal do jogo
│-- player.c      # Lógica do jogador
│-- player.h      # Definições do jogador
│-- .vscode/      # Configurações do VS Code (opcional)
```

## 🛠️ Como Rodar o Projeto no PC

### 1. Instalar o compilador GCC
Se você ainda não tem o GCC instalado, siga as instruções:
- **Windows:** Instale o [MinGW](https://osdn.net/projects/mingw/) e adicione o caminho `bin` ao PATH.
- **Linux/Mac:** Instale com o seguinte comando:
  ```bash
  sudo apt install gcc  # Debian/Ubuntu
  sudo pacman -S gcc    # Arch Linux
  brew install gcc      # macOS
  ```

### 2. Clonar o repositório

```bash
git clone https://github.com/SantiaGhou/Rpg-C-Math.git
```

### 3. Acessar a pasta do projeto
```bash
cd Rpg-C-Math
```

### 4. Compilar o jogo

```bash
gcc -o rpg main.c game.c player.c enemy.c -lm
```

### 5. Executar o jogo

```bash
./rpg  # Linux/Mac
rpg.exe  # Windows (caso compile com MinGW)
```

## 🎮 Como Jogar

- **Início:** O jogo começa com a criação do personagem.
- **Atributos:** O jogador pode visualizar seus atributos iniciais como força, vida e defesa.
- **Exploração:** O jogo apresenta opções para enfrentar inimigos ou descansar para recuperar vida.
- **Batalha:**
  - O jogador escolhe entre atacar ou defender.
  - O ataque reduz a vida do inimigo com base nos atributos do jogador.
  - A defesa reduz o dano recebido no turno do inimigo.
  - A batalha continua até que o jogador ou o inimigo sejam derrotados.
- **Vitória:** Se vencer a batalha, o jogador pode ganhar pontos de experiência e melhorar seus atributos.
- **Game Over:** Se perder, o jogo se encerra.

## 📜 Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

---

Divirta-se jogando e melhorando suas habilidades! 🎲🔥

