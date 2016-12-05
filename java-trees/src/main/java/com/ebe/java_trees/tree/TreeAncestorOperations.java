package com.ebe.java_trees.tree;

import com.ebe.java_trees.Tree;

import java.util.List;
import java.util.Set;
import java.util.function.Consumer;

public interface TreeAncestorOperations<K,V>  {

    // view content
    Set<K> getAncestorsKeys();
    List<V> getAncestorsValues();

    // view structure
    Tree<K,V> getAncestor(K key);
    Set<Tree<K,V>> getAncestors();

    // info
    boolean isAncestor(K key);
    boolean hasAncestors();
    int nrAncestors();

    // iterate
    void iterateBottomUp(Consumer<Tree<K,V>> function);

}
