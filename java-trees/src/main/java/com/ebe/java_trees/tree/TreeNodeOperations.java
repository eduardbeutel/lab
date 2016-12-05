package com.ebe.java_trees.tree;

import com.ebe.java_trees.Tree;

import java.util.Comparator;
import java.util.Set;

public interface TreeNodeOperations<K,V> {

    // view content
    K getKey();
    V getValue();

    // view structure
    Tree<K,V> getParent();
    Tree<K,V> getChild(K key);
    Set<Tree<K,V>> getChildren();

    // edit structure
    void addChild(Tree<K,V> child);
    void removeChild(K key);
    void clear();

    // info
    int size();
    int nrChildren();
    boolean isChild(K key);
    boolean hasChildren();
    boolean hasParent();

    // sort
    void sortChildren(Comparator<Tree<K,V>> comparator);
    void sortChildrenAscendingByValue();

}
