package com.ebe.java_trees.tree;

import com.ebe.java_trees.Tree;

import java.util.Comparator;
import java.util.List;
import java.util.Set;
import java.util.function.Consumer;

public interface TreeDescendantOperations<K,V> {

    // view content
    Set<K> getDescendantsKeys();
    List<V> getDescendantsValues();

    // edit content
    void setDescendantValue(K key);

    // view structure
    Tree<K,V> getDescendant(K key);
    Set<Tree<K,V>> getDescendants();

    // edit structure
    void removeDescendant(K key);
    void removeDescendants(Set<K> key);
    void removeDescendantsExcept(Set<K> key);

    // info
    boolean isDescendant(K key);
    boolean hasDescendants();
    int nrDescendants();

    // sort
    void sortDescendants(Comparator<Tree<K,V>> comparator);
    void sortDescendantsAscendingByValue();

    // iterate
    void iterateTopDown(Consumer<Tree<K,V>> function);

}
