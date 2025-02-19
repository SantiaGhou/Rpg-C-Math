#include <stdio.h>
#include <string.h>
#include "enemy.h"

void init_enemy(Enemy *enemy, const char *name, int health, int strength, int magic, int stamina, int defense) {
    strncpy(enemy->name, name, sizeof(enemy->name) - 1);
    enemy->name[sizeof(enemy->name) - 1] = '\0';
    enemy->health = health;
    enemy->strength = strength;
    enemy->magic = magic;
    enemy->stamina = stamina;
    enemy->defense = defense;
}

void display_enemy_status(const Enemy *enemy) {
    printf("=== Status do Inimigo ===\n");
    printf("Nome: %s\n", enemy->name);
    printf("Saúde: %d\n", enemy->health);
    printf("Força: %d\n", enemy->strength);
    printf("Magia: %d\n", enemy->magic);
    printf("Stamina: %d\n", enemy->stamina);
    printf("Defesa: %d\n", enemy->defense);
    printf("=========================\n");
}