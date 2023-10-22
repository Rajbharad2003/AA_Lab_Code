#include <bits/stdc++.h>

using namespace std;

class Point
{
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class CPP
{
    vector<Point> points;

    int dist(int i, int j)
    {
        return sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
    }

public:
    pair<Point, Point> run()
    {
        int n = points.size();

        int minIndex1 = 0, minIndex2 = 1, minDist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = dist(i, j);
                if (a < minDist)
                {
                    minIndex1 = i;
                    minIndex2 = j;
                    minDist = a;
                }
            }
        }
        return {points[minIndex1], points[minIndex2]};
    }

    void takeInput()
    {
        cout << "enter number of point" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            points.push_back(Point(x, y));
        }
    }
};

int main()
{

    CPP p;
    p.takeInput();
    auto ans = p.run();
    cout << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << endl;

    return 0;
}