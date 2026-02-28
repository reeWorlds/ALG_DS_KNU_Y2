#include <iostream>
#include <vector>
using namespace std;


double distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double min_dist(vector <pair<int, int> > points)
{
    // Base case: array of size 1
    if (points.size() <= 1)
    {
        return 1e9; // return a very large dummy distance
    }

    // Splitting array: left and right halves
    int mid = points.size() / 2;
    vector <pair<int, int> > points_left, points_right;
    for (int i = 0; i < mid; i++)
    {
        points_left.push_back(points[i]);
    }
    for (int i = mid; i < points.size(); i++)
    {
        points_right.push_back(points[i]);
    }

    // Min distance on left and right halves (recursively)
    double min_left_dist = min_dist(points_left);
    double min_right_dist = min_dist(points_right);
 
    // Minimum distance between point from left and point from right halves
    double min_cross_dist = 1e9; // initialize to a very large dummy distance
    for (int i = 0; i < points_left.size(); i++)
    {
        for (int j = 0; j < points_right.size(); j++)
        {
            min_cross_dist = min(min_cross_dist, distance(points_left[i].first, points_left[i].second, points_right[j].first, points_right[j].second));
        }
    }

    // Combining all cases
    double min_dist = min(min(min_left_dist, min_right_dist), min_cross_dist);

    return min_dist;
}

/*
5
0 0
1 4
2 3
5 1
4 3

*/


int main()
{
    int n, i, x, y;
    vector <pair<int, int> > points;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    double min_distance = min_dist(points);
    cout << "Minimum distance: " << min_distance << "\n";

    return 0;
}
