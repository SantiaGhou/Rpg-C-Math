#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "enemy.h"

void start_game();
void game_loop(Player *player, Enemy *enemy);
void boss_fight(Player *player, const char *boss_name, int health, int strength, int magic, int stamina, int defense);

#endif