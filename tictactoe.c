#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int displayUser();
int selectUser(int* player1, int* player2);
int createUser();
int deleteUser();
void appendRecord(int winner, int loser, int win1, int win2);
void checkName(char name[], int num);
void searchUser();
void initializeFile();
void menuSelection(int *player1, int *player2);
struct playerData {
	char username[15];
	int wins;
	int loses;
};

int main()
{
	
int x,y,a,b,i,W,ps1=0,ps2=0, user1 = -1, user2 = -1;
char re, name1[15], name2[15];
char arr2d[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};

printf("Welcome to the Tic Tac Toe machine! \nTwo players take turns entering coordinates to indicate which square they want. \nPlayer 1 is represented by 'O' and player 2 is represented by 'X'. \nThe coordinates are two numbers from 1 to 3 that represent a square on the board. \nThe first number is for lines and the second is for collumns.\nFor example the middle right square would be written as : 2 3\n\n");

menuSelection(&user1, &user2);
checkName(name1, user1);
checkName(name2, user2);

start:
	system("cls");
	printf("The current scores are:\n%s: %d   |   %s: %d\n\n", name1,ps1,name2,ps2);
	for(x=0;x<3;x++)
	{
		for(y=0;y<3;y++)
		{
			arr2d[x][y]='-';
		}
	}
	W=0;
	i=0;
tie:
while(i<9)
{
	for(x=0;x<3;x++)
	{
		for(y=0;y<3;y++)
		{
			printf("[%c]",arr2d[x][y]);
		}
	printf("\n");
	}
	player1:
		printf("\n");
		printf("%s enter coordinates : ", name1);
		scanf("%d %d",&a,&b);
		if(arr2d[a-1][b-1]=='O'||arr2d[a-1][b-1]=='X'||a>3||a<1||b>3||b<1)
		{
			printf("Invalid move");
			goto player1;
		}
		system("cls");
		printf("The current scores are:\n%s: %d   |   %s: %d\n\n", name1,ps1,name2,ps2);
		arr2d[a-1][b-1]='O';
		for(x=0;x<3;x++)
			{
				for(y=0;y<3;y++)
				{
					printf("[%c]",arr2d[x][y]);
				}
			printf("\n");

			}
		i++;
		//horizontal
		if((arr2d[0][0]=='O'&&arr2d[0][1]=='O'&&arr2d[0][2]=='O')||(arr2d[1][0]=='O'&&arr2d[1][1]=='O'&&arr2d[1][2]=='O')||(arr2d[2][0]=='O'&&arr2d[2][1]=='O'&&arr2d[2][2]=='O'))
		{
			W=1;
			goto endings;
		}
		//vertical
		if((arr2d[0][0]=='O'&&arr2d[1][0]=='O'&&arr2d[2][0]=='O')||(arr2d[0][1]=='O'&&arr2d[1][1]=='O'&&arr2d[2][1]=='O')||(arr2d[0][2]=='O'&&arr2d[1][2]=='O'&&arr2d[2][2]=='O'))
		{
			W=1;
			goto endings;
		}
		//diagonal
		if((arr2d[0][0]=='O'&&arr2d[1][1]=='O'&&arr2d[2][2]=='O')||(arr2d[0][2]=='O'&&arr2d[1][1]=='O'&&arr2d[2][0]=='O'))
		{
			W=1;
			goto endings;
		}
		if(i>=9)
		{
			goto tie;
		}
	player2:
		printf("\n");
		printf("%s enter coordinates : ", name2);
		scanf("%d %d",&a,&b);
		if(arr2d[a-1][b-1]=='O'||arr2d[a-1][b-1]=='X'||a>3||a<1||b>3||b<1)
		{
			printf("Invalid move");
			goto player2;
		}
		system("cls");
		printf("The current scores are:\n%s: %d   |   %s: %d\n\n", name1,ps1,name2,ps2);
		arr2d[a-1][b-1]='X';
		i++;
		//horizontal
		if((arr2d[0][0]=='X'&&arr2d[0][1]=='X'&&arr2d[0][2]=='X')||(arr2d[1][0]=='X'&&arr2d[1][1]=='X'&&arr2d[1][2]=='X')||(arr2d[2][0]=='X'&&arr2d[2][1]=='X'&&arr2d[2][2]=='X'))
		{
			W=2;
			goto endings;
		}
		//vertical
		if((arr2d[0][0]=='X'&&arr2d[1][0]=='X'&&arr2d[2][0]=='X')||(arr2d[0][1]=='X'&&arr2d[1][1]=='X'&&arr2d[2][1]=='X')||(arr2d[0][2]=='X'&&arr2d[1][2]=='X'&&arr2d[2][2]=='X'))
		{
			W=2;
			goto endings;
		}
		//diagonal
		if((arr2d[0][0]=='X'&&arr2d[1][1]=='X'&&arr2d[2][2]=='X')||(arr2d[0][2]=='X'&&arr2d[1][1]=='X'&&arr2d[2][0]=='X'))
		{
			W=2;
			goto endings;
		}
}
		endings: 
		if(W==1)
		{
			ps1=ps1+1;
		}
		else if(W==2)
		{
			ps2=ps2+1;
		}
		system("cls");
		printf("The current scores are:\n%s: %d   |   %s: %d\n\n", name1,ps1,name2,ps2);
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				printf("[%c]",arr2d[x][y]);
			}
			printf("\n");
		} 
	printf("\n");
		if(W==1)
		{
			printf("%s wins\n", name1);
		}
		else if(W==2)
		{
			printf("%s wins\n", name2);
		}
		else
		{
			printf("It's a draw\n");
		}
		
		printf("\nWould you like to go again?\n");
		retry:	
		scanf("%c",&re);
		if(re=='Y'||re=='y')
		{
		printf("\n");
		goto start;
		}
		else if(re=='N'||re=='n')
		goto end;
		else
		{
		printf("Please enter 'Y' or 'N'\n");
		goto retry;	
		}
	end:
		system("cls");
		printf("The final scores are:\n%s: %d   |   %s: %d\n",name1,ps1,name2,ps2);
		if(ps1>ps2)
		{
			printf("%s is the winner of this session!", name1);	
		}
		else if(ps1<ps2)
		{
			printf("%s is the winner of this session!", name2);
		}
		else
		{
			printf("it's a tie!");
		}
		
		//append record
		appendRecord(user1, user2, ps1, ps2);
			
	return 0;
}

int selectUser(int* player1, int* player2) {
	FILE* fp;
	fp = fopen("ticdata.txt", "r");
	int i = 1, numUsers, w, l, play1, play2;
	
	if (fp == NULL) {
		initializeFile();
    }
    
    fscanf(fp, "%d", &numUsers);
    fgetc(fp);
    
	if (numUsers < 2) {
		fclose(fp);
		printf("! Users inadequate, please create user\n");
		createUser();
	}
        
	displayUser(1);
	
	back:
	printf("\nFirst player: ");
	scanf("%d", &play1);
	if (play1 > numUsers) {
		printf("! Please pick a valid number\n");
		goto back;
	}
	
	back2:
	printf("Second player: ");
	scanf("%d", &play2);
	if (play2 > numUsers) {
		printf("! Please pick a valid number\n");
		goto back2;
	}
	else if (play2 == play1) {
		printf("! Please pick a different user\n");
		goto back2;
	}
	
	*player1 = play1;
	*player2 = play2;
	
	fclose(fp);
	printf("\n");
	return 0;
}

int createUser() {
	char name[15], yn = 'Y'; int numUsers;
	
	FILE* fp;
	fp = fopen("ticdata.txt", "r+");
	
	if (fp == NULL) {
		initializeFile();
    }	
	
	printf("[ User Creation ]\n");
	fscanf(fp, "%d", &numUsers);

	maxUser:
	if (numUsers == 10) {
		printf("! Maximum ammount of users has been reached\n");
		printf("! Delete a user to create a new one\n\n");
		return 0;
	}
	
	create:
	printf("Username: ");
	scanf(" %14[^\n]", name);
	numUsers++;
	
    fseek(fp, 0, SEEK_SET);
    fprintf(fp, "%d\n", numUsers);
    
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "%s#0#0\n", name);
    
    printf("Do you want to create another user? [Y/N] ");
    scanf(" %c%*c", &yn);
    yn = (toupper(yn));
    	
    if (yn == 'Y' && numUsers == 10) {
    	goto maxUser;
	}
	else if (yn == 'Y') {
		goto create;
	}
	else if (numUsers < 2) {
		printf("Please create one more user to play\n");
		goto create;
	}
	printf("< Code exited to implement changes >");
	fclose(fp);
	exit(0);
}

int displayUser(int method) {
    FILE* fp;
    fp = fopen("ticdata.txt", "r");
	if (fp == NULL) {
		initializeFile();
    }

    struct playerData list[10];
    struct playerData tempUser;
    int numUsers, i, j, k = 0;
    char temp[15];
    
    fscanf(fp, "%d", &numUsers);

	printf("[ Players list ]\n");
    printf("No.   User                Record\n");
    printf("--------------------------------\n");
    while (fscanf(fp, " %14[^#]#%d#%d", &list[k].username, &list[k].wins, &list[k].loses) == 3) {
        k++;
    }
	
	if (method == 2) {
		// sort berdasarkan rank dan alfabet
	    for (i = 0; i < numUsers; i++) {
	        for (j = 0; j < numUsers - i - 1; j++) {
	            if ((list[j].wins - list[j].loses) < (list[j + 1].wins - list[j+1].loses) ||
				((list[j].wins - list[j].loses) == (list[j + 1].wins - list[j+1].loses)
				&& strcmp(list[j].username, list[j + 1].username) > 0)) {
		                tempUser = list[j + 1];
		                list[j + 1] = list[j];
		                list[j] = tempUser;
	            }
	        }
	    }
	}

    for (i = 0; i < numUsers; i++) {
    	printf("%d", i + 1);
    	if (i == 10) {
    		printf("    ");
		}
		else {
			printf("     ");
		}
        printf("%-20s", list[i].username);
        printf("%d-%d\n", list[i].wins, list[i].loses);
    }
	
	printf("\n");
    fclose(fp);
    return 0;
}

int deleteUser() {
	FILE *fp = fopen("ticdata.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

	if (fp == NULL) {
		initializeFile();
    }
    
    char name[15];
    int numUsers, win, lose, deleteNum, i = 1;
    
    fscanf(fp, "%d", &numUsers);
    
    displayUser(1);
    
    printf("User number to be deleted: ");
    scanf("%d", &deleteNum);

	fprintf(temp, "%d\n", numUsers - 1);
	
    while (fscanf(fp, "%14[^#]#%d#%d", name, &win, &lose) == 3) {
        if (i != deleteNum) {
            fprintf(temp, "%s#%d#%d\n", name, win, lose);
        }
        i++;
    }

    fclose(fp);
    fclose(temp);

    remove("ticdata.txt");
    rename("temp.txt", "ticdata.txt");

	printf("< Code exited to implement changes >");
	exit(0);
}

void appendRecord(int user1, int user2, int win1, int win2) {
    FILE* fp = fopen("ticdata.txt", "r");
    
    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    int i, numUsers, k = 0;
    fscanf(fp, "%d", &numUsers);

    struct playerData playerList[10];

    while (fscanf(fp, "%14[^#]#%d#%d", &playerList[k].username, &playerList[k].wins, &playerList[k].loses) == 3) {
    	k++;
	}

    for (i = 0; i <= numUsers; i++) {
        if (i + 1 == user1) {
            playerList[i].wins += win1;
            playerList[i].loses += win2;
        }
        if (i + 1 == user2) {
            playerList[i].wins += win2;
            playerList[i].loses += win1;
        }
    }
    
    fclose(fp);
    
	FILE* fp2;
	fp2 = fopen("ticdata.txt", "w");
	
	fprintf(fp2, "%d", numUsers);
	
	for (i = 0; i < numUsers; i++) {
	    fprintf(fp2, "%s#%d#%d", playerList[i].username, playerList[i].wins, playerList[i].loses);
	}
	
	fclose(fp2);
}

void checkName(char name[], int num) {
    int numUsers, wins, loses, k = 0;
    char user[15];
    FILE* fp;

    fp = fopen("ticdata.txt", "r");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fscanf(fp, "%d", &numUsers);

    while (fscanf(fp, " %14[^#]#%d#%d", user, &wins, &loses) == 3) {
        if (k + 1 == num) {
            strcpy(name, user);
            break;
        }
        k++;
    }

    fclose(fp);
}

void searchUser() {
	int numUsers, wins, loses, k = 0, i;
	float winrate;
    char user[15], name[15];
    FILE* fp;

    fp = fopen("ticdata.txt", "r");

	if (fp == NULL) {
		initializeFile();
    }

    fscanf(fp, "%d", &numUsers);
    
    printf("Username: ");
    scanf(" %s", name);

    for (i = 0; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    
    // linear search
    while (fscanf(fp, " %14[^#]#%d#%d", user, &wins, &loses) == 3) {
    		
    	for (i = 0; i < strlen(user); i++) {
        	user[i] = tolower(user[i]);
    	}
        if (strcmp(user, name) == 0) {
            printf("\nUser %s\n", user);
            printf("Wins = %d\n", wins);
            printf("loses = %d\n", loses);
            
            if (loses == 0) {
            	if (wins == 0) {
            		winrate = 0;
				}
				else {
					winrate = 100;
				}
            		
			}
			else {
				winrate = wins * 100 / loses;
			}
            printf("Winrate = %.2f%\n\n", winrate);
            fclose(fp);
            return;
        }
        k++;
    }

	printf(">> User not found\n\n");
    fclose(fp);
}

void initializeFile() {
    FILE *fp;
	fp = fopen("ticdata.txt", "w");
    
    fprintf(fp, "0\n");

    fclose(fp);
    printf("! Initializing file data\n");
    printf("! Please re-run code\n");
    exit(0);
}

void menuSelection(int *player1, int *player2) {
    int select;
    while (*player1 == -1 && *player2 == -1) {
    	printf("! To start playing, please select users\n");
        printf("[ User Menu ]\n");
        printf("1. Select User\n");
        printf("2. Create User\n");
        printf("3. Display User Rank\n");
        printf("4. Delete User\n");
        printf("5. Search User Profile\n");
        printf("6. Exit\n");
        printf("> ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                printf("\n");
                selectUser(player1, player2);
                break;
            case 2:
                printf("\n");
                createUser();
                break;
            case 3:
                printf("\n");
                displayUser(2);
                break;
            case 4:
                printf("\n");
                deleteUser();
                break;
            case 5:
                printf("\n");
                searchUser();
                break;
            case 6:
            	system("cls");
				exit(0);
            	break;
            default:
                printf("! Please choose a valid option\n");
                break;
        }
    }
}



