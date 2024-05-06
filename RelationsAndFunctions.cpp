#include <vector>
#include <iostream>

using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::endl;


class Relation{
    private:
        vector<vector<int>> RelationshipMatrix;

    public:
        Relation(const vector<vector<int>>& coordinates);
        bool IsSymetric(int rows);
        bool IsTransitive(int rows);
        bool IsReflexive(int rows);
        bool IsFunction(int rows);
        void DomainAndCodomain();

};


Relation::Relation(const vector<vector<int>>& coordinates):RelationshipMatrix(coordinates){}

bool Relation::IsReflexive(int rows){
    for (int row = 0; row < rows; row++){
        if (RelationshipMatrix[row][row] != 1) return false;
    }

    return true;
}

bool Relation::IsSymetric(int rows){
    for (int row = 0; row < rows; row++){
        for (int column = 0; column < rows; column++){
            if (RelationshipMatrix[row][column] != RelationshipMatrix[column][row]) return false;
        }

    }

    return true;
}

bool Relation::IsTransitive(int rows){
    vector<vector<int>> square;
    square.assign(RelationshipMatrix.begin(), RelationshipMatrix.end());

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            square[i][j] = 0;
            for (int k = 0; k < rows; k++){
                square[i][j] += RelationshipMatrix[i][k] * RelationshipMatrix[k][j];
            }
        }
    }

    for (int row = 0; row < rows; row++){
        for (int column = 0; column < rows; column++){
            if (square[row][column] != RelationshipMatrix[row][column]) return false;
        }
    }

    return true;
}


bool Relation::IsFunction(int rows){
    int OnesInMatrix = 0;

    for (int row = 0; row < rows; row++){
        for (int column = 0; column < rows; column++){

            if (RelationshipMatrix[row][column] == 1){
                OnesInMatrix++;

                if (OnesInMatrix > rows) return false;
            }
        }
    }

    return true;
}


vector<vector<int>> CreateRelationshipMatrix(const vector<pair<int, int>> &elements, int rows, int columns){
    //create matrix
}


void displayMatrix(vector<vector<int>>& matrix){
    for(auto& row : matrix){
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}


int main(){
    int x, y, Number_of_coordinates, rows = 0, columns = 0;
    vector<vector<int>> coordinates;
    vector<pair<int, int>> elements;


    cout << "===C++ RELATIONSHIPS & FUNCTIONS CLI===" << endl;
    cout << "How many coordinates will you have?> ";
    cin >> Number_of_coordinates;

    cout << "Enter your coordinates -> x y:" << endl;
    for (int cords = 0; cords < Number_of_coordinates; cords++){
        cin >> x >> y;
        elements.push_back({x, y});
    }
    cout << "\n";

    //determine size of matrix


    coordinates = CreateRelationshipMatrix(elements, rows, columns);
    cout << "\n---Relationship as matrix---\n";
    displayMatrix(coordinates);

    cout << endl;
    Relation func(coordinates);
    cout << "\n\n---Properties---\n";
    cout << "Is reflexive?: " << func.IsReflexive(rows) << endl;
    cout << "Is symetric?: " << func.IsSymetric(rows) << endl;
    cout << "Is Transitive?: " << func.IsTransitive(rows) << endl;
    cout << "Is it a function?: " << func.IsFunction(rows) << endl;

    return 0;
}


//Modify the generation of the matrix as it is not doing it correctly




