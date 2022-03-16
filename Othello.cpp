#include <iostream>
#include <vector>

using namespace std;

class Coordinates{
    private:
        int i;
        int j;
    public:
        Coordinates(){
            i=0;
            j=0;
        }

        Coordinates(int row, int col){
            i=row;
            j=col;
        }

        void setCoords(int row, int col){
            i=row;
            j=col;
        }

        void operator = (const Coordinates &C ) { 
            i = C.i;
            j = C.j;
        }
        
        bool operator == (const Coordinates &C){
            if(C.i==i && C.j==j){
                return true;
            }
            else return false;
        }

        bool operator != (const Coordinates &C ) { 
            return !(*this==C);
        }

        int getI(){
            return i;
        }

        int getJ(){
            return j;
        }

};

class Board{
    public:
        char** table;
        int value;
       
        bool convertBrackets(char turn, int row, int col){
            char convertTo;
            char opponent;
            if(turn=='W'){
               
                convertTo = 'W';
                opponent = 'B';
            }
            else {            
                convertTo= 'B';
                opponent='W';
            }
            bool toReturn = false;

            bool check = false;
            for(int i=row, j=col; i>=0, j>=0; i--, j--){
                if(!InsidePremises(i, j)){
                    break;
                }
                if(table[i][j]==opponent){
                    check= true;
                }
                if(table[i][j]=='-'&& check==false){
                    break;
                }
                if(table[i][j]==turn && check==true){
                    for(int k=i, l=j; k!=row, l!=col; k++, l++){
                        if(table[k][j]!=convertTo){
                            toReturn=true;
                        }
                        table[k][l]=convertTo;
                    }
                    return toReturn;
                }               
            }
            check = false;
            for(int i=row; i>=0; i--){
                if(!InsidePremises(i, col)){
                    break;
                }
                if(table[i][col]==opponent){
                    check= true;
                }
                if(table[i][col]=='-'&& check==false){
                    break;
                }
                if(table[i][col]==turn && check==true){
                    for(int k=i; k!=row; k++){
                        if(table[k][col]!=convertTo){
                            toReturn=true;
                        }
                        table[k][col]=convertTo;
                    }
                    return toReturn;
                }               
            }
            check = false;
            for(int i=row, j=col; i>=0, j<=7; i--, j++){
                if(!InsidePremises(i, j)){
                    break;
                }
                if(table[i][j]==opponent){
                    check= true;
                }
                if(table[i][j]=='-'&& check==false){
                    break;
                }
                if(table[i][j]==turn && check==true){
                    for(int k=i, l=j; k!=row, l!=col; k++, l--){
                        if(table[k][j]!=convertTo){
                            toReturn=true;
                        }
                        table[k][l]=convertTo;
                    }
                    return toReturn;
                }               
            }

            check = false;
            for(int j=col; j>=0; j--){
                if(!InsidePremises(row, j)){
                    break;
                }
                if(table[row][j]==opponent){
                    check= true;
                }
                if(table[row][j]=='-'&& check==false){
                    break;
                }
                if(table[row][j]==turn && check==true){
                    for(int l=j; l!=col; l++){
                        if(table[row][j]!=convertTo){
                            toReturn=true;
                        }
                        table[row][l]=convertTo;
                    }
                    return toReturn;
                }               
            }

            check = false;
            for(int j=col; j<=7; j++){
                if(!InsidePremises(row, j)){
                    break;
                }
                if(table[row][j]==opponent){
                    check= true;
                }
                if(table[row][j]=='-'&& check==false){
                    break;
                }
                if(table[row][j]==turn && check==true){
                    for(int l=j; l!=col; l--){
                        if(table[row][j]!=convertTo){
                            toReturn=true;
                        }
                        table[row][l]=convertTo;
                    }
                    return toReturn;
                }               
            }

            check = false;
            for(int i=row, j=col; i<=7, j>=0; i++, j--){
                if(!InsidePremises(i, j)){
                    break;
                }
                if(table[i][j]==opponent){
                    check= true;
                }
                if(table[i][j]=='-'&& check==false){
                    break;
                }
                if(table[i][j]==turn && check==true){
                    for(int k=i, l=j; k!=row, l!=col; k--, l++){
                        if(table[k][j]!=convertTo){
                            toReturn=true;
                        }
                        table[k][l]=convertTo;
                    }
                    return toReturn;
                }               
            }

            check = false;
            for(int i=row; i<=7; i++){
                if(!InsidePremises(i, col)){
                    break;
                }
                if(table[i][col]==opponent){
                    check= true;
                }
                if(table[i][col]=='-'&& check==false){
                    break;
                }
                if(table[i][col]==turn && check==true){
                    for(int k=i; k!=row; k--){
                        if(table[k][col]!=convertTo){
                            toReturn=true;
                        }
                        table[k][col]=convertTo;
                    }
                    return toReturn;
                }               
            }

            check = false;
            for(int i=row, j=col; i<=7, j<=7; i++, j++){
                if(!InsidePremises(i, j)){
                    break;
                }
                if(table[i][j]==opponent){
                    check= true;
                }
                if(table[i][j]=='-'&& check==false){
                    break;
                }
                if(table[i][j]==turn && check==true){
                    for(int k=i, l=j; k!=row, l!=col; k--, l--){
                        if(table[k][j]!=convertTo){
                            toReturn=true;
                        }
                        table[k][l]=convertTo;
                    }
                    return toReturn;
                }               
            }

            return toReturn;
        }

        bool InsidePremises(int i, int j){
            if(i<0){
                return false;
            }
            else if(j<0){
                return false;
            }
            else if(i>7){
                return false;
            }
            else if(j>7){
                return false;
            }
            return true;
        }

        Coordinates exploreNeighbors(int row, int col, char turn, int direction){
            char toLook;
            Coordinates falseReturn(-1, -1);
            if(turn=='W'){
                toLook = 'B';
            }
            else 
                toLook= 'W';

            if(direction==1){
                bool check = false;
                for(int i=row, j=col; i>=0, j>=0; i--, j--){
                    if(!InsidePremises(i, j)){
                        return falseReturn;
                    }
                    if(table[i][j]==toLook){
                        check= true;
                    }
                    if(table[i][j]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[i][j]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[i][j]=='-'&& check==true){
                        Coordinates toReturn(i, j);
                        return toReturn;
                    }               
                }
            }
            else if(direction==2){
                bool check = false;
                for(int i=row; i>=0; i--){
                    if(!InsidePremises(i, col)){
                        return falseReturn;;
                    }
                    if(table[i][col]==toLook){
                        check= true;
                    }
                    if(table[i][col]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[i][col]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[i][col]=='-'&& check==true){
                        Coordinates toReturn(i, col);
                        return toReturn;
                    }               
                }
            }
            else if(direction==3){
                bool check = false;
                for(int i=row, j=col; i>=0, j<=7; i--, j++){
                    if(!InsidePremises(i, j)){
                        return falseReturn;;
                    }
                    if(table[i][j]==toLook){
                        check= true;
                    }
                    if(table[i][j]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[i][j]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[i][j]=='-'&& check==true){
                        Coordinates toReturn(i, j);
                        return toReturn;
                    }               
                }
            }
            else if(direction==4){
                bool check = false;
                for(int j=col; j>=0; j--){
                    if(!InsidePremises(row, j)){
                        return falseReturn;;
                    }
                    if(table[row][j]==toLook){
                        check= true;
                    }
                    if(table[row][j]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[row][j]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[row][j]=='-'&& check==true){
                        Coordinates toReturn(row, j);
                        return toReturn;
                    }               
                }
            }
            else if(direction==6){
                bool check = false;
                for(int j=col; j<=7; j++){
                    if(!InsidePremises(row, j)){
                        return falseReturn;;
                    }
                    if(table[row][j]==toLook){
                        check= true;
                    }
                    if(table[row][j]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[row][j]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[row][j]=='-'&& check==true){
                        Coordinates toReturn(row, j);
                        return toReturn;
                    }               
                }
            }
            else if(direction==7){
                bool check = false;
                for(int i=row, j=col; i<=7, j>=0; i++, j--){
                    if(!InsidePremises(i, j)){
                        return falseReturn;;
                    }
                    if(table[i][j]==toLook){
                        check= true;
                    }
                    if(table[i][j]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[i][j]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[i][j]=='-'&& check==true){
                        Coordinates toReturn(i, j);
                        return toReturn;
                    }               
                }
            }
            else if(direction==8){
                bool check = false;
                for(int i=row; i<=7; i++){
                    if(!InsidePremises(i, col)){
                        return falseReturn;;
                    }
                    if(table[i][col]==toLook){
                        check= true;
                    }
                    if(table[i][col]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[i][col]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[i][col]=='-'&& check==true){
                        Coordinates toReturn(i, col);
                        return toReturn;
                    }               
                }
            }
            else if(direction==9){
                bool check = false;
                for(int i=row, j=col; i<=7, j<=7; i++, j++){
                    if(!InsidePremises(i, j)){
                        return falseReturn;;
                    }
                    if(table[i][j]==toLook){
                        check= true;
                    }
                    if(table[i][j]=='-'&& check==false){
                        return falseReturn;;
                    }
                    if(table[i][j]==turn && check==true){
                        return falseReturn;
                    }
                    if(table[i][j]=='-'&& check==true){
                        Coordinates toReturn(i, j);
                        return toReturn;
                    }               
                }
            }
            return falseReturn;
        }
        
        bool gamecomplete()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (table[i][j] == '-')
                    {
                        return false;
                        break;
                    }

                }
            }
            return true;
        }
    public:
        int countw()
        {
            int counter=0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (table[i][j] == 'W')
                    {
                        counter++;
                    }

                }
            }
            return counter;
        }
        
        int countb()
        {
            int counter = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (table[i][j] == 'B')
                    {
                        counter++;
                    }

                }
            }
            return counter;
        }
        
        Board(){
           
           table = new char*[8];
           for(int i=0; i<8; i++){
               table[i]= new char[8];
           }
           for(int i=0; i<8; i++){
               for(int j=0; j<8; j++){
                   table[i][j]='-';
               }
           }
           table[3][3]='W';
           table[3][4]='B';
           table[4][3]='B';
           table[4][4]='W';
           value = countw() - countb();
        }
        
        void print(){
            cout << "W: " << countw() << "    " << "B: " << countb() << endl;
            cout<<"  ";
            for(int i=0; i<8; i++){
                cout<<i<<" ";
            }
            cout<<endl;
            for(int i=0; i<8; i++){
                cout<<i<<" ";
                for(int j=0; j<8; j++){
                    cout<<table[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        vector<Coordinates> getOpenCoords(char turn){
            vector<Coordinates> openStates;
            Coordinates falseReturn(-1, -1);
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(table[i][j]==turn){
                        Coordinates toPush = exploreNeighbors(i, j, turn, 2);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                        toPush = exploreNeighbors(i, j, turn, 1);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                        toPush = exploreNeighbors(i, j, turn, 3);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                        toPush = exploreNeighbors(i, j, turn, 4);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                        toPush = exploreNeighbors(i, j, turn, 6);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                        toPush = exploreNeighbors(i, j, turn, 7);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                        toPush = exploreNeighbors(i, j, turn, 8);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                        toPush = exploreNeighbors(i, j, turn, 9);
                        if(toPush!=falseReturn)openStates.push_back(toPush);
                    }
                }
            }
            for(auto os=openStates.begin(); os!=openStates.end(); ++os){
               table[(*os).getI()][(*os).getJ()]='O';
            }
            return openStates;
        }

        bool makeMove(char turn, int row, int col){
            if(table[row][col]!='O'){
                cout<<"Invalid Move, Try Again"<<endl;
                return false;
            }
            else{
                table[row][col]=turn;
                for(int i=0; i<8; i++){
                    for(int j=0; j<8; j++){
                        if(table[i][j]=='O'){
                            table[i][j]='-';
                        }
                    }
                }
                print();
                while(convertBrackets(turn, row, col)!=false){
                    print();
                }
            }
            return true;
        }
        
        Board testmove(char turn, int row, int col) {
                Board  temp;
                temp.copytable(table);
                temp.table[row][col] = turn;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (temp.table[i][j] == 'O') {
                            temp.table[i][j] = '-';
                        }
                    }
                }
                //print();
                while (temp.convertBrackets(turn, row, col) != false) {
                   // print();
                }
                return temp;
            }
           
        int evaluationfun(Board  obj)
        {
            int sizew= obj.getOpenCoords('W').size();
            int sizeb=obj.getOpenCoords('B').size();
            return sizew - sizeb;

        }

        void operator=(const Board& obj) {
            
            value = obj.value;
           table = new char* [8];
            for (int i = 0; i < 8; i++) {
                table[i] = new char[8];
            }
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    table[i][j] = obj.table[i][j];
                }
            }
            
        }
        
        Board(const Board& obj)
        {
            value = obj.value;
            table = new char* [8];
            for (int i = 0; i < 8; i++) {
                table[i] = new char[8];
            }
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    table[i][j] = obj.table[i][j];
                }
            }
            
        }
        
        Board minmax(Board  state, int  depth, bool isMax,Board & main)
            
        {
            Board retobj;
            //cout << depth << endl;

            if (depth == 0)
            {
               
                retobj = state;
                retobj.value = evaluationfun(state);
               
                return retobj;

            }
            else
            {
                
                if (isMax == true)
                {
                    
                    int max = -9999;
                    vector<Coordinates> temp = state.getOpenCoords('W');
                    for (auto it = temp.begin(); it != temp.end(); ++it) {
                        int  i = it->getI();
                        int j = it->getJ();
                        Board child = state.testmove('W', i, j);
                        
                        isMax = false;
                        retobj = minmax(child, depth - 1, isMax,main);
                        
                        if (max < retobj.value)
                        {
                            max = retobj.value;
                            
                            main = child;
                            
                        }
                    }
                    return retobj;
                }
                else if (isMax == false)
                {
                    
                    int min = 9999;
                    vector<Coordinates> temp = state.getOpenCoords('B');
                    
                    for (auto it = temp.begin(); it != temp.end(); ++it) {
                        int  i = it->getI();
                        int j = it->getJ();
                        Board child = state.testmove('B', i, j);
                        isMax == true;
                        int passer = depth - 1;
                        
                        retobj = minmax(child, 0, isMax,main);
                        
                        if (min > retobj.value)
                        {
                            min = retobj.value;
                            
                        }
                    }
                    
                    return retobj;
                }
            }

        }
        
        void copytable(char ** arr)
            {
            
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    table[i][j] = arr[i][j];
                }
            }
            }
        
        int counto()
        {
            int counter = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (table[i][j] == 'O')
                    {
                        counter++;
                    }

                }
            }
            return counter;
        }
       
        void playgame()
        {
            Board temp;
            Board answer;
            char player = 'W';
            while (!temp.gamecomplete())
            {
                
                int i;
                int j;
                
                if (player == 'W')
                {
                   
                   temp=minmax(temp,2, true,answer);
                   temp = answer;
                   temp.print();
                    player = 'B';
                   
                }
                else if (player == 'B')
                {
                    cout << "Your Turn" << endl;
                    temp.getOpenCoords('B');
                    temp.print();
                    if (temp.counto() == 0)
                    {
                        cout << "Moves Exhausted" << endl;
                        break;
                    }
                    else {
                        cout << "Enter Coordinates: ";
                        cin >> i;
                        cout << endl;
                        cin >> j;
                        temp = temp.testmove('B', i, j);

                        player = 'W';
                    }
                }
            }
            if (countw() > countb())
            {
                cout << "Player White is the winner" << endl;
            }
            else
            {
                cout << "Player Black is the winner" << endl;
            }
      }
};


 int main(){
    Board myBoard;
    myBoard.playgame();
  
}