package com.ebe.java_trees.tree;

import com.ebe.java_trees.Tree;

import java.util.List;
import java.util.Set;

public interface TreeLeafOperations<K,V>  {

    // view content
    Set<K> getLeafsKeys();
    List<V> getLeafsValues();

    // view structure
    Tree<K,V> getLeaf(K key);
    Set<Tree<K,V>> getLeafs();

    // edit structure
    void removeLeaf(K key);

    // info
    boolean isLeaf(K key);
    boolean hasLeafs();
    int nrLeafs();

}
