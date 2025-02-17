/*

Spiral Order Matrix

Ideas:
    In one (outer) iteration, traverse one cycle of matrix clockwise
        Traverse along the top row, left to right
        Traverse along the right column, top to bottom
        Traverse along the bottom row, right to left
        Traverse along the left column, bottom to top
    Keep track of the boundaries of the matrix
    Keep track of the number of elements traversed at an instance

Algorithm:
    1. Initialize the result vector
    2. Initialize the boundaries of the matrix
    3. Initialize the number of elements traversed
    4. Initialize the total number of elements in the matrix
    5. While the number of elements traversed is less than the total number of elements in the matrix
        6. Traverse the top row from left to right
            7. Check the top boundary, left boundary, right boundary (no need for bottom boundary)
            8. Traverse along the top row, left to right
            9. Increment the number of elements traversed
            10. Move to the next row
        11. Traverse the right column from top to bottom
            12. Check the top boundary, right boundary, bottom boundary (no need for left boundary)
            13. Traverse along the right column, top to bottom
            14. Increment the number of elements traversed
            15. Move to the previous column
        16. Traverse the bottom row from right to left
            17. Check the bottom boundary, left boundary, right boundary (no need for top boundary)
            18. Traverse along the bottom row, right to left
            19. Increment the number of elements traversed
            20. Move to the previous row
        21. Traverse the left column from bottom to top
            22. Check the left boundary, top boundary, bottom boundary (no need for right boundary)
            23. Traverse along the left column, bottom to top
            24. Increment the number of elements traversed
            25. Move to the next column
    26. Return the result vector
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix){
            vector<int> result;
            int m = matrix.size();
            int n = matrix[0].size();
            
            int top = 0, bottom = m-1, left = 0, right = n-1;
            int current_elements = 0;
            int total_elements = m*n;

            while(current_elements < total_elements){
                //Traverse the top row from left to right
                //Check the top boundary, left boundary, right boundary (no need for bottom boundary)
                if(current_elements < total_elements && top < m && left < n && right >= 0){
                    for(int i = left; i <= right; i++){
                        result.push_back(matrix[top][i]);
                        current_elements++;
                    }

                    //Move to the next row
                    top++;
                }

                //Traverse the right column from top to bottom
                //Check the top boundary, right boundary, bottom boundary (no need for left boundary)
                if(current_elements < total_elements && top < m && bottom >= 0 && right >= 0){
                    for(int i = top; i <= bottom; i++){
                        result.push_back(matrix[i][right]);
                        current_elements++;
                    }

                    //Move to the previous column
                    right--;
                }

                //Traverse the bottom row from right to left
                //Check the bottom boundary, left boundary, right boundary (no need for top boundary)
                if(current_elements < total_elements && bottom >= 0 && left < n && right >= 0){
                    for(int i = right; i >= left; i--){
                        result.push_back(matrix[bottom][i]);
                        current_elements++;
                    }

                    //Move to the previous row
                    bottom--;
                }

                //Traverse the left column from bottom to top
                //Check the left boundary, top boundary, bottom boundary (no need for right boundary)
                if(current_elements < total_elements && left < n && top < m && bottom >= 0){
                    for(int i = bottom; i >= top; i--){
                        result.push_back(matrix[i][left]);
                        current_elements++;
                    }

                    //Move to the next column
                    left++;
                }
            }
            return result;
        }
    
};

int main(){
    Solution s;

    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = s.spiralOrder(matrix);

    for(auto& r : result)
        cout<<r<<" ";

    cout << endl;
    return 0;
}