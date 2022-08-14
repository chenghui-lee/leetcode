// Solution taken from https://leetcode.com/problems/word-ladder-ii/discuss/2411758/Java-Solution-DFS%2BBFS
// To be solved later
class Solution {
    Set<String> visited = null;
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> master = new ArrayList<>();
        Set<String> dictionary = new HashSet<>(wordList);
        if(beginWord.length() != endWord.length() || !dictionary.contains(endWord)) 
            return master;
        if(beginWord.equals(endWord) && dictionary.contains(endWord)){
            master.add(List.of(beginWord));
            return master;
        }
        Map<String, Integer> visitedAtLevel = new HashMap<>();
        Map<String, List<String>> graph = new HashMap<>();
        BFS(beginWord, endWord, dictionary, visitedAtLevel, graph);
        List<String> currPath = new ArrayList<>();
        visited = new HashSet<>();
        DFS(graph, master, currPath, beginWord, endWord);
        return master;
    }
    
    public void DFS(Map<String, List<String>> graph, List<List<String>> master, List<String> path, String start, String end){
      if(visited.contains(start)) return;
        if(start.equals(end)){
            path.add(start);
            master.add(new ArrayList<>(path));
            path.remove(path.size() -1);
            visited = new HashSet<>();
            return;
        }

        if(graph.get(start) == null || graph.get(start).isEmpty())
            return;

        visited.add(start);
        for(String curr : graph.get(start)){
            path.add(start);
            DFS(graph, master, path, curr, end);
            if(!path.isEmpty())
                path.remove(path.size()-1);
        }
    }
    
    public void BFS(String start, String end, Set<String> dictionary, Map<String, Integer> visitedAtLevel, Map<String, List<String>> graph){
        Queue<String> q = new LinkedList<>();
        q.add(start);
        visitedAtLevel.put(start, 0);
        while(!q.isEmpty()){
            String currWord = q.poll();
            char[] arr = currWord.toCharArray();
            for(int i=0 ; i<arr.length; ++i){
                char currChar = arr[i];
                for(char j='a'; j<='z'; ++j){
                    if(arr[i] == j) continue;
                    arr[i] = j;
                    String temp = new String(arr);
                    if(dictionary.contains(temp)){
                       if(!visitedAtLevel.containsKey(temp)){
                           visitedAtLevel.put(temp, visitedAtLevel.getOrDefault(currWord, -1)+1);
                           graph.putIfAbsent(currWord, new ArrayList<>());
                           graph.get(currWord).add(temp);
                           q.add(temp);
                       }else if(visitedAtLevel.get(temp) == visitedAtLevel.get(currWord)+1){
                           graph.putIfAbsent(currWord, new ArrayList<>());
                           graph.get(currWord).add(temp);
                       }
                    }
                }
                arr[i] = currChar;
            }
        }
    }
}
