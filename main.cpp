#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>

using namespace std;

// random generator function:
int myrandom (int i) { return std::rand()%i;}

// Structures
struct Figure {
	int col;
	int row;
	long long int val;

	bool operator< (const Figure& fig) const
	{
	    return (val < fig.val);
	}
};

struct Move {
	int x;
	int y;
};

struct Field {
	int x;
	int y;
	bool visited;
};

bool operator==(const Figure& left, const Figure& right)
{
    return left.col == right.col &&
           left.row == right.row;
}

struct AscendingOrder
{
    inline bool operator() (const Figure& struct1, const Figure& struct2)
    {
        return (struct1.val > struct2.val);
    }
};

// Variables
int n; // chessboard size;
int k; // max number of queens
int loadValue; // load queen on nil to the position;
int a; // to iterathe through visited board
int b; // to iterathe through visited board
int figures_on_chessboard = 0;
string output = "";

// Chessboard declaration
long long int** chessboard; // = new int*[n];
bool** visitedboard; // = new int*[n];

// Figures declaration
vector<Figure> figures;
stack <string> results;

// Movements declaration
Move moves[8] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

// Function delcaration
Move* get_path(int x1, int y1, int x2, int y2);
bool is_accessible(struct Field *f1, struct Field *f2);
void solve();
void print_path();
string intToStr(int n);
bool find_solution(int c_size, vector<Figure> figures);
Figure get_hittable(int col, int row, int m);
void add_to_prior_queue(Figure f, vector<Figure>* q_figure);
void remove_figure(vector<Figure> &figures, Figure f);

int main() {
    std::ios_base::sync_with_stdio(false);
  	srand ( unsigned ( time(0) ) );

	cin >> n;
	cin >> k;

	chessboard = new long long int*[n];
	visitedboard = new bool*[n];
	for (int i = 0; i < n; ++i) {
		chessboard[i] = new long long int[n];
		visitedboard[i] = new bool[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> loadValue;
			chessboard[i][j] = loadValue;
			if (loadValue != 0) {
                figures_on_chessboard += 1;
                visitedboard[i][j] = false;
                Figure figure;
                figure.col = i;
                figure.row = j;
                figure.val = loadValue;

                add_to_prior_queue(figure, &figures);
			}
		}
	}

	solve();
	print_path();

	return 0;
}

void solve() {
    find_solution(figures_on_chessboard, figures);
}

void hit(struct Figure *f1, struct Figure *f2) {
    figures.pop_back();
    f1->val = 0;
    f2->val *= 2;
}

bool find_solution(int solution_size, vector<Figure> q_figures) {
    if (solution_size <= k)
        return true;

    while(!q_figures.empty()) {
        Figure curr_fig = q_figures.front();
        q_figures.erase(q_figures.begin());

        // Try to hit in every possible direction
        for (int m = 0; m < 8; m++) {
            // Get the figure that is accessible from current figure
            Figure hit_figure = get_hittable(curr_fig.col, curr_fig.row, m);
            a = hit_figure.col;
            b = hit_figure.row;

            // If their values are equal to each other, then hit one figure by the other.
            if (hit_figure.val == curr_fig.val) {

                // create new priority queue for the recursive call - with the starting individual state for call.
                vector<Figure> new_q_figures;
                new_q_figures = q_figures;
                remove_figure(new_q_figures, hit_figure);

                // keep on date the chessboard and queue state
                chessboard[curr_fig.col][curr_fig.row] = 0;
                chessboard[a][b] *= 2;
                Figure new_figure = {a, b, hit_figure.val*2};
                add_to_prior_queue(new_figure, &new_q_figures);

                // recursive call to find the path
                if (find_solution(solution_size - 1, new_q_figures)) {
                    string o_res = intToStr(curr_fig.col) + " " + intToStr(curr_fig.row) + " " + intToStr(hit_figure.col) + " " + intToStr(hit_figure.row) + "\n";
                    // put the current path on stack (store the path from success way)
                    results.push(o_res);
                    return true;
                }

                // restore changes when returning from recursive call
                chessboard[curr_fig.col][curr_fig.row] = curr_fig.val;
                chessboard[hit_figure.col][hit_figure.row] = hit_figure.val;
            }
        }
    }
    return false;
}

void add_to_prior_queue(Figure f, vector<Figure>* q_figure) {
    // Put figure to the queue
    q_figure->push_back(f);
    // Sort the figures by value to keep them in order.
    // It cause the better performance - firstly a smaller figures are hit what
    // cause the new appearing figures have bigger value.
    // Randomiser makes the figures in the queue are not always in the same order.
    int randomizer = rand() % (int) 50;
    if (randomizer < 47)
        sort(q_figure->begin(), q_figure->end());
}

Figure get_hittable(int col, int row, int m) {
    int move_x = moves[m].x;
    int move_y = moves[m].y;

    col += move_x;
    row += move_y;

    while(col >= 0 && col < n && row >= 0 && row < n) {
        if (chessboard[col][row] != 0) {
            // may be possible to be hit if the value is same like in the second figure.
            return {col, row, chessboard[col][row]};
        }
        col += move_x;
        row += move_y;
    }
    // not hittable
    Figure res = {-1, -1, 0};
    return res;
}

void print_path() {
    // pop each atomic move from stack due to reverse the recursive path.
    while(!results.empty()) {
        string s_r = results.top();
        results.pop();
        cout<<s_r;
    }
}

void remove_figure(vector<Figure> &figures, Figure f) {
    // Remove the exact Figure from the vector of Figures (the priority queue here).
	figures.erase(
		remove_if(figures.begin(), figures.end(), [&](Figure const & figure)
			{
				return figure == f;
			}
		),figures.end()
	);
}

string intToStr(int n) {
    // Parse int to string in result output reasons.
    string tmp;
    if(n < 0) {
        tmp = "-";
        n = -n;
    }
    if(n > 9)
        tmp += intToStr(n / 10);
    tmp += n % 10 + 48;
    return tmp;
}
