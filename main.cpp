#include <iostream>
using namespace std;

int main() {

  int b[8][8]{0}, row, col = 0;
  int config = 1;

  b[0][0] = 1; //places a queen in the first row and column

  nc: col++;
    if (col == 8) goto print;
    row = -1;

  nr: row++;
    if (row == 8) goto backtrack;

  //row test
  for(int i = 0; i < col; i++) {
    if (b[row][i] == 1) goto nr;
  }

  //up diagonal test
  for(int i = 1; (row - i) >= 0 && (col - i) >= 0; i++) {
    if (b[row-i][col-i] == 1) goto nr; 
  }

  //down diagonal test
  for(int i = 1; (row+i) < 8 && (col-i) >= 0; i++) {
    if (b[row+i][col-i] == 1) goto nr;
  }
  
  //b[r][c] is safe, place a queen
  b[row][col] = 1;
  goto nc;

  backtrack:
    col--;
    if (col == -1) return 0;

    row = 0;
    while (b[row][col] != 1) row++;
    b[row][col] = 0;
    goto nr;

  print:
  cout << "Configuration " << config++ << ": " << endl;
  for(int r = 0; r < 8; r++) {  //prints the rows
        for(int c = 0; c < 8; c++) { //prints the columns
            cout << b[r][c] << " ";
        }
        cout << endl;
    }
     cout << endl;
     goto backtrack; //goes to the next possible combination
  }