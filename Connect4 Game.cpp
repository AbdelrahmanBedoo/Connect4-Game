/* Sama Emad | Id: 900233026
   Abdelrahman Abdelbaky | Id: 900232797 
*/

#include <iostream>
using namespace std;
int game[6][7] = {0};
int empty_places[7]={5,5,5,5,5,5,5};
char player, player2;
int still_valid(int game[][7]){
  for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){
      if(!game[i][j])
        return 1;
    }
  }
  return 0;
}
void print(int game[][7]){
  cout<<endl;
  for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){
       if(game[i][j]==0)
         cout<<"0 ";
      else
        cout<<(char)game[i][j]<<" ";
    }
    cout<<endl;
  }
}
int column_valid(int column_num){
  if(game[empty_places[column_num]][column_num]){
    empty_places[column_num]--;
  }
  if(empty_places[column_num]<0)
    return 1;
  return 0;
}

int check_winner(char player_num) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (game[i][j] == ((int)player_num)) {
                // Check horizontal
                if (j + 3 < 7 && game[i][j + 1] == ((int)player_num) && game[i][j + 2] == ((int)player_num) && game[i][j + 3] == ((int)player_num))
                    return 1;

                // Check vertical
                if (i + 3 < 6 && game[i + 1][j] == ((int)player_num) && game[i + 2][j] == ((int)player_num) && game[i + 3][j] == ((int)player_num))
                    return 1;

                // Check diagonals
                if (i + 3 < 6) {
                    if (j + 3 < 7 && game[i + 1][j + 1] == ((int)player_num) && game[i + 2][j + 2] == ((int)player_num) && game[i + 3][j + 3] == ((int)player_num))
                        return 1;
                    if (j - 3 >= 0 && game[i + 1][j - 1] == ((int)player_num) && game[i + 2][j - 2] == ((int)player_num) && game[i + 3][j - 3] == ((int)player_num))
                        return 1;
                }
            }
        }
    }
    return 0; 
}
int playGame2(){
  cout<<"\n--------------------------------\n";
  int column_num;
  if(!still_valid(game)){
    cout<<"Game over!";
    return 0;
  }
  do{
  cout << "\nPlayer 2: In what column do you want to place your coin? \n";
  cin>>column_num;
  }while(column_num<0 || column_num>7 || column_valid(--column_num));
  game[empty_places[column_num]][column_num] = (int)player2; 
  print(game);
  if (check_winner(player2)) {
      cout << "Player 2 (R) wins!" << endl;
      return 0;
  }
  return 1;
}
int playGame(){
  int column_num;
  cout<<"\n--------------------------------\n";
  if(!still_valid(game)){
    cout<<"Game over!";
    return 0;
  }
  do{
  cout << "\nPlayer 1: In what column do you want to place your coin? \n";
  cin>>column_num;
  }while(column_num<0 || column_num>7 || column_valid(--column_num));
  game[empty_places[column_num]][column_num] = (int)player;
  print(game);
  if (check_winner(player)) {
      cout << "Player 1 (R) wins!" << endl;
      return 0;
  }
  if(!playGame2())
    return 0;
  playGame();
  return 1;
}
int main() {
  cout << "Welcome to Connect 4 game! \n";
  print(game);
  do{cout<<"\nWho will start the game? (player R or B): ";
  cin>>player;
  }while(player != 'R' && player != 'B');
  if(player=='R')
    player2='B';
  else
    player2='R';
  playGame();
}