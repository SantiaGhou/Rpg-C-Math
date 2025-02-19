/**
 *  This file implements player-related functions such as initialization,
 *  status display, dice rolling and performing attribute-based actions.
 */
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <time.h>
 #include "player.h"

 void init_player(Player *player, const char *name) {
     strncpy(player->name, name, sizeof(player->name) - 1);
     player->name[sizeof(player->name) - 1] = '\0';
     player->health = 100;
     player->strength = 5;
     player->magic = 5;
     player->stamina = 5;
     player->persuasion = 5;
     player->stealth = 5;
 }

 void display_player_status(const Player *player) {
     printf("=== Status do Jogador ===\n");
     printf("Nome: %s\n", player->name);
     printf("Saúde: %d\n", player->health);
     printf("Força: %d\n", player->strength);
     printf("Magia: %d\n", player->magic);
     printf("Stamina: %d\n", player->stamina);
     printf("Persuasão: %d\n", player->persuasion);
     printf("Stealth: %d\n", player->stealth);
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
         printf("Você falhou...\n");
         return 0;
     }
 }