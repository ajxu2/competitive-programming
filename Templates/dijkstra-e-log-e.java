static class Pair<K, V> {
    public K f; public V s;
    public Pair(K f, V s) {
        this.f = f; this.s = s;
    }
}
static long[] dijk(ArrayList<Pair<Integer, Integer>>[] adj, int node) {
    long[] dist = new long[adj.length];
    Arrays.fill(dist, 1000000000000000000L); dist[node] = 0;
    PriorityQueue<Pair<Long, Integer>> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x.f));
    pq.add(new Pair<>(0L, node));
    while (!pq.isEmpty()) {
        Pair<Long, Integer> process = pq.remove();
        if (process.f > dist[process.s]) continue;
        for (Pair<Integer, Integer> i : adj[process.s]) {
            if (dist[process.s] + i.s < dist[i.f]) {
                dist[i.f] = dist[process.s] + i.s;
                pq.add(new Pair<>(dist[i.f], i.f));
            }
        }
    }
    return dist;
}
