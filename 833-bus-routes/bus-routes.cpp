#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Map each stop to the bus routes that serve it.
        unordered_map<int, vector<int>> routesByStop;
        for (int route = 0; route < static_cast<int>(routes.size()); ++route) {
            for (int stop : routes[route]) {
                routesByStop[stop].push_back(route);
            }
        }

        // Start with every route serving the source; each requires one bus.
        queue<pair<int, int>> q;
        unordered_set<int> visitedRoutes;
        unordered_set<int> visitedStops;
        for (int route : routesByStop[source]) {
            q.push({route, 1});
            visitedRoutes.insert(route);
        }

        // Explore routes in increasing order of buses taken.
        while (!q.empty()) {
            auto [route, buses] = q.front();
            q.pop();

            for (int stop : routes[route]) {
                if (stop == target) return buses;
                if (!visitedStops.insert(stop).second) continue;

                for (int nextRoute : routesByStop[stop]) {
                    if (visitedRoutes.insert(nextRoute).second) {
                        q.push({nextRoute, buses + 1});
                    }
                }
            }
        }

        return -1;
    }
};