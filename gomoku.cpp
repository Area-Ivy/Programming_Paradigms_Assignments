#define _CRT_SECURE_NO_WARNINGS

#include <random>                              
#include <algorithm>                          
#include <unordered_map>                        
#include <stdio.h>                          
#include <stdlib.h>                             
#include <string.h>                          
#include <time.h>                               
#include <iostream>
#include <vector>   
#include <math.h>    

using namespace std;
typedef unsigned long long ULL;                 

//点的状态
enum State{
    Empty=0,                                     
    Black=1,                                       
    White=2                                        
};

//带分数的点
struct Point{
    int x;                                       
    int y;                                       
    int score;                                   
};

//哈希状态
struct HashKey{
    int depth;                                   
    int score;                                   
};

const int DIRECTION_X[4] = { 0, 1, 1, 1 };                 //方向（X）
const int DIRECTION_Y[4] = { 1, 0, 1, -1 };                //方向（Y）
const int BLOCK[6] = { 0, 1, 20, 120, 720, 500000};        //棋型分数（眠）
const int LIVE[6]  = { 0, 20, 120, 720, 4320, 500000};     //棋型分数（活）
const int SEARCH_DEPTH = 5;                                //搜索深度
const int MAX_BRANCH = 40;                                 //最大分支数

State player;                                              //己方
State enemy;                                               //对手
State board[12][12];                                       //棋盘
int score[12][12][3];                                      //分数表
int stepCount;                                             //当前步数
ULL zobristTable[12][12][3];                               //Zobrist表
ULL currentZobristKey;                                     //当前的Zobrist键值
unordered_map<ULL, HashKey> transTable;                    //置换表

class AutoChess
{
public:
//构造函数，初始化棋盘，分数表和Zobrist表
AutoChess(){
    memset(board, 0, sizeof(board));
    memset(score, 0, sizeof(score));
    InitZobrist();
};
~AutoChess(){};

//初始化Zobrist表
void InitZobrist()
{
    std::random_device randomDevice; 
    std::mt19937_64 rng(randomDevice()); 
    std::uniform_int_distribution<ULL> unidist; 
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            for (int k = 0; k < 3; k++) {
                zobristTable[i][j][k] = unidist(rng);
            }
        }
    }
    currentZobristKey = 0;
}

//检测是否在棋盘内
bool isInBound(const int x, const int y)
{
    return (x >= 0 && x < 12) && ( y >= 0 && y < 12);   
}

//检测周围是否有棋子
bool chessAround(const int x, const int y)
{
    for (int i = max(0, x - 1); i <=min(11, x + 1); i++) {
        for (int j = max(0, y - 1); j <= min(11, y + 1); j++) {
            if (i == x && j == y) {
                continue; 
            }
            if (board[i][j] != Empty) {
                return true;
            }
        }
    }
    return false;
}

//评估棋型：count为总棋子数，block为阻挡数，countBetweenEmpty为隔了间隔后的棋子数（为-1意为无间隔）
int evaluateLine(const int count, const int block, const int countBetweenEmpty)
{   
    //无间隔
    if (countBetweenEmpty == -1) {
        if (count >= 5) {
            return LIVE[5];               
        }
        if (block == 0) {
            if(1 <= count && count <= 5){
                return LIVE[count];
            } 
        }
        if (block == 1) {
            if(1 <= count && count <= 5){
                return BLOCK[count];
            } 
        }
    } 
    //间隔一侧有一个子
    else if (countBetweenEmpty == 1 || count - countBetweenEmpty == 1) {
        if (count >= 6) {
            return LIVE[5];               
        }
        if (block == 0) {
            if(count == 2 || count == 3){
                return LIVE[count];
            }
            if(count == 4){
                return BLOCK[4];
            }
            if(count == 5){
                return LIVE[4];
            }
        }
        if (block == 1) {
            if(2 <= count && count <= 4){
                return BLOCK[count];
            } 
            if(count == 5){
                return BLOCK[4];
            }
        }
    } 
    //间隔一侧有二个子
    else if (countBetweenEmpty == 2 || count - countBetweenEmpty == 2) {
        if (count >= 7) {
            return LIVE[5];               
        }
        if (block == 0) {
            if(count == 3){
                return LIVE[3];
            }
            if(count == 4 || count == 5){
                return BLOCK[4];
            }
            if(count == 6){
                return LIVE[4];
            }
        }
        if (block == 1) {
            if(count == 3){
                return BLOCK[3];
            }
            if(count == 4 || count == 5){
                return BLOCK[4];
            }
            if(count == 6){
                return LIVE[4];
            }
        }
        if (block == 2) {
            if(4 <= count && count <= 6){
                return BLOCK[4];
            }
        }
    } 
    //间隔一侧有三个子
    else if (countBetweenEmpty == 3 || count - countBetweenEmpty == 3) {
        if (count >= 8) {
            return LIVE[5];              
        }
        if (block == 0) {
            if(count == 4 || count == 5){
                return LIVE[3];
            }
            if(count == 6){
                return BLOCK[4];
            }
            if(count == 7){
                return LIVE[4];
            }
        }
        if (block == 1) {
            if(count >= 4 && count <= 6){
                return BLOCK[4];
            }
            if(count == 7){
                return LIVE[4];
            }
        }
        if (block == 2) {
            if(count >= 4 && count <= 7){
                return BLOCK[4];
            }
        }
    }
    //间隔一侧有四个子
    else if (countBetweenEmpty == 4 ||count - countBetweenEmpty == 4) {
        if (count >= 9) {
            return LIVE[5];               
        }
        if (block == 0) {
            if(count >= 4 && count <= 7){
                return LIVE[4];
            }
        }
        if (block == 1) {
            if(count >= 4 && count <= 7){
                return BLOCK[4];
            }
            if(count == 8){
                return LIVE[4];
            }
        }
        if (block == 2) {
            if(count >= 5 && count <= 8){
                return BLOCK[4];
            }
        }
    }
    //间隔一侧有五个子
    else if (countBetweenEmpty == 5 || count - countBetweenEmpty == 5) {
        return LIVE[5];                   
    }
    return 0;                               
}

//评估点的分数
int evaluatePoint(const int x, const int y, const State flag)
{
    int value = 0;
    for(int dir=0; dir<4; dir++){
        int count = 1, block = 0, countBetweenEmpty = -1;//默认反方向那一部分为countBetweenEmpty
        for (int i = 1 ; ; i++) {
            int newX = x + i * DIRECTION_X[dir];
            int newY = y + i * DIRECTION_Y[dir];
            //出界等价于有阻挡，结束搜索
            if (!isInBound(newX,newY)) {
                block++;
                break;
            }
            //如果为空
            if (board[newX][newY] == Empty) {
                //如果之前没有间隔，且该间隔后有棋子，则记录已经检索到的棋子数；若之前已有过间隔，则停止搜索。
                if (countBetweenEmpty == -1 && i < isInBound(newX + DIRECTION_X[dir],newY + DIRECTION_Y[dir]) && board[newX + DIRECTION_X[dir]][newY + DIRECTION_Y[dir]] == flag) {
                    countBetweenEmpty = count;
                    continue;
                }
                else {
                    break;
                }
            }
            //如果为要检索的棋子
            else if (board[newX][newY] == flag) {
                count++;
                continue;
            }
            //是对方的棋子
            else {
                block++;
                break;
            }
        }
        //换反方向搜索，由于正方向可能已经有countBetweenEmpty，这一部分的处理逻辑为扩展countBetweenEmpty    
        for (int i = 1; true; i++) {
            int newX = x - i * DIRECTION_X[dir];
            int newY = y - i * DIRECTION_Y[dir];
            if (!isInBound(newX,newY)) {
                block++;
                break;
            }
            if (board[newX][newY] == Empty) {
                if (countBetweenEmpty == -1 && isInBound(newX - DIRECTION_X[dir],newY - DIRECTION_Y[dir]) && board[newX - DIRECTION_X[dir]][newY - DIRECTION_Y[dir]] == flag) {
                    countBetweenEmpty = 0;
                    continue;
                }
                else {
                    break;
                }
            }
            else if (board[newX][newY] == flag) {
                count++;
                if (countBetweenEmpty != -1) {
                    countBetweenEmpty++;
                }
                continue;
            }
            else {
                block++;
                break;
            }
        } 
        value += evaluateLine(count, block, countBetweenEmpty);
    }
    return value;
}

//更新分数表
void updateScore(const int x, const int y)
{
    //更新新落子位置的分数
    if (board[x][y] ==player) {
        score[x][y][player] = evaluatePoint(x, y, player);
    }
    else if (board[x][y] == enemy) {
        score[x][y][enemy] = evaluatePoint(x, y, enemy);
    }
    else {
        score[x][y][player] = 0;
        score[x][y][enemy] = 0;
    }
 
    //更新可能被新落子影响的棋子
    for (int dir = 0; dir < 4; dir++) {
        int newX, newY;
        newX = x, newY = y;
        while (true) {
            newX += DIRECTION_X[dir];
            newY += DIRECTION_Y[dir];
            if (!isInBound(newX, newY)) {
                break;
            }
            if (board[newX][newY] == player) {
                score[newX][newY][player] = evaluatePoint(newX, newY, player);
            }
            else if (board[newX][newY] == enemy) {
                score[newX][newY][enemy] = evaluatePoint(newX, newY, enemy);
            }
        }
        newX = x, newY = y;
        while (true) {
            newX -= DIRECTION_X[dir];
            newY -= DIRECTION_Y[dir];
            if (!isInBound(newX, newY)) {
                break;
            }
            if (board[newX][newY] == player) {
                score[newX][newY][player] = evaluatePoint(newX, newY, player);
            }
            else if (board[newX][newY] == enemy) {
                score[newX][newY][enemy] = evaluatePoint(newX, newY, enemy);
            }
        }
    }
}

//评价棋盘总分数
int evaluateBoard()
{
    int result = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (board[i][j] == player) {
                result += score[i][j][player];
            }
            else if (board[i][j] == enemy) {
                result -= score[i][j][enemy]; 
            }
        }
    }
    return result;
}

//落子
void setChess(const int x, const int y, const State flag)
{
    stepCount++;
    currentZobristKey ^= zobristTable[x][y][board[x][y]];//撤销之前状态对currentZobristKey的影响
    board[x][y] = flag;
    currentZobristKey ^= zobristTable[x][y][flag];//添加当前状态对currentZobristKey的影响
    updateScore(x, y);//更新分数表   
}

//删除棋子（setChess的相反操作）
void delChess(const int x, const int y)
{
    stepCount--;
    currentZobristKey ^= zobristTable[x][y][board[x][y]];
    board[x][y] = Empty;
    currentZobristKey ^= zobristTable[x][y][Empty];    
    updateScore(x, y);
}

//检测是否成五
bool checkFive(const int x, const int y, const State flag)
{
    int i, j, count;
    for (int dir = 0; dir < 4; dir++) {
        count = 1;
        i = x + DIRECTION_X[dir];
        j = y + DIRECTION_Y[dir];
        while (isInBound(i, j) && board[i][j] == flag) {
            count++;
            i += DIRECTION_X[dir];
            j += DIRECTION_Y[dir];
        }
        i = x - DIRECTION_X[dir];
        j = y - DIRECTION_Y[dir];
        while (isInBound(i, j) && board[i][j] == flag) {
            count++;
            i -= DIRECTION_X[dir];
            j -= DIRECTION_Y[dir];
        }
        if (count >= 5) {
            return true;
        }
    }
    return false;
}

//生成走法列表
void generateMoves(Point moves[], int& movesLength, const State flag)
{
    movesLength = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            //遍历并存储可走点
            if (board[i][j] == Empty && chessAround(i, j)) {
                moves[movesLength].x = i;
                moves[movesLength].y = j;
                moves[movesLength].score = 2 * evaluatePoint(i, j, flag) + evaluatePoint(i,j,static_cast<State>(3 - flag));	//评估并记录当前点的分数用于排序，考虑防守并优先进攻
                movesLength++;
            }
        }
    }
    //lamda表达式，等价于bool cmp(const Point& a, const Point& b){ return a.score > b.score; }  sort(moves, moves + movesLength,cmp);
    sort(moves, moves + movesLength, [](const Point& a, const Point& b) {
        return a.score > b.score;
    });
}

//检测是否有致胜或不得不堵的位置
bool checkKeyLine(const int x, const int y, const State flag, const int checkCount, const int checkEmpty)
{
    int i, j, count, empty;
    for (int dir = 0; dir < 4; dir++) {
        count = 1;
        empty = 0;
        i = x + DIRECTION_X[dir];
        j = y + DIRECTION_Y[dir];
        while (isInBound(i, j)) {
            if (board[i][j] == flag) {
                count++;
            }
            else if (board[i][j] == Empty) {
                empty++;
                break;
            }
            else {
                break;
            }
            i += DIRECTION_X[dir];
            j += DIRECTION_Y[dir];
        }
        i = x - DIRECTION_X[dir];
        j = y - DIRECTION_Y[dir];
        while (isInBound(i, j)) {
            if (board[i][j] == flag) {
                count++;
            }
            else if (board[i][j] == Empty) {
                empty++;
                break;
            }
            else {
                break;
            }
            i -= DIRECTION_X[dir];
            j -= DIRECTION_Y[dir];
        }

        if (count == checkCount && empty == checkEmpty) {
            return true;
        }
    }
    return false;
}

//检测是否有可以跳过搜索树的移动
bool findKeyMove(int& nextX, int& nextY, int& score)
{
    if (stepCount == 5) {
        if (board[4][7] == Empty) {
            nextX = 4;
            nextY = 7;
            return false;
        }
        if (board[7][4] == Empty) {
            nextX = 7;
            nextY = 4;
            return false;
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (board[i][j] == Empty && checkFive(i, j, player)) {
                nextX = i;
                nextY = j;
                return false;
            }
        }
    }


    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (board[i][j] == Empty && checkFive(i, j, enemy)) {
                nextX = i;
                nextY = j;
                return false;
            }
        }
    }

    bool flag = 0;
    int tempScore = -1;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (board[i][j] == Empty && ( checkKeyLine(i, j, player, 4, 2) || (checkKeyLine(i, j, player, 4, 1) && checkKeyLine(i, j, player, 3, 2)))) {
                nextX = i;
                nextY = j;
                if(!flag){
                    tempScore = evaluatePoint(i, j, player)+evaluatePoint(i, j, enemy);
					flag = 1;	
				}
				else{
					if(tempScore < evaluatePoint(i, j, player)+evaluatePoint(i, j, enemy)){
						nextX = i;
                        nextY = j;
					} 
				}
               
            }
        }
    }
    if(flag){
        return false;	
	}  
	//如果有多个点需要堵，要么必输，要么堵哪个都行
    //对于后一种情况，找到那个最优点落子
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (board[i][j] == Empty && (checkKeyLine(i, j, enemy, 4, 2) || (checkKeyLine(i, j, enemy, 4, 1) && checkKeyLine(i, j, enemy, 3, 2)))) {
                nextX = i;
                nextY = j;
                if(!flag){
                    tempScore=evaluatePoint(i,j,player)+evaluatePoint(i,j,enemy);
					flag = 1;	
				}
				else{
					if(tempScore < evaluatePoint(i,j,player)+evaluatePoint(i,j,enemy)){
						nextX = i;
                        nextY = j;
					} 
				}
            }
        }
    }
    if(flag){
        return false;	
	}  
	
    return true;
}

//Alpha-Beta搜索树
int AlphaBeta(const int depth, int alpha, const int beta, const State flag, int& bestX, int& bestY, bool top = false)
{
    //检测当前局面是否已经在置换表中
    unordered_map<ULL, HashKey>::iterator it = transTable.find(currentZobristKey);
    if (it != transTable.end()) {
        auto entry = it->second;
        if (entry.depth >= depth) {
            return entry.score;
        }
    }
    
    if (depth == 0) {
        int score = -evaluateBoard(); //到叶子节点，对当前局面打分，因为深度是单数所以有负号
        transTable[currentZobristKey] = { depth, score }; //更新置换表
        return score;
    }

    int score = 0, tempBestX = -1, tempBestY = -1, movesLength = 0;
    Point nextMoves[144];
    generateMoves(nextMoves, movesLength, flag);

    //启发式搜索，最多搜前40个优先级高的点
    for (int k = 0; k < min(movesLength, MAX_BRANCH); k++) {
        int i = nextMoves[k].x, j = nextMoves[k].y;
        setChess(i, j, flag); 
        score = -AlphaBeta(depth - 1, -beta, -alpha, static_cast<State>(3 - flag), bestX, bestY);
        delChess(i, j); 
        if (score >= beta) {
            return beta; 
        }
        if (score > alpha) {
            alpha = score; 
            tempBestX = i;
            tempBestY = j;
        }
    }

    if (top && tempBestX  != -1 && tempBestY != -1) {
        bestX = tempBestX;
        bestY = tempBestY;
    }

    return alpha;
}


//我方回合
void myTurn()
{
    int nextX = -1 , nextY = -1, score = 0;
    if(findKeyMove(nextX, nextY, score)) {
        score = AlphaBeta(SEARCH_DEPTH, -1000000000, 1000000000, player, nextX, nextY, true);
    }
    setChess(nextX, nextY, player);
    printf("%d %d\n", nextX, nextY);
    fflush(stdout);
}



//对方回合
void enemyTurn()
{
    int x, y;
    scanf("%d %d", &x, &y);
    setChess(x, y, enemy);
}

};


AutoChess AI;

int main()
{
    char command[10] = { 0 };
    while (true) {
        memset(command, 0, sizeof(command));
        scanf("%s", command);
        if (strcmp(command, "START") == 0) {
            scanf("%d", &player);
            enemy = static_cast<State>(3 - player);
            AI.setChess(5, 5, White);
            AI.setChess(6, 6, White);
            AI.setChess(5, 6, Black);
            AI.setChess(6, 5, Black);
            printf("OK\n");
            fflush(stdout);
        }
        else if (strcmp(command, "PLACE") == 0) {
            AI.enemyTurn();
        }
        else if (strcmp(command, "TURN") == 0) {  
            //clock_t startTime = clock();
            AI. myTurn();
            //printf("DEBUG [Time = %ldms]\n", clock() - startTime);
            //fflush(stdout);  
        }
        else if (strcmp(command, "END") == 0) {
            return 0;
        }
    }
}
