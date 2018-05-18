from py2neo import authenticate, cypher, Graph

g = Graph(password="123", host="localhost", http_port=11004, https_port=11006, bolt_port=11005, user="neo4j")
testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "r")
    query = ["match (n) detach delete(n)"]
    size = int(f.readline())
    print(size)
    nodes = list(range(size))
    query += ["foreach (i in %s | create(:Node {value: i}))" % nodes]
    array = list(map(int, f.readline().split()))
    for i in range(len(array)):
        query += ["match (a:Node {value: %d}), (b: Node {value: %d}) create (a)-[:G]->(b)" % (i, array[i])]
    print(query)
    for q in query:
        g.run(q)
    print("done")
    f.close()
    input()
