import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class Tidal {
	class TidalFlow {
		ArrayDeque<Edge> stk = new ArrayDeque<Edge>();
		int N, fptr, bptr, s, t, oo = 987654321;
		ArrayList<Edge>[] adjj;
		Edge[][] adj;
		int[] q, dist, pool;

		TidalFlow(int NN) {
			N = (t = (s = NN) + 1) + 1;
			adjj = new ArrayList[N];
			for (int i = 0; i < N; i++)
				adjj[i] = new ArrayList<Edge>();
			adj = new Edge[N][0];
			dist = new int[N];
			pool = new int[N];
			q = new int[N];
		}

		void add(int i, int j, int cap) {
			Edge fwd = new Edge(i, j, cap, 0);
			Edge rev = new Edge(j, i, 0, 0); // for bidirectional, set -cap
			adjj[i].add(rev.rev = fwd);
			adjj[j].add(fwd.rev = rev);
		}

		int augment() {
			Arrays.fill(dist, Integer.MAX_VALUE);
			pool[t] = dist[s] = fptr = bptr = 0;
			pool[q[bptr++] = s] = oo;
			while (bptr > fptr && q[fptr] != t)
				for (Edge e : adj[q[fptr++]]) {
					if (dist[e.i] < dist[e.j])
						pool[e.j] += e.carry = Math.min(e.cap - e.flow, pool[e.i]);
					if (dist[e.i] + 1 < dist[e.j] && e.cap > e.flow)
						dist[q[bptr++] = e.j] = dist[e.i] + 1;
				}
			if (pool[t] == 0)
				return 0;
			Arrays.fill(pool, fptr = bptr = 0);
			pool[q[bptr++] = t] = oo;
			while (bptr > fptr)
				for (Edge e : adj[q[fptr++]]) {
					if (pool[e.i] == 0)
						break;
					int f = e.rev.carry = Math.min(pool[e.i], e.rev.carry);
					if (dist[e.i] > dist[e.j] && f != 0) {
						if (pool[e.j] == 0)
							q[bptr++] = e.j;
						pool[e.i] -= f;
						pool[e.j] += f;
						stk.push(e.rev);
					}
				}
			int res = pool[s];
			Arrays.fill(pool, 0);
			pool[s] = res;
			while (stk.size() > 0) {
				Edge e = stk.pop();
				int f = Math.min(e.carry, pool[e.i]);
				pool[e.i] -= f;
				pool[e.j] += f;
				e.flow += f;
				e.rev.flow -= f;
			}
			return res;
		}

		int getFlow() {
			int res = 0, f = 1;
			for (int i = 0; i < N; i++)
				adj[i] = adjj[i].toArray(adj[i]);
			while (f != 0)
				res += f = augment();
			return res;
		}

		class Edge {
			int i, j, cap, flow, carry;
			Edge rev;

			Edge(int ii, int jj, int cc, int ff) {
				i = ii;
				j = jj;
				cap = cc;
				flow = ff;
			}
		}
	}
}