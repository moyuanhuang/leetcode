/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// represent each line as x1 - x2 / y1 - y2 = a
// ultilizing bcd
// considering overlap points

class Solution {
public:
    int maxPoints(vector<Point>& points) {
      if(points.size() <= 2)
        return points.size();
      int res = 2;
      for(int i = 0; i < points.size(); i++){
        unordered_map<int, unordered_map<int, int> > umap;
        int overlap = 0, max_count = 0;
        for(int j = i + 1; j < points.size(); j++){
          int x = points[i].x - points[j].x;
          int y = points[i].y - points[j].y;
          if(x == 0 and y == 0){
            overlap++;
            continue;
          }
          int temp = bcd(x, y);
          cout << "bcd for " << x << " " << y << " is " << temp << endl;
          if(temp != 0){
            x /= temp;
            y /= temp;
          }
          if(umap.count(x) != 0){
            if(umap[x].count(y) != 0){
              umap[x][y]++;
            }
            else{
              umap[x][y] = 1;
            }
          }
          else{
            umap[x] = unordered_map<int, int>();
            umap[x][y] = 1;
          }
          max_count = max(max_count, umap[x][y]);
        }
        res = max(res,  max_count + overlap + 1);
      }
      return res;
    }

private:
  int bcd(int a, int b){
    if(b == 0)  return a;
    return bcd(b, a % b);
  }

};
