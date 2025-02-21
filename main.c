// this is the entry point of the program it contains the story line

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void intro() {
    printf("\n=========================================\n");
    printf("BEM-VINDO AO REALMOS DE THARN\n");
    printf("=========================================\n");
    printf("\n");
    printf("Em tempos antigos, Tharn era um reino pacífico e prospero,\n");
    printf("guiado por um rei justo e sábio. No entanto, o equilíbrio foi\n");
    printf("quebrado quando as sombras do Velho Senhor retornaram.\n");
    printf("\n");
    printf("Monstros terríveis emergiram das profundezas, devastando cidades\n");
    printf("e vilarejos. O rei, desesperado, chamou os bravos heróis de todo o\n");
    printf("reino para enfrentar essa ameaça.\n");
    printf("\n");
    printf("Você é um destes heróis, escolhido para restaurar a paz a Tharn.\n");
    printf("Sua jornada começa agora...\n");
    printf("\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar(); // Para capturar a tecla Enter
    printf("\n");
}

void chapter_one(Player *player) {
    printf("\n=========================================\n");
    printf("CAPÍTULO 1: O INÍCIO DA VIAGEM\n");
    printf("=========================================\n");
    printf("\n");
    printf("Você acorda em uma caverna sombria, lembrando vagamente de uma\n");
    printf("missão para recuperar um artefato mágico que poderia derrotar o\n");
    printf("Velho Senhor.\n");
    printf("\n");
    printf("A caverna é úmida e fria, com paredes rochosas e um rio subterrâneo\n");
    printf("correndo ao fundo. Você percebe que está sozinho e precisa encontrar\n");
    printf("uma saída.\n");
    printf("\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar(); // Para capturar a tecla Enter
    printf("\n");

    printf("Você ouve um barulho distante. Parece alguém ou algo se movendo.\n");
    printf("Você se aproxima cautelosamente e vê uma figura humana encapuzada.\n");
    printf("A figura parece ferida e desacordada.\n");
    printf("\n");
    printf("O que você deseja fazer?\n");
    printf("1. Tentar acordar a figura\n");
    printf("2. Ignorar a figura e procurar uma saída\n");
    printf("Escolha uma ação (1/2): ");

    int choice;
    char pick_up;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê tenta acordar a figura. Depois de alguns minutos, ela abre os olhos.\n");
        printf("É uma jovem elfa ferida, chamada Elara.\n");
        printf("\n");
        printf("Elara: 'Ah... Obrigada por me acordar. Meu nome é Elara. Estava procurando\n");
        printf("o artefato mágico quando fui capturada por um grupo de orcs.\n");
        printf("Eles me trancaram nesta caverna, mas agora posso ajudar você.'\n");
        printf("\n");
        printf("O que você deseja fazer?\n");
        printf("1. Aceitar a ajuda de Elara\n");
        printf("2. Recusar a ajuda de Elara\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide aceitar a ajuda de Elara.\n");
            printf("Elara: 'Ótimo! Juntos podemos encontrar a saída e derrotar os orcs.\n");
            printf("Vamos explorar esta caverna e encontrar uma forma de escapar.'\n");
            printf("\n");
        } else {
            printf("\nVocê decide recusar a ajuda de Elara.\n");
            printf("Elara: 'Tudo bem, mas você precisará encontrar a saída sozinho.\n");
            printf("Boa sorte...' Elara se levanta e parte em direção a um túnel escuro.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar a figura e procurar uma saída.\n");
        printf("Você começa a explorar a caverna, procurando por qualquer abertura.\n");
        printf("\n");
    }

    printf("Enquanto explora a caverna, você encontra um goblin selvagem!\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy enemy;
    init_enemy(&enemy, "Goblin", 50, 6, 3, 4, 2);

    display_enemy_status(&enemy);
    game_loop(player, &enemy);

    printf("\nVocê derrotou o Goblin!\n");
    collect_item(player);
    gain_experience(player, 50);

    if (choice == 1) {
        printf("\nElara: 'Excelente trabalho! Agora, vamos explorar mais esta caverna\n");
        printf("e encontrar uma saída. Talvez haja outros itens úteis aqui.'\n");
    } else {
        printf("\nVocê continua explorando a caverna sozinho.\n");
        printf("Talvez haja outros itens úteis aqui.\n");
    }

    printf("\nEnquanto caminha, você encontra uma poção de cura no chão!\n");
    printf("Deseja pegar a poção de cura? (s/n): ");
    char pick_up;
    scanf(" %c", &pick_up);


    if (pick_up == 's' || pick_up == 'S') {
        Item item;
        strcpy(item.name, "Poção de Cura");
        item.type = 3; // Cura
        item.value = 20;
        player->health += item.value;
        printf("Você pegou a Poção de Cura! Saúde aumentada em %d. Nova Saúde: %d\n", item.value, player->health);
    } else {
        printf("Você não pegou a poção de cura.\n");
    }

    printf("\nContinuando sua exploração, você encontra um túnel escuro e um corredor iluminado.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Entrar no túnel escuro\n");
    printf("2. Seguir pelo corredor iluminado\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide entrar no túnel escuro.\n");
        printf("O túnel é estreito e úmido. Você ouve sons estranhos vindo do fundo.\n");
        printf("Você se move cautelosamente...\n");
        printf("\n");
        printf("De repente, um grupo de orcs aparece!\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando um inimigo
        Enemy orcs[3];
        init_enemy(&orcs[0], "Orc", 60, 7, 2, 5, 3);
        init_enemy(&orcs[1], "Orc", 60, 7, 2, 5, 3);
        init_enemy(&orcs[2], "Orc", 60, 7, 2, 5, 3);

        for (int i = 0; i < 3; i++) {
            printf("\nOrc %d:\n", i + 1);
            display_enemy_status(&orcs[i]);
            game_loop(player, &orcs[i]);
            printf("\nVocê derrotou o Orc %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 60);
        }
    } else {
        printf("\nVocê decide seguir pelo corredor iluminado.\n");
        printf("O corredor é largo e bem iluminado, mas há sinais de recentes conflitos.\n");
        printf("Você vê marcas de lutas e objetos quebrados ao longo do caminho.\n");
        printf("\n");
        printf("Enquanto caminha, você encontra um livro mágico no chão!\n");
        printf("Deseja pegar o livro mágico? (s/n): ");
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Livro Mágico");
            item.type = 1; // Dano
            item.value = 15;
            add_item(player, item);
            printf("Você pegou o Livro Mágico! Dano aumentado em %d.\n", item.value);
        } else {
            printf("Você não pegou o livro mágico.\n");
        }

        printf("\nContinuando pelo corredor, você encontra um guarda caído!\n");
        printf("Ele está inconsciente, mas ainda vive.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Tentar acordar o guarda\n");
        printf("2. Ignorar o guarda e continuar\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê tenta acordar o guarda. Depois de alguns minutos, ele abre os olhos.\n");
            printf("Guarda: 'Ah... Obrigado por me acordar. Meu nome é Thorne. Estava patrulhando\n");
            printf("este corredor quando fui atacado por um grupo de orcs.\n");
            printf("Eles me deixaram aqui, mas agora posso ajudar você.'\n");
            printf("\n");
            printf("O que você deseja fazer?\n");
            printf("1. Aceitar a ajuda de Thorne\n");
            printf("2. Recusar a ajuda de Thorne\n");
            printf("Escolha uma ação (1/2): ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\nVocê decide aceitar a ajuda de Thorne.\n");
                printf("Thorne: 'Ótimo! Juntos podemos encontrar a saída e derrotar os orcs.\n");
                printf("Vamos explorar este corredor e encontrar uma forma de escapar.'\n");
                printf("\n");
            } else {
                printf("\nVocê decide recusar a ajuda de Thorne.\n");
                printf("Thorne: 'Tudo bem, mas você precisará encontrar a saída sozinho.\n");
                printf("Boa sorte...' Thorne se levanta e parte em direção a um túnel escuro.\n");
                printf("\n");
            }
        } else {
            printf("\nVocê decide ignorar o guarda e continuar.\n");
            printf("Você continua explorando o corredor sozinho.\n");
            printf("\n");
        }

        printf("Continuando seu caminho, você encontra um tesouro escondido!\n");
        printf("Deseja abrir o baú? (s/n): ");
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Escudo Mágico");
            item.type = 2; // Defesa
            item.value = 15;
            add_item(player, item);
            printf("Você pegou o Escudo Mágico! Defesa aumentada em %d.\n", item.value);
        } else {
            printf("Você não pegou o tesouro.\n");
        }
    }

    printf("\nFinalmente, você encontra uma saída da caverna!\n");
    printf("Você está fora da caverna e vê dois caminhos:\n");
    printf("1. Caminho da Montanha\n");
    printf("2. Caminho do Bosque Encantado\n");
    printf("Qual caminho você deseja seguir? (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê escolheu o Caminho da Montanha.\n");
        printf("O caminho é longo e cheio de perigos, mas promete levar você\n");
        printf("mais diretamente ao coração do reino.\n");
    } else if (choice == 2) {
        printf("\nVocê escolheu o Caminho do Bosque Encantado.\n");
        printf("O bosque é misterioso e cheio de criaturas mágicas, mas pode\n");
        printf("oferecer caminhos alternativos e tesouros ocultos.\n");
    } else {
        printf("Opção inválida. Você segue o Caminho da Montanha por padrão.\n");
        choice = 1;
    }

    printf("\nVocê continua sua jornada...\n");
}

void chapter_two(Player *player) {
    printf("\n=========================================\n");
    printf("CAPÍTULO 2: O CAMINHO DA MONTANHA\n");
    printf("=========================================\n");
    printf("\n");
    printf("Você segue pelo Caminho da Montanha. O caminho é longo e cheio de perigos,\n");
    printf("mas promete levar você mais diretamente ao coração do reino.\n");
    printf("\n");
    printf("A montanha é alta e coberta de neve, com rochas escorregadias e ventos fortes.\n");
    printf("Você sente que está cada vez mais próximo do seu objetivo, mas os perigos\n");
    printf("também aumentam.\n");
    printf("\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar(); // Para capturar a tecla Enter
    printf("\n");

    printf("Enquanto caminha, você encontra um acampamento abandonado de viajantes.\n");
    printf("Há sinais de uma batalha recente e alguns itens espalhados pelo chão.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Explorar o acampamento\n");
    printf("2. Ignorar o acampamento e continuar\n");
    printf("Escolha uma ação (1/2): ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide explorar o acampamento.\n");
        printf("Você encontra um mapa antigo e algumas ferramentas úteis.\n");
        printf("O mapa parece mostrar o caminho para o Castelo Condenado.\n");
        printf("\n");
        printf("Deseja pegar o mapa? (s/n): ");
        char pick_up;
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Mapa Antigo");
            item.type = 0; // Outro tipo de item
            item.value = 0;
            add_item(player, item);
            printf("Você pegou o Mapa Antigo!\n");
        } else {
            printf("Você não pegou o mapa.\n");
        }
        printf("Deseja pegar as ferramentas? (s/n): ");
        scanf(" %c", &pick_up);
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Ferramentas");
            item.type = 0; // Outro tipo de item
            item.value = 0;
            add_item(player, item);
            printf("Você pegou as Ferramentas!\n");
        } else {
            printf("Você não pegou as ferramentas.\n");
        }
    } else {
        printf("\nVocê decide ignorar o acampamento e continuar.\n");
        printf("Você continua seguindo pelo caminho da montanha.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um goblin líder.\n");
    printf("Este goblin parece mais forte e experiente que os outros.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy goblin_lider;
    init_enemy(&goblin_lider, "Goblin Líder", 80, 8, 4, 6, 4);

    display_enemy_status(&goblin_lider);
    game_loop(player, &goblin_lider);

    printf("\nVocê derrotou o Goblin Líder!\n");
    collect_item(player);
    gain_experience(player, 100);

    printf("\nContinuando seu caminho, você encontra um urso gigante bloqueando o caminho!\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy urso_gigante;
    init_enemy(&urso_gigante, "Urso Gigante", 120, 12, 2, 8, 5);

    display_enemy_status(&urso_gigante);
    game_loop(player, &urso_gigante);

    printf("\nVocê derrotou o Urso Gigante!\n");
    collect_item(player);
    gain_experience(player, 150);

    printf("\nEnquanto caminha, você encontra um clérigo velho.\n");
    printf("Ele parece estar procurando algo importante.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Conversar com o clérigo\n");
    printf("2. Ignorar o clérigo e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide conversar com o clérigo.\n");
        printf("Clérigo: 'Ah, herói! Estou procurando o artefato mágico que pode derrotar o Velho Senhor.\n");
        printf("Se você encontrar, por favor, me avise. Estou aqui para ajudar.'\n");
        printf("\n");
        printf("O clérigo oferece uma poção de cura para você.\n");
        printf("Deseja pegar a poção de cura? (s/n): ");
        char pick_up;
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Poção de Cura");
            item.type = 3; // Cura
            item.value = 20;
            player->health += item.value;
            printf("Você pegou a Poção de Cura! Saúde aumentada em %d. Nova Saúde: %d\n", item.value, player->health);
        } else {
            printf("Você não pegou a poção de cura.\n");
        }
    } else {
        printf("\nVocê decide ignorar o clérigo e continuar.\n");
        printf("Você continua seguindo pelo caminho da montanha.\n");
        printf("\n");
    }

    printf("\nContinuando sua jornada, você encontra um acampamento de orcs.\n");
    printf("Os orcs parecem estar planejando algo.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Atacar os orcs\n");
    printf("2. Observar silenciosamente\n");
    printf("3. Ignorar e continuar\n");
    printf("Escolha uma ação (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide atacar os orcs.\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando inimigos
        Enemy orcs[5];
        init_enemy(&orcs[0], "Orc", 70, 9, 3, 6, 4);
        init_enemy(&orcs[1], "Orc", 70, 9, 3, 6, 4);
        init_enemy(&orcs[2], "Orc", 70, 9, 3, 6, 4);
        init_enemy(&orcs[3], "Orc", 70, 9, 3, 6, 4);
        init_enemy(&orcs[4], "Orc", 70, 9, 3, 6, 4);

        for (int i = 0; i < 5; i++) {
            printf("\nOrc %d:\n", i + 1);
            display_enemy_status(&orcs[i]);
            game_loop(player, &orcs[i]);
            printf("\nVocê derrotou o Orc %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 80);
        }
    } else if (choice == 2) {
        printf("\nVocê decide observar silenciosamente.\n");
        printf("Você vê que os orcs estão planejando um ataque em uma cidade próxima.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Alertar a cidade\n");
        printf("2. Ignorar e continuar\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide alertar a cidade.\n");
            printf("Você corre para a cidade e avisa os habitantes sobre o ataque.\n");
            printf("Os habitantes ficam gratos e oferecem uma poção de cura para você.\n");
            printf("Deseja pegar a poção de cura? (s/n): ");
            char pick_up;
            scanf(" %c", &pick_up);

            if (pick_up == 's' || pick_up == 'S') {
                Item item;
                strcpy(item.name, "Poção de Cura");
                item.type = 3; // Cura
                item.value = 20;
                player->health += item.value;
                printf("Você pegou a Poção de Cura! Saúde aumentada em %d. Nova Saúde: %d\n", item.value, player->health);
            } else {
                printf("Você não pegou a poção de cura.\n");
            }
        } else {
            printf("\nVocê decide ignorar e continuar.\n");
            printf("Você continua seguindo pelo caminho da montanha.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar e continuar.\n");
        printf("Você continua seguindo pelo caminho da montanha.\n");
        printf("\n");
    }

    printf("\nFinalmente, você chega ao topo da montanha e vê o Castelo Condenado diante de si.\n");
    printf("O castelo está cercado por fortes muralhas e guardas vigilantes.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Atacar diretamente o castelo\n");
    printf("2. Procurar uma entrada secreta\n");
    printf("3. Esperar por uma oportunidade\n");
    printf("Escolha uma ação (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide atacar diretamente o castelo.\n");
        printf("Você enfrenta os guardas e começa a batalha!\n");

        // Inicializando inimigos
        Enemy guardas[3];
        init_enemy(&guardas[0], "Guarda", 100, 10, 5, 7, 6);
        init_enemy(&guardas[1], "Guarda", 100, 10, 5, 7, 6);
        init_enemy(&guardas[2], "Guarda", 100, 10, 5, 7, 6);

        for (int i = 0; i < 3; i++) {
            printf("\nGuarda %d:\n", i + 1);
            display_enemy_status(&guardas[i]);
            game_loop(player, &guardas[i]);
            printf("\nVocê derrotou o Guarda %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 120);
        }
    } else if (choice == 2) {
        printf("\nVocê decide procurar uma entrada secreta.\n");
        printf("Você explora as redondezas do castelo e encontra uma escada secreta.\n");
        printf("Você sobe pela escada e entra no castelo.\n");
    } else {
        printf("\nVocê decide esperar por uma oportunidade.\n");
        printf("Você espera até que os guardas estejam distraídos e então entra no castelo.\n");
    }

    printf("\nVocê está dentro do castelo e vê um corredor que leva ao coração do castelo.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Seguir pelo corredor\n");
    printf("2. Explorar outros caminhos\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide seguir pelo corredor.\n");
        printf("Você continua seguindo pelo corredor até chegar a uma sala com um grande portão.\n");
    } else {
        printf("\nVocê decide explorar outros caminhos.\n");
        printf("Você explora outros caminhos do castelo, mas não encontra nada de útil.\n");
        printf("Você volta ao corredor principal e continua.\n");
    }

    printf("\nVocê chega ao portão e vê o Grande Salão do Castelo.\n");
    printf("O Grande Salão está cheio de inimigos e um grande boss aguarda.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Atacar os inimigos\n");
    printf("2. Esperar por uma oportunidade\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide atacar os inimigos.\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando inimigos
        Enemy inimigos[4];
        init_enemy(&inimigos[0], "Inimigo", 90, 11, 6, 8, 5);
        init_enemy(&inimigos[1], "Inimigo", 90, 11, 6, 8, 5);
        init_enemy(&inimigos[2], "Inimigo", 90, 11, 6, 8, 5);
        init_enemy(&inimigos[3], "Inimigo", 90, 11, 6, 8, 5);

        for (int i = 0; i < 4; i++) {
            printf("\nInimigo %d:\n", i + 1);
            display_enemy_status(&inimigos[i]);
            game_loop(player, &inimigos[i]);
            printf("\nVocê derrotou o Inimigo %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 150);
        }
    } else {
        printf("\nVocê decide esperar por uma oportunidade.\n");
        printf("Você espera até que os inimigos estejam distraídos e então ataca.\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando inimigos
        Enemy inimigos[4];
        init_enemy(&inimigos[0], "Inimigo", 90, 11, 6, 8, 5);
        init_enemy(&inimigos[1], "Inimigo", 90, 11, 6, 8, 5);
        init_enemy(&inimigos[2], "Inimigo", 90, 11, 6, 8, 5);
        init_enemy(&inimigos[3], "Inimigo", 90, 11, 6, 8, 5);

        for (int i = 0; i < 4; i++) {
            printf("\nInimigo %d:\n", i + 1);
            display_enemy_status(&inimigos[i]);
            game_loop(player, &inimigos[i]);
            printf("\nVocê derrotou o Inimigo %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 150);
        }
    }

    printf("\nFinalmente, você chega ao Grande Boss do castelo!\n");
    printf("O Grande Boss é um dragão lendário chamado Drakon.\n");
    printf("Prepare-se para a batalha final!\n");

    // Inicializando o boss
    Enemy drakon;
    init_enemy(&drakon, "Drakon", 250, 20, 15, 10, 10);

    display_enemy_status(&drakon);
    game_loop(player, &drakon);

    printf("\nVocê derrotou Drakon!\n");
    printf("O caminho para o Velho Senhor está livre.\n");
    printf("Você continua sua jornada...\n");
}

void chapter_three(Player *player) {
    printf("\n=========================================\n");
    printf("CAPÍTULO 3: O BOSQUE ENCANTADO\n");
    printf("=========================================\n");
    printf("\n");
    printf("Você segue pelo Caminho do Bosque Encantado. O bosque é misterioso e cheio\n");
    printf("de criaturas mágicas. Você sente uma energia mística no ar e percebe que\n");
    printf("cada passo pode levar a novos desafios e descobertas.\n");
    printf("\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar(); // Para capturar a tecla Enter
    printf("\n");

    printf("Enquanto caminha, você encontra um portal brilhante no meio de um claro.\n");
    printf("O portal emite uma luz azul intensa e você sente uma energia mística.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Entrar no portal\n");
    printf("2. Ignorar o portal e continuar\n");
    printf("Escolha uma ação (1/2): ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide entrar no portal.\n");
        printf("Você sente uma energia mística envolvendo você enquanto atravessa o portal.\n");
        printf("Quando você emerge do outro lado, você está em um novo local.\n");
        printf("Você está em um vale mágico repleto de flores coloridas e árvores altas.\n");
        printf("No centro do vale, há um lago cristalino com um reflexo místico.\n");
        printf("\n");
        printf("Deseja beber da água do lago? (s/n): ");
        char pick_up;
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            printf("Você bebe da água do lago e sente uma energia mística fluindo por todo o seu corpo.\n");
            printf("Seus atributos aumentam significativamente!\n");
            player->strength += 5;
            player->magic += 5;
            player->stamina += 5;
            player->persuasion += 5;
            player->stealth += 5;
            printf("Nova Força: %d\n", player->strength);
            printf("Nova Magia: %d\n", player->magic);
            printf("Nova Stamina: %d\n", player->stamina);
            printf("Nova Persuasão: %d\n", player->persuasion);
            printf("Novo Stealth: %d\n", player->stealth);
        } else {
            printf("Você não bebe da água do lago e continua seu caminho.\n");
        }
    } else {
        printf("\nVocê decide ignorar o portal e continuar.\n");
        printf("Você continua seguindo pelo caminho do bosque.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um elfo antigo meditando sob uma árvore gigante.\n");
    printf("O elfo parece estar protegendo algo importante.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Conversar com o elfo\n");
    printf("2. Ignorar o elfo e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide conversar com o elfo.\n");
        printf("Elfo: 'Ah, herói! Eu sou Eldrin, um elfo sábio que protege este bosque há séculos.\n");
        printf("Estou guardando um artefato mágico que pode ser crucial para sua jornada.\n");
        printf("Se você prometer me ajudar em troca, eu lhe concederei o artefato.'\n");
        printf("\n");
        printf("O que você deseja fazer?\n");
        printf("1. Prometer ajudar Eldrin\n");
        printf("2. Recusar a ajuda de Eldrin\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide prometer ajudar Eldrin.\n");
            printf("Eldrin: 'Ótimo! Aqui está o artefato mágico que você precisa.'\n");
            printf("Eldrin entrega um anel mágico para você.\n");

            Item item;
            strcpy(item.name, "Anel Mágico");
            item.type = 1; // Dano
            item.value = 20;
            add_item(player, item);
            printf("Você pegou o Anel Mágico! Dano aumentado em %d.\n", item.value);
        } else {
            printf("\nVocê decide recusar a ajuda de Eldrin.\n");
            printf("Eldrin: 'Tudo bem, mas você precisará encontrar o artefato sozinho.\n");
            printf("Boa sorte...' Eldrin volta a meditar.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o elfo e continuar.\n");
        printf("Você continua seguindo pelo caminho do bosque.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um esqueleto guardião protegendo um tesouro.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy esqueleto_guardiao;
    init_enemy(&esqueleto_guardiao, "Esqueleto Guardião", 150, 10, 8, 6, 5);

    display_enemy_status(&esqueleto_guardiao);
    game_loop(player, &esqueleto_guardiao);

    printf("\nVocê derrotou o Esqueleto Guardião!\n");
    collect_item(player);
    gain_experience(player, 150);

    printf("\nEnquanto caminha, você encontra um elfo selvagem hostil.\n");
    printf("O elfo selvagem parece estar defendendo seu território.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy elfo_selvagem;
    init_enemy(&elfo_selvagem, "Elfo Selvagem", 120, 9, 7, 5, 4);

    display_enemy_status(&elfo_selvagem);
    game_loop(player, &elfo_selvagem);

    printf("\nVocê derrotou o Elfo Selvagem!\n");
    collect_item(player);
    gain_experience(player, 120);

    printf("\nContinuando seu caminho, você encontra um grupo de trolls gigantes bloqueando o caminho.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando inimigos
    Enemy trolls[3];
    init_enemy(&trolls[0], "Troll", 180, 15, 3, 10, 6);
    init_enemy(&trolls[1], "Troll", 180, 15, 3, 10, 6);
    init_enemy(&trolls[2], "Troll", 180, 15, 3, 10, 6);

    for (int i = 0; i < 3; i++) {
        printf("\nTroll %d:\n", i + 1);
        display_enemy_status(&trolls[i]);
        game_loop(player, &trolls[i]);
        printf("\nVocê derrotou o Troll %d!\n", i + 1);
        collect_item(player);
        gain_experience(player, 180);
    }

    printf("\nEnquanto caminha, você encontra um druida velho cuidando de plantas mágicas.\n");
    printf("O druida parece estar em transe, concentrado em suas feitiços.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Conversar com o druida\n");
    printf("2. Ignorar o druida e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide conversar com o druida.\n");
        printf("Druida: 'Ah, herói! Eu sou Mithrandir, um druida que conhece os segredos deste bosque.\n");
        printf("Posso te ensinar um feitiço poderoso para fortalecer seus poderes mágicos.\n");
        printf("Deseja aprender o feitiço? (s/n): ");
        char learn_spell;
        scanf(" %c", &learn_spell);

        if (learn_spell == 's' || learn_spell == 'S') {
            printf("Você decide aprender o feitiço.\n");
            printf("Mithrandir ensina você um feitiço poderoso que aumenta sua magia.\n");
            player->magic += 10;
            printf("Nova Magia: %d\n", player->magic);
        } else {
            printf("Você decide não aprender o feitiço.\n");
            printf("Mithrandir: 'Tudo bem, mas você precisará encontrar forças internas para enfrentar os desafios.\n");
            printf("Boa sorte...' Mithrandir volta a cuidar das plantas mágicas.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o druida e continuar.\n");
        printf("Você continua seguindo pelo caminho do bosque.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um lobo solitário.\n");
    printf("O lobo parece estar ferido e desacordado.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Tentar acordar o lobo\n");
    printf("2. Ignorar o lobo e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê tenta acordar o lobo. Depois de alguns minutos, ele abre os olhos.\n");
        printf("O lobo é um companheiro fiel chamado Fang.\n");
        printf("\n");
        printf("Fang: 'Obrigado por me acordar. Meu nome é Fang. Estava ferido e você me salvou.\n");
        printf("Posso te ajudar em sua jornada.'\n");
        printf("\n");
        printf("O que você deseja fazer?\n");
        printf("1. Aceitar a ajuda de Fang\n");
        printf("2. Recusar a ajuda de Fang\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide aceitar a ajuda de Fang.\n");
            printf("Fang: 'Ótimo! Juntos podemos enfrentar qualquer desafio neste bosque.\n");
            printf("Vamos continuar nossa jornada.'\n");
            printf("\n");
        } else {
            printf("\nVocê decide recusar a ajuda de Fang.\n");
            printf("Fang: 'Tudo bem, mas você precisará enfrentar os desafios sozinho.\n");
            printf("Boa sorte...' Fang parte em direção a uma clareira.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o lobo e continuar.\n");
        printf("Você continua seguindo pelo caminho do bosque.\n");
        printf("\n");
    }

    printf("Continuando seu caminho, você encontra um acampamento de bandits.\n");
    printf("Os bandits parecem estar planejando um roubo em uma aldeia próxima.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Atacar os bandits\n");
    printf("2. Observar silenciosamente\n");
    printf("3. Ignorar e continuar\n");
    printf("Escolha uma ação (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide atacar os bandits.\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando inimigos
        Enemy bandits[4];
        init_enemy(&bandits[0], "Bandit", 70, 8, 4, 6, 4);
        init_enemy(&bandits[1], "Bandit", 70, 8, 4, 6, 4);
        init_enemy(&bandits[2], "Bandit", 70, 8, 4, 6, 4);
        init_enemy(&bandits[3], "Bandit", 70, 8, 4, 6, 4);

        for (int i = 0; i < 4; i++) {
            printf("\nBandit %d:\n", i + 1);
            display_enemy_status(&bandits[i]);
            game_loop(player, &bandits[i]);
            printf("\nVocê derrotou o Bandit %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 80);
        }
    } else if (choice == 2) {
        printf("\nVocê decide observar silenciosamente.\n");
        printf("Você vê que os bandits estão planejando um ataque em uma aldeia próxima.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Alertar a aldeia\n");
        printf("2. Ignorar e continuar\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide alertar a aldeia.\n");
            printf("Você corre para a aldeia e avisa os habitantes sobre o ataque.\n");
            printf("Os habitantes ficam gratos e oferecem uma poção de cura para você.\n");
            printf("Deseja pegar a poção de cura? (s/n): ");
            char pick_up;
            scanf(" %c", &pick_up);

            if (pick_up == 's' || pick_up == 'S') {
                Item item;
                strcpy(item.name, "Poção de Cura");
                item.type = 3; // Cura
                item.value = 20;
                player->health += item.value;
                printf("Você pegou a Poção de Cura! Saúde aumentada em %d. Nova Saúde: %d\n", item.value, player->health);
            } else {
                printf("Você não pegou a poção de cura.\n");
            }
        } else {
            printf("\nVocê decide ignorar e continuar.\n");
            printf("Você continua seguindo pelo caminho do bosque.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar e continuar.\n");
        printf("Você continua seguindo pelo caminho do bosque.\n");
        printf("\n");
    }

    printf("\nContinuando sua jornada, você encontra um palácio abandonado no meio do bosque.\n");
    printf("O palácio parece antigo e misterioso, com janelas quebradas e grifos dançando ao redor.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Explorar o palácio\n");
    printf("2. Ignorar o palácio e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide explorar o palácio.\n");
        printf("Você entra no palácio e encontra uma sala com um trono vazio e um livro antigo.\n");
        printf("O livro parece conter segredos importantes sobre o Velho Senhor.\n");
        printf("\n");
        printf("Deseja pegar o livro? (s/n): ");
        char pick_up;
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Livro Antigo");
            item.type = 0; // Outro tipo de item
            item.value = 0;
            add_item(player, item);
            printf("Você pegou o Livro Antigo!\n");
        } else {
            printf("Você não pegou o livro.\n");
        }

        printf("Continuando sua exploração, você encontra uma armadura mágica no chão!\n");
        printf("Deseja pegar a armadura mágica? (s/n): ");
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Armadura Mágica");
            item.type = 2; // Defesa
            item.value = 20;
            add_item(player, item);
            printf("Você pegou a Armadura Mágica! Defesa aumentada em %d.\n", item.value);
        } else {
            printf("Você não pegou a armadura mágica.\n");
        }
    } else {
        printf("\nVocê decide ignorar o palácio e continuar.\n");
        printf("Você continua seguindo pelo caminho do bosque.\n");
        printf("\n");
    }

    printf("\nFinalmente, você chega ao limite do Bosque Encantado e vê uma antiga ponte de pedra.\n");
    printf("A ponte está fraca e parece que está prestes a cair.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Tentar atravessar a ponte\n");
    printf("2. Procurar uma alternativa\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide tentar atravessar a ponte.\n");
        printf("Você começa a atravessar a ponte, mas ela começa a se mover instavelmente.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Continuar atravessando\n");
        printf("2. Voltar e procurar uma alternativa\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê continua atravessando a ponte.\n");
            printf("A ponte cai e você quase cai junto.\n");
            printf("Você perde 20 de saúde.\n");
            player->health -= 20;
            printf("Nova Saúde: %d\n", player->health);
        } else {
            printf("\nVocê decide voltar e procurar uma alternativa.\n");
            printf("Você volta e encontra uma trilha secreta que leva ao outro lado do bosque.\n");
            printf("Você segue pela trilha e chega ao outro lado sem perdas.\n");
        }
    } else {
        printf("\nVocê decide procurar uma alternativa.\n");
        printf("Você encontra uma trilha secreta que leva ao outro lado do bosque.\n");
        printf("Você segue pela trilha e chega ao outro lado sem perdas.\n");
    }

    printf("\nVocê está fora do Bosque Encantado e vê uma cidade distante.\n");
    printf("A cidade parece abandonada e cheia de ruínas, mas há sinais de vida.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Entrar na cidade\n");
    printf("2. Ignorar a cidade e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide entrar na cidade.\n");
        printf("Você vê ruínas de casas e sinais de uma batalha recente.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Explorar a cidade\n");
        printf("2. Ignorar a cidade e continuar\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide explorar a cidade.\n");
            printf("Você encontra um templo abandonado no centro da cidade.\n");
            printf("No templo, você encontra um altar com um símbolo estranho.\n");
            printf("O que você deseja fazer?\n");
            printf("1. Interagir com o altar\n");
            printf("2. Ignorar o altar e continuar\n");
            printf("Escolha uma ação (1/2): ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\nVocê decide interagir com o altar.\n");
                printf("O altar começa a brilhar e você sente uma energia mística fluindo por todo o seu corpo.\n");
                printf("Seus atributos aumentam significativamente!\n");
                player->strength += 5;
                player->magic += 5;
                player->stamina += 5;
                player->persuasion += 5;
                player->stealth += 5;
                printf("Nova Força: %d\n", player->strength);
                printf("Nova Magia: %d\n", player->magic);
                printf("Nova Stamina: %d\n", player->stamina);
                printf("Nova Persuasão: %d\n", player->persuasion);
                printf("Novo Stealth: %d\n", player->stealth);
            } else {
                printf("\nVocê decide ignorar o altar e continuar.\n");
                printf("Você continua seguindo pelo caminho.\n");
                printf("\n");
            }
        } else {
            printf("\nVocê decide ignorar a cidade e continuar.\n");
            printf("Você continua seguindo pelo caminho.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar a cidade e continuar.\n");
        printf("Você continua seguindo pelo caminho.\n");
        printf("\n");
    }

    printf("\nFinalmente, você chega a uma encruzilhada no caminho.\n");
    printf("Há três caminhos possíveis:\n");
    printf("1. Caminho para o Oeste\n");
    printf("2. Caminho para o Sul\n");
    printf("3. Caminho para o Norte\n");
    printf("Qual caminho você deseja seguir? (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê escolhe o Caminho para o Oeste.\n");
        printf("O caminho leva você a uma floresta densa e cheia de criaturas mágicas.\n");
    } else if (choice == 2) {
        printf("\nVocê escolhe o Caminho para o Sul.\n");
        printf("O caminho leva você a uma planície vasta e cheia de flores mágicas.\n");
    } else if (choice == 3) {
        printf("\nVocê escolhe o Caminho para o Norte.\n");
        printf("O caminho leva você a uma caverna misteriosa e cheia de tesouros ocultos.\n");
    } else {
        printf("Opção inválida. Você segue o Caminho para o Oeste por padrão.\n");
        choice = 1;
    }

    printf("\nVocê continua sua jornada...\n");
}

void chapter_four(Player *player) {
    printf("\n=========================================\n");
    printf("CAPÍTULO 4: A CIDADE ABANDONADA\n");
    printf("=========================================\n");
    printf("\n");
    printf("Você chega a uma cidade abandonada, repleta de ruínas e sinais de uma batalha recente.\n");
    printf("A cidade parece estar infestada por monstros e criaturas mágicas. Você sente uma presença\n");
    printf("malévola no ar e percebe que precisa explorar a cidade para encontrar pistas sobre o Velho Senhor.\n");
    printf("\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar(); // Para capturar a tecla Enter
    printf("\n");

    printf("Enquanto caminha, você encontra um templo abandonado no centro da cidade.\n");
    printf("O templo está cheio de ruínas, mas há sinais de vida recente.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Explorar o templo\n");
    printf("2. Ignorar o templo e continuar\n");
    printf("Escolha uma ação (1/2): ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide explorar o templo.\n");
        printf("Você entra no templo e encontra um altar com um símbolo estranho.\n");
        printf("No altar, há um livro antigo e uma chave mágica.\n");
        printf("\n");
        printf("Deseja pegar o livro? (s/n): ");
        char pick_up;
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Livro Antigo");
            item.type = 0; // Outro tipo de item
            item.value = 0;
            add_item(player, item);
            printf("Você pegou o Livro Antigo!\n");
        } else {
            printf("Você não pegou o livro.\n");
        }

        printf("Deseja pegar a chave mágica? (s/n): ");
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            Item item;
            strcpy(item.name, "Chave Mágica");
            item.type = 0; // Outro tipo de item
            item.value = 0;
            add_item(player, item);
            printf("Você pegou a Chave Mágica!\n");
        } else {
            printf("Você não pegou a chave mágica.\n");
        }
    } else {
        printf("\nVocê decide ignorar o templo e continuar.\n");
        printf("Você continua seguindo pela cidade abandonada.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um grupo de zumbis vagando pelas ruínas.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando inimigos
    Enemy zumbis[3];
    init_enemy(&zumbis[0], "Zumbi", 50, 5, 2, 3, 1);
    init_enemy(&zumbis[1], "Zumbi", 50, 5, 2, 3, 1);
    init_enemy(&zumbis[2], "Zumbi", 50, 5, 2, 3, 1);

    for (int i = 0; i < 3; i++) {
        printf("\nZumbi %d:\n", i + 1);
        display_enemy_status(&zumbis[i]);
        game_loop(player, &zumbis[i]);
        printf("\nVocê derrotou o Zumbi %d!\n", i + 1);
        collect_item(player);
        gain_experience(player, 50);
    }

    printf("\nContinuando sua jornada, você encontra um mercenário ferido em uma casa abandonada.\n");
    printf("O mercenário parece estar procurando ajuda para escapar da cidade.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Tentar acordar o mercenário\n");
    printf("2. Ignorar o mercenário e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide tentar acordar o mercenário. Depois de alguns minutos, ele abre os olhos.\n");
        printf("Mercenário: 'Ah... Obrigado por me acordar. Meu nome é Thorne. Estava patrulhando\n");
        printf("esta cidade quando fui atacado por zumbis.\n");
        printf("Eles me deixaram aqui, mas agora posso ajudar você.'\n");
        printf("\n");
        printf("O que você deseja fazer?\n");
        printf("1. Aceitar a ajuda de Thorne\n");
        printf("2. Recusar a ajuda de Thorne\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide aceitar a ajuda de Thorne.\n");
            printf("Thorne: 'Ótimo! Juntos podemos encontrar a saída desta cidade e derrotar os monstros.\n");
            printf("Vamos explorar esta cidade e encontrar uma forma de escapar.'\n");
            printf("\n");
        } else {
            printf("\nVocê decide recusar a ajuda de Thorne.\n");
            printf("Thorne: 'Tudo bem, mas você precisará encontrar a saída sozinho.\n");
            printf("Boa sorte...' Thorne se levanta e parte em direção a um túnel escuro.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o mercenário e continuar.\n");
        printf("Você continua explorando a cidade abandonada.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um dragão pequeno bloqueando um caminho.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy dragao_pequeno;
    init_enemy(&dragao_pequeno, "Dragão Pequeno", 100, 12, 8, 5, 6);

    display_enemy_status(&dragao_pequeno);
    game_loop(player, &dragao_pequeno);

    printf("\nVocê derrotou o Dragão Pequeno!\n");
    collect_item(player);
    gain_experience(player, 150);

    printf("\nEnquanto caminha, você encontra um elfo misterioso sentado em uma pedra.\n");
    printf("O elfo parece estar observando algo com interesse.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Conversar com o elfo\n");
    printf("2. Ignorar o elfo e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide conversar com o elfo.\n");
        printf("Elfo: 'Ah, herói! Eu sou Elenor, uma elfa misteriosa que conhece os segredos desta cidade.\n");
        printf("Posso te ajudar a encontrar a saída, mas preciso de sua ajuda em troca.\n");
        printf("Deseja aceitar minha ajuda? (s/n): ");
        char accept_help;
        scanf(" %c", &accept_help);

        if (accept_help == 's' || accept_help == 'S') {
            printf("Você decide aceitar a ajuda de Elenor.\n");
            printf("Elenor: 'Ótimo! Juntos podemos encontrar a saída e derrotar os monstros.\n");
            printf("Vamos explorar esta cidade e encontrar uma forma de escapar.'\n");
            printf("\n");
        } else {
            printf("Você decide recusar a ajuda de Elenor.\n");
            printf("Elenor: 'Tudo bem, mas você precisará encontrar a saída sozinho.\n");
            printf("Boa sorte...' Elenor parte em direção a um túnel escuro.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o elfo e continuar.\n");
        printf("Você continua explorando a cidade abandonada.\n");
        printf("\n");
    }
    printf("Continuando sua jornada, você encontra um tesouro escondido em uma casa abandonada!\n");
    printf("Deseja abrir o baú? (s/n): ");
    scanf(" %c", &pick_up);

    if (pick_up == 's' || pick_up == 'S') {
        Item item;
        strcpy(item.name, "Espada de Élites");
        item.type = 1; // Dano
        item.value = 25;
        add_item(player, item);
        printf("Você pegou a Espada de Élites! Dano aumentado em %d.\n", item.value);
    } else {
        printf("Você não pegou o tesouro.\n");
    }

    printf("\nContinuando sua jornada, você encontra um acampamento de monstros.\n");
    printf("Os monstros parecem estar planejando algo.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Atacar os monstros\n");
    printf("2. Observar silenciosamente\n");
    printf("3. Ignorar e continuar\n");
    printf("Escolha uma ação (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide atacar os monstros.\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando inimigos
        Enemy monstros[4];
        init_enemy(&monstros[0], "Monstro", 80, 10, 5, 7, 4);
        init_enemy(&monstros[1], "Monstro", 80, 10, 5, 7, 4);
        init_enemy(&monstros[2], "Monstro", 80, 10, 5, 7, 4);
        init_enemy(&monstros[3], "Monstro", 80, 10, 5, 7, 4);

        for (int i = 0; i < 4; i++) {
            printf("\nMonstro %d:\n", i + 1);
            display_enemy_status(&monstros[i]);
            game_loop(player, &monstros[i]);
            printf("\nVocê derrotou o Monstro %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 100);
        }
    } else if (choice == 2) {
        printf("\nVocê decide observar silenciosamente.\n");
        printf("Você vê que os monstros estão planejando um ataque em uma torre próxima.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Alertar a torre\n");
        printf("2. Ignorar e continuar\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide alertar a torre.\n");
            printf("Você corre para a torre e avisa os habitantes sobre o ataque.\n");
            printf("Os habitantes ficam gratos e oferecem uma poção de cura para você.\n");
            printf("Deseja pegar a poção de cura? (s/n): ");
            scanf(" %c", &pick_up);

            if (pick_up == 's' || pick_up == 'S') {
                Item item;
                strcpy(item.name, "Poção de Cura");
                item.type = 3; // Cura
                item.value = 20;
                player->health += item.value;
                printf("Você pegou a Poção de Cura! Saúde aumentada em %d. Nova Saúde: %d\n", item.value, player->health);
            } else {
                printf("Você não pegou a poção de cura.\n");
            }
        } else {
            printf("\nVocê decide ignorar e continuar.\n");
            printf("Você continua explorando a cidade abandonada.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar e continuar.\n");
        printf("Você continua explorando a cidade abandonada.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um livro mágico em uma biblioteca abandonada.\n");
    printf("O livro parece conter informações valiosas sobre o Velho Senhor.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Pegar o livro\n");
    printf("2. Ignorar o livro e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide pegar o livro.\n");
        printf("Você lê o livro e descobre informações cruciais sobre o Velho Senhor.\n");
        printf("O livro também contém um feitiço poderoso para fortalecer seus poderes mágicos.\n");
        printf("Deseja aprender o feitiço? (s/n): ");
        char learn_spell;
        scanf(" %c", &learn_spell);

        if (learn_spell == 's' || learn_spell == 'S') {
            printf("Você decide aprender o feitiço.\n");
            printf("O feitiço aumenta significativamente sua magia.\n");
            player->magic += 10;
            printf("Nova Magia: %d\n", player->magic);
        } else {
            printf("Você decide não aprender o feitiço.\n");
            printf("Você continua explorando a cidade.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o livro e continuar.\n");
        printf("Você continua explorando a cidade abandonada.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um urso gigante bloqueando o caminho para a saída da cidade.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy urso_gigante;
    init_enemy(&urso_gigante, "Urso Gigante", 150, 15, 3, 10, 7);

    display_enemy_status(&urso_gigante);
    game_loop(player, &urso_gigante);

    printf("\nVocê derrotou o Urso Gigante!\n");
    collect_item(player);
    gain_experience(player, 200);

    printf("\nContinuando sua jornada, você encontra um acampamento de goblins.\n");
    printf("Os goblins parecem estar planejando um ataque em uma aldeia próxima.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Atacar os goblins\n");
    printf("2. Observar silenciosamente\n");
    printf("3. Ignorar e continuar\n");
    printf("Escolha uma ação (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide atacar os goblins.\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando inimigos
        Enemy goblins[5];
        init_enemy(&goblins[0], "Goblin", 60, 7, 3, 5, 3);
        init_enemy(&goblins[1], "Goblin", 60, 7, 3, 5, 3);
        init_enemy(&goblins[2], "Goblin", 60, 7, 3, 5, 3);
        init_enemy(&goblins[3], "Goblin", 60, 7, 3, 5, 3);
        init_enemy(&goblins[4], "Goblin", 60, 7, 3, 5, 3);

        for (int i = 0; i < 5; i++) {
            printf("\nGoblin %d:\n", i + 1);
            display_enemy_status(&goblins[i]);
            game_loop(player, &goblins[i]);
            printf("\nVocê derrotou o Goblin %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 70);
        }
    } else if (choice == 2) {
        printf("\nVocê decide observar silenciosamente.\n");
        printf("Você vê que os goblins estão planejando um ataque em uma aldeia próxima.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Alertar a aldeia\n");
        printf("2. Ignorar e continuar\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide alertar a aldeia.\n");
            printf("Você corre para a aldeia e avisa os habitantes sobre o ataque.\n");
            printf("Os habitantes ficam gratos e oferecem uma poção de cura para você.\n");
            printf("Deseja pegar a poção de cura? (s/n): ");
            scanf(" %c", &pick_up);

            if (pick_up == 's' || pick_up == 'S') {
                Item item;
                strcpy(item.name, "Poção de Cura");
                item.type = 3; // Cura
                item.value = 20;
                player->health += item.value;
                printf("Você pegou a Poção de Cura! Saúde aumentada em %d. Nova Saúde: %d\n", item.value, player->health);
            } else {
                printf("Você não pegou a poção de cura.\n");
            }
        } else {
            printf("\nVocê decide ignorar e continuar.\n");
            printf("Você continua explorando a cidade abandonada.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar e continuar.\n");
        printf("Você continua explorando a cidade abandonada.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um druida antigo cuidando de plantas mágicas.\n");
    printf("O druida parece estar em transe, concentrado em seus feitiços.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Conversar com o druida\n");
    printf("2. Ignorar o druida e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide conversar com o druida.\n");
        printf("Druida: 'Ah, herói! Eu sou Mithrandir, um druida que conhece os segredos desta cidade.\n");
        printf("Posso te ensinar um feitiço poderoso para fortalecer seus poderes mágicos.\n");
        printf("Deseja aprender o feitiço? (s/n): ");
        char learn_spell;
        scanf(" %c", &learn_spell);

        if (learn_spell == 's' || learn_spell == 'S') {
            printf("Você decide aprender o feitiço.\n");
            printf("Mithrandir ensina você um feitiço poderoso que aumenta sua magia.\n");
            player->magic += 10;
            printf("Nova Magia: %d\n", player->magic);
        } else {
            printf("Você decide não aprender o feitiço.\n");
            printf("Mithrandir: 'Tudo bem, mas você precisará encontrar forças internas para enfrentar os desafios.\n");
            printf("Boa sorte...' Mithrandir volta a cuidar das plantas mágicas.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o druida e continuar.\n");
        printf("Você continua explorando a cidade abandonada.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um goblin lider bloqueando o caminho para a saída da cidade.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy goblin_lider;
    init_enemy(&goblin_lider, "Goblin Líder", 100, 10, 5, 7, 5);

    display_enemy_status(&goblin_lider);
    game_loop(player, &goblin_lider);

    printf("\nVocê derrotou o Goblin Líder!\n");
    collect_item(player);
    gain_experience(player, 150);

    printf("\nContinuando sua jornada, você encontra um portal brilhante em uma clareira.\n");
    printf("O portal emite uma luz azul intensa e você sente uma energia mística.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Entrar no portal\n");
    printf("2. Ignorar o portal e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide entrar no portal.\n");
        printf("Você sente uma energia mística envolvendo você enquanto atravessa o portal.\n");
        printf("Quando você emerge do outro lado, você está em um novo local.\n");
        printf("Você está em um vale mágico repleto de flores coloridas e árvores altas.\n");
        printf("No centro do vale, há um lago cristalino com um reflexo místico.\n");
        printf("\n");
        printf("Deseja beber da água do lago? (s/n): ");
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            printf("Você bebe da água do lago e sente uma energia mística fluindo por todo o seu corpo.\n");
            printf("Seus atributos aumentam significativamente!\n");
            player->strength += 5;
            player->magic += 5;
            player->stamina += 5;
            player->persuasion += 5;
            player->stealth += 5;
            printf("Nova Força: %d\n", player->strength);
            printf("Nova Magia: %d\n", player->magic);
            printf("Nova Stamina: %d\n", player->stamina);
            printf("Nova Persuasão: %d\n", player->persuasion);
            printf("Novo Stealth: %d\n", player->stealth);
        } else {
            printf("Você não bebe da água do lago e continua seu caminho.\n");
        }
    } else {
        printf("\nVocê decide ignorar o portal e continuar.\n");
        printf("Você continua seguindo pela cidade abandonada.\n");
        printf("\n");
    }

    printf("\nFinalmente, você chega à saída da cidade abandonada e vê três caminhos possíveis:\n");
    printf("1. Caminho para o Oeste\n");
    printf("2. Caminho para o Sul\n");
    printf("3. Caminho para o Norte\n");
    printf("Qual caminho você deseja seguir? (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê escolhe o Caminho para o Oeste.\n");
        printf("O caminho leva você a uma floresta densa e cheia de criaturas mágicas.\n");
    } else if (choice == 2) {
        printf("\nVocê escolhe o Caminho para o Sul.\n");
        printf("O caminho leva você a uma planície vasta e cheia de flores mágicas.\n");
    } else if (choice == 3) {
        printf("\nVocê escolhe o Caminho para o Norte.\n");
        printf("O caminho leva você a uma caverna misteriosa e cheia de tesouros ocultos.\n");
    } else {
        printf("Opção inválida. Você segue o Caminho para o Oeste por padrão.\n");
        choice = 1;
    }

    printf("\nVocê continua sua jornada...\n");
}


void chapter_five(Player *player) {
    printf("\n=========================================\n");
    printf("CAPÍTULO 5: O ENCONTRO COM SATANÁS\n");
    printf("=========================================\n");
    printf("\n");
    printf("Você chega ao Castelo Condenado, onde sente uma energia malévola dominando o ambiente.\n");
    printf("As portas do castelo estão abertas, revelando um corredor escuro e sombrio.\n");
    printf("Você sente que está cada vez mais próximo do seu objetivo final: derrotar Satanás.\n");
    printf("\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar(); // Para capturar a tecla Enter
    printf("\n");

    printf("Enquanto caminha pelo corredor, você encontra um acampamento de demônios.\n");
    printf("Os demônios parecem estar planejando algo terrível.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Atacar os demônios\n");
    printf("2. Observar silenciosamente\n");
    printf("3. Ignorar e continuar\n");
    printf("Escolha uma ação (1/2/3): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide atacar os demônios.\n");
        printf("Prepare-se para a batalha!\n");

        // Inicializando inimigos
        Enemy demonios[4];
        init_enemy(&demonios[0], "Demônio", 100, 12, 8, 6, 5);
        init_enemy(&demonios[1], "Demônio", 100, 12, 8, 6, 5);
        init_enemy(&demonios[2], "Demônio", 100, 12, 8, 6, 5);
        init_enemy(&demonios[3], "Demônio", 100, 12, 8, 6, 5);

        for (int i = 0; i < 4; i++) {
            printf("\nDemônio %d:\n", i + 1);
            display_enemy_status(&demonios[i]);
            game_loop(player, &demonios[i]);
            printf("\nVocê derrotou o Demônio %d!\n", i + 1);
            collect_item(player);
            gain_experience(player, 150);
        }
    } else if (choice == 2) {
        printf("\nVocê decide observar silenciosamente.\n");
        printf("Você vê que os demônios estão planejando um ataque em uma torre próxima.\n");
        printf("O que você deseja fazer?\n");
        printf("1. Alertar a torre\n");
        printf("2. Ignorar e continuar\n");
        printf("Escolha uma ação (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVocê decide alertar a torre.\n");
            printf("Você corre para a torre e avisa os habitantes sobre o ataque.\n");
            printf("Os habitantes ficam gratos e oferecem uma poção de cura para você.\n");
            printf("Deseja pegar a poção de cura? (s/n): ");
            char pick_up;
            scanf(" %c", &pick_up);

            if (pick_up == 's' || pick_up == 'S') {
                Item item;
                strcpy(item.name, "Poção de Cura");
                item.type = 3; // Cura
                item.value = 20;
                player->health += item.value;
                printf("Você pegou a Poção de Cura! Saúde aumentada em %d. Nova Saúde: %d\n", item.value, player->health);
            } else {
                printf("Você não pegou a poção de cura.\n");
            }
        } else {
            printf("\nVocê decide ignorar e continuar.\n");
            printf("Você continua seguindo pelo corredor do castelo.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar e continuar.\n");
        printf("Você continua seguindo pelo corredor do castelo.\n");
        printf("\n");
    }

    printf("Continuando seu caminho, você encontra um druida antigo, Mithrandir, em uma sala isolada.\n");
    printf("Mithrandir parece estar esperando por você.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Conversar com Mithrandir\n");
    printf("2. Ignorar Mithrandir e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide conversar com Mithrandir.\n");
        printf("Mithrandir: 'Herói, você chegou até aqui por causa do seu valor e coragem.\n");
        printf("Mas agora, você enfrentará o verdadeiro vilão: Satanás.\n");
        printf("Prepare-se para a batalha final. Você precisa derrotar Satanás para restaurar a paz em Tharn.'\n");
        printf("\n");
    } else {
        printf("\nVocê decide ignorar Mithrandir e continuar.\n");
        printf("Você continua seguindo pelo corredor do castelo.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um tesouro escondido em uma sala secreta.\n");
    printf("Deseja abrir o baú? (s/n): ");
    char pick_up;
    scanf(" %c", &pick_up);

    if (pick_up == 's' || pick_up == 'S') {
        Item item;
        strcpy(item.name, "Amuleto da Luz");
        item.type = 2; // Defesa
        item.value = 30;
        add_item(player, item);
        printf("Você pegou o Amuleto da Luz! Defesa aumentada em %d.\n", item.value);
    } else {
        printf("Você não pegou o tesouro.\n");
    }

    printf("Continuando seu caminho, você encontra um livro mágico em uma biblioteca antiga.\n");
    printf("O livro parece conter informações valiosas sobre Satanás.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Pegar o livro\n");
    printf("2. Ignorar o livro e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide pegar o livro.\n");
        printf("Você lê o livro e descobre informações cruciais sobre Satanás.\n");
        printf("O livro também contém um feitiço poderoso para fortalecer seus poderes mágicos.\n");
        printf("Deseja aprender o feitiço? (s/n): ");
        char learn_spell;
        scanf(" %c", &learn_spell);

        if (learn_spell == 's' || learn_spell == 'S') {
            printf("Você decide aprender o feitiço.\n");
            printf("O feitiço aumenta significativamente sua magia.\n");
            player->magic += 15;
            printf("Nova Magia: %d\n", player->magic);
        } else {
            printf("Você decide não aprender o feitiço.\n");
            printf("Você continua explorando o castelo.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar o livro e continuar.\n");
        printf("Você continua explorando o castelo.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um urso gigante bloqueando o caminho para a sala do tesouro.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy urso_gigante;
    init_enemy(&urso_gigante, "Urso Gigante", 150, 15, 3, 10, 7);

    display_enemy_status(&urso_gigante);
    game_loop(player, &urso_gigante);

    printf("\nVocê derrotou o Urso Gigante!\n");
    collect_item(player);
    gain_experience(player, 200);

    printf("Continuando seu caminho, você encontra uma sala com um grande portão fechado.\n");
    printf("O portão está protegido por uma magia poderosa e parece impossível de abrir.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Tentar abrir o portão\n");
    printf("2. Procurar uma chave\n");
    printf("3. Ignorar e continuar\n");
    printf("Escolha uma ação (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide tentar abrir o portão.\n");
        printf("O portão resiste à sua tentativa e você sente uma energia negra emanando dele.\n");
        printf("Você precisa de uma chave mágica para abrir o portão.\n");
        printf("\n");
    } else if (choice == 2) {
        printf("\nVocê decide procurar uma chave.\n");
        printf("Você explora os corredores do castelo e encontra a Chave Mágica que pegou anteriormente.\n");
        printf("Deseja usar a chave mágica? (s/n): ");
        scanf(" %c", &pick_up);

        if (pick_up == 's' || pick_up == 'S') {
            printf("Você decide usar a chave mágica.\n");
            printf("A chave mágica brilha e o portão se abre lentamente.\n");
            printf("Você entra na sala do tesouro.\n");
        } else {
            printf("Você decide não usar a chave mágica e continua explorando.\n");
            printf("Você precisa encontrar a chave mágica para abrir o portão.\n");
            printf("\n");
        }
    } else {
        printf("\nVocê decide ignorar e continuar.\n");
        printf("Você continua explorando os corredores do castelo.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um elfo misterioso, Elenor, em uma sala iluminada por luzes místicas.\n");
    printf("Elenor parece estar esperando por você.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Conversar com Elenor\n");
    printf("2. Ignorar Elenor e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide conversar com Elenor.\n");
        printf("Elenor: 'Herói, você chegou até aqui graças à sua coragem e determinação.\n");
        printf("Mas agora, você enfrentará Satanás, o verdadeiro vilão por trás dessa destruição.\n");
        printf("Prepare-se para a batalha final. Você precisa derrotar Satanás para restaurar a paz em Tharn.'\n");
        printf("\n");
    } else {
        printf("\nVocê decide ignorar Elenor e continuar.\n");
        printf("Você continua seguindo pelo corredor do castelo.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você encontra um acampamento de goblins liderados por um chefe.\n");
    printf("O chefe parece estar preparando um plano para capturar você.\n");
    printf("Prepare-se para a batalha!\n");

    // Inicializando um inimigo
    Enemy goblin_chefe;
    init_enemy(&goblin_chefe, "Goblin Chefe", 120, 10, 6, 8, 6);

    display_enemy_status(&goblin_chefe);
    game_loop(player, &goblin_chefe);

    printf("\nVocê derrotou o Goblin Chefe!\n");
    collect_item(player);
    gain_experience(player, 180);

    printf("Continuando seu caminho, você encontra uma sala com um altar mágico.\n");
    printf("O altar parece estar ligado a uma magia poderosa que protege Satanás.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Destruir o altar\n");
    printf("2. Ignorar o altar e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide destruir o altar.\n");
        printf("Você usa sua magia para destruir o altar.\n");
        printf("A sala começa a tremer e o portão se abre lentamente.\n");
        printf("Você entra na sala do tesouro.\n");
    } else {
        printf("\nVocê decide ignorar o altar e continuar.\n");
        printf("Você continua explorando os corredores do castelo.\n");
        printf("Você precisa encontrar uma maneira de destruir o altar para abrir o portão.\n");
        printf("\n");
    }

    printf("Continuando sua jornada, você chega à sala do tesouro.\n");
    printf("A sala está cheia de tesouros mágicos e um grande portão que leva ao salão principal.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Abrir o portão\n");
    printf("2. Ignorar o portão e continuar\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nVocê decide abrir o portão.\n");
        printf("O portão se abre lentamente, revelando o salão principal do castelo.\n");
        printf("No centro do salão, você vê Satanás, o verdadeiro vilão.\n");
    } else {
        printf("\nVocê decide ignorar o portão e continuar.\n");
        printf("Você continua explorando a sala do tesouro.\n");
        printf("Você precisa abrir o portão para enfrentar Satanás.\n");
        printf("\n");
    }

    printf("\n=========================================\n");
    printf("BOSS FINAL: SATANÁS\n");
    printf("=========================================\n");
    printf("\n");
    printf("Satanás: 'Ah, herói! Você realmente pensou que poderia derrotar-me assim tão facilmente?\n");
    printf("Eu sou Satanás, o verdadeiro vilão por trás dessa destruição em Tharn.\n");
    printf("Prepare-se para a batalha final!'\n");
    printf("\n");

    // Inicializando o boss
    Enemy satanas;
    init_enemy(&satanas, "Satanás", 300, 25, 20, 15, 15);

    display_enemy_status(&satanas);
    game_loop(player, &satanas);

    printf("\nVocê derrotou Satanás!\n");
    printf("A paz foi restaurada a Tharn. Parabéns, herói!\n");
    printf("Você completou sua jornada e derrotou o verdadeiro vilão.\n");
    printf("\n");
    printf("O que você deseja fazer?\n");
    printf("1. Ver status final\n");
    printf("2. Sair do jogo\n");
    printf("Escolha uma ação (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n=========================================\n");
        printf("STATUS FINAL\n");
        printf("=========================================\n");
        display_player_status(player);
        printf("=========================================\n");
    }

    printf("Saindo do jogo. Até logo!\n");
    exit(0);
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    Player player;
    char name[50];

    printf("Bem-vindo ao RPG Terminal!\n");
    printf("Digite o nome do seu personagem: ");
    scanf("%49s", name);

    init_player(&player, name);
    display_player_status(&player);

    intro();
    chapter_one(&player);
    chapter_two(&player);
    chapter_three(&player);
    chapter_four(&player);
    chapter_five(&player);

    return 0;
}