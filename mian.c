#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEAMS 13
#define MAX_DRIVERS 26

#define ADMIN_PASSWORD "123456"

int i;

//Admin Login
int adminLogin()
{
    char enteredPwd[50];
    int attempts = 0;

    while(attempts < 3)
    {
        printf("\n=== ADMIN LOGIN ===\n");
        printf("Enter Admin Password: ");
        scanf(" %[^\n]", enteredPwd);

        if(strcmp(enteredPwd, ADMIN_PASSWORD) == 0)
        {
            printf("\nAccess Granted.\n");
            return 1;  // success
        }
        else
        {
            attempts++;
            printf("\nWrong Password. Attempts left: %d\n", 3 - attempts);
        }
    }

    printf("\nToo many failed attempts. Access Denied.\n");
    return 0;  // failed
}

//CASE 1:1: Register Team

//global variables
typedef struct {
    int id;
    char name[50];
    char team[50];
    char tire[20];
    int gridPosition;
    int points;
    int disqualified;
} Driver;

typedef struct Team {
  char teamName[50];   // Added team name here
  Driver driversQueue[2];
  char teamPwd[20];
} Team;

typedef struct TeamNode {
    Team data;
    struct TeamNode *next;
} TeamsQueue;

typedef struct DriverNode {
    Driver data;
    struct DriverNode *next;
} DriversQueue;

TeamsQueue *teamFront = NULL;
TeamsQueue *teamRear = NULL;

DriversQueue *driverFront = NULL;
DriversQueue *driverRear = NULL;


int teamsQRear = 0;
int driversQRear = 0;
int teamsQFront = 0;
int driversQFront = 0;

void preliminaryBid()
{
    int preBidIndex = 0, ch;
    int preDocBool = 0, preBidBool = 0;
    while(preBidIndex != 2)
    {
        printf("\nPreliminary Bid");
        printf("\n---------------");
        printf("\n1. Submit Documents: \n\ta) Signed Non-Disclosure Agreement (NDA)\n\tb) Proof of Corporate Identity & Ownership\n\tc) Relevant Experience & Capabilities Report"); //click one button to submit all three reports
        printf("\n2. Submit Bid Amount");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        if(ch==1)
        {
            if(preDocBool == 0) {
                preDocBool = 1;
                printf("\nDocuments Submitted Successfully\n");
                preBidIndex++;
            }
            else {
                printf("\nDocuments already submitted\n");
            }
        }
        else if (ch==2)
        {
            if(preBidBool == 1) printf("\nBid already submitted\n");
            else {
                printf("\nChoose Payment Method: \n1. SWIFT\n2. Bank Wire Transfer\n3. Wise\n");
                printf("\nEnter your choice: ");
                scanf("%d", &ch);
                if(ch>0 && ch<4 && preBidBool == 0) {
                    printf("\nEnter your choice: ");
                    scanf("%d", &ch);
                    printf("\nConfirm Payment: $20000?\n1. Yes\n2. No\n");
                    if (ch==1) {
                        preBidIndex++; preBidBool++;
                    }
                    else if(ch == 2)
                        printf("\nPayment Failed\n");
                    else
                        printf("\nInvalid Choice\n Payment Failed\n");
                }
            }
        }
        else printf("\nInvalid Choice\n");

        if(preBidIndex == 2) printf("\nPreliminary Bid Successful\n");
    }
}

void applicationProcess()
{
    int appIndex = 0, ch;
    int docSubmitted = 0, feePaid = 0;

    while(appIndex != 2)
    {
        printf("\nApplication Process");
        printf("\n-------------------");
        printf("\n1. Submit Documents:");
        printf("\n\ta) 5 Year Business Plan Document");
        printf("\n\tb) Proof of Funding Document");
        printf("\n\tc) Tech Infrastructure Report");
        printf("\n2. Pay Application Fee ($300000)");

        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            if(docSubmitted == 0)
            {
                docSubmitted = 1;
                appIndex++;
                printf("\nDocuments Submitted Successfully\n");
            }
            else
            {
                printf("\nDocuments already submitted\n");
            }
        }
        else if(ch == 2)
        {
            if(feePaid == 1)
            {
                printf("\nApplication fee already paid\n");
            }
            else
            {
                printf("\nChoose Payment Method:");
                printf("\n1. SWIFT");
                printf("\n2. Bank Wire Transfer");
                printf("\n3. Corporate Escrow Account");
                printf("\n4. Wise");

                printf("\n\nEnter your choice: ");
                scanf("%d", &ch);

                if(ch >= 1 && ch <= 4)
                {
                    int confirm;
                    printf("\nConfirm Payment: $300000?");
                    printf("\n1. Yes");
                    printf("\n2. No");
                    printf("\nEnter your choice: ");
                    scanf("%d", &confirm);

                    if(confirm == 1)
                    {
                        feePaid = 1;
                        appIndex++;
                        printf("\nPayment Successful\n");
                    }
                    else
                    {
                        printf("\nPayment Cancelled\n");
                    }
                }
                else
                {
                    printf("\nInvalid Payment Method\n");
                }
            }
        }
        else
        {
            printf("\nInvalid Choice\n");
        }

        if(appIndex == 2)
        {
            printf("\nApplication Process Completed Successfully\n");
        }
    }
}

void finalPayments()
{
    int lastPayIndex = 0;
    int antiPaid = 0, annualPaid = 0;
    int ch;

    while(lastPayIndex != 2)
    {
        printf("\nFinal Step\n----------\n1. Anti-Dilution Payment: 300M USD\n2. Annual Team Entry Fee: 26M USD");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            if(antiPaid)
            {
                printf("\nAnti-Dilution Payment already completed.\n");
            }
            else
            {
                printf("\nPayment Method:");
                printf("\n1. Corporate Escrow Account");
                printf("\n2. Bank Wire Transfer (Staged)");
                printf("\nEnter choice: ");
                scanf("%d", &ch);

                if(ch == 1 || ch == 2)
                {
                    int confirm;
                    printf("\nConfirm Payment: 300M USD?");
                    printf("\n1. Yes\n2. No\nEnter choice: ");
                    scanf("%d", &confirm);

                    if(confirm == 1)
                    {
                        antiPaid = 1;
                        lastPayIndex++;
                        printf("\nAnti-Dilution Payment Successful.\n");
                    }
                    else
                        printf("\nPayment Cancelled.\n");
                }
                else
                    printf("\nInvalid Payment Method.\n");
            }
        }
        else if(ch == 2)
        {
            if(annualPaid)
            {
                printf("\nAnnual Entry Fee already completed.\n");
            }
            else
            {
                printf("\nPayment Method:");
                printf("\n1. Corporate Escrow Account");
                printf("\n2. SWIFT");
                printf("\n3. Bank Wire Transfer (Staged)");
                printf("\nEnter choice: ");
                scanf("%d", &ch);

                if(ch >= 1 && ch <= 3)
                {
                    int confirm;
                    printf("\nConfirm Payment: 26M USD?");
                    printf("\n1. Yes\n2. No\nEnter choice: ");
                    scanf("%d", &confirm);

                    if(confirm == 1)
                    {
                        annualPaid = 1;
                        lastPayIndex++;
                        printf("\nAnnual Entry Fee Payment Successful.\n");
                    }
                    else
                        printf("\nPayment Cancelled.\n");
                }
                else
                    printf("\nInvalid Payment Method.\n");
            }
        }
        else
            printf("\nInvalid Choice.\n");

        if(lastPayIndex == 2)
            printf("\nAll Final Payments Completed Successfully.\n");
    }
}

int isDriverIDExists(int id) {
    DriversQueue *temp = driverFront;

    while (temp != NULL) {
        if (temp->data.id == id) {
            return 1;   // ID exists
        }
        temp = temp->next;
    }

    return 0;   // ID does NOT exist
}

void inputTeamDetails()
{
    if(teamsQRear >= MAX_TEAMS)
    {
        printf("\nMaximum team capacity reached (13 teams).\n");
        return;
    }

    if(driversQRear + 2 > MAX_DRIVERS)
    {
        printf("\nMaximum driver capacity reached (26 drivers).\n");
        return;
    }

    TeamsQueue *newTeamNode = (TeamsQueue*)malloc(sizeof(TeamsQueue));

    if(newTeamNode == NULL) {
        printf("Something Went Wrong! (Memory Allocation Failed! Server Memory is full.\nWe'll be repairing it soon.\n");
        return;
    }
    
    newTeamNode->next = NULL;

    printf("\nEnter Team Name: ");
    scanf(" %[^\n]", newTeamNode->data.teamName);

    printf("\nEnter Team Password: ");
    scanf(" %[^\n]", newTeamNode->data.teamPwd);

    for(int i = 0; i < 2; i++)
    {
        DriversQueue *newDriverNode = (DriversQueue*)malloc(sizeof(DriversQueue));
        newDriverNode->next = NULL;

        printf("\nEnter details for Driver %d\n", i + 1);

        do {
            printf("Driver ID: ");
            scanf("%d", &newDriverNode->data.id);

            if (isDriverIDExists(newDriverNode->data.id)) {
                printf("ID Already exists.\nEnter a different Driver ID:\n");
            }

        } while (isDriverIDExists(newDriverNode->data.id));

        printf("Driver Name: ");
        scanf(" %[^\n]", newDriverNode->data.name);

        strcpy(newDriverNode->data.team, newTeamNode->data.teamName);

        newTeamNode->data.driversQueue[i] = newDriverNode->data;

        // ENQUEUE driver
        if(driverFront == NULL)
            driverFront = driverRear = newDriverNode;
        else {
            driverRear->next = newDriverNode;
            driverRear = newDriverNode;
        }

        driversQRear++;
    }

    finalPayments();

    // ENQUEUE team
    if(teamFront == NULL)
        teamFront = teamRear = newTeamNode;
    else {
        teamRear->next = newTeamNode;
        teamRear = newTeamNode;
    }

    teamsQRear++;

    printf("\nTeam and Drivers Registered Successfully!\n");
    printf("\nTeam Name: %s\n", newTeamNode->data.teamName);
    printf("Drivers:\n");
    for(int i = 0; i < 2; i++) {
        printf("\tID: %d, Name: %s\n",
               newTeamNode->data.driversQueue[i].id,
               newTeamNode->data.driversQueue[i].name);}
}

void RegTeam() {
    preliminaryBid();
    applicationProcess();
    inputTeamDetails();
}

//CASE 2:1 Team Selection
void teamQDetails()
{
    printf("\nDisplaying Team Details");
    printf("\n----------------------");

    TeamsQueue *temp = teamFront;
    int count = 1;

    if(teamFront == NULL)
    {
        printf("\nNo teams registered.\n");
        return;
    }

    while(temp != NULL)
    {
        printf("\nTeam %d: %s\n", count, temp->data.teamName);
        printf("\tDriver 1 - ID: %d | Name: %s\n",
               temp->data.driversQueue[0].id,
               temp->data.driversQueue[0].name);
        printf("\tDriver 2 - ID: %d | Name: %s\n",
               temp->data.driversQueue[1].id,
               temp->data.driversQueue[1].name);

        temp = temp->next;
        count++;
    }

    int ch = 0;
    while(ch != 1) {
        printf("\n\nType 1 to go back: ");
        scanf("%d", &ch);
    }
}

Team selectedTeams[MAX_TEAMS];
Driver selectedDrivers[MAX_DRIVERS];
int teamCount = 0;
int driverCount = 0;

void selectTeam()
{
    int ch = 0;
    printf("\nSelect Team\n");
    printf("------------\n");

    while(ch != 3)
    {
        if(teamFront == NULL)
        {
            printf("\nNo teams in queue.\n");
            return;
        }

        printf("\nTeam: %s\n", teamFront->data.teamName);
        printf("\n\tDriver 1 - %s\n",
               teamFront->data.driversQueue[0].name);
        printf("\n\tDriver 2 - %s\n",
               teamFront->data.driversQueue[1].name);

        printf("\n1. Approve\n2. Refuse\n3. Back\nEnter your choice: ");
        scanf("%d", &ch);

        if(ch == 1 || ch == 2)
        {
            if(ch == 1)
            {
                printf("\nTeam Approved\n");
                selectedTeams[teamCount++] = teamFront->data;
            }
            else
            {
                printf("\nTeam Refused\n");
            }

            // REMOVE team (DEQUEUE)
            TeamsQueue *tempTeam = teamFront;
            teamFront = teamFront->next;
            if(teamFront == NULL)
                teamRear = NULL;

            free(tempTeam);
            teamsQRear--;

            // REMOVE 2 drivers from driver queue
            for(int i = 0; i < 2; i++)
            {
                if(driverFront != NULL)
                {
                    DriversQueue *tempDriver = driverFront;
                    if(ch == 1)
                        selectedDrivers[driverCount++] = tempDriver->data;

                    driverFront = driverFront->next;
                    if(driverFront == NULL)
                        driverRear = NULL;

                    free(tempDriver);
                    driversQRear--;
                }
            }
        }
        else if(ch == 3)
        {
            printf("\nGoing Back ...\n");
        }
        else
        {
            printf("\nInvalid Choice\n");
        }
    }
}

void TeamSelection()
{
    int ch = 0;
    while(ch!=3) {
        printf("\n1. Team Queue Details\n2. Select Team\n3. Go Back\nEnter your choice: ");
        scanf("%d", &ch);
        if(ch==1) teamQDetails();
        else if(ch==2) selectTeam();
        else if(ch==3) printf("Exiting...");
        else printf("\nInvalid Choice\n");
    }
}

//CASE 2:2 Setup Schedule
#define MAX_ROUNDS 20   // maximum allowed rounds per race

typedef struct {
    char place[50];
    char qualiTime[30];
    char raceTime[30];
} Round;

typedef struct RaceNode {
    int raceID;
    int totalRounds;
    Round rounds[MAX_ROUNDS];
    struct RaceNode *next;
} RaceNode;

RaceNode *raceHead = NULL;
RaceNode *raceTail = NULL;
int raceCounter = 1;

int currentRaceID = 0;
int currentRoundIndex = 0;
int gameOver = 0;      // 0 = race ongoing, 1 = race finished
int qualiCompleted = 0;
int raceCompleted = 0;

void addRace()
{
    RaceNode *newRace = (RaceNode*)malloc(sizeof(RaceNode));
    if(newRace == NULL) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newRace->raceID = raceCounter++;
    newRace->totalRounds = 5;  // 1 test + 4 normal
    newRace->next = NULL;

    printf("\n=== ADD NEW RACE ===\n");

    // TEST ROUND
    printf("\nTest Round\n------------\n");
    printf("Enter Place: ");
    scanf(" %[^\n]", newRace->rounds[0].place);
    printf("Enter Qualifying Stage Time: ");
    scanf(" %[^\n]", newRace->rounds[0].qualiTime);
    printf("Enter Race Time: ");
    scanf(" %[^\n]", newRace->rounds[0].raceTime);

    // ROUND 1–4
    for(int i = 1; i < 5; i++)
    {
        printf("\nRound %d\n---------\n", i);
        printf("Enter Place: ");
        scanf(" %[^\n]", newRace->rounds[i].place);
        printf("Enter Qualifying Stage Time: ");
        scanf(" %[^\n]", newRace->rounds[i].qualiTime);
        printf("Enter Race Time: ");
        scanf(" %[^\n]", newRace->rounds[i].raceTime);
    }

    // ENQUEUE race
    if(raceHead == NULL)
        raceHead = raceTail = newRace;
    else {
        raceTail->next = newRace;
        raceTail = newRace;
    }

    printf("\nRace Added Successfully!\n");
}

void viewRounds(RaceNode *race)
{
    printf("\nRace ID: %d\n", race->raceID);
    printf("------------------------\n");

    for(int i = 0; i < race->totalRounds; i++)
    {
        if(i == 0)
            printf("\nTest Round\n");
        else
            printf("\nRound %d\n", i);

        printf("Place: %s\n", race->rounds[i].place);
        printf("Qualifying Time: %s\n", race->rounds[i].qualiTime);
        printf("Race Time: %s\n", race->rounds[i].raceTime);
    }
}

void SetupSchedule()
{
    int ch = 0;

    while(ch != 6)
    {
        printf("\n=== SETUP SCHEDULE ===\n");
        printf("1. Add Race\n");
        printf("2. View Races\n");
        printf("3. Add Round\n");
        printf("4. Delete Round\n");
        printf("5. Modify Round\n");
        printf("6. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            addRace();
        }
        else if(ch == 2)
        {
            RaceNode *temp = raceHead;
            if(temp == NULL)
            {
                printf("\nNo Races Scheduled Yet.\n");
            }
            while(temp != NULL)
            {
                viewRounds(temp);
                temp = temp->next;
            }
        }
        else if(ch >= 3 && ch <= 5)
        {
            if(raceHead == NULL)
            {
                printf("\nNo Races Available.\n");
                continue;
            }

            int id;
            printf("\nEnter Race ID: ");
            scanf("%d", &id);

            RaceNode *temp = raceHead;
            while(temp != NULL && temp->raceID != id)
                temp = temp->next;

            if(temp == NULL)
            {
                printf("\nRace Not Found.\n");
                continue;
            }

            if(ch == 3)
            {
                if(temp->totalRounds >= MAX_ROUNDS)
                {
                    printf("\nMaximum Rounds Reached.\n");
                    continue;
                }

                int i = temp->totalRounds;
                printf("\nAdding Round %d\n", i);
                printf("Enter Place: ");
                scanf(" %[^\n]", temp->rounds[i].place);
                printf("Enter Qualifying Time: ");
                scanf(" %[^\n]", temp->rounds[i].qualiTime);
                printf("Enter Race Time: ");
                scanf(" %[^\n]", temp->rounds[i].raceTime);

                temp->totalRounds++;
                printf("\nRound Added Successfully.\n");
            }
            else if(ch == 4)
            {
                int r;
                printf("\nEnter Round Number to Delete: ");
                scanf("%d", &r);

                if(r <= 0 || r >= temp->totalRounds)
                {
                    printf("\nInvalid Round Number.\n");
                    continue;
                }

                for(int i = r; i < temp->totalRounds - 1; i++)
                {
                    temp->rounds[i] = temp->rounds[i + 1];
                }

                temp->totalRounds--;
                printf("\nRound Deleted Successfully.\n");
            }
            else if(ch == 5)
            {
                int r;
                printf("\nEnter Round Number to Modify: ");
                scanf("%d", &r);

                if(r < 0 || r >= temp->totalRounds)
                {
                    printf("\nInvalid Round Number.\n");
                    continue;
                }

                printf("Enter New Place: ");
                scanf(" %[^\n]", temp->rounds[r].place);
                printf("Enter New Qualifying Time: ");
                scanf(" %[^\n]", temp->rounds[r].qualiTime);
                printf("Enter New Race Time: ");
                scanf(" %[^\n]", temp->rounds[r].raceTime);

                printf("\nRound Modified Successfully.\n");
            }
        }
        else if(ch == 6)
        {
            printf("\nReturning to Admin Menu...\n");
        }
        else
        {
            printf("\nInvalid Choice\n");
        }
    }
}

// ================= QUALIFICATION BST =================

typedef struct QualiNode {
    char teamName[50];
    char driver1[50];
    char driver2[50];
    float lapTime;
    struct QualiNode *left;
    struct QualiNode *right;
} QualiNode;

QualiNode *qualiRoot = NULL;

QualiNode* createQualiNode(char team[], char d1[], char d2[], float time)
{
    QualiNode *newNode = (QualiNode*)malloc(sizeof(QualiNode));
    strcpy(newNode->teamName, team);
    strcpy(newNode->driver1, d1);
    strcpy(newNode->driver2, d2);
    newNode->lapTime = time;
    newNode->left = newNode->right = NULL;
    return newNode;
}

QualiNode* insertQuali(QualiNode *root, char team[], char d1[], char d2[], float time)
{
    if(root == NULL)
        return createQualiNode(team, d1, d2, time);

    if(time < root->lapTime)
        root->left = insertQuali(root->left, team, d1, d2, time);
    else
        root->right = insertQuali(root->right, team, d1, d2, time);

    return root;
}

int gridPosition = 1;

void displayGrid(QualiNode *root)
{
    if(root == NULL)
        return;

    displayGrid(root->left);

    printf("\nPosition %d", gridPosition++);
    printf("\nTeam: %s", root->teamName);
    printf("\nDrivers: %s & %s", root->driver1, root->driver2);
    printf("\nLap Time: %.3f\n", root->lapTime);
    printf("-------------------------");

    displayGrid(root->right);
}

void freeQualiTree(QualiNode *root)
{
    if(root == NULL)
        return;

    freeQualiTree(root->left);
    freeQualiTree(root->right);
    free(root);
}

void Qualification()
{
    if(raceHead == NULL)
    {
        printf("\nNo Race Scheduled.\n");
        return;
    }

    if(qualiCompleted == 1)
    {
        printf("\nQualification Already Completed For This Round.\n");
        return;
    }

    if(teamCount == 0)
    {
        printf("\nNo Teams Selected Yet.\n");
        return;
    }

    printf("\n=== QUALIFICATION STAGE ===\n");

    qualiRoot = NULL;
    gridPosition = 1;

    for(int i = 0; i < teamCount; i++)
    {
        float lap;
        printf("\nEnter Qualifying Lap Time For Team %s: ",
               selectedTeams[i].teamName);
        scanf("%f", &lap);

        qualiRoot = insertQuali(
            qualiRoot,
            selectedTeams[i].teamName,
            selectedTeams[i].driversQueue[0].name,
            selectedTeams[i].driversQueue[1].name,
            lap
        );
    }

    printf("\n=== STARTING GRID ===\n");
    gridPosition = 1;
    displayGrid(qualiRoot);
    freeQualiTree(qualiRoot);
    qualiRoot = NULL;

    qualiCompleted = 1;

    printf("\nQualification Completed Successfully.\n");
}

// ================= TIRE STACK =================

typedef struct TireNode {
    char tireType[20];
    struct TireNode *next;
} TireNode;

typedef struct {
    TireNode *top;
} TireStack;

TireStack driverTireStacks[MAX_DRIVERS];

void pushTire(int driverIndex, char tire[])
{
    TireNode *newNode = (TireNode*)malloc(sizeof(TireNode));
    strcpy(newNode->tireType, tire);
    newNode->next = driverTireStacks[driverIndex].top;
    driverTireStacks[driverIndex].top = newNode;
}

void displayTireHistory(int driverIndex)
{
    TireNode *temp = driverTireStacks[driverIndex].top;
    printf("Tire History: ");
    while(temp != NULL)
    {
        printf("%s -> ", temp->tireType);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ================= PRIORITY QUEUE =================

typedef struct ResultNode {
    Driver driver;
    float totalTime;
    struct ResultNode *next;
} ResultNode;

ResultNode *resultHead = NULL;

void insertResult(Driver d, float time)
{
    ResultNode *newNode = (ResultNode*)malloc(sizeof(ResultNode));
    newNode->driver = d;
    newNode->totalTime = time;
    newNode->next = NULL;

    if(resultHead == NULL || time < resultHead->totalTime)
    {
        newNode->next = resultHead;
        resultHead = newNode;
        return;
    }

    ResultNode *temp = resultHead;
    while(temp->next != NULL && temp->next->totalTime < time)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

int pointsTable[10] = {25,18,15,12,10,8,6,4,2,1};

void LiveRaceInput()
{
    if(teamCount == 0)
    {
        printf("\nNo Teams Selected.\n");
        return;
    }

    if(qualiCompleted == 0)
    {
        printf("\nQualification Not Completed Yet.\n");
        return;
    }

    if(raceCompleted == 1)
    {
        printf("\nRace Already Completed.\n");
        return;
    }

    printf("\n=== LIVE RACE INPUT ===\n");

    resultHead = NULL;

    // Initialize tire stacks
    for(int i = 0; i < driverCount; i++)
        driverTireStacks[i].top = NULL;

    float fastestLap = 999999;
    int fastestDriverIndex = -1;

    for(int i = 0; i < driverCount; i++)
    {
        float totalTime;
        float lap;

        printf("\nDriver: %s (%s)\n",
               selectedDrivers[i].name,
               selectedDrivers[i].team);

        printf("Enter Total Race Time: ");
        scanf("%f", &totalTime);

        printf("Enter Fastest Lap Time: ");
        scanf("%f", &lap);

        if(lap < fastestLap)
        {
            fastestLap = lap;
            fastestDriverIndex = i;
        }

        int tireChanges;
        printf("Number of Tire Changes: ");
        scanf("%d", &tireChanges);

        for(int t = 0; t < tireChanges; t++)
        {
            char tire[20];
            printf("Enter Tire Type: ");
            scanf(" %[^\n]", tire);
            pushTire(i, tire);
        }

        insertResult(selectedDrivers[i], totalTime);
    }

    printf("\n=== RACE RESULTS ===\n");

    ResultNode *temp = resultHead;
    int position = 0;

    while(temp != NULL)
    {
        printf("\nPosition %d", position + 1);
        printf("\nDriver: %s", temp->driver.name);
        printf("\nTeam: %s", temp->driver.team);
        printf("\nTotal Time: %.2f\n", temp->totalTime);

        // Update original driver array
        for(int i = 0; i < driverCount; i++)
        {
            if(strcmp(selectedDrivers[i].name, temp->driver.name) == 0)
            {
                if(position < 10)
                    selectedDrivers[i].points += pointsTable[position];
            }
        }

        position++;
        temp = temp->next;
    }

    if(fastestDriverIndex != -1)
    {
        selectedDrivers[fastestDriverIndex].points += 1;
        printf("\nFastest Lap: %s (+1 Point)\n",
               selectedDrivers[fastestDriverIndex].name);
    }

    raceCompleted = 1;
    gameOver = 1;

    printf("\nRace Completed Successfully.\n");
}

//penalty
#define MAX_BANNED 20

Team bannedTeams[MAX_BANNED];
int bFront = -1, bRear = -1;

void ApplyPenalty()
{
    char name[50];
    int choice;

    printf("\nEnter Driver Name: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < driverCount; i++)
    {
        if(strcmp(selectedDrivers[i].name, name) == 0)
        {
            printf("\n1. Deduct Points");
            printf("\n2. Add Time Penalty");
            printf("\nChoice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                int pts;
                printf("Enter Points to Deduct: ");
                scanf("%d", &pts);
                selectedDrivers[i].points -= pts;
            }
            else if(choice == 2)
            {
                printf("Time penalty recorded (visual only).\n");
            }

            printf("Penalty Applied Successfully.\n");
            return;
        }
    }

    printf("Driver Not Found.\n");
}

void DisqualifyDriver()
{
    char name[50];

    printf("\nEnter Driver Name to Disqualify: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < driverCount; i++)
    {
        if(strcmp(selectedDrivers[i].name, name) == 0)
        {
            selectedDrivers[i].disqualified = 1;
            printf("Driver Disqualified.\n");
            return;
        }
    }

    printf("Driver Not Found.\n");
}

void BanTeam(Team t)
{
    if((bRear + 1) % MAX_BANNED == bFront)
    {
        printf("Ban List Full.\n");
        return;
    }

    if(bFront == -1)
        bFront = 0;

    bRear = (bRear + 1) % MAX_BANNED;
    bannedTeams[bRear] = t;

    printf("Team Banned Successfully.\n");
}

void DisqualifyTeam()
{
    char name[50];

    printf("Enter Team Name to Ban: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < teamCount; i++)
    {
        if(strcmp(selectedTeams[i].teamName, name) == 0)
        {
            BanTeam(selectedTeams[i]);
            printf("Team Removed From Championship.\n");
            return;
        }
    }

    printf("Team Not Found.\n");
}

void ResetRaceState()
{
    qualiCompleted = 0;
    raceCompleted = 0;
    gameOver = 0;
    resultHead = NULL;
    qualiRoot = NULL;

    printf("\nSystem Ready For Next Round.\n");
}

void RaceControlPanel()
{
    int ch = 0;

    while(ch != 5)
    {
        printf("\n=== RACE CONTROL ===");
        printf("\n1. Apply Penalty");
        printf("\n2. Disqualify Driver");
        printf("\n3. Ban Team");
        printf("\n4. Reset Round");
        printf("\n5. Back");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: ApplyPenalty(); break;
            case 2: DisqualifyDriver(); break;
            case 3: DisqualifyTeam(); break;
            case 4: ResetRaceState(); break;
        }
    }
}

//user part

void Schedules()
{
    if(raceHead == NULL)
    {
        printf("\nNo Races Scheduled Yet.\n");
        return;
    }

    RaceNode *temp = raceHead;

    printf("\n=== RACE SCHEDULES ===\n");

    while(temp != NULL)
    {
        printf("\nRace ID: %d\n", temp->raceID);

        for(int i = 0; i < temp->totalRounds; i++)
        {
            if(i == 0)
                printf("\nTest Round\n");
            else
                printf("\nRound %d\n", i);

            printf("Place: %s\n", temp->rounds[i].place);
            printf("Quali Time: %s\n", temp->rounds[i].qualiTime);
            printf("Race Time: %s\n", temp->rounds[i].raceTime);
        }

        printf("\n---------------------------\n");
        temp = temp->next;
    }
}

void Results()
{
    if(driverCount == 0)
    {
        printf("\nNo Results Available Yet.\n");
        return;
    }

    // Create temp copy for sorting
    Driver tempDrivers[MAX_DRIVERS];
    for(int i = 0; i < driverCount; i++)
        tempDrivers[i] = selectedDrivers[i];

    // Bubble sort by points descending
    for(int i = 0; i < driverCount - 1; i++)
    {
        for(int j = 0; j < driverCount - i - 1; j++)
        {
            if(tempDrivers[j].points < tempDrivers[j+1].points)
            {
                Driver t = tempDrivers[j];
                tempDrivers[j] = tempDrivers[j+1];
                tempDrivers[j+1] = t;
            }
        }
    }

    printf("\n=== CHAMPIONSHIP STANDINGS ===\n");

    for(int i = 0; i < driverCount; i++)
    {
        printf("\nPosition %d", i+1);
        printf("\nDriver: %s", tempDrivers[i].name);
        printf("\nTeam: %s", tempDrivers[i].team);
        printf("\nPoints: %d\n", tempDrivers[i].points);
        printf("-------------------------");
    }

    if(driverCount > 0)
    {
        printf("\n🏆 Championship Leader: %s (%d pts)\n",
               tempDrivers[0].name,
               tempDrivers[0].points);
    }
}

void TeamDashboard()
{
    char teamName[50];

    printf("\nEnter Team Name: ");
    scanf(" %[^\n]", teamName);

    for(int i = 0; i < teamCount; i++)
    {
        if(strcmp(selectedTeams[i].teamName, teamName) == 0)
        {
            printf("\n=== TEAM DASHBOARD ===\n");
            printf("Team: %s\n", selectedTeams[i].teamName);

            for(int d = 0; d < driverCount; d++)
            {
                if(strcmp(selectedDrivers[d].team, teamName) == 0)
                {
                    printf("\nDriver: %s", selectedDrivers[d].name);
                    printf("\nPoints: %d", selectedDrivers[d].points);

                    if(selectedDrivers[d].disqualified)
                        printf("\nStatus: DISQUALIFIED");
                    else
                        printf("\nStatus: Active");

                    printf("\n");
                    displayTireHistory(d);
                    printf("---------------------");
                }
            }
            return;
        }
    }

    printf("Team Not Found.\n");
}

void TeamModification()
{
    char teamName[50], pwd[50];

    printf("\nEnter Team Name: ");
    scanf(" %[^\n]", teamName);

    for(int i = 0; i < teamCount; i++)
    {
        if(strcmp(selectedTeams[i].teamName, teamName) == 0)
        {
            printf("Enter Team Password: ");
            scanf(" %[^\n]", pwd);

            if(strcmp(selectedTeams[i].teamPwd, pwd) != 0)
            {
                printf("Wrong Password.\n");
                return;
            }

            int ch;
            printf("\n1. Change Team Name");
            printf("\n2. Change Driver Name");
            printf("\nChoice: ");
            scanf("%d", &ch);

            if(ch == 1)
            {
                printf("Enter New Team Name: ");
                scanf(" %[^\n]", selectedTeams[i].teamName);
                printf("Team Name Updated.\n");
            }
            else if(ch == 2)
            {
                char oldName[50];
                printf("Enter Driver Name: ");
                scanf(" %[^\n]", oldName);

                for(int d = 0; d < driverCount; d++)
                {
                    if(strcmp(selectedDrivers[d].name, oldName) == 0 &&
                       strcmp(selectedDrivers[d].team, teamName) == 0)
                    {
                        printf("Enter New Name: ");
                        scanf(" %[^\n]", selectedDrivers[d].name);
                        printf("Driver Updated.\n");
                        return;
                    }
                }

                printf("Driver Not Found.\n");
            }

            return;
        }
    }

    printf("Team Not Found.\n");
}

//--- MAIN FUNCTION ---
int main() 
{
    int choice;
    int inCh = 0;

    do 
    {
        printf("\nBelgian GRAN PRIX");
        printf("\n-----------------");
        printf("\n1. User\n2. Admin\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            inCh = 0;
            while(inCh != 6) {
                printf("\nMenu\n----\n");
                printf("1. Register Your Team");
                printf("\n2. Schedules");
                printf("\n3. Team Dashboard");
                printf("\n4. Results");
                printf("\n5. Team Modification");
                printf("\n6. Back");
                printf("\nEnter your choice: ");
                scanf("%d", &inCh);

                switch(inCh) {
                    case 1:
                        RegTeam();
                        break;
                    case 2:
                        Schedules();
                        break;
                    case 3:
                        TeamDashboard();
                        break;
                    case 4:
                        Results();
                        break;
                    case 5:
                        TeamModification();
                        break;
                    case 6:
                        break;
                    default:
                        printf("\nInvalid Choice\n");
                }
            }
            break;

            case 2: {
                if(!adminLogin()) {
                    printf("\nReturning to Main Menu...\n");
                    break;
                }

                inCh = 0;
                while(inCh != 6) {
                    printf("\nAdmin Menu\n-----------\n");
                    printf("1. Team Selection");
                    printf("\n2. Setup Schedule");
                    printf("\n3. Qualifying Stage");
                    printf("\n4. Live Race Input");
                    printf("\n5. Penalty and Disqualification");
                    printf("\n6. Back");
                    printf("\nEnter your choice: ");
                    scanf("%d", &inCh);

                    switch(inCh) {
                        case 1:
                            TeamSelection();
                            break;
                        case 2:
                            SetupSchedule();
                            break;
                        case 3:
                            Qualification();
                            break;
                        case 4:
                            LiveRaceInput();
                            break;
                        case 5:
                            RaceControlPanel();
                            break;
                        case 6:
                            break;
                        default:
                            printf("\nInvalid Choice\n");
                    }
                }
                break;
            }

            case 3:
                printf("Bye!");
                break;
        }
    } while(choice!=3);

    return 0;
}