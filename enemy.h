#ifndef ENEMY_H
#define ENEMY_H

typedef struct {
    char name[50];
    int health;
    int strength;
    int magic;
    int stamina;
    int defense;
} Enemy;

void init_enemy(Enemy *enemy, const char *name, int health, int strength, int magic, int stamina, int defense);
void display_enemy_status(const Enemy *enemy);

#endif