#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef long long lint;

struct Location {
	lint x, y;
	bool operator<(const Location &a) {
		if (x == a.x) {
			return y < a.y;
		}
		return x < a.x;
	}
	bool operator<=(const Location &a) {
		if (x == a.x) {
			return y <= a.y;
		}
		return x <= a.x;
	}
	bool operator==(const Location &a) {
		return x == a.x && y == a.y;
	}
};

struct Node {
	lint edge, capacity;
	Node *reverse;
	Node(lint edge, lint capacity) :edge(edge), capacity(capacity), reverse(NULL) {}
};

lint n, k, h, m; // ¸ð¼­¸®¼ö, ÃÖ´ë¼ö, Áã±¸¸Û¼ö, Áã¼ö
Location edges[1001], holes[251], mices[251];
lint level[10001], sink;
vector<vector<Node*> > network;

inline lint ccw(Location pivot, Location a, Location b) {
	int result = 1LL * pivot.x * a.y + a.x * b.y + b.x * pivot.y - 1LL * pivot.x * b.y - a.x * pivot.y - b.x * a.y;
	if (result > 0) { return 1; }
	else if (result < 0) { return -1; }
	return 0;
}

bool canFlow(Node node) {
	return level[node.edge] == -1 && node.capacity > 0;
}

bool networkFlow() {
	memset(level, -1, sizeof(level));
	queue<int> Queue; Queue.push(0);
	level[0] = 0;
	while (!Queue.empty()) {
		int node = Queue.front(); Queue.pop();
		for (int i = 0; i < network[node].size(); i++) {
			Node &next = *network[node][i];
			if (canFlow(next)) {
				level[next.edge] = level[node] + 1;
				Queue.push(next.edge);
			}
		}
	}
	return level[sink] != -1;
}

int renualFlow(int node = 0, int flow = 987654321) {
	if (node == sink) { return flow; }
	for (int i = 0; i < network[node].size(); i++) {
		Node &next = *network[node][i];
		if (level[next.edge] == level[node] + 1 && next.capacity > 0) {
			int f = renualFlow(next.edge, min(flow, next.capacity));
			if (f > 0) {
				next.capacity -= f;
				next.reverse->capacity += f;
				return f;
			}
		}
	}
	return 0;
}

bool between(Location hole, Location edge1, Location edge2) {
	if (ccw(hole, edge1, edge2) != 0) {
		return false;
	}
	if (edge1.x != edge2.x) {
		return edge1.x <= hole.x && hole.x <= edge2.x
			|| edge2.x <= hole.x && hole.x <= edge1.x;
	}
	else {
		return edge1.y <= hole.y && hole.y <= edge2.y
			|| edge2.y <= hole.y && hole.y <= edge1.y;
	}
}

bool isIntersect(Location a, Location b, Location c, Location d) {
	lint abc = ccw(a, b, c), abd = ccw(a, b, d),
		cda = ccw(c, d, a), cdb = ccw(c, d, b);
	bool isBetween = between(b, c, d);
	if (abc * abd == 0 && cda * cdb == 0) {
		if (b < a) { swap(a, b); }
		if (d < c) { swap(c, d); }
		if (b == c || b == d) {
			return false;
		}
		return c < b && a < d;
	}
	else if (abc * abd == 0 || cda * cdb == 0) {
		if (abc * abd != 0) {
			return true;
		}
		return false;
	}
	return abc * abd < 0 && cda * cdb < 0;
}

bool canSeek(Location mice, Location hole) {
	for (int i = 0; i < n; i++) {
		if (isIntersect(mice, hole, edges[i % n], edges[(i + 1) % n])) {
			return false;
		}
	}
	return true;
}

void makeNetwork() {
	network.resize(m + h + 2);
	for (int i = 1; i <= m; i++) {
		Node *a = new Node(i, 1);
		Node *b = new Node(0, 0);
		a->reverse = b;
		b->reverse = a;
		network[0].push_back(a);
		network[i].push_back(b);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= h; j++) {
			if (canSeek(mices[i], holes[j])) {
				Node *a = new Node(m + j, 1);
				Node *b = new Node(i, 0);
				a->reverse = b;
				b->reverse = a;
				network[i].push_back(a);
				network[m + j].push_back(b);
			}
		}
	}
	for (int i = m + 1; i <= m + h; i++) {
		Node *a = new Node(sink, k);
		Node *b = new Node(i, 0);
		a->reverse = b;
		b->reverse = a;
		network[i].push_back(a);
		network[sink].push_back(b);
	}
}

void init() {
	cin >> n >> k >> h >> m;
	sink = m + h + 1;
	network.clear();
	for (int i = 0; i < n; i++) {
		cin >> edges[i].x >> edges[i].y;
	}
	for (int i = 1; i <= h; i++) {
		cin >> holes[i].x >> holes[i].y;
	}
	for (int i = 1; i <= m; i++) {
		cin >> mices[i].x >> mices[i].y;
	}
}

int main() {
	lint maxFlow = 0;
	init();
	makeNetwork();
	while (networkFlow()) {
		while (true) {
			lint flow = renualFlow();
			if (!flow) { break; }
			maxFlow += flow;
		}
	}
	cout << (maxFlow == m ? "Possible" : "Impossible") << '\n';
	return 0;
}