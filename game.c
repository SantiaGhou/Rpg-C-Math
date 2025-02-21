#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "player.h"
#include "enemy.h"

void start_game() {
    Player player;
    char name[50];

    printf("Digite o nome do seu personagem: ");
    scanf("%49s", name);

    init_player(&player, name);
    display_player_status(&player);

    printf("O jogo começou! Boa sorte, %s.\n", player.name);
}

void game_loop(Player *player, Enemy *enemy) {
    int choice;
    int success;

    while (1) {
        printf("\nO que você deseja fazer?\n");
        printf("1. Lutar\n");
        printf("2. Usar Magia\n");
        printf("3. Correr\n");
        printf("4. Persuadir\n");
        printf("5. Espiar\n");
        printf("6. Ver Status\n");
        printf("7. Sair do Jogo\n");
        printf("Escolha uma ação: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                success = perform_action(player, player->strength);
                if (success) {
                    printf("Você atingiu o %s!\n", enemy->name);
                    enemy->health -= 10; // Dano causado pelo jogador
                    if (enemy->health <= 0) {
                        printf("Você derrotou o %s!\n", enemy->name);
                        return; // Fim do capítulo
                    }
                } else {
                    printf("Você errou o ataque!\n");
                }
                break;
            case 2:
                success = perform_action(player, player->magic);
                if (success) {
                    printf("Você usou magia contra o %s!\n", enemy->name);
                    enemy->health -= 15; // Dano causado pelo jogador
                    if (enemy->health <= 0) {
                        printf("Você derrotou o %s!\n", enemy->name);
                        return; // Fim do capítulo
                    }
                } else {
                    printf("Sua magia falhou!\n");
                }
                break;
            case 3:
                success = perform_action(player, player->stamina);
                if (success) {
                    printf("Você conseguiu fugir!\n");
                    return; // Fim do capítulo
                } else {
                    printf("Você não conseguiu fugir!\n");
                }
                break;
            case 4:
                success = perform_action(player, player->persuasion);
                if (success) {
                    printf("Você persuadiu o %s!\n", enemy->name);
                    return; // Fim do capítulo
                } else {
                    printf("Você não conseguiu persuadir o %s!\n", enemy->name);
                }
                break;
            case 5:
                success = perform_action(player, player->stealth);
                if (success) {
                    printf("Você espiou o %s!\n", enemy->name);
                    display_enemy_status(enemy);
                } else {
                    printf("Você não conseguiu espiar o %s!\n", enemy->name);
                }
                break;
            case 6:
                display_player_status(player);
                break;
            case 7:
                printf("Saindo do jogo. Até logo!\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }

        if (enemy->health > 0) {
            printf("\nO %s ataca!\n", enemy->name);
            int enemy_attack = roll_dice() + enemy->strength - player->defense;
            if (enemy_attack > 0) {
                player->health -= enemy_attack;
                printf("Você tomou %d de dano!\n", enemy_attack);
                if (player->health <= 0) {
                    printf("Você foi derrotado pelo %s!\n", enemy->name);
                    exit(0); // Fim do jogo por derrota
                }
            } else {
                printf("O ataque do %s foi mitigado!\n", enemy->name);
            }
        }
    }
}

void boss_fight(Player *player, const char *boss_name, int health, int strength, int magic, int stamina, int defense) {
    printf("\n=========================================\n");
    printf("BOSS BATTLE: %s\n", boss_name);
    printf("=========================================\n");

    Enemy boss;
    init_enemy(&boss, boss_name, health, strength, magic, stamina, defense);
    display_enemy_status(&boss);

    game_loop(player, &boss);
}