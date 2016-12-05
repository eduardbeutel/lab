package com.ebe.java_trees.tree;

import com.ebe.java_trees.Tree;

import java.util.List;
import java.util.Set;

public interface TreeLevelOperations<K,V>
{

    // view content
    Set<K> getKeysOnLevel(int level);
    List<V> getValuesOnLevel(int level);

    // view structure
    Tree<K,V> getNodeOnLevel(K key, int level);
    Set<Tree<K,V>> getNodesOnLevel(int level);

    // edit structure
    void removeLevel(int level);

    // info
    void isOnLevel(K key, int level);
    int nrLevels();
    int lastLevel();
    int rootLevel();

}
