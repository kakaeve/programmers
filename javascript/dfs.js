const graph = {
    A: ['B', 'C'],
    B: ['A', 'D'],
    C: ['A', 'G', 'H', 'I'],
    D: ['B', 'E', 'F'],
    E: ['D'],
    F: ['D'],
    G: ['C'],
    H: ['C'],
    I: ['C', 'J'],
    J: ['I']
  };

  const BFS = (graph, startNode) =>{
    const visited = [];
    let needVisit = [];

    needVisit.push(startNode);

    while(needVisit.length!==0){
        const node = needVisit.shift();
        if(!visited.includes(node)){
            visited.push(node)
            console.log("needVisit : " + needVisit);
            console.log("graph[node] : " + graph[node]);
            needVisit = [...needVisit,...graph[node]];
            console.log("result : " + needVisit);

        }
    }
    return visited;
  };

  //console.log(BFS(graph,"A"))

  const DFS = (graph, startNode) => {
    const visited = [];
    let needVisit = [];

    needVisit.push(startNode);

    while(needVisit.length!==0){
        const node = needVisit.pop();
        console.log(node)
        if(!visited.includes(node)){
            visited.push(node)
            console.log("needVisit : " + needVisit);
            console.log("graph[node] : " + graph[node]);
            needVisit = [...needVisit,...graph[node]];
            console.log("result : " + needVisit);
        }
    }
    return visited;
  }

  console.log(DFS(graph,"A"))