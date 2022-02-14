# C++ STL Algorithms

1. ## Heaps

    ```C++
    make_heap(begin, end);
    push_heap(begin, end);
    pop_heap(begin, end);
    sort_heap(begin, end);
    ```

    

2. ## Sorts

    ```C++
    sort(begin, end);
    partial_sort(begin, last);
    nth_element(begin, end);
    inplace_merge(begin, last);
    ```

    

3. ## Permutationers

    ```C++
    bool partition(begin, end);
    partition_point(begin, end);
    
    rotate(first, n_first, last); // front -> back
    shuffle(begin, end);
    next_permutation(begin, end);
    prev_permutation(begin, end);
    reverse(begin, end);
    ```

    

4. ## Queriers

    ```C++
    count(v);
    accumulate(begin, last, init);
    reduce(begin, last, init); // transform_reduce(begin, last, init);
    partial_sum(begin, last, OutputIter);
    partial_sum(begin, last, OutputIter, binary_op);
    inclusive_scan(); // 2 4 6 8 10
    exclusive_scan(); // 2 2 4 6 8
    inner_product();
    adjacent_difference();
    sample();
    all_of();
    any_of();
    none_of();
    equal(); // same as size and everything
    lexicographical_compare(); // abcdefg < abcdz
    mismatch(a.begin, a.end, b.begin, b.end); // returns a pair<it, it> that first position two rows differ
    ```

    

5. ## Search

    ```C++
    // UNSORTED: (& find value)
    find(v);
    adjacent_find(begin, end); // returns a value that the first position where two adjacent values occer in a row
    // SORTED: (& find sub range)
    equal_range();
    lower_bound(begin, end, v);
    upper_bound(begin, end, v);
    binary_search(v); // boolean
    find_first_of();
    
    max_element(begin, end);
    min_element(begin, end);
    minmax_element(begin, end); // returns a pair<it, it>
    ```

    

6. ## Sets

    ```C++
    // A - B
    set_different(A.begin, A.end, B.begin, B.end, back_inserter(res));
    // linear complexity, returns the elements which in set A but not in set B.(OutputIter, sorted)
    // intersection
    set_intersection();
    // union
    set_union();
    // union - intersection
    set_symmetric_difference();
    // include
    includes();
    // merge
    merge();
    ```

    

7. ## Movers

    ```C++
    copy(first, last, OutputIter);
    move(first, last, OutputIter);
    swap_ranges(first, last, OutputIter); // the same size
    // instead of for loops + copy
    copy_backward();
    move_backward();
    ```

    

8. ## Value modifiers

    ```C++
    fill(first, last, v); // fill all elements = v
    generate(first, last, f); // every position's value = f(i)
    iota(first, last, v); // increment it until fill the whole blocks
    replace(first, last, v1, v2); // replace every v1 by v2
    ```

    

9. ## Structure changers

    ```C++
    remove(begin, end, v); // pulls up the collection by leaving only those should not be removed, returns an Iter that points where the first element that should be crossed out
    unique(begin, end); // for adjacent elements and `one`can not be removed
    // USING:
    erase(remove(begin, end, v), end);
    erase(unique(begin, end), end);
    ```

    

10. etc.