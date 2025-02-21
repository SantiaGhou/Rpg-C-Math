#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

#define MAX_INVENTORY_SIZE 10

typedef struct {
    Item items[MAX_INVENTORY_SIZE];
    int size;
} Inventory;

Inventory inventory;

void init_player(Player *player, const char *name) {
    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0';
    player->health = 100;
    player->strength = 5;
    player->magic = 5;
    player->stamina = 5;
    player->persuasion = 5;
    player->stealth = 5;
    player->defense = 0;
    player->level = 1;
    player->experience = 0;

    inventory.size = 0;
}

void display_player_status(const Player *player) {
    printf("=== Status do Jogador ===\n");
    printf("Nome: %s\n", player->name);
    printf("Saúde: %d\n", player->health);
    printf("Nível: %d\n", player->level);
    printf("Experiência: %d\n", player->experience);
    printf("Próximo nível: %d\n", player->level * 100);
    printf("Força: %d\n", player->strength);
    printf("Magia: %d\n", player->magic);
    printf("Stamina: %d\n", player->stamina);
    printf("Persuasão: %d\n", player->persuasion);
    printf("Stealth: %d\n", player->stealth);
    printf("Defesa: %d\n", player->defense);
    printf("=========================\n");
}

int roll_dice() {
    return rand() % 10 + 1;
}

int perform_action(const Player *player, int attribute) {
    if (attribute < 0 || attribute > 10) {
        printf("Atributo inválido!\n");
        return 0;
    }

    int dice_roll = roll_dice();
    int total = dice_roll + attribute;

    printf("Você rolou um %d no dado.\n", dice_roll);
    printf("Total (dado + atributo): %d\n", total);

    if (total >= 10) {
        printf("Ação bem-sucedida!\n");
        return 1;
    } else {
        printf("Ação falhou...\n");
        return 0;
    }
}

void add_item(Player *player, Item item) {
    if (inventory.size < MAX_INVENTORY_SIZE) {
        inventory.items[inventory.size++] = item;
        printf("Item adicionado ao inventário: %s\n", item.name);
    } else {
        printf("Inventário cheio! Não foi possível adicionar o item: %s\n", item.name);
    }
}

void display_inventory(const Player *player) {
    if (inventory.size == 0) {
        printf("Seu inventário está vazio.\n");
        return;
    }

    printf("=== Inventário ===\n");
    for (int i = 0; i < inventory.size; i++) {
        printf("%d. %s (%s +%d)\n", i + 1, inventory.items[i].name,
               inventory.items[i].type == 1 ? "Dano" :
               inventory.items[i].type == 2 ? "Defesa" :
               inventory.items[i].type == 3 ? "Cura" :
               "Outro", inventory.items[i].value);
    }
    printf("==================\n");
}

void gain_experience(Player *player, int exp) {
    player->experience += exp;
    printf("Você ganhou %d de experiência!\n", exp);
    check_level_up(player);
}

void check_level_up(Player *player) {
    int next_level_exp = player->level * 100;
    if (player->experience >= next_level_exp) {
        player->level++;
        player->experience -= next_level_exp;
        printf("\n=========================================\n");
        printf("LEVEL UP!\n");
        printf("=========================================\n");
        printf("Você subiu para o nível %d!\n", player->level);
        level_up(player);
    }
}

void level_up(Player *player) {
    printf("Você ganhou pontos de atributo para distribuir.\n");
    printf("Você tem 5 pontos para distribuir entre:\n");
    printf("1. Força\n");
    printf("2. Magia\n");
    printf("3. Stamina\n");
    printf("4. Persuasão\n");
    printf("5. Stealth\n");

    int points = 5;
    int choice, value;

    while (points > 0) {
        printf("\nVocê tem %d ponto(s) restantes.\n", points);
        printf("Escolha um atributo para aumentar (1-5): ");
        scanf("%d", &choice);

        printf("Quantos pontos você quer adicionar (máximo %d): ", points);
        scanf("%d", &value);

        if (value <= 0 || value > points) {
            printf("Valor inválido. Tente novamente.\n");
            continue;
        }

        switch (choice) {
            case 1:
                player->strength += value;
                printf("Força aumentada em %d. Nova Força: %d\n", value, player->strength);
                break;
            case 2:
                player->magic += value;
                printf("Magia aumentada em %d. Nova Magia: %d\n", value, player->magic);
                break;
            case 3:
                player->stamina += value;
                printf("Stamina aumentada em %d. Nova Stamina: %d\n", value, player->stamina);
                break;
            case 4:
                player->persuasion += value;
                printf("Persuasão aumentada em %d. Nova Persuasão: %d\n", value, player->persuasion);
                break;
            case 5:
                player->stealth += value;
                printf("Stealth aumentada em %d. Novo Stealth: %d\n", value, player->stealth);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }

        points -= value;
    }
}

void pickup(Player *player, const char *item_name, int item_type, int item_value) {
    Item item;
    strcpy(item.name, item_name);
    item.type = item_type;
    item.value = item_value;

    switch (item_type) {
        case 1: // Dano
            player->strength += item_value;
            printf("Você pegou %s! Dano aumentado em %d. Nova Força: %d\n", item.name, item.value, player->strength);
            break;
        case 2: // Defesa
            player->defense += item_value;
            printf("Você pegou %s! Defesa aumentada em %d. Nova Defesa: %d\n", item.name, item.value, player->defense);
            break;
        case 3: // Cura
            player->health += item_value;
            printf("Você pegou %s! Saúde aumentada em %d. Nova Saúde: %d\n", item.name, item.value, player->health);
            break;
        case 0: // Outro
            add_item(player, item);
            printf("Você pegou %s!\n", item.name);
            break;
        default:
            printf("Tipo de item inválido!\n");
            return;
    }

    add_item(player, item);
}