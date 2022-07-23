class Solution {
public:
    void f(vector<vector<int>>& image, int sr, int sc, int &color, int &org){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc > image[0].size() || image[sr][sc] == color || image[sr][sc] != org)
            return;
        image[sr][sc] = color;
        f(image,sr + 1, sc, color, org);
        f(image,sr - 1, sc, color, org);
        f(image,sr, sc + 1, color, org);
        f(image,sr, sc - 1, color, org);
        return;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if(org != color)
        f(image, sr, sc, color, org);
        return image;
    }
};