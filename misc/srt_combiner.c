/*This code is designed especially for language learners.
*If you have subtitles for the same video in two languages (as SRT files),
*(or a whole season of them with the names in a pattern)
*and you want to play them together on a video player,
*this code merges them into one easily parse-able SRT file,
*which contains both of the languages.
*All you need to run this is tcc and this file*/
#include <stdio.h>
#include <string.h>
#include <string.h>

//Globally defined filenames of source SRT files.
//It is important that filenames of the subtitles be in a pattern if multiple episodes are to be merged
//For example, "Dark-S03E01.srt" followed by "Dark-S03E02.srt"
//It is better to edit the values here. I can't seem to implement this as a scanf variant in main()

char Engname[] = "Dark.S03E01.720p.WEB.H264-GHOSTS.srt";  //Eng Subtitle Filename
char Gername[] = "Dark.S03E01.NF.WEB-DL.German.Germany.GER.srt";  //German/Other Lang. Subtitle Filename
int EngPos = 10;  //Eng position of last variable digit ...E0'3'... in string Engname
int GerPos = 10;  //Similar for German
int EpisodeCount = 7;  //No. of episodes you want the loop to run to
char Dualname[] = "T01.srt";  //Name of Final file 

//Globally defined temp arrays of strings to hold one subtitle
char GerSub[5][100];
char EngSub[5][100];

//scans a subtitle from a source SRT file
void scanSub(FILE *LAN, char Sub[5][100]){
	for(int a=0;a<5;a++){
		fgets(Sub[a],100,LAN);
		if(Sub[a][0] == '\n') return;
	}
	return;
}

//prints a subtitle to the final file
//{\an8} makes the subtitle appear on top of the screen instead of bottom
void printSub(FILE *LAN, char Sub[5][100], int ONEifGER){
	for(int a=0; a<5;a++){ 
		if(Sub[a][0] == '\n') break;
		if(a==2 && ONEifGER) fputs("{\\an8}",LAN);
		fputs(Sub[a],LAN);
		if(a==0) fputs("\n",LAN);
	}
	fputs("\n",LAN);
	return;
}	

void srtCombiner(){

	// open files for writing
	FILE *ENG = fopen(Engname,"r");
	FILE *GER = fopen(Gername,"r");

	//Take first subtitles in
	scanSub(GER,GerSub);
	scanSub(ENG,EngSub);
	int subcounter = 1;

	if(ENG == NULL || GER == NULL) return;
	FILE *DUAL = fopen(Dualname,"w");

	while( !(feof(GER) && feof(ENG)) ){
		
		//Compare timers
		int comp = strcmp(GerSub[1],EngSub[1]);
			
		//do the thing
		if(comp == 0){
			sprintf(GerSub[0], "%d", subcounter);
			printSub(DUAL, GerSub, 1);
			subcounter++;
			scanSub(GER, GerSub);
				
			sprintf(EngSub[0], "%d", subcounter);
			printSub(DUAL, EngSub, 0);
			subcounter++;
			scanSub(ENG, EngSub);
		}
		else if((comp>0 && !feof(ENG)) || feof(GER) ){
			sprintf(EngSub[0], "%d", subcounter);
			printSub(DUAL, EngSub, 0);
			subcounter++;
			scanSub(ENG, EngSub);
		}
		else if((comp<0 && !feof(GER)) || feof(ENG) ){
			sprintf(GerSub[0], "%d", subcounter);
			printSub(DUAL, GerSub, 1);
			subcounter++;
			scanSub(GER, GerSub);
		}
			
	}

	fclose(ENG); fclose(GER); fclose(DUAL);
}


int main(){

	int n = EpisodeCount;
	int gp = GerPos, ep = EngPos;

	for(int i=0; i<n; i++){
		srtCombiner();
		printf("%s done \n", Dualname);

		//update names for next cycle
		if(Gername[gp] == '9'){
			Gername[gp-1]++; Gername[gp] = '0';
			Engname[ep-1]++; Engname[ep] = '0';
			Dualname[1]++; Dualname[2] = '0';
		}
		else{
			Gername[gp]++;
			Engname[ep]++;
			Dualname[2]++;
		}
	}

	return 0;
}
		
		
		
		
		
		
		
		
		
		
		

