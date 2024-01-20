#include<stdio.h>

struct teams{
    char names[50];
    int matches;
    int scores;
};

typedef struct teams Teams;


int main(void)
{

    Teams teams[50];
   
    int numTeams = 0;
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        sscanf(line,"%[^0-9] %d %d\n", &teams[numTeams].names, &teams[numTeams].matches, &teams[numTeams].scores);
		numTeams++;
	}
    

    //winners
    int maxScore = teams[0].scores;
    for(int i=0; i<numTeams;i++){
        int maxpoint;
        int possible;
        possible=(((numTeams-1)*2)-teams[i].matches)*3 ;
        maxpoint= teams[i].scores + possible; 
        char teamname;
        if (maxpoint>=maxScore){
            char teamname[] = teams[i].names;
            //char teamname[]=teamname;
            int i=0;
            while(teamname[i]!='\0'){
                printf("%c",teamname[0]);
                i++;
            }
            printf("%s\n",teamname);
         
        }
    }
   
    
    for(int i=0; i<numTeams;i++){
        int count=0;
        for(int j=i+1;j<numTeams;j++){
            int maxpoint1;
            int possible1;
            possible1=(((numTeams-1)*2)-teams[j].matches)*3 ;
            maxpoint1=teams[j].scores+possible1;
            
            if(teams[i].scores>maxpoint1){
                count++;
            }
        }
        if(count<3){
            printf("%s\n",teams[i].names);
        } 
    }
    

    
}