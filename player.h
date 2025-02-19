//This file is part of the player, this is where we store its information.

#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char name[50];
    int health;
    int strength;
    int magic;
    int stamina;
    int persuasion;
    int stealth;
} Player;

void init_player(Player *player, const char *name);
void display_player_status(const Player *player);
int roll_dice();
int perform_action(const Player *player, int attribute);

#endif