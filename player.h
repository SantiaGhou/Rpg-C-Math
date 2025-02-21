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
    int defense;
    int level;
    int experience;
} Player;

typedef struct {
    char name[50];
    int type; // 1 - Dano, 2 - Defesa, 3 - Cura, 0 - Outro
    int value;
} Item;

void init_player(Player *player, const char *name);
void display_player_status(const Player *player);
int roll_dice();
int perform_action(const Player *player, int attribute);
void add_item(Player *player, Item item);
void display_inventory(const Player *player);
void gain_experience(Player *player, int exp);
void check_level_up(Player *player);
void level_up(Player *player);
void pick_up(Player *player, const char *item_name, int item_type, int item_value);

#endif