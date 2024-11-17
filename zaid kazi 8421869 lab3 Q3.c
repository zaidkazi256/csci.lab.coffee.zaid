#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_TEAMS 10
#define SQUAD_SIZE 25

// Struct Definitions
typedef struct {
    int day, month, year;
} date_t;

typedef struct {
    char name[26];
    int kit_number;
    date_t birth_date;
    char position[21];
} player_t;

typedef struct {
    char name[21];
    player_t players[SQUAD_SIZE];
    int active_size;
} team_t;

// Global Variables
team_t teams[NUM_TEAMS];
int num_enrolled_teams = 0;

// Function Prototypes
void display_menu();
void enroll_club();
void add_player();
void search_update();
void display_club_statistics();
void handle_error(char *message);

// Main Function
int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume newline character
        switch (choice) {
            case 1:
                enroll_club();
                break;
            case 2:
                add_player();
                break;
            case 3:
                search_update();
                break;
            case 4:
                display_club_statistics();
                break;
            default:
                printf("Exiting program. Goodbye!\n");
                return 0;
        }
    }
}

// Function Definitions

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Search/Update Player\n");
    printf("4. Display Club Statistics\n");
    printf("Any other key to exit\n");
    printf("Enter your choice: ");
}

void enroll_club() {
    if (num_enrolled_teams >= NUM_TEAMS) {
        handle_error("Maximum number of clubs enrolled.");
        return;
    }
    printf("Enter club name: ");
    fgets(teams[num_enrolled_teams].name, 21, stdin);
    teams[num_enrolled_teams].name[strcspn(teams[num_enrolled_teams].name, "\n")] = '\0';
    teams[num_enrolled_teams].active_size = 0;
    num_enrolled_teams++;
}

void add_player() {
    int club_index;
    printf("Select club by index (0 to %d): ", num_enrolled_teams - 1);
    scanf("%d", &club_index);
    getchar();
    if (club_index < 0 || club_index >= num_enrolled_teams) {
        handle_error("Invalid club selection.");
        return;
    }
    if (teams[club_index].active_size >= SQUAD_SIZE) {
        handle_error("Maximum squad size reached.");
        return;
    }
    player_t *new_player = &teams[club_index].players[teams[club_index].active_size];

    printf("Enter player name: ");
    fgets(new_player->name, 26, stdin);
    new_player->name[strcspn(new_player->name, "\n")] = '\0';
    
    printf("Enter kit number (1-99): ");
    scanf("%d", &new_player->kit_number);
    getchar();

    // Check for duplicates
    for (int i = 0; i < teams[club_index].active_size; i++) {
        if (strcasecmp(teams[club_index].players[i].name, new_player->name) == 0 ||
            teams[club_index].players[i].kit_number == new_player->kit_number) {
            handle_error("Duplicate player name or kit number found.");
            return;
        }
    }
    
    // Get remaining player details
    printf("Enter birth date (day month year): ");
    scanf("%d %d %d", &new_player->birth_date.day, &new_player->birth_date.month, &new_player->birth_date.year);
    getchar();

    printf("Enter position: ");
    fgets(new_player->position, 21, stdin);
    new_player->position[strcspn(new_player->position, "\n")] = '\0';

    teams[club_index].active_size++;
}

void search_update() {
    char search_name[26];
    int search_kit, found = 0;
    printf("Search by player name or kit number (1 for name, 2 for kit): ");
    int search_type;
    scanf("%d", &search_type);
    getchar();
    
    if (search_type == 1) {
        printf("Enter player name: ");
        fgets(search_name, 26, stdin);
        search_name[strcspn(search_name, "\n")] = '\0';
        for (int i = 0; i < num_enrolled_teams; i++) {
            for (int j = 0; j < teams[i].active_size; j++) {
                if (strcasecmp(teams[i].players[j].name, search_name) == 0) {
                    printf("Player found: %s, Kit: %d\n", teams[i].players[j].name, teams[i].players[j].kit_number);
                    found = 1;
                    // Prompt to update
                    printf("Enter new position (leave blank to keep current): ");
                    fgets(teams[i].players[j].position, 21, stdin);
                    teams[i].players[j].position[strcspn(teams[i].players[j].position, "\n")] = '\0';
                }
            }
        }
    } else if (search_type == 2) {
        printf("Enter kit number: ");
        scanf("%d", &search_kit);
        getchar();
        for (int i = 0; i < num_enrolled_teams; i++) {
            for (int j = 0; j < teams[i].active_size; j++) {
                if (teams[i].players[j].kit_number == search_kit) {
                    printf("Player found: %s, Kit: %d\n", teams[i].players[j].name, teams[i].players[j].kit_number);
                    found = 1;
                    // Prompt to update
                    printf("Enter new position (leave blank to keep current): ");
                    fgets(teams[i].players[j].position, 21, stdin);
                    teams[i].players[j].position[strcspn(teams[i].players[j].position, "\n")] = '\0';
                }
            }
        }
    } else {
        handle_error("Invalid search type.");
    }
    
    if (!found) handle_error("Player not found.");
}

void display_club_statistics() {
    for (int i = 0; i < num_enrolled_teams; i++) {
        printf("Club: %s\n", teams[i].name);
        printf("Number of Players: %d\n", teams[i].active_size);
        for (int j = 0; j < teams[i].active_size; j++) {
            player_t *p = &teams[i].players[j];
            printf("  Player: %s, Kit: %d, Position: %s, Birth Date: %d-%d-%d\n",
                   p->name, p->kit_number, p->position,
                   p->birth_date.day, p->birth_date.month, p->birth_date.year);
        }
    }
}

void handle_error(char *message) {
    printf("Error: %s\n", message);
}
